;=============================================================================
; Title:        Atari 2600 reverse bits include file.
; Algorithm:    Various macros to reverse bits e.g 00001101 -> 10110000.
; Filename:     a2k6-algo-revbit.inc
; Platform:     Atari 2600 / 65XX
; Language:     65XX Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-17 15:28
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
; Thanks to Ryan Witmer (15/01/2021) for posting the details of a version of 
; the stack method into Atari Age Discord #programming channel:- 
;     Depends on how fast you need it.  I did it in my last game by shifting 
;     each bit off the end into carry and then pushing the status register 
;     onto the stack.  After all 8 bits were on the stack I pulled them off 
;     and rotated them in from the other side.
;     This is slow, but the code for this is much smaller than a lookup table.
;     If you need the results fast, then yeah, lookup table.
;-----------------------------------------------------------------------------
; Note: Input is the A register and output will be in the A register.
;       If two numbers are given separated by a slash then the first is if ZP
;       memory is used, and the second if memory is above address 255.
;
; Impl. Reg.  RAM   STACK DATA  CODE  CPU   Title
; ---------------------------------------------------------------------------
; REG   A+X+Y 0     0     0     44    88    Registers only.
; STACK A     0     7     0     30    81    Stack carry.
; MEM   A     1     0     0     26/35 59/68 Memory (temporary byte).
; NYBL1 A+X|Y 1     1     16    24/26 43/45 Nybble look-up v1 (2 x 4-bit).
; NLUT2 A+X|Y 1     1     32    20/22 35/37 Nybble look-up v2 (2 x 4-bit).
; BLUT  A+X|Y 0     0     256   4     6     Byte look-up (8-bit).
;-----------------------------------------------------------------------------

                .IFNDEF     __A2K6_ALGO_REVBIT__INC__
                .DEFINE     __A2K6_ALGO_REVBIT__INC__

;=============================================================================
; Atari 2600 Various Reverse Bit Implementations.
;=============================================================================



;-----------------------------------------------------------------------------
; REG - Registers only.
;-----------------------------------------------------------------------------

.MACRO          REVBIT_REG
                rol
                tay
                ror
                tax
                tya
                rol
                tay
                txa
                ror
                tax
                tya
                rol
                tay
                txa
                ror
                tax
                tya
                rol
                tay
                txa
                ror
                tax
                tya
                rol
                tay
                txa
                ror
                tax
                tya
                rol
                tay
                txa
                ror
                tax
                tya
                rol
                tay
                txa
                ror
                tax
                tya
                rol
                txa
                ror
.ENDMACRO



;-----------------------------------------------------------------------------
; STACK - Stack carry.
;
; ZP: 7 Stack Bytes; 30 Code Bytes; (16*2)+(7*3)+(7*4) = 81 CPU Clocks.
;-----------------------------------------------------------------------------

.MACRO          REVBIT_STACK
                ror
                php
                ror
                php
                ror
                php
                ror
                php
                ror
                php
                ror
                php
                ror
                php
                ror
                ror
                plp
                ror
                plp
                ror
                plp
                ror
                plp
                ror
                plp
                ror
                plp
                ror
                plp
                ror
.ENDMACRO



;-----------------------------------------------------------------------------
; MEM - Memory (temporary byte).
;
; ZP: 1 RAM Byte; 2+(8*2)+8 = 26 Code Bytes; 3+(8*5)+(8*2) = 59 CPU Clocks.
; 16: 1 RAM Byte; 3+(8*3)+8 = 35 Code Bytes; 4+(8*6)+(8*2) = 68 CPU Clocks.
;-----------------------------------------------------------------------------

.MACRO          REVBIT_MEM      tmp_addr
                sta             tmp_addr
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
                ror             tmp_addr
                rol
.ENDMACRO



;-----------------------------------------------------------------------------
; NYBL1 - Nybble look-up v1 (2 x 4-bit).
; ZP: 1 RAM Byte; 1 Stack Byte; 24 Code Bytes; 43 CPU Clocks.
; 16: 1 RAM Byte; 1 Stack Byte; 26 Code Bytes; 45 CPU Clocks.
; Note: CPU Clocks assume data address is > 255 and data within single page.
;-----------------------------------------------------------------------------

; Reverse bits in A using X register.

.MACRO          REVBIT_NLUT1_X  data_addr,tmp_addr
                PHA
                AND             #$0F
                TAX
                LDA             data_addr,X
                STA             tmp_addr
                PLA
                LSR
                LSR
                LSR
                LSR
                TAX
                LDA             data_addr,X
                LSR
                LSR
                LSR
                LSR
                ORA             tmp_addr
.ENDMACRO


; Reverse bits in A using Y register.

.MACRO          REVBIT_NLUT1_Y  data_addr,tmp_addr
                PHA
                AND             #$0F
                TAX
                LDA             data_addr,Y
                STA             tmp_addr
                PLA
                LSR
                LSR
                LSR
                LSR
                TAX
                LDA             data_addr,Y
                LSR
                LSR
                LSR
                LSR
                ORA             tmp_addr
.ENDMACRO


; Data - should be within a single page.

