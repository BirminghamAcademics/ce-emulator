CEDEV ?= $(shell cedev-config --prefix)

CFLAGS=-O2
ICON=icon.png
ARCHIVED=YES

all: CHRONOS CORE_GB CORE_SMS

CHRONOS:
	$(CC) chronos.c -o CHRONOS.8xp

CORE_GB:
	$(CC) cores.c -DCORE_ID=1 -o CORE_GB.8xv

CORE_SMS:
	$(CC) cores.c -DCORE_ID=3 -o CORE_SMS.8xv
