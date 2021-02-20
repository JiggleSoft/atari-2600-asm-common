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

 * std/ --- Standard core include files.

 * stdx/ --- Standard extra include files.

 * algo --- Algorithms
   * rev/ --- Reverse bits.
   * rnd/ --- Pseudo random number generators. 
   * aim/ --- Approximate vector from one co-ordinate to another. 
   * pack/ --- Compression tools and decompression macros.
   * sort/ --- Data sorting.
   * zoom/ --- Graphics zoom and scaling.

 * font/ --- Various fonts.

 * control/ -- Additional controllers.

 * kernel/ -- Various Kernels.

 * cart/ --- Various cartridges (bank switching schemes).

 * example/ --- Example applications.

 * skunk-works

 * lost-and-found/

 * archive/

 



 * doc/ --- Documentation

 * src/ --- Source code.

   * std/ --- Standard core include files.
     * doc/
     * make/ --- Standard CC65 assembler/linker and Atari 2600 make file fragments.
     * asmcfg/ --- Standard assembler/linker configurations.
       * a2k6-4k.cfg --- Atari 2600 4K ROM cartridge CA65 linker configuration file.
     * asminc/ --- Standard assembler include files.
       * a2k6std.inc --- Atari 2600 Standard Include (Includes the 4 includes below).
       * a2k6plat.inc --- Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).
       * a2k6riot.inc --- Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.
       * a2k6tia.inc --- Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio).
       * a2k6init.inc --- Atari 2600 Initialise Hardware following Power-up/Reset (CPU, RIOT, TIA).

   * stdx/ --- Standard extra include files.
     * asminc/ --- Standard extra assembler include files.
       * Any files within here are WIP and will cover items such as:-
         * Bank Switching, RIOT Timer, TIA Playfields, TIA Sprites, Atari 2600 Utilities, 6507 CPU Utilities, Console Switches, TIA Video, TIA Colour, Controllers (Joysticks,Keyboards,Trackball,Driving,Paddles,etc.), TIA Audio, etc.

   * font/
     * TBD

   * kernel/ --- Kernel implementations.
     * Any files within here are WIP and will cover different kernel implementations.

   * cart/ --- Cartridge type specific and bank switching.
     * asmcfg/
       * TBD
     * asminc/
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

; Future Candidate: BF, BFSC, BUS, CDF0, CDF1, CDFJ, CDFJ+, CM, CTY, DF, DFSC,
;                   DPC+, FA2, FC, MDM, TVBoy, WD.
; Unsupported:      4A50.
; Unknown:          Star Castle scheme.


   * test/ --- Test applications and includes.
     * Any files within here are WIP test applications.

 * examples/ --- Example applications.
     * Any files within here are WIP example applications.

 * build/ --- Build batch files.
   * Any files within here are WIP batch scripts.

---

##  TODO: MIGRATE TO TOC ABOVE

### Standard Core

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| std      | doc      | README.md                | 2.0      | 1%       |          | Standard core docs. |
| std      | make     | cc65.rules               | 2.0      | Complete |          | CC65 make rules. |
| std      | make     | a2k6.rules               | 2.0      | Complete |          | Atari 2600 make rules. |
| std      | asmcfg   | a2k6cart-1k.cfg          | 2.0      | 90%      |          | Atari 2600 1K ROM CC65 linker configuraiton. |
| std      | asmcfg   | a2k6cart-2k.cfg          | 2.0      | 90%      |          | Atari 2600 2K ROM CC65 linker configuraiton. |
| std      | asmcfg   | a2k6cart-4k.cfg          | 2.0      | Complete |          | Atari 2600 4K ROM CC65 linker configuraiton. |
| std      | asminc   | a2k6std.inc              | 2.0      | Complete |          | Standard core includes (all std core includes). |
| std      | asminc   | a2k6plat.inc             | 2.0      | Complete |          | Platforms (NTSC,PAL,SECAM). |
| std      | asminc   | a2k6riot.inc             | 2.0      | Complete |          | RIOT (registers and constants). |
| std      | asminc   | a2k6tia.inc              | 2.0      | Complete |          | TIA (registers and constants). |
| std      | asminc   | a2k6init.inc             | 2.0      | Complete |          | Initialisation (CPU, TIA, RIOT). |

### Standard Extra

