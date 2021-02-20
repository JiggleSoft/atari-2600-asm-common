# Atari 2600 - Algorithm - Reverse Bits (REVBIT)

Various implementations for reversing all the bits within a byte.
All with different CODE size, RAM size, STACK size, RODATA size, and CPU clock trade-off's.
Although this version of the code is written for the Atari 2600 it could be used for other 65xx based systems.
Also the algorithms method could be migrated to other architectures / platforms.


## Problem

The original issue was posted to the Atari Age Discord channel #programming as follows:

```
DEVGOD 14/01/2021

So what is the easiest way to flip the bits of the byte in the accumulator on Atari 2600 6502 assembly?
Like, if I have %00000011, how would I change this accumulator value to %11000000?
```

Thanks to Ryan Witmer for his description of a method he had used (an optimised version of this exists within my include file):-

```
Ryan Witmer 15/01/2021

Depends on how fast you need it.
I did it in my last game by shifting each bit off the end into carry and then pushing the status register onto the stack.
After all 8 bits were on the stack I pulled them off and rotated them in from the other side.

This is slow, but the code for this is much smaller than a lookup table.

If you need the results fast, then yeah, lookup table.
```

This has thus lead to this implementation.
Code is written for the CA65 (https://cc65.github.io/) assembler and can easily be ported to other assemblers.


## Implementations

Input is via the A register and output will also be within the A register.

| Impl. | Reg.           | RAM | STACK | DATA | CODE  | CPU   | Title |
|-------|----------------|-----|-------|------|-------|-------|-------|
| REG   | A AND (X OR Y) | 0   | 0     | 0    | 44    | 88    | Registers only. |
| STACK | A              | 0   | 7     | 0    | 30    | 81    | Stack carry. |
| MEM   | A              | 1   | 0     | 0    | 26/35 | 59/68 | Memory (temporary byte). |
| NLUT1 | A AND (X OR Y) | 1   | 1     | 16   | 24/26 | 43/45 | Nybble look-up v1 (2 x 4-bit). |
| NLUT2 | A AND (X OR Y) | 1   | 1     | 32   | 20/22 | 35/37 | Nybble look-up v2 (2 x 4-bit). |
| BLUT  | A AND (X OR Y) | 0   | 0     | 256  | 4     | 6     | Byte look-up (8-bit). |

Note: If two numbers are given separated by a slash then the first is if ZP memory is used, and the second if memory is above address 255.


The following macros and parameters are implemented:-

 * REVBIT_REG
 * REVBIT_STACK
 * REVBIT_MEM    tmp_addr
 * REVBIT_NLUT1_X  data_addr,tmp_addr
 * REVBIT_NLUT1_Y  data_addr,tmp_addr
 * REVBIT_NLUT2_X  data_addr,tmp_addr
 * REVBIT_NLUT2_Y  data_addr,tmp_addr
 * REVBIT_BLUT_X   data_addr
 * REVBIT_BLUT_Y   data_addr

Note: Selection of index register is by the macro suffix where applicable e.g. *_X, *_Y.


Data tables are defined with assembler directives by using the following macros:-

 * REVBIT_NLUT1_DATA
 * REVBIT_NLUT2_DATA
 * REVBIT_BLUT_DATA


## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.

