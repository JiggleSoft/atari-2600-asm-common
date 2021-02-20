;=============================================================================
; Title:        Pseudo Random Number Generator library common include.
; Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
; Filename:     rndlfsr16-i.inc
; Platform:     65XX
; Language:     65XX Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (cpu65xx@jigglesoft.co.uk)
; Date:         2021-01-07 00:07
; Version:      2.0.0
; Note:         Ported from Microchip PIC8 implementation.
;-----------------------------------------------------------------------------
; Copyright (c) 2021 Justin Lane
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.
;-----------------------------------------------------------------------------



;------------------------------------------------------------------------------
; CONSTANTS
;------------------------------------------------------------------------------

; Default shift register seed value.

RND_SEED_DEFAULT    =           0xACE1



;------------------------------------------------------------------------------
; MACROS
;------------------------------------------------------------------------------


;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

.MACRO          RND_INIT_QUICK
		        RND_SET_SEED    RND_SEED_DEFAULT
.ENDMACRO


;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

.MACRO          RND_INIT
		        RND_INIT_QUICK
		        LDA             #$00
		        STA             rnd_shift
		        STA             rnd_fback
		        STA             rnd_value
.ENDMACRO


;------------------------------------------------------------------------------
; Set the 16-bit shift register with a seed value. Will use default seed is 0.
;------------------------------------------------------------------------------

.MACRO          RND_SET_SR      seed
                .IF seed = 0
                LDA             #.HIGHBYTE(RND1_SEED_DEFAULT)
                STA             rnd1_sr_hi
                LDA             #.LOWBYTE(RND1_SEED_DEFAULT)
                STA             rnd1_sr_lo
                .ELSE
                LDA             #.HIGHBYTE(seed)
                STA             rnd1_sr_hi
                LDA             #.LOWBYTE(seed)
                STA             rnd1_sr_lo
                .ENDIF
.ENDMACRO


;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

.MACRO          RND_FIX_SR
                .LOCAL          rnd_fixed_sr
                LDA             rnd_sr_hi
                BNE             @rnd_fixed_sr
                LDA             rnd_sr_lo
                BNE             @rnd_fixed_sr
                RND_SET_SEED    RND_SEED_DEFAULT
rnd_fixed_sr:
.ENDMACRO


;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

.MACRO          RND_SET_SHIFT   shift
                LDA             #shift
                STA             rnd_shift
.ENDMACRO


;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

.MACRO          RND_NEXT_BITS   num_bits
                RND_SET_SHIFT   num_bits
                JSR             rnd_next_bits
.ENDMACRO


;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

.MACRO          RND_GET_BITS    num_bits
                .IF num_bits = 8
                JSR             rnd_get_byte
                .ELSE
                .IF num_bits = 1
                JSR             rnd_get_bit
                .ELSE
                RND_SET_SHIFT   num_bits
                JSR             rnd_get_bits
                .ENDIF
                .ENDIF
.ENDMACRO



;------------------------------------------------------------------------------


