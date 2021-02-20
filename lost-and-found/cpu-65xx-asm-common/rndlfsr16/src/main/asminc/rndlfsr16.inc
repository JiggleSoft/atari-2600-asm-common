;=============================================================================
; Title:        Pseudo Random Number Generator library client include.
; Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
; Filename:     rndlfsr16.inc
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


                .IFDEF          RND_LIB_ENABLE


;------------------------------------------------------------------------------
; INCLUDES
;------------------------------------------------------------------------------

; Common include.

                .INCLUDE        "rndlfsr16-i.inc"



;------------------------------------------------------------------------------
; IMPORT - UNININITALISED DATA SEGMENT (BSS)
;------------------------------------------------------------------------------

; Current state of the shift register (hi and lo bytes).

                .IFDEF          RND_BSS_ZEROPAGE
                .IMPORTZP       rnd_sr_hi
                .IMPORTZP       rnd_sr_lo
                .ELSE
                .IMPORT         rnd_sr_hi
                .IMPORT         rnd_sr_lo
                .ENDIF


; Number of bits to shift (rnd_shift_bits sub-routine input data).

                .IFDEF          RND_BSS_ZEROPAGE
                .IMPORTZP       rnd_shift
                .ELSE
                .IMPORT         rnd_shift
                .ENDIF


; Calculated feedback bit (low bit) (rnd_shift_bits sub-routine work data).

                .IFDEF          RND_BSS_ZEROPAGE
                .IMPORTZP       rnd_fback
                .ELSE
                .IMPORT         rnd_fback
                .ENDIF


; Last calculated random value (rnd_get_[bit|bits|byte] sub-routine out data).

                .IFDEF          RND_BSS_ZEROPAGE
                .IMPORTZP       rnd_value
                .ELSE
                .IMPORT         rnd_value
                .ENDIF



;------------------------------------------------------------------------------
; IMPORT - FUNCTIONS (CODE)
;------------------------------------------------------------------------------


                .IFDEF          RND_INIT_ENABLE
;------------------------------------------------------------------------------
; Library initialisation.
;
; Note: Must be called once before use to initialise the shift register.
;       A zero shift register value will prevent random number generation.
;
; Input: None.
; Work: A.
; Output: A=0.
;------------------------------------------------------------------------------
                .IMPORT         rnd_init:
                .ENDIF


                .IFDEF          RND_FIX_SR_ENABLE
;------------------------------------------------------------------------------
; Fix the shift register if 0.
;
; Note: A zero shift register value will prevent random number generation.
;
; Input: None.
; Work: A.
; Output: If rnd_sr_hi and rnd_sr_low are zero then set to RND_SEED_DEFAULT.
;------------------------------------------------------------------------------
                .IMPORT         rnd_fix_sr:
                .ENDIF


                .IFDEF          RND_NEXT_BIT_ENABLE
;------------------------------------------------------------------------------
; Calculate the next bit by shifting the shift register 1-bit with feedback.
;
; Input: None.
; Work: A = Undefined.
; Output: Carry (C) flag contains next bit of random data.
;------------------------------------------------------------------------------
                .IMPORT         rnd_next_bit:
                .ENDIF


                .IFDEF          RND_INIT_ENABLE
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
                .IMPORT         rnd_next_bits:
                .ENDIF


                .IFDEF          RND_GET_BIT_ENABLE
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
                .IMPORT         rnd_get_bit:
                .ENDIF


                .IFDEF          RND_GET_BITS_ENABLE
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
                .IMPORT         rnd_get_bits:
                .ENDIF


                .IFDEF          RND_GET_BYTE_ENABLE
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
                .IMPORT         rnd_get_byte:
                .ENDIF



;------------------------------------------------------------------------------
; MACROS
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------


                .ENDIF          ; RND_LIB_ENABLE


;------------------------------------------------------------------------------


