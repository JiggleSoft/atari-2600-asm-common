# Atari 2600 - Standard Extra Include, Linker Configuration, and Make Rules Files.

---

## Index

* stdx/ --- Standard extra include files.
    * src/main/
        * asminc/
            * Composite Include Files
                * atari2k6.inc --- Atari 2600 all standard and standard extra include files.
                * a2k6-stdx.inc --- Atari 2600 standard extra include file.
            * 65XX CPU Specific
                * a2k6-stdx-cpu.inc --- Atari 2600 Central Processing Unit (CPU).
                    * Spinning delays, pseudo instructions, etc.
                * a2k6-stdx-lib.inc --- Atari 2600 Libraries.
                    * Standard library functions, memcpy, memcmp, memset, etc.
            * Atari 2600 Specific
                * a2k6-stdx-util.inc --- Atari 2600 Utilities.
            * 6532 RAM, I/O, Timer (RIOT)
                * a2k6-stdx-rram.inc --- Atari 2600 RIOT RAM.
                * a2k6-stdx-rio.inc --- Atari 2600 RIOT IO.
                * a2k6-stdx-rtim.inc --- Atari 2600 RIOT Timer.
            * Atari Television Interface Adapter (TIA)
                * a2k6-stdx-tcol.inc --- Atari 2600 TIA Colour.
                * a2k6-stdx-tvid.inc --- Atari 2600 TIA Video display utilities.
                * a2k6-stdx-tpf.inc --- Atari 2600 TIA Playfield utilities.
                * a2k6-stdx-tspr.inc --- Atari 2600 TIA Sprite.
                * a2k6-stdx-tio.inc --- Atari 2600 TIA IO.
                * a2k6-stdx-taud.inc --- Atari 2600 TIA Audio.
            * Control Input (Console Switches and Joysticks)
                * a2k6-stdx-csw.inc --- Atari 2600 Console Switches.
                * a2k6-stdx-joy.inc --- Atari 2600 Standard Digital Joystick / Paddle Controller.
