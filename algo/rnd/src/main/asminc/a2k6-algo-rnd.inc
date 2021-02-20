; DO NOT COMMIT - WORK IN PROGRESS
;=============================================================================
; Title:        Atari 2600 pseudo random number generation include file.
; Algorithm:    Various Linear Feedback Shift Register (LFSR) macros.
; Filename:     a2k6-algo-rnd.inc
; Platform:     Atari 2600 / 65XX
; Language:     65XX Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-09 22:44
; Version:      2.0.0
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
; Impl. State  Range   Return  Title
; ---------------------------------------------------------------------------
; XON    8-bit ?TO DO? ?TO DO? Xorshift 8-bit ( ? )
; XON2  16-bit ?TO DO? ?TO DO? Xorshift 16-bit ( ? )
; GAL    8-bit 1-255   1-255   Galois 8-bit LFSR (1-255)
; GALX   8-bit 0-255   0-255   Galois 8-bit LFSR Extra Range (0-255)
; GAL2  16-bit 1-65535 0-255 ? Galois 16-bit LFSR (1-65535)
; GAL2X 16-bit 0-65535 0-255   Galois 16-bit LFSR Extra Range (0-65535)
; FIB    8-bit 1-255   1-255   Fibonacci 8-bit LFSR (1-255)
; FIB2  16-bit 1-65535 0-255 ? Fibonacci 16-bit LFSR (1-255)
; PIT   16-bit                 Fibonacci 8-bit LFSR (1-255) (Pitfall)
; BAS    8-bit 1-255   1-255   Galois 8-bit LFSR (1-255) (Batari Basic)
; BAS2  16-bit                 Galois 16-bit LFSR (?) (Batari Basic)
; PIC   16-bit ?       ?       Fibonacci 16-bit LFSR (Ported Microchip PIC8)
;-----------------------------------------------------------------------------

                .IFNDEF     __A2K6_ALGO_RND__INC__
                .DEFINE     __A2K6_ALGO_RND__INC__

;=============================================================================
; Atari 2600 Various Pseudo Random Number Generator Implementations.
;=============================================================================


;-----------------------------------------------------------------------------
; FIXME: Impl.
;-----------------------------------------------------------------------------

; TODO: Impl.
; REVIEW: Is this include file requried?


;-----------------------------------------------------------------------------
;
;-----------------------------------------------------------------------------


;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

.MACRO          RND_SET_DEST_FROM_ADDR    addr,dest
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO


;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

.MACRO          RND_SET_DEST_FROM_REG    addr,dest
                ;FIXME do next
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO



;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

.MACRO          RND_FIXME   ---  INIT FROM TIUMER 8 bit allow or disallow 0 and also 16 bit with one byte timer and other byte xor of timer so will not be 0
;SET_DEST_FROM_REG    addr,dest
                ;FIXME do next
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO



;-----------------------------------------------------------------------------
; Fibonacci 8-bit Linear Feedback Shift Register (LFSR) (a la Pitfall 2).
;-----------------------------------------------------------------------------


;-----------------------------------------------------------------------------
; Constants.
;-----------------------------------------------------------------------------

; Default initial random number seed value.

RND_PF2_SEED_DEFAULT    =       0xC4


;-----------------------------------------------------------------------------
; Initialise random number stored at address (addr) with immediate seed value.
; Note: If the seed is not supplied or 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_PF2_INIT    addr,seed
    .IFBLANK seed
                LDA             #RND_PF2_SEED_DEFAULT
    .ELSE
        .IF seed = 0
                LDA             #RND_PF2_SEED_DEFAULT
        .ELSE
                LDA             #seed
        .ENDIF
    .ENDIF
                STA         addr
.ENDMACRO


;-----------------------------------------------------------------------------
; Fix the random number stored at address (addr) if it is zero.
; Note: If a seed is not supplied or is 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_PF2_FIX     addr,seed
                LDA             addr
                BNE             @is_valid
                RND_PF2_INIT    addr,seed
