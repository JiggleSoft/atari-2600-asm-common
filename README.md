# JiggleSoft
---
## atari2600_common
Atari 2600 common includes, headers, libraries, and tooling. 
Home on GitHub (https://github.com/JiggleSoft/atari2600_common)
---
### Supported 6507 Assemblers
 * CA65 (https://www.cc65.org/doc/ca65.html)
---
### Contact
 * Justin Lane (atari2600@jigglesoft.co.uk)
---
### Table of Contents
 * doc/ --- Documentation
 * src/ --- Source code.
   * std/ --- Standard core include files.
     * asmcfg/ --- Standard assembler/linker configurations.
     * asminc/ --- Standard assembler include files.
       * a2k6std.inc --- Atari 2600 Standard Include (Includes the 4 includes below).
       * a2k6plat.inc --- Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).
       * a2k6riot.inc --- Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.
       * a2k6tia.inc --- Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio).
       * a2k6init.inc --- Atari 2600 Initialise Hardware following Power-up/Reset (CPU, RIOT, TIA).
---
#### Work In Progress (WIP) below:-
   * stdx/ --- Standard extra include files.
     * asminc/ --- Standard extra assembler include files.
       * Any files within here are WIP and will cover items such as:-
         * Bank Switching, RIOT Timer, TIA Playfields, TIA Sprites, Atari 2600 Utilities, 6507 CPU Utilities, Console Switches, TIA Video, TIA Colour, Controllers (Joysticks,Keyboards,Trackball,Driving,Paddles,etc.), TIA Audio, etc.
   * kernel/ --- Kernel implementations.
     * Any files within here are WIP and will cover different kernel implementations.
   * test/ --- Test applications and includes.
     * Any files within here are WIP test applications.
 * examples/ --- Example applications.
     * Any files within here are WIP example applications.
 * build/ --- Build batch files.
   * Any files within here are WIP batch scripts.
