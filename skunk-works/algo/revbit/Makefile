include ../../../../std/src/main/make/cc65.rules
include ../../../../std/src/main/make/a2k6.rules

all:
	echo "PLEASE MAKE TARGET: build, clean, run."

a2k6-algo-revbit-main.4k: a2k6-algo-revbit-main.o
	$(LD65) -C /home/qh8404/git/js_gh/atari-2600-asm-common-develop/std/src/main/asmcfg/a2k6-4k.cfg -m a2k6-algo-revbit-main.map -Ln a2k6-algo-revbit-main.labels -vm a2k6-algo-revbit-main.o -o a2k6-algo-revbit-main.4k

a2k6-algo-revbit-main.o: a2k6-algo-revbit-main.s
	ca65 -D NO_STELLA_REG_NAMES -D PLATFORM_PAL -I /home/qh8404/git/js_gh/atari-2600-asm-common-develop/std/src/main/asminc/ -I /home/qh8404/git/js_gh/atari-2600-asm-common-develop/stdx/src/main/asminc/ --cpu 6502X -t atari2600 -l a2k6-algo-revbit-main.lst a2k6-algo-revbit-main.s -o a2k6-algo-revbit-main.o

build: a2k6-algo-revbit-main.4k

run:	build
	stella a2k6-algo-revbit-main.4k
	
clean:
	$(RM) a2k6-algo-revbit-main.4k
	$(RM) a2k6-algo-revbit-main.o
	$(RM) a2k6-algo-revbit-main.map
	$(RM) a2k6-algo-revbit-main.labels

