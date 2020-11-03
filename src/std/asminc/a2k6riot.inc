;==============================================================================
; Name:         Atari 2600 RAM, Input/Output, Timer (RIOT) chip include file.
; Filename:     a2k6riot.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-02 23:21
; Vesion:       1.2.0
;------------------------------------------------------------------------------
; Copyright (c) 2020 Justin Lane
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
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Random Access Memory (RAM) Address Range.
;------------------------------------------------------------------------------

                .IFNDEF        RIOT_RAM_BASE
RIOT_RAM_BASE    :=    $80        ; RIOT RAM base (start) address.
                .ENDIF
                .IFNDEF        RIOT_RAM_SIZE
RIOT_RAM_SIZE    =    $80        ; RIOT RAM addressable size.
                .ENDIF
                .IFNDEF        RIOT_RAM_LAST
RIOT_RAM_LAST    :=    (RIOT_RAM_BASE+RIOT_RAM_SIZE-1)    ; RIOT RAM last address.
                .ENDIF

;------------------------------------------------------------------------------
; RIOT Register Address Range.
;------------------------------------------------------------------------------

                .IFNDEF        RIOT_REG_BASE
RIOT_REG_BASE    :=    $280    ; RIOT Registers base address.
                .ENDIF
                .IFNDEF        RIOT_REG_SIZE
RIOT_REG_SIZE    =    $20        ; RIOT Registers addressable size.
                .ENDIF
                .IFNDEF        RIOT_REG_LAST
RIOT_REG_LAST    :=    (RIOT_REG_BASE+RIOT_REG_SIZE-1)    ; RIOT Registers last addr.
                .ENDIF

;------------------------------------------------------------------------------
; RIOT Register Addresses.
;------------------------------------------------------------------------------

DATAREGA := (RIOT_REG_BASE+$00)    ; $00 rw Data Register A.
DDIRREGA := (RIOT_REG_BASE+$01)    ; $01 rw Data Direction Register A.
DATAREGB := (RIOT_REG_BASE+$02)    ; $02 rw Data Register B.
DDIRREGB := (RIOT_REG_BASE+$03)    ; $03 rw Data Direction Register B.
RTIMDINT := (RIOT_REG_BASE+$04) ; $04 r  Read Timer Disable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WEDCNEDI := (RIOT_REG_BASE+$04)    ; $04  w Write Edge-Detect Control PA7,
                                ;        Negative Edge-Detect,
                                ;        Disable Interrupt.
RINTFLAG := (RIOT_REG_BASE+$05)    ; $05 r  Read Interrupt Flag Register,
                                ;        Bit 7 = Timer, 6 = PA7 Edge-Detect,
                                ;        Clear PA7 Interrupt Flag.
WEDCPEDI := (RIOT_REG_BASE+$05)    ; $05  w Write Edge Detect Control PA7,
                                ;        Positive Edge-Detect,
                                ;        Disable Interrupt.
WEDCNEEI := (RIOT_REG_BASE+$06)    ; $06  w Write Edge Detect Control PA7,
                                ;        Negative Edge-Detect,
                                ;        Enable Interrupt.
WEDCPEEI := (RIOT_REG_BASE+$07)    ; $07  w Write Edge Detect Control PA7,
                                ;        Positive Edge-Detect, Enable Interrupt.
                                ; $08    Unused / Mirror.
                                ; $09    Unused / Mirror.
                                ; $0A    Unused / Mirror.
                                ; $0B    Unused / Mirror.
RTIMEINT := (RIOT_REG_BASE+$0C)    ; $0C r  Read Timer Enable Interrupt,
                                ;        Clear Timer Interrupt Flag.
                                ; $0D    Unused / Mirror.
                                ; $0E    Unused / Mirror.
                                ; $0F    Unused / Mirror.
                                ; $10    Unused / Mirror.
                                ; $11    Unused / Mirror.
                                ; $12    Unused / Mirror.
                                ; $13    Unused / Mirror.
WTIM1DI  := (RIOT_REG_BASE+$14)    ; $14  w Write Timer, Divide by 1,
                                ;        Disable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WTIM8DI  := (RIOT_REG_BASE+$15)    ; $15  w Write Timer, Divide by 8,
                                ;        Disable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WTIM64DI := (RIOT_REG_BASE+$16)    ; $16  w Write Timer, Divide by 64,
                                ;        Disable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WTIM1KDI := (RIOT_REG_BASE+$17)    ; $17  w Write Timer, Divide by 1024,
                                ;        Disable Interrupt,
                                ;        Clear Timer Interrupt Flag.
                                ; $18    Unused / Mirror.
                                ; $19    Unused / Mirror.
                                ; $1A    Unused / Mirror.
                                ; $1B    Unused / Mirror.
WTIM1EI  := (RIOT_REG_BASE+$1C)    ; $1C  w Write Timer, Divide by 1,
                                ;        Enable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WTIM8EI  := (RIOT_REG_BASE+$1D)    ; $1D  w Write Timer, Divide by 8,
                                ;        Enable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WTIM64EI := (RIOT_REG_BASE+$1E) ; $1E  w Write Timer, Divide by 64,
                                ;        Enable Interrupt,
                                ;        Clear Timer Interrupt Flag.
WTIM1KEI := (RIOT_REG_BASE+$1F)    ; $1F  w Write Timer, Divide by 1024,
                                ;        Enable Interrupt,
                                ;        Clear Timer Interrupt Flag.

;------------------------------------------------------------------------------
; RIOT Register Addresses Base and Address Offset Options.
;------------------------------------------------------------------------------

; Read Timer, Set Interrupt Disable/Enable, and Clear Timer Interrupt Flag.

