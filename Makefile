#!/bin/make

# Makefile - Atari 2600 - Asm Common

RELEASE_NAME=atari-2600-asm-common
RELEASE_VER=2.0.0-beta-0
RELEASE_DIR=${RELEASE_NAME}-${RELEASE_VER}

build: build_info clean_release build_dir build_std build_stdx build_algo build_font build_kernel build_cart build_control build_jigglesoft
	echo "FINISH - RELEASE: ${RELEASE_NAME}; VERSION: ${RELEASE_VER}"

build_info:
	echo "START - RELEASE: ${RELEASE_NAME}; VERSION: ${RELEASE_VER}"

build_dir:
	mkdir -p build/${RELEASE_DIR}
	echo "build/${RELEASE_DIR}" > build/${RELEASE_DIR}.makeflag
	mkdir -p build/${RELEASE_DIR}/asminc
	mkdir -p build/${RELEASE_DIR}/asmcfg
	mkdir -p build/${RELEASE_DIR}/make

build_std: build_dir
	cp std/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp std/src/main/asmcfg/* build/${RELEASE_DIR}/asmcfg/
	cp std/src/main/make/* build/${RELEASE_DIR}/make/

build_stdx: build_dir
	cp stdx/src/main/asminc/* build/${RELEASE_DIR}/asminc/

build_algo: build_dir
	cp algo/revbit/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp algo/rnd/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp algo/aim/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp algo/scroll/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp algo/pack/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp algo/zoom/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp algo/sort/src/main/asminc/* build/${RELEASE_DIR}/asminc/

build_font: build_dir
	cp font/src/main/asminc/* build/${RELEASE_DIR}/asminc/

build_kernel: build_dir
	mkdir -p build/${RELEASE_DIR}/asminc
	cp kernel/src/main/asminc/* build/${RELEASE_DIR}/asminc/

build_cart: build_dir
	mkdir -p build/${RELEASE_DIR}/asminc
	cp cart/src/main/asminc/* build/${RELEASE_DIR}/asminc/
	cp cart/src/main/asmcfg/* build/${RELEASE_DIR}/asmcfg/

build_control: build_dir
	mkdir -p build/${RELEASE_DIR}/asminc
	cp control/src/main/asminc/* build/${RELEASE_DIR}/asminc/

build_jigglesoft: build_dir
	mkdir -p build/${RELEASE_DIR}/asminc
	cp jigglesoft/src/main/asminc/* build/${RELEASE_DIR}/asminc/

build/test-kick-the-tyres: test/src/kick-the-tyres.s
	$(CA65) -D NO_STELLA_REG_NAMES -D PLATFORM_NTSC -I build/${RELEASE_DIR}/asminc --cpu 6502X -t atari2600 test/src/kick-tyhe-tyres.s -o build/kick-the-tyres.o

clean_release:
	$(RM) -r build/${RELEASE_DIR}

clean:
	$(RM) -r build