@is_valid:
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_PF2_NEXT    addr,dest
                LDA             addr
                ASL
                EOR             addr
                ASL
                EOR             addr
                ASL
                ASL
                EOR             addr
                ASL
                ROL             addr
                RND_SET_DEST_FROM_ADDR  addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next two random numbers at address (addr) and discard the first.
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_PF2_NEXT2   addr,dest
                RND_PF2_NEXT    addr
                RND_PF2_NEXT    addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the previous random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_PF2_PREV    addr,dest
                LDA             addr
                ASL
                EOR             addr
                ASL
                EOR             addr
                ASL
                ASL
                ROL
                EOR             addr
                LSR
                ROR             addr
                RND_SET_DEST_FROM_ADDR  addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the previous two random numbers at address (addr) and discard the first.
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_PF2_PREV2   addr,dest
                RND_PF2_PREV    addr
                RND_PF2_PREV    addr,dest
.ENDMACRO



;-----------------------------------------------------------------------------
; Galois Linear Feedback Shift Register (LFSR) 8-bit.
;-----------------------------------------------------------------------------


;-----------------------------------------------------------------------------
; Constants.
;-----------------------------------------------------------------------------

; Default initial random number seed value.

RND_XXX_SEED_DEFAULT    =   0xXX

REG_XXX_ALG_XX          =   0xFF

;;;;REG_XXX_ALG_XX          =   0x8E
REG_XXX_ALG_95          =   0x95
REG_XXX_ALG_96          =   0x96
REG_XXX_ALG_A6          =   0xA6
REG_XXX_ALG_AF          =   0xAF
REG_XXX_ALG_81          =   0xB1
REG_XXX_ALG_82          =   0xB2
REG_XXX_ALG_XX          =   0xB4
REG_XXX_ALG_XX          =   0xB8
REG_XXX_ALG_XX          =   0xC3
REG_XXX_ALG_XX          =   0xC6
REG_XXX_ALG_XX          =   0xD4
REG_XXX_ALG_XX          =   0xE1
REG_XXX_ALG_XX          =   0xE7
REG_XXX_ALG_XX          =   0xF3
REG_XXX_ALG_XX          =   0xFA

RND_XXX_DEST_REG_A      =   A
RND_XXX_DEST_REG_X      =   X
RND_XXX_DEST_REG_Y      =   Y


;-----------------------------------------------------------------------------
; Initialise random number stored at address (addr) with immediate seed value.
; Note: If the seed is not supplied or 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_INIT    addr,seed
                .IFBLANK        seed
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                .IF seed = 0
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                LDA             #seed
                .ENDIF
                .ENDIF
                STA         addr
.ENDMACRO


;-----------------------------------------------------------------------------
; Fix the random number stored at address (addr) if it is zero.
; Note: If a seed is not supplied or is 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_FIX     addr,seed
                LDA             addr
                BNE             @not_zero
                RND_XXX_INIT    addr,seed
@not_zero:
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

;add algo
.MACRO          RND_XXX_NEXT    addr,dest
                LDA             addr
                LSR
                BCC             @skip_eor
                EOR             #aLGO FIXME
@skip_eor
                STA             addr

                ;FIXME do next
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next two random numbers at address (addr) and discard the first.
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

;add algo
.MACRO          RND_XXX_NEXT2   addr,dest
                RND_XXX_NEXT    addr
                RND_XXX_NEXT    addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the previous random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

;add algo
.MACRO          RND_XXX_PREV    addr,dest
                LDA             addr
                ASL
                BCC             @skip_eor
                EOR             #ALGO rotated left 1 bit
@skip_eor:
                ; FIXME
.ENDMACRO


;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

;add algo
.MACRO          RND_XXX_PREV2   addr,dest
                RND_XXX_PREV    addr
                RND_XXX_PREV    addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; GALOIS LFSR 16 bit
;-----------------------------------------------------------------------------


;-----------------------------------------------------------------------------
; Constants.
;-----------------------------------------------------------------------------

; Default initial random number seed value.

RND_XXX_SEED_DEFAULT    =   0xXX



RND_XXX_DEST_REG_A      =   A
RND_XXX_DEST_REG_X      =   X
RND_XXX_DEST_REG_Y      =   Y


;-----------------------------------------------------------------------------
; Initialise random number stored at address (addr) with immediate seed value.
; Note: If the seed is not supplied or 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_INIT    addr,seed
                .IFBLANK        seed
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                .IF seed = 0
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                LDA             #seed
                .ENDIF
                .ENDIF
                STA         addr
.ENDMACRO


;-----------------------------------------------------------------------------
; Fix the random number stored at address (addr) if it is zero.
; Note: If a seed is not supplied or is 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_FIX     addr,seed
                LDA             addr
                BNE             @not_zero
                RND_XXX_INIT    addr,seed