These files may not make it into the final release of 2.1. Also additional files may be added.

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| stdx     | doc      | README.md                | 2.1      | TODO     |          | Standard extra docs. |
| stdx     | asminc   | atari2k6.inc             | 2.1      | 5%       |          | Atari 2600 standard core and extra includes (all standard core and extra includes). |
| stdx     | asminc   | a2k6stdx.inc             | 2.1      | 5%       |          | Standard Extra includes file (all standard extra includes). |
| stdx     | asminc   | a2k6cpu.inc              | 2.1      | 5%       |          | CPU utils. |
| stdx     | asminc   | a2k6util.inc             | 2.1      | 5%       |          | Atari 2600 utils. |
| stdx     | asminc   | a2k6rram.inc             | 2.1      | 5%       |          | RIOT RAM utils. |
| stdx     | asminc   | a2k6rio.inc              | 2.1      | 5%       |          | RIOT I/O utils. |
| stdx     | asminc   | a2k6rtim.inc             | 2.1      | 5%       |          | RIOT Timer utils. |
| stdx     | asminc   | a2k6tio.inc              | 2.1      | 5%       |          | TIA I/O utils. |
| stdx     | asminc   | a2k6taud.inc             | 2.1      | 5%       |          | TIA Audio utils, |
| stdx     | asminc   | a2k6tcol.inc             | 2.1      | 5%       |          | TIA Colour utils include. |
| stdx     | asminc   | a2k6tcol-ntsc.inc        | 2.1      | 5%       |          | TIA NTSC Colour utils. |
| stdx     | asminc   | a2k6tcol-pal.inc         | 2.1      | 5%       |          | TIA PAL Colour utils. |
| stdx     | asminc   | a2k6tcol-secam.inc       | 2.1      | 5%       |          | TIA SECAM Colour utils. |
| stdx     | asminc   | a2k6tvid.inc             | 2.1      | 5%       |          | TIA Video display utils. |
| stdx     | asminc   | a2k6tpf.inc              | 2.1      | 5%       |          | TIA Playfield utils. |
| stdx     | asminc   | a2k6tspr.inc             | 2.1      | 5%       |          | TIA Sprites utils. |
| stdx     | asminc   | a2k6csw.inc              | 2.1      | 5%       |          | Atari 2600 Console Switches utils. |

### Fonts

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| font     | asminc   | a2k6font.inc             | 2.2      |          |          |          |
| font     | asminc   | a2k6font-4x5-num.inc     | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x5-norm.inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-norm.inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-bold.inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |
| font     | asminc   | a2k6font-8x8-    .inc    | 2.2      |          |          |          |

### TV Standards

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
|          |          |                          |          |          |          |          |

### Music / SFX

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
|          |          |                          |          |          |          |          |

### Examples

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| example  | first    | a2k6first-main.s         |          |         |           |          |
| example  | first    | Makefile                 |          |         |           |          |
| example  | picture  | a2k6port-main.s          |          |         |           |          |
| example  | picture  | Makefile                 |          |         |           |          |
| example  | pong     | a2k6pong-main.s          |          |         |           |          |
| example  | pong     | Makefile                 |          |         |           |          |
|          |          |                          |          |         |           |          |

### Controllers

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| stdx     | asminc   | a2k6joy.inc              | 2.1      |          |          | Atari 2600 joystick / controller include file. |
| stdx     | asminc   | a2k6djoy.inc             | 2.1      | 5%       |          | Atari 2600 Digital Joystick utils. |
| stdx     | asminc   | a2k6ajoy.inc             | 2.TBD    |          |          | Atari 2600 Analogue Joystick / Paddle utilities include file. |
| stdx     | asminc   | a2k6driv.inc             | 2.TBD    |          |          | Atari 2600 Driving Controller utilities include file. |
| stdx     | asminc   | a2k6keyb.inc             | 2.TBD    |          |          | Atari 2600 Keyboard / Keypad utilities include file. |
| stdx     | asminc   | a2k6lgun.inc             | 2.TBD    |          |          | Atari 2600 Light Gun utilities include file. |
| stdx     | asminc   | a2k6trak.inc             | 2.TBD    |          |          | Atari 2600 Track Ball utilities include file. |  
|          |          |                          |          |          |          |          |

### Kernels

#### Picture Kernel

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| kernel   | asminc   | a2k6kern-pict.inc        |          |          |          | Kernel for rendering pictures (PF, COLUBK, and COLUPF). |
| kernel   | asminc   | a2k6kern-pong.inc        |          |          |          | Kernel that support pong games (PF, P0, P1, M0, M1, BL, priorities, and colours). |
|          |          |                          |          |          |          |          |

