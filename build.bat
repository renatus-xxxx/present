zcc +msx -create-app -O3 -DAMALLOC -subtype=msxdos main.c msxclib.c msxalib.c -bn PRESENT.COM -lm -Wall
del PRESENT.img
move /y PRESENT.COM bin
cd bin
copy dosformsx.DSK PRESENT.DSK
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PRESENT.COM
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK present.000
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK present.001
cd ../
