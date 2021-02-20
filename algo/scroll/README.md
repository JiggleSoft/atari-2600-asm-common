# Atari 2600 - Algorithm - Scroll (SCROLL)

Routines for scrolling memory (playfields and sprites).


## Description

These macros support the shifting and rotation of memory for horizontal scrolling of RAM memory buffers.

The 65XX source code is written for the CA65 (https://cc65.github.io/) assembler and can easily be ported to other assemblers.


## Macros


### Shift or Rotate a Line of Memory by 1 Bit Either Left or Right.

#### Shift a line of memory left by 1 bit.
 * SCROLL_SHIFT_ABS_MEM_LINE_LEFT  ptr,num

#### Shift a line of memory right by 1 bit.
 * SCROLL_SHIFT_ABS_MEM_LINE_RIGHT ptr,num

#### Shift a line of memory left by 1 bit with carry.
 * SCROLL_SHIFT_ABS_MEM_LINE_LEFT_CARRY  ptr,num

#### Shift a line of memory right by 1 bit with carry.
 * SCROLL_SHIFT_ABS_MEM_LINE_RIGHT_CARRY ptr,num

#### Rotate a line of memory left by 1 bit.
 * SCROLL_ROTATE_MEM_LINE_LEFT ptr,num

#### Rotate a line of memory right by 1 bit.
 * SCROLL_ROTATE_MEM_LINE_RIGHT ptr,num


### Shift or Rotate a Block of Memory by 1 Bit Either Left or Right.

#### Shift a block of memory left by 1 bit.
 * SCROLL_SHIFT_ABS_MEM_BLOCK_LEFT  ptr,width,height

#### Shift a block of memory right by 1 bit.
 * SCROLL_SHIFT_ABS_MEM_BLOCK_RIGHT ptr,width,height

#### Rotate a block of memory left by 1 bit.
 * SCROLL_ROTATE_ABS_MEM_BLOCK_LEFT ptr,width,height

#### Rotate a block of memory right by 1 bit.
 * SCROLL_ROTATE_ABS_MEM_BLOCK_RIGHT ptr,width,height


---

## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.