#### Pong Kernel

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| kernel   | asminc   | a2k6kern-pict.inc        |          |          |          | Kernel for rendering pictures (PF, COLUBK, and COLUPF). |
| kernel   | asminc   | a2k6kern-pong.inc        |          |          |          | Kernel that support pong games (PF, P0, P1, M0, M1, BL, priorities, and colours). |
|          |          |                          |          |          |          |          |

### Cartridge Type / Bank Switching

#### Non-Bank Switched

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asmcfg   | TBD                      |          |          |          |          |
| cart     | asminc   | CARTRIDGE TYPE AUTO INC  |          |          |          |          |
| cart     | asminc   | a2k6cart.inc             | 2.TBD    |          |          |          |
|          |          | SUPER CART               | 2.TBD    |          |          |          |
| cart     | asminc   | a2k6cart-sc.inc          | 2.TBD    |          |          |          |
|          |          |                          |          |          |          |          |

#### Non-Bank Switched

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-1k.inc          | 2.TBD    |          |          |          |
| cart     | asminc   | a2k6cart-2k.inc          | 2.TBD    |          |          |          |
| cart     | asminc   | a2k6cart-4k.inc          | 2.TBD    |          |          |          |
| cart     | asminc   | a2k6cart-4ksc.inc        | 2.TBD    |          |          |          |
| cart     | asminc   | a2k6cart-cv.inc          | 2.TBD    |          |          |          |
|          |          |                          |          |          |          |          |

#### Legacy Atari

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-f8.inc          | 2.       |          |          |          |
| cart     | asminc   | a2k6cart-f8sc.inc        | 2.       |          |          |          |
| cart     | asminc   | a2k6cart-f6.inc          | 2.       |          |          |          |
| cart     | asminc   | a2k6cart-f6sc.inc        | 2.       |          |          |          |
| cart     | asminc   | a2k6cart-f4.inc          | 2.       |          |          |          |
| cart     | asminc   | a2k6cart-f4sc.inc        | 2.       |          |          |          |
|          |          |                          |          |          |          |          |

#### Legacy Other

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-3f.inc          | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-dpc.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-e0.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-e7.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-e78k.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-f0.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-fa.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-fe.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-ua.inc   | TBD         |        |       |          |          |
|          |          |                          |          |          |          |          |

#### Modern

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-0840.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-3e.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-3eplus.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-3ex.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-ar.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-ef.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-efsc.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-sb.inc   | TBD         |        |       |          |          |
| cart     | asminc   |        * a2k6cart-x08.inc   | TBD         |        |       |          |          |
|          |          |                          |          |          |          |          |

#### Experimental

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | -------- | EXPERIMENTAL                  |          |        |       |          |          |
| cart     | asminc   | a2k6cart-jl1.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-jl2.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-jl3.inc   | TBD         |        |       |          |          |
| cart     | asminc   | a2k6cart-jl4.inc   | TBD         |        |       |          |          |
|          |          |                          |          |          |          |          |

#### Future Candidate

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-bf.inc    | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-bfsc.inc  | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-bus.inc   | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-cdf0.inc  | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-cdf1.inc  | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-cdfj.inc  | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-cdfjplus.inc     | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-cm.inc    | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-cty.inc   | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-df.inc    | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-dfsc.inc  | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-dpcplus.inc     | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-fa2.inc   | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-fc.inc    | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-mdm.inc   | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-tvboy.inc | TBD         |        |       |          | Future         |
| cart     | asminc   | a2k6cart-wd.inc    | TBD         |        |       |          | Future         |
|          |          |                          |          |          |          |          |

#### Unsupported

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-4a50.inc  | N/A         |        |       |          | Unsupported.   |
|          |          |                          |          |          |          |          |

#### Unknown

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| cart     | asminc   | a2k6cart-????.inc  | TBD         |        |       |          | Unknown: Star Castle ? |
|          |          |                          |          |          |          |          |


### ? LOST AND FOUND ?

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| stdx     | asminc   | a2k6xram.inc             |          |          |        |       |          | Atari 2600 Expansion RAM utilities include file. |
| stdx     | asminc   | a2k6vid.inc                         |          |          |        |       |          | Atari 2600 video include file. |
| stdx     | asminc   | a2k6joy.inc              |          |          |        |       |          | Atari 2600 Common Joystick/Controller utilities include file. |
|          |          |                          |          |          |          |          |


