#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msxclib.h"
#include "msxalib.h"

#define BUF_SZ           (1024)
#define MAX_FILENAME_LEN (16)

int scload(char* fn) {
  FILE* fp;
  static char buff[BUF_SZ];
  unsigned int vram = 0x0000;
  if ((fp = fopen(fn, "rb"))) {
    fread(buff, 7, 1, fp); /* skip header */
    int read;
    while ((read = fread(buff, sizeof(char), BUF_SZ, fp))) {
      ldirvm(vram, buff, read);
      vram += BUF_SZ;
    }
    fclose(fp);
    return 0;
  }
  return 1;
}

int edge_key(int line, int bitmask, int* old) {
  int s = ((snsmat(line) & bitmask) == 0);
  int r = (s && !*old);
  *old = s;
  return r;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: present <filename>\n");
    exit(0);
  } else {
    ginit();
    screen(8);
    color(255, 0, 0);
    char base_filename[MAX_FILENAME_LEN];
    memset(base_filename, 0, MAX_FILENAME_LEN);
    strncpy(base_filename, argv[1], MAX_FILENAME_LEN); // Copy the base filename
    int file_index = 0;
    char current_filename[MAX_FILENAME_LEN];
    snprintf(current_filename, MAX_FILENAME_LEN, "%s.%03d", base_filename, file_index);
    scload(current_filename);
    int old_esc = 0, old_l = 0, old_r, old_u, old_d = 0;
    while(!edge_key(7, 0x04, &old_esc)){                                 // ESC
      if (edge_key(8, 0x80, &old_r) || (edge_key(8, 0x40, &old_r))) {   // right or down
        snprintf(current_filename, MAX_FILENAME_LEN, "%s.%03d", base_filename, file_index + 1);
        if (scload(current_filename) == 0) {
          file_index++;
        }
      }
      if (edge_key(8, 0x10, &old_l) || (edge_key(8, 0x20, &old_r))) {   // left or up
        if (file_index > 0) {
          snprintf(current_filename, MAX_FILENAME_LEN, "%s.%03d", base_filename, file_index - 1);
          if (scload(current_filename) == 0) {
            file_index--;
          }
        }
      }
    }
    screen(0);
  }
  return 0;
}