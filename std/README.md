# Atari 2600 - Standard Core Include, Linker Configuration, and Make Rules Files.

---

## Index

* std/ --- Standard core files.
    * src/main/
        * asmcfg/ --- CC65 assembler/linker cartridge configurations.
            * a2k6-1k.cfg --- Atari 2600 1K ROM cartridge CA65 linker configuration file.
            * a2k6-2k.cfg --- Atari 2600 2K ROM cartridge CA65 linker configuration file.
            * a2k6-4k.cfg --- Atari 2600 4K ROM cartridge CA65 linker configuration file.
        * asminc/ --- Standard core assembler include files.
            * a2k6-std.inc --- Atari 2600 Standard Include (Includes the 4 includes below).
            * a2k6-std-plat.inc --- Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).
            * a2k6-std-riot.inc --- Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.
            * a2k6-std-tia.inc --- Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio).
            * a2k6-std-init.inc --- Atari 2600 Initialise Hardware following Power-up/Reset (CPU, RIOT, TIA).
        * make/ --- Make rules.
            * cc65.rules -- CC65 make rules files.
            * a2k6.rules -- Atari 2600 make rules files.
