# Atari 2600 - Algorithm - Zoom (ZOOM)

Routines for scaling the Atari 2600 playfield and sprites.


## Problem

The original vector based Lunar Lander zoomed in as you got to a lower altitude and zoomed out as you gained altitude.
These routines were coded to provide this effect on the Atari 2600.

The 65XX source code is written for the CA65 (https://cc65.github.io/) assembler and can easily be ported to other assemblers.


## Solution

Horizontal scaling is performed by scaling data from ROM/RAM into RAM.\
Vertical scaling is performed by the kernel by duplicating or skipping lines.\
Sprites and Playfields are supported as below.


---

### Sprite 8 -> 0 to 16

Scale an 8-bit wide sprite up to 16-bits (2 sprites) down to 1-bit wide.

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

### Playfield

Scale an 8-bit wide sprite up to 16-bits (2 sprites) to 1-bit wide.

#### Macro prefix

ZOOM_PF_40_

#### Input

zoom_pf_40_src          pointer, source playfield data pointer.
zoom_pf_40_srcwidth     Source playfield data width in pixels (% 8 must == 0).
zoom_pf_40_srcheight    Source playfield data height in pixels (% 8 must == 0).    

#### Working

#### Output


---

## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.
