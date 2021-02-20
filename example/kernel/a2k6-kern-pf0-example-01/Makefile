#------------------------------------------------------------------------------
# Makefile for a2k6-kern-pf0-example-01.
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------
# CONFIGURATION
#------------------------------------------------------------------------------

ASM_COMMON_DIR=../../../build/atari-2600-asm-common-2.0.0-beta-0
STELLA="stella"
BUILD_DIR=build


#------------------------------------------------------------------------------
# INCLUDE RULES
#------------------------------------------------------------------------------

include ${ASM_COMMON_DIR}/make/cc65.rules
include ${ASM_COMMON_DIR}/make/a2k6.rules


#------------------------------------------------------------------------------
# BUILD
#------------------------------------------------------------------------------

default:
	@echo "Please make with known target e.g. clean, build, build-ntsc, run, run-pal"


#------------------------------------------------------------------------------
# BUILD
#------------------------------------------------------------------------------

build: build-ntsc build-pal build-secam
	@


build-ntsc: ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-ntsc.4k
	@

build-pal: ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-pal.4k
	@

build-secam: ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-secam.4k
	@


build-init:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${BUILD_DIR}/ntsc
	mkdir -p ${BUILD_DIR}/pal
	mkdir -p ${BUILD_DIR}/secam


${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-ntsc.4k: build-init ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-main-ntsc.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-ntsc.map -Ln ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-ntsc.labels -vm ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-main-ntsc.o -o ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-ntsc.4k

${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-pal.4k: build-init ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-main-pal.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-pal.map -Ln ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-pal.labels -vm ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-main-pal.o -o ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-pal.4k

${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-secam.4k: build-init ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-main-secam.o
	$(LD65) -C ${ASM_COMMON_DIR}/asmcfg/a2k6-4k.cfg -m ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-secam.map -Ln ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-secam.labels -vm ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-main-secam.o -o ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-secam.4k



${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-main-ntsc.o: a2k6-kern-pf0-example-01-main.s a2k6-kern-pf0-example-01-gfx.inc
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_NTSC -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-main-ntsc.lst a2k6-kern-pf0-example-01-main.s -o ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-main-ntsc.o

${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-main-pal.o: a2k6-kern-pf0-example-01-main.s a2k6-kern-pf0-example-01-gfx.inc
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_PAL -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-main-pal.lst a2k6-kern-pf0-example-01-main.s -o ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-main-pal.o

${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-main-secam.o: a2k6-kern-pf0-example-01-main.s a2k6-kern-pf0-example-01-gfx.inc
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_SECAM -I ${ASM_COMMON_DIR}/asminc/ --cpu 6502X -t atari2600 -l ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-main-secam.lst a2k6-kern-pf0-example-01-main.s -o ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-main-secam.o



#------------------------------------------------------------------------------
# RUN
#------------------------------------------------------------------------------

run: run-ntsc run-pal run-secam
	@

run-ntsc: build-ntsc
	$(STELLA) -format NTSC ${BUILD_DIR}/ntsc/a2k6-kern-pf0-example-01-ntsc.4k

run-pal: build-pal
	$(STELLA) -format PAL ${BUILD_DIR}/pal/a2k6-kern-pf0-example-01-pal.4k

run-secam: build-secam
	$(STELLA) -format SECAM ${BUILD_DIR}/secam/a2k6-kern-pf0-example-01-secam.4k


#------------------------------------------------------------------------------
# CLEAN
#------------------------------------------------------------------------------

clean: clean-ntsc clean-pal clean-secam
	$(RM) -f ${BUILD_DIR}

clean-ntsc:
	$(RM) -r ${BUILD_DIR}/ntsc

clean-pal:
	$(RM) -r ${BUILD_DIR}/pal

clean-secam:
	$(RM) -r ${BUILD_DIR}/secam