.MACRO          REVBIT_NLUT1_DATA
    .BYTE   $00,$80,$40,$c0,$20,$a0,$60,$e0,$10,$90,$50,$d0,$30,$b0,$70,$f0
.ENDMACRO



;-----------------------------------------------------------------------------
; NLUT2 - Nybble look-up v2 (2 x 4-bit).
;
; ZP: 1 RAM Byte; 1 Stack Byte; 20 Code Bytes; 35 CPU Clocks.
; 16: 1 RAM Byte; 1 Stack Byte; 22 Code Bytes; 37 CPU Clocks.
; Note: CPU Clocks assume data address is > 255 and data within single page.
;-----------------------------------------------------------------------------

; Reverse bits in A using X register.

.MACRO          REVBIT_NLUT2_X  data_addr,tmp_addr
                PHA
                AND             #$0F
                TAX
                LDA             data_addr,X
                STA             tmp_addr
                PLA
                LSR
                LSR
                LSR
                LSR
                TAX
                LDA             data_addr+16,X
                ORA             tmp_addr
.ENDMACRO


; Reverse bits in A using Y register.

.MACRO          REVBIT_NLUT2_Y  data_addr,tmp_addr
                PHA
                AND             #$0F
                TAY
                LDA             data_addr,Y
                STA             tmp_addr
                PLA
                LSR
                LSR
                LSR
                LSR
                TAY
                LDA             data_addr+16,Y
                ORA             tmp_addr
.ENDMACRO


; Data - should be within a single page.

.MACRO          REVBIT_NLUT2_DATA
    .BYTE   $00,$80,$40,$c0,$20,$a0,$60,$e0,$10,$90,$50,$d0,$30,$b0,$70,$f0
    .BYTE   $00,$08,$04,$0c,$02,$0a,$06,$0e,$01,$09,$05,$0d,$03,$0b,$07,$0f
.ENDMACRO



;-----------------------------------------------------------------------------
; BLUT - Byte look-up (8-bit).
;
; 1+3 = 4 Code Bytes; 2+4 = 6 CPU Clocks.
; Note: CPU Clocks assume data address is > 255 and data within single page.
;-----------------------------------------------------------------------------

; Reverse bits in A using X register.

.MACRO          REVBIT_BLUT_X   data_addr
                TAX
                LDA             data_addr,X
.ENDMACRO


; Reverse bits in A using Y register.

.MACRO          REVBIT_BLUT_Y   data_addr
                TAY
                LDA             data_addr,Y
.ENDMACRO


; Data - should be page aligned.

.MACRO          REVBIT_BLUT_DATA
    .BYTE   $00,$80,$40,$c0,$20,$a0,$60,$e0,$10,$90,$50,$d0,$30,$b0,$70,$f0
    .BYTE   $08,$88,$48,$c8,$28,$a8,$68,$e8,$18,$98,$58,$d8,$38,$b8,$78,$f8
    .BYTE   $04,$84,$44,$c4,$24,$a4,$64,$e4,$14,$94,$54,$d4,$34,$b4,$74,$f4
    .BYTE   $0c,$8c,$4c,$cc,$2c,$ac,$6c,$ec,$1c,$9c,$5c,$dc,$3c,$bc,$7c,$fc
    .BYTE   $02,$82,$42,$c2,$22,$a2,$62,$e2,$12,$92,$52,$d2,$32,$b2,$72,$f2
    .BYTE   $0a,$8a,$4a,$ca,$2a,$aa,$6a,$ea,$1a,$9a,$5a,$da,$3a,$ba,$7a,$fa
    .BYTE   $06,$86,$46,$c6,$26,$a6,$66,$e6,$16,$96,$56,$d6,$36,$b6,$76,$f6
    .BYTE   $0e,$8e,$4e,$ce,$2e,$ae,$6e,$ee,$1e,$9e,$5e,$de,$3e,$be,$7e,$fe
    .BYTE   $01,$81,$41,$c1,$21,$a1,$61,$e1,$11,$91,$51,$d1,$31,$b1,$71,$f1
    .BYTE   $09,$89,$49,$c9,$29,$a9,$69,$e9,$19,$99,$59,$d9,$39,$b9,$79,$f9
    .BYTE   $05,$85,$45,$c5,$25,$a5,$65,$e5,$15,$95,$55,$d5,$35,$b5,$75,$f5
    .BYTE   $0d,$8d,$4d,$cd,$2d,$ad,$6d,$ed,$1d,$9d,$5d,$dd,$3d,$bd,$7d,$fd
    .BYTE   $03,$83,$43,$c3,$23,$a3,$63,$e3,$13,$93,$53,$d3,$33,$b3,$73,$f3
    .BYTE   $0b,$8b,$4b,$cb,$2b,$ab,$6b,$eb,$1b,$9b,$5b,$db,$3b,$bb,$7b,$fb
    .BYTE   $07,$87,$47,$c7,$27,$a7,$67,$e7,$17,$97,$57,$d7,$37,$b7,$77,$f7
    .BYTE   $0f,$8f,$4f,$cf,$2f,$af,$6f,$ef,$1f,$9f,$5f,$df,$3f,$bf,$7f,$ff
.ENDMACRO



;-----------------------------------------------------------------------------

                .ENDIF


