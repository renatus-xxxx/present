zcc +msx -create-app -O3 -DAMALLOC -subtype=msxdos main.c msxclib.c msxalib.c -bn PRESENT.COM -lm -Wall
del PRESENT.img
move /y PRESENT.COM bin
cd bin
copy dos2formsx.DSK PRESENT.DSK
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PRESENT.COM
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.000
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.001
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.002
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.003
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.004
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.005
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.006
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.007
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK PWRPT.008
START /WAIT DISKMGR.exe -A -F -C PRESENT.DSK AUTOEXEC.BAT
cd ../
