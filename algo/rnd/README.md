# Atari 2600 - Algorithm - Random (RND)

Fast bit stream pseudo random number generator implemented with a 16-bit linear feedback shift register (LFSR).
Although this version of the code is written for the Atari 2600 it could be used for other 65xx based systems.
Also the algorithms method could be migrated to other architectures / platforms.
Actually this implementation was ported from my Microchip PIC8 implementation.


## Description

Generate pseudo random numbers efficiently utilising a Linear Feedback Shift Register.
LFSR's are actually used internally by several counters in the Atari 2600 TIA chip.

The initial seed value is 0xACE1.

Here is an illustration of this LFSR's implementation:-

```
; Feedback (F) is calculated with the taps on rnd_sr_lo bits 0, 2, 3, 5.
; rnd_sr_lo is shifted right and value shifted out of bit 0 is the output stream.
; rnd_sr_hi is shifted right and the value shifted out of bit 0 goes into bit 7
; of rnd_sr_hi. The feedback becomes bit 7 of rndval_hi.
;
; rnd_sr_hi                            rnd_sr_lo
; | 7 | 6 | 5 | 4 | 3 | 2 |  1 |  0 |->| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |->| O |
;   ^                                            |       |   |       |      u
;   |                                            |       |    \     /       t
;   |                                            |       |      XOR         p
;   |                                            |       |       |          u
;   |                                            |      XOR------           t
;   |                                            |       |
; | F |<----------------------------------------XOR------
; Feedback
;
```

Get bits will take the lowest n bits from rndval_lo and then run the feedback and shift process n times.\
Note that the bits taken will be returned will start population of the returned value from bits 0, then 1, etc.



### Persisted State

rnd_sr_hi, rnd_sr_lo    High and low bytes of the shift register. Must not be zero as the LFSR will not function.


### Input

rnd_shift   How many bits are required to be shifted / output. 


### Working

rnd_fback   Feedback value low bit (bit 0). Other bits undefined.


### Output

rnd_value   Last produced random value. 1 to 8 bits depending on function. Low bits populated first.


## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.
