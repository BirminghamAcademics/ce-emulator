CC=$(CEDEV)/bin/ez80-clang
CFLAGS=-O2
ARCHIVED=YES

all: CHRONOS CORE_GB CORE_SMS CORE_GG

CHRONOS:
	$(CC) chronos.c -o CHRONOS.8xp

CORE_GB:
	$(CC) cores.c -DCORE_ID=1 -o CORE_GB.8xv

CORE_SMS:
	$(CC) cores.c -DCORE_ID=3 -o CORE_SMS.8xv

CORE_GG:
	$(CC) cores.c -DCORE_ID=4 -o CORE_GG.8xv

clean:
	rm -f *.8xp *.8xv