RTIMB       := (RIOT_REG_BASE+$04)    ; Read Timer Base Address.
RTIMO_INT_D =  $00    ; RTIM Offset to Disable Interrupt.
RTIMO_INT_E =  $08    ; RTIM Offset to Enable Interrupt.

; Write Edge-Detect Control PA7, Set Edge Detect Neg/Pos and Interrupt Dis/En.

WEDCB        := (RIOT_REG_BASE+$04)    ; Write Edge-Detect Control PA7 Base Addr.
WEDCO_EDGE_N =  $00    ; WEDC Offset for Negative Edge-Detect.
WEDCO_EDGE_P =  $01    ; WEDC Offset for Positive Edge-Detect.
WEDCO_INT_D  =  $00    ; WEDC Offset to Disable Interrupt.
WEDCO_INT_E     =  $02    ; WEDC Offset to Enable Interrupt.

; Write Timer, Clear Timer Interrupt Flag, Set Time Div and Interrupt Dis/En.

WTIMB        := (RIOT_REG_BASE+$14)    ; Write Timer Base Address.

WTIMO_DIV_1  = $00    ; WTIM Offset to set Divide by 1.
WTIMO_DIV_8  = $01    ; WTIM Offset to set Divide by 8.
WTIMO_DIV_64 = $02    ; WTIM Offset to set Divide by 64.
WTIMO_DIV_1K = $03    ; WTIM Offset to set Divide by 1024.

WTIMO_INT_D  = $00    ; WTIM Offset to Disable Interrupt.
WTIMO_INT_E  = $08    ; WTIM Offset to Enable Interrupt.

;------------------------------------------------------------------------------
; RIOT Stella Include Name Compatibility.
;------------------------------------------------------------------------------

            .IFNDEF        NO_STELLA_REG_NAMES

; Read Registers

SWCHA        :=        DATAREGA
SWACNT        :=        DDIRREGA
SWCHB        :=        DATAREGB
SWBCNT        :=        DDIRREGB
INTIM        :=        RTIMDINT
TIMINT         :=         RINTFLAG

; Write Registers

TIM1T        :=        WTIM1DI
TIM8T         :=        WTIM8DI
TIM64T        :=        WTIM64DI
T1024T        :=        WTIM1KDI

            .ENDIF

;------------------------------------------------------------------------------
; Joystick Directions Player 1 and Player 2
; DATAREGA Data Register A and DDIRREGA Data Direction Register A.
;------------------------------------------------------------------------------

JOYB_P1R    =    7    ; Joystick Player 1, Right Direction Bit.
JOYB_P1L    =    6    ; Joystick Player 1, Left Direction Bit.
JOYB_P1D    =    5    ; Joystick Player 1, Down Direction Bit.
JOYB_P1U    =    4    ; Joystick Player 1, Up Direction Bit.
JOYB_P2R    =    3    ; Joystick Player 2, Right Direction Bit.
JOYB_P2L    =    2    ; Joystick Player 2, Left Direction Bit.
JOYB_P2D    =    1    ; Joystick Player 2, Down Direction Bit.
JOYB_P2U    =    0    ; Joystick Player 2, Up Direction Bit.

JOYM_P1        =    $F0    ; Joystick Player 1, Direction Mask.
JOYM_P2        =    $0F    ; Joystick Player 2, Direction Mask.

JOYF_P1R    =    $80    ; Joystick Player 1, Right Direction Flag.
JOYF_P1L    =    $40    ; Joystick Player 1, Left Direction Flag.
JOYF_P1D    =    $20    ; Joystick Player 1, Down Direction Flag.
JOYF_P1U    =    $10    ; Joystick Player 1, Up Direction Flag.
JOYF_P2R    =    $08    ; Joystick Player 2, Right Direction Flag.
JOYF_P2L    =    $04    ; Joystick Player 2, Left Direction Flag.
JOYF_P2D    =    $02    ; Joystick Player 2, Down Direction Flag.
JOYF_P2U    =    $01    ; Joystick Player 2, Up Direction Flag.

;------------------------------------------------------------------------------
; Console Switches and Three Unused Bits.
; DATAREGB Data Register B and DDIRREGB Data Direction Register B.
; WARNING: Bits 7, 6, 3, 1, and 0 must always be inputs and never outputs!
;------------------------------------------------------------------------------

CSWB_P2D    =    7    ; Console Switch Player 2 Difficulty (0=B, 1=A) Bit.
CSWB_P1D    =    6    ; Console Switch Player 1 Difficulty (0=B, 1=A) Bit.
;            =    5    ; Unused Bit, Extra Bit of RAM.
;            =    4    ; Unused Bit, Extra Bit of RAM.
CSWB_COL    =    3    ; Console Switch Colour or B&W (0=B&W, 1 = Colour) Bit.
;            =    2    ; Unused Bit, Extra Bit of RAM.
CSWB_SEL    =    1    ; Console Switch Select (0=depressed, 1=untouched) Bit.
CSWB_RES    =    0    ; Console Switch Reset (0=depressed, 1=untouched) Bit.

CSWF_P2D    =    $80    ; Console Switch Player 2 Difficulty (0=B, 1=A) Flag.
CSWF_P1D    =    $40    ; Console Switch Player 1 Difficulty (0=B, 1=A) Flag.
;            =    $20    ; Unused Bit, Extra Bit of RAM.
;            =    $10    ; Unused Bit, Extra Bit of RAM.
CSWF_COL    =    $08    ; Console Switch Colour or B&W (0=B&W, 1 = Colour) Flag.
;            =    $04    ; Unused Bit, Extra Bit of RAM.
CSWF_SEL    =    $02    ; Console Switch Select (0=depressed, 1=untouched) Flag.
CSWF_RES    =    $01    ; Console Switch Reset (0=depressed, 1=untouched) Flag.

;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------


