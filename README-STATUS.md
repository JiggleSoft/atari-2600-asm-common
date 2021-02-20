# JiggleSoft Atari 2600 Assembler Common

## Project Progress

### Standard Core

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| std      | doc      | README-std.md            | 2.0      | Complete |          | Standard core docs. |
| std      | make     | cc65.rules               | 2.0      | Complete |          | CC65 make rules. |
| std      | make     | a2k6.rules               | 2.0      | Complete |          | Atari 2600 make rules. |
| std      | asmcfg   | a2k6-1k.cfg              | 2.0      | Complete |          | Atari 2600 1K ROM CC65 linker configuraiton. |
| std      | asmcfg   | a2k6-2k.cfg              | 2.0      | Complete |          | Atari 2600 2K ROM CC65 linker configuraiton. |
| std      | asmcfg   | a2k6-4k.cfg              | 2.0      | Complete |          | Atari 2600 4K ROM CC65 linker configuraiton. |
| std      | asminc   | a2k6-std.inc             | 2.0      | Complete |          | Standard core includes (all std core includes). |
| std      | asminc   | a2k6-std-plat.inc        | 2.0      | Complete |          | Platforms (NTSC,PAL,SECAM). |
| std      | asminc   | a2k6-std-riot.inc        | 2.0      | Complete |          | RIOT (registers and constants). |
| std      | asminc   | a2k6-std-tia.inc         | 2.0      | Complete |          | TIA (registers and constants). |
| std      | asminc   | a2k6-std-init.inc        | 2.0      | Complete |          | Initialisation (CPU, TIA, RIOT). |

### Standard Extra

These files may not make it into the final release of 2.1. Also additional files may be added.

| Group    | Type     | Name                     | Target   | Status   | Release  | Notes    |
| -------- | -------- | ------------------------ | -------- | -------- | -------- | -------- |
| stdx     | doc      | README.md                | 2.1      | Complete |          | Standard extra docs. |
| stdx     | asminc   | atari2k6.inc             | 2.1      | 5%       |          | Atari 2600 standard core and extra includes (all standard core and extra includes). |
| stdx     | asminc   | a2k6-stdx.inc             | 2.1      | 5%       |          | Standard Extra includes file (all standard extra includes). |
| stdx     | asminc   | a2k6-stdx-cpu.inc              | 2.1      | 5%       |          | CPU utils. |
| stdx     | asminc   | a2k6-stdx-lib.inc             | 2.1      | 5%       |          | Atari 2600 Library. |
| stdx     | asminc   | a2k6-stdx-util.inc             | 2.1      | 5%       |          | Atari 2600 utils. |
| stdx     | asminc   | a2k6-stdx-rram.inc             | 2.1      | 5%       |          | RIOT RAM utils. |
| stdx     | asminc   | a2k6-stdx-rio.inc              | 2.1      | 5%       |          | RIOT I/O utils. |
| stdx     | asminc   | a2k6-stdx-rtim.inc             | 2.1      | 5%       |          | RIOT Timer utils. |
| stdx     | asminc   | a2k6-stdx-tio.inc              | 2.1      | 5%       |          | TIA I/O utils. |
| stdx     | asminc   | a2k6-stdx-taud.inc             | 2.1      | 5%       |          | TIA Audio utils, |
| stdx     | asminc   | a2k6-stdx-tcol.inc             | 2.1      | 5%       |          | TIA Colour utils include. |
| stdx     | asminc   | a2k6-stdx-tcol-ntsc.inc        | 2.1      | 5%       |          | TIA NTSC Colour utils. |
| stdx     | asminc   | a2k6-stdx-tcol-pal.inc         | 2.1      | 5%       |          | TIA PAL Colour utils. |
| stdx     | asminc   | a2k6-stdx-tcol-secam.inc       | 2.1      | 5%       |          | TIA SECAM Colour utils. |
| stdx     | asminc   | a2k6-stdx-tvid.inc             | 2.1      | 5%       |          | TIA Video display utils. |
| stdx     | asminc   | a2k6-stdx-tpf.inc              | 2.1      | 5%       |          | TIA Playfield utils. |
| stdx     | asminc   | a2k6-stdx-tspr.inc             | 2.1      | 5%       |          | TIA Sprites utils. |
| stdx     | asminc   | a2k6-stdx-csw.inc              | 2.1      | 5%       |          | Atari 2600 Console Switches utils. |
| stdx     | asminc   | a2k6-stdx-joy.inc              | 2.1      | 5%       |          | Atari 2600 Joystick. |

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


