;=============================================================================
; Title:        Pseudo Random Number Generator client include.
; Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
; Filename:     a2k6algo-rnd.inc
; Platform:     Atari 2600 / 65XX
; Language:     65XX Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-05 21:48
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
; INCLUDES
;------------------------------------------------------------------------------

; Algorithm common include.

                .INCLUDE        "a2k6algo-rnd-i.inc"



;------------------------------------------------------------------------------
; IMPORT - UNININITALISED DATA SEGMENT (BSS)
;------------------------------------------------------------------------------

; Current state of the shift register (hi and lo bytes).

                .IMPORTZP       rnd_sr_hi
                .IMPORTZP       rnd_sr_lo


; Number of bits to shift (rnd_shift_bits sub-routine input data).

                .IMPORTZP       rnd_shift


; Calculated feedback bit (low bit) (rnd_shift_bits sub-routine work data).

                .IMPORTZP       rnd_fback


; Last calculated random value (rnd_get_[bit|bits|byte] sub-routine out data).

                .IMPORTZP       rnd_value



;------------------------------------------------------------------------------
; IMPORT (CODE)
;------------------------------------------------------------------------------

                .IMPORT         rnd_init:
                .IMPORT         rnd_next_bit:
                .IMPORT         rnd_next_bits:
                .IMPORT         rnd_get_bit:
                .IMPORT         rnd_get_bits:
                .IMPORT         rnd_get_byte:



;------------------------------------------------------------------------------
; MACROS
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------


