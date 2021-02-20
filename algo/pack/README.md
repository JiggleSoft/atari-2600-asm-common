# Atari 2600 - Algorithm - Pack (PACK)

Tools for compressing and routines for decompression.


## Problem

FIXME

The 65XX source code is written for the CA65 (https://cc65.github.io/) assembler and can easily be ported to other assemblers.


## Solution

FIXME


---

### FIXME

FIXME

#### Macro prefix

ZOOM_SPR_8_16_

#### Input

zoom_spr_8_16_src       pointer, source sprite data pointer.
zoom_spr_8_16_height    unsigned byte, source sprite data height in pixels (% 8 must == 0).
zoom_spr_8_16_zoom      unsigned 4.4 fixed point, zoom scale factor.

#### Working

zoom_spr_8_16_line      unsigned byte, line position.
zoom_spr_8_16_pixel     unsigned byte, pixel position counter.

#### Output
zoom_spr_8_16_dst1       Destination sprite data pointer 1.
zoom_spr_8_16_dst2       Destination sprite data pointer 2.


---

## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.