@not_zero:
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_NEXT    addr,dest
                ;FIXME do next
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next two random numbers at address (addr) and discard the first.
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_NEXT2   addr,dest
                RND_XXX_NEXT    addr
                RND_XXX_NEXT    addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the previous random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_PREV    addr,dest
                ; FIXME
.ENDMACRO


;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_PREV2   addr,dest
                RND_XXX_PREV    addr
                RND_XXX_PREV    addr,dest
.ENDMACRO




;-----------------------------------------------------------------------------
; xor 8 bit
;-----------------------------------------------------------------------------


;-----------------------------------------------------------------------------
; Constants.
;-----------------------------------------------------------------------------

; Default initial random number seed value.

RND_XXX_SEED_DEFAULT    =   0xXX



RND_XXX_DEST_REG_A      =   A
RND_XXX_DEST_REG_X      =   X
RND_XXX_DEST_REG_Y      =   Y


;-----------------------------------------------------------------------------
; Initialise random number stored at address (addr) with immediate seed value.
; Note: If the seed is not supplied or 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_INIT    addr,seed
                .IFBLANK        seed
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                .IF seed = 0
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                LDA             #seed
                .ENDIF
                .ENDIF
                STA         addr
.ENDMACRO


;-----------------------------------------------------------------------------
; Fix the random number stored at address (addr) if it is zero.
; Note: If a seed is not supplied or is 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_FIX     addr,seed
                LDA             addr
                BNE             @not_zero
                RND_XXX_INIT    addr,seed
@not_zero:
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_NEXT    addr,dest
                ;FIXME do next
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next two random numbers at address (addr) and discard the first.
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_NEXT2   addr,dest
                RND_XXX_NEXT    addr
                RND_XXX_NEXT    addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the previous random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_PREV    addr,dest
                ; FIXME
.ENDMACRO


;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_PREV2   addr,dest
                RND_XXX_PREV    addr
                RND_XXX_PREV    addr,dest
.ENDMACRO







;-----------------------------------------------------------------------------
; xor 8 bit + whiley number
;-----------------------------------------------------------------------------


;-----------------------------------------------------------------------------
; Constants.
;-----------------------------------------------------------------------------

; Default initial random number seed value.

RND_XXX_SEED_DEFAULT    =   0xXX



RND_XXX_DEST_REG_A      =   A
RND_XXX_DEST_REG_X      =   X
RND_XXX_DEST_REG_Y      =   Y


;-----------------------------------------------------------------------------
; Initialise random number stored at address (addr) with immediate seed value.
; Note: If the seed is not supplied or 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_INIT    addr,seed
                .IFBLANK        seed
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                .IF seed = 0
                LDA             #RND_XXX_SEED_DEFAULT
                .ELSE
                LDA             #seed
                .ENDIF
                .ENDIF
                STA         addr
.ENDMACRO


;-----------------------------------------------------------------------------
; Fix the random number stored at address (addr) if it is zero.
; Note: If a seed is not supplied or is 0 then the default seed value is used.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_FIX     addr,seed
                LDA             addr
                BNE             @not_zero
                RND_XXX_INIT    addr,seed
@not_zero:
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_NEXT    addr,dest
                ;FIXME do next
                .IFNBLANK       dest
                .IF             dest = RND_XXX_DEST_REG_A
                LDA             addr
                .ELSEIF         dest = RND_XXX_DEST_REG_X
                LDA             addr
                TAX
                .ELSEIF         dest = RND_XXX_DEST_REG_Y
                LDA             addr
                TAY
                .ELSE
                .ERROR          "Invalid destination!"
                .ENDIF
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the next two random numbers at address (addr) and discard the first.
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_NEXT2   addr,dest
                RND_XXX_NEXT    addr
                RND_XXX_NEXT    addr,dest
.ENDMACRO


;-----------------------------------------------------------------------------
; Get the previous random number value at address (addr).
; Note: If the destination (dest) is supplied then store random number there.
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_PREV    addr,dest
                ; FIXME
.ENDMACRO


;-----------------------------------------------------------------------------
;
;
;-----------------------------------------------------------------------------

.MACRO          RND_XXX_PREV2   addr,dest
                RND_XXX_PREV    addr
                RND_XXX_PREV    addr,dest
.ENDMACRO



;-----------------------------------------------------------------------------

                .ENDIF


