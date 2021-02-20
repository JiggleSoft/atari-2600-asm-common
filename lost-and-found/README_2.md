# JiggleSoft Atari 2600 Assembler Common
## Includes, Libraries, Configuration, and Build Scripts. 

---

## atari-2600-asm-common

Atari 2600 assembler common includes, libraries, configuration, and build scripts.\
The projects home is located on GitHub at https://github.com/JiggleSoft/atari2600-asm-common \
The projects status/roadmap can be viewed [here](STATUS-README.md).

## Supported 6507 Assemblers

 * CA65 (https://cc65.github.io/)

## Licensing

Copyright (C) 2020 Justin Lane.

All content in this repository is licensed under the [Apache 2.0 license](LICENSE-2.0.txt).\
Please refer to the [LICENSE](LICENSE) file for full details.

## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.

---

## Repository Table of Contents

 * doc/ --- Documentation.

 * std/ --- Standard core files.
   * src/main/
     * asmcfg/ --- Cartridge (bank switching) configurations.
       * a2k6-1k.cfg
       * a2k6-2k.cfg
       * a2k6-4k.cfg
     * asminc/ --- Standard core assembler include files.
       * a2k6-std.inc
       * a2k6-std-plat.inc
       * a2k6-std-riot.inc
       * a2k6-std-tia.inc
       * a2k6-std-init.inc
     * make/ --- Make rules.
       * cc65.rules
       * a2k6.rules

 * stdx/ --- Standard extra include files.
   * src/main/
     * asminc/
       * atari2k6.inc
       * a2k6-std.inc --- Atari 2600 standard include file.
       * a2k6-stdx.inc --- Atari 2600 standard extra include file.
       * a2k6-stdx-cpu.inc --- Atari 2600 Central Processing Unit (CPU).
       * a2k6-stdx-dat.inc --- Atari 2600 Data.
       * a2k6-stdx-util.inc --- Atari 2600 Utilities.
       * a2k6-stdx-rram.inc --- Atari 2600 RIOT RAM.
       * a2k6-stdx-rio.inc --- Atari 2600 RIOT IO.
       * a2k6-stdx-rtim.inc --- Atari 2600 RIOT Timer.
       * a2k6-stdx-tcol.inc --- Atari 2600 TIA Colour.
       * a2k6-stdx-tvid.inc --- Atari 2600 TIA Video display utilities.
       * a2k6-stdx-tpf.inc --- Atari 2600 TIA Playfield utilities.
       * a2k6-stdx-tspr.inc --- Atari 2600 TIA Sprite.
       * a2k6-stdx-tio.inc --- Atari 2600 TIA IO.
       * a2k6-stdx-taud.inc --- Atari 2600 TIA Audio.
       * a2k6-stdx-csw.inc --- Atari 2600 Console Switches.
       * a2k6-stdx-joy.inc --- Atari 2600 Standard Digital Joystick / Paddle Controller.
       * a2k6-stdx-lib.inc --- Atari 2600 Libraries.
       * a2k6-stdx-rtl.inc --- Atari 2600 Runtime Library.

 * algo --- Algorithms
   * rev/ --- Reverse bits.
   * rnd/ --- Pseudo random number generators.
   * aim/ --- Approximate vector from one co-ordinate to another.
   * pack/ --- Compression tools and decompression macros.
   * sort/ --- Data sorting.
   * zoom/ --- Graphics zoom and scaling.

 * font/ --- Various fonts.
   * TBD

 * control/ -- Additional controllers (keypad, driving).
   * TBD

 * kernel/ -- Various Kernels and Micro Kernels.
   * src/main/
     * asminc/
       * a2k6-kern-pf0.inc --- Playfield 0 Kernel.
       * a2k6-kern-pong.inc --- Pong Kernel. 

 * cart/ --- Various cartridges (bank switching schemes).
   * a2k6cart.inc
   
   * a2k6cart-sc.inc

   * a2k6cart-1k.inc
   * a2k6cart-2k.inc
   * a2k6cart-4k.inc
   * a2k6cart-4ksc.inc
   * a2k6cart-cv.inc

   * a2k6cart-f8.inc
   * a2k6cart-f8sc.inc
   * a2k6cart-f6.inc
   * a2k6cart-f6sc.inc
   * a2k6cart-f4.inc
   * a2k6cart-f4sc.inc

   * a2k6cart-3f.inc
   * a2k6cart-dpc.inc
   * a2k6cart-e0.inc
   * a2k6cart-e7.inc
   * a2k6cart-e78k.inc
   * a2k6cart-f0.inc
   * a2k6cart-fa.inc
   * a2k6cart-fe.inc
   * a2k6cart-ua.inc

   * a2k6cart-0840.inc
   * a2k6cart-3e.inc
   * a2k6cart-3eplus.inc
   * a2k6cart-3ex.inc
   * a2k6cart-ar.inc
   * a2k6cart-ef.inc
   * a2k6cart-efsc.inc
   * a2k6cart-sb.inc
   * a2k6cart-x08.inc

   * a2k6cart-jl1.inc
   * a2k6cart-jl2.inc
   * a2k6cart-jl3.inc
   * a2k6cart-jl4.inc

   * To Sort
     * Future Candidate: 
       * BF, BFSC, BUS, CDF0, CDF1, CDFJ, CDFJ+, CM, CTY, DF, DFSC,
       * DPC+, FA2, FC, MDM, TVBoy, WD. 
     * Unsupported:
       * 4A50.
     * Unknown:
       * Star Castle scheme.

 * example/ --- Example applications.

 * skunk-works/ --- Testing ideas and prototypes. 

 * lost-and-found/ --- Temporary storage for source, docs, data to be sorted out.

 * archive/ --- Long term storage of code of historical interest.
