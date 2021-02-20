# JiggleSoft Atari 2600 Assembler Common
## Includes, Libraries, Configuration, and Build Scripts. 

---

## atari-2600-asm-common

Atari 2600 assembler common includes, libraries, configuration, and build scripts.\
The projects home is located on GitHub at https://github.com/JiggleSoft/atari2600-asm-common \
The projects status/roadmap can be viewed [here](README-STATUS.md).

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

 * [doc/](doc/) --- Documentation.

 * [std/](std/) --- Standard core include, linker configuration, and make rules files.
   * src/main/
     * asmcfg/ --- Cartridge (bank switching) configurations.
     * asminc/ --- Standard core assembler include files.
     * make/ --- Make rules.

 * [stdx/](stdx/) --- Standard extra include, linker configuration, and make rules files.
   * src/main/
     * asminc/ --- Standard extra assembler include files.

 * [algo/](algo/) --- Algorithms
   * [rnd/](algo/rnd/) --- Pseudo random number generators.
   * [aim/](algo/aim/) --- Approximate vector from one co-ordinate to another.
   * [revbit/](algo/revbit/) --- Reverse bits.
   * [pack/](algo/pack/) --- Compression tools and decompression macros.
   * [sort/](algo/sort/) --- Data sorting.
   * [zoom/](algo/zoom/) --- Graphics zoom and scaling.

 * [font/](font/) --- Various fonts.
   * src/main/
     * asminc/
       * TBD

 * [control/](control/) -- Additional controllers (keypad, driving).
     * src/main/
         * asminc/
             * TBD

 * [kernel/](kernel/) -- Various Kernels and Micro Kernels.
   * src/main/
     * asminc/
       * a2k6-kern-test.inc --- Test Card Kernel.
       * a2k6-kern-splash.inc --- Splash Screen Kernel.
       * a2k6-kern-pf0.inc --- Playfield 0 Kernel.
       * a2k6-kern-pong.inc --- Pong Kernel. 

 * [cart/](cart/) --- Various cartridges (bank switching schemes).
     * asmcfg/ --- Cartridge (bank switching) configurations.
     * asminc/ --- Cartridge (bank switching) assembler include files.

 * [example/](example/) --- Example applications.

 * [jigglesoft/](jigglesoft/) --- JiggleSoft's media.

 * [skunk-works/](skunk-works/) --- Testing ideas and prototypes. 

 * [lost-and-found/](lost-and-found/) --- Temporary storage for source, docs, data to be sorted out.

 * [archive/](archive/) --- Long term storage of code of historical interest.
