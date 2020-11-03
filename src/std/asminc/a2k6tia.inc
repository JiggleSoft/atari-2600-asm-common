;==============================================================================
; Name:         Atari 2600 TIA chip include file.
; Filename:     a2k6tia.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
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
; Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio).
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; TIA Register Address Range.
;------------------------------------------------------------------------------

                .IFNDEF            TIA_REG_BASE
TIA_REG_BASE    :=    $00        ; TIA Registers base (start) address.
                .ENDIF
                .IFNDEF            TIA_REG_SIZE
TIA_REG_SIZE    =    $40        ; TIA Registers addressable size.
                .ENDIF
                .IFNDEF            TIA_REG_LAST
TIA_REG_LAST    :=    (TIA_REG_BASE+TIA_REG_SIZE-1) ; TIA Registers last address.
                .ENDIF

;------------------------------------------------------------------------------
; TIA Register Read Address Range.
;------------------------------------------------------------------------------

                .IFNDEF            TIA_REG_R_BASE
TIA_REG_R_BASE    :=    TIA_REG_BASE    ; TIA Registers read base (start) address.
                .ENDIF
                .IFNDEF            TIA_REG_R_SIZE
TIA_REG_R_SIZE    =    $0E                ; TIA Registers read addressable size.
                .ENDIF
                .IFNDEF            TIA_REG_R_LAST
TIA_REG_R_LAST    :=    (TIA_REG_R_BASE+TIA_REG_R_SIZE-1) ; TIA Reg read last addr.
                .ENDIF

;------------------------------------------------------------------------------
; TIA Register Write Address Range.
;------------------------------------------------------------------------------

                .IFNDEF            TIA_REG_W_BASE
TIA_REG_W_BASE    :=    TIA_REG_BASE    ; TIA Registers write base (start) address.
                .ENDIF
                .IFNDEF            TIA_REG_W_SIZE
TIA_REG_W_SIZE    =    $2D                ; TIA Registers write addressable size.
                .ENDIF
                .IFNDEF            TIA_REG_W_LAST
TIA_REG_W_LAST    :=    (TIA_REG_W_BASE+TIA_REG_W_SIZE-1) ; TIA Reg write last add.
                .ENDIF

;------------------------------------------------------------------------------
; TIA Register Addresses (Stella Include Name Compatibile).
;------------------------------------------------------------------------------

; Note: 0 = must be 0, 1 = must be 1, - = unused (use 0), [a-v] = used bits.

CXM0P    := (TIA_REG_R_BASE+$00)    ; $00 r  nn-- ---- Read Collision Bit 7=M0-P1, 6=M0-P0.
VSYNC    := (TIA_REG_W_BASE+$00)    ; $00  w ---- --n- Vertical Sync Set-Clear.
CXM1P    := (TIA_REG_R_BASE+$01)    ; $01 r  nn-- ---- Read Collision Bit 7=M1-P0, 6=M1-P1.
VBLANK    := (TIA_REG_W_BASE+$01)    ; $01  w nn-- --n- Vertical Blank Set-Clear.
CXP0FB    := (TIA_REG_R_BASE+$02)    ; $02 r  nn-- ---- Read Collision Bit 7=P0-PF, 6=P0-BL.
WSYNC    := (TIA_REG_W_BASE+$02)    ; $02  w -STROBE-  Wait for Horizontal Blank.
CXP1FB    := (TIA_REG_R_BASE+$03)    ; $03 r  nn-- ---- Read Collision Bit 7=P1-PF, 6=P1-BL.
RSYNC    := (TIA_REG_W_BASE+$03)    ; $03  w -STROBE-  Reset Horizontal Sync Counter.
CXM0FB    := (TIA_REG_R_BASE+$04)    ; $04 r  nn-- ---- Read Collision Bit 7=M0-PF, 6=M0-BL.
NUSIZ0    := (TIA_REG_W_BASE+$04)    ; $04  w --nn -nnn Number/Size Player/Missle 0.
CXM1FB    := (TIA_REG_R_BASE+$05)    ; $05 r  nn-- ---- Read Collision Bit 7=M1-PF, 6=M1-BL.
NUSIZ1    := (TIA_REG_W_BASE+$05)    ; $05  w --nn -nnn Number/Size Player/Missle 1.
CXBLPF    := (TIA_REG_R_BASE+$06)    ; $06 r  n--- ---- Read Collision Bit 7=BL-PF.
COLUP0    := (TIA_REG_W_BASE+$06)    ; $06  w nnnn nnn- Color-Luminance Player 0.
CXPPMM    := (TIA_REG_R_BASE+$07)    ; $07 r  nn-- ---- Read Collision Bit 7=P0-P1, 6=M0-M1.
COLUP1    := (TIA_REG_W_BASE+$07)    ; $07  w nnnn nnn- Color-Luminance Player 1.
INPT0    := (TIA_REG_R_BASE+$08)    ; $08 r  n--- ---- Read Pot Port I0 [Dumped/Grounded].
COLUPF    := (TIA_REG_W_BASE+$08)    ; $08  w nnnn nnn- Color-Luminance Playfield.
INPT1    := (TIA_REG_R_BASE+$09)    ; $09 r  n--- ---- Read Pot Port I1 [Dumped/Grounded].
COLUBK    := (TIA_REG_W_BASE+$09)    ; $09  w nnnn nnn- Color-Luminance Background.
INPT2    := (TIA_REG_R_BASE+$0A)    ; $0A r  n--- ---- Read Pot Port I2 [Dumped/Grounded].
CTRLPF    := (TIA_REG_W_BASE+$0A)    ; $0A  w --nn -nnn Control Playfield, Ball Size, Collisions.
INPT3    := (TIA_REG_R_BASE+$0B)    ; $0B r  n--- ---- Read Pot Port I3 [Dumped/Grounded].
REFP0    := (TIA_REG_W_BASE+$0B)    ; $0B  w ---- n--- Reflect Player 0.
INPT4    := (TIA_REG_R_BASE+$0C)    ; $0C r  n--- ---- Read Input (Trigger) I4 [Latched].
REFP1    := (TIA_REG_W_BASE+$0C)    ; $0C  w ---- n--- Reflect Player 1.
INPT5    := (TIA_REG_R_BASE+$0D)    ; $0D r  n--- ---- Read Input (Trigger) I5 [Latched].
PF0        := (TIA_REG_W_BASE+$0D)    ; $0D  w nnnn ---- Playfield Register Byte 0.
PF1        := (TIA_REG_W_BASE+$0E)    ; $0E  w nnnn nnnn Playfield Register Byte 1.
PF2        := (TIA_REG_W_BASE+$0F)    ; $0F  w nnnn nnnn Playfield Register Byte 2.
RESP0    := (TIA_REG_W_BASE+$10)    ; $10  w -STROBE-  Reset Player 0.
RESP1    := (TIA_REG_W_BASE+$11)    ; $11  w -STROBE-  Reset Player 1.
RESM0    := (TIA_REG_W_BASE+$12)    ; $12  w -STROBE-  Reset Missle 0.
RESM1    := (TIA_REG_W_BASE+$13)    ; $13  w -STROBE-  Reset Missle 1.
RESBL    := (TIA_REG_W_BASE+$14)    ; $14  w -STROBE-  Reset Ball.
AUDC0    := (TIA_REG_W_BASE+$15)    ; $15  w ---- nnnn Audio Control 0.
AUDC1    := (TIA_REG_W_BASE+$16)    ; $16  w ---- nnnn Audio Control 1.
AUDF0    := (TIA_REG_W_BASE+$17)    ; $17  w ---n nnnn Audio Frequency 0.
AUDF1    := (TIA_REG_W_BASE+$18)    ; $18  w ---n nnnn Audio Frequency 1.
AUDV0    := (TIA_REG_W_BASE+$19)    ; $19  w ---- nnnn Audio Volume 0.
AUDV1    := (TIA_REG_W_BASE+$1A)    ; $1A  w ---- nnnn Audio Volume 1.
GRP0    := (TIA_REG_W_BASE+$1B)    ; $1B  w nnnn nnnn Graphics Register Player 0.
GRP1    := (TIA_REG_W_BASE+$1C)    ; $1C  w nnnn nnnn Graphics Register Player 1.
ENAM0    := (TIA_REG_W_BASE+$1D)    ; $1D  w ---- --n- Graphics Enable Missle 0.
ENAM1    := (TIA_REG_W_BASE+$1E)    ; $1E  w ---- --n- Graphics Enable Missle 1
ENABL    := (TIA_REG_W_BASE+$1f)    ; $1F  w ---- --n- Graphics Enable Ball.
HMP0    := (TIA_REG_W_BASE+$20)    ; $20  w nnnn ---- Horizontal Motion Player 0.
HMP1    := (TIA_REG_W_BASE+$21)    ; $21  w nnnn ---- Horizontal Motion Player 1.
HMM0    := (TIA_REG_W_BASE+$22)    ; $22  w nnnn ---- Horizontal Motion Missle 0.
HMM1    := (TIA_REG_W_BASE+$23)    ; $23  w nnnn ---- Horizontal Motion Missle 1.
HMBL    := (TIA_REG_W_BASE+$24)    ; $24  w nnnn ---- Horizontal Motion Ball.
VDELP0    := (TIA_REG_W_BASE+$25)    ; $25  w ---- ---n Vertical Delay Player 0.
VDELP1    := (TIA_REG_W_BASE+$26)    ; $26  w ---- ---n Vertical Delay Player 1.
VDELBL    := (TIA_REG_W_BASE+$27)    ; $27  w ---- ---n Vertical Delay Ball.
RESMP0    := (TIA_REG_W_BASE+$28)    ; $28  w ---- --n- Reset Missle 0 to Player 0.
RESMP1    := (TIA_REG_W_BASE+$29)    ; $29  w ---- --n- Reset Missle 1 to Player 1.
HMOVE    := (TIA_REG_W_BASE+$2A)    ; $2A  w -STROBE-  Apply Horizontal Motion.
HMCLR    := (TIA_REG_W_BASE+$2B)    ; $2B  w -STROBE-  Clear Horizontal Move Registers.
CXCLR    := (TIA_REG_W_BASE+$2C)    ; $2C  w -STROBE-  Clear Collision Latches.
                                ; $2D    Unused / Mirror.
                                ; $2E    Unused / Mirror.
                                ; $2F    Unused / Mirror.
                                ; $30    Unused / Mirror.
                                ; $31    Unused / Mirror.
                                ; $32    Unused / Mirror.
                                ; $33    Unused / Mirror.
                                ; $34    Unused / Mirror.
                                ; $35    Unused / Mirror.
                                ; $36    Unused / Mirror.
                                ; $37    Unused / Mirror.
                                ; $38    Unused / Mirror.
                                ; $39    Unused / Mirror.
                                ; $3A    Unused / Mirror.
                                ; $3B    Unused / Mirror.
                                ; $3C    Unused / Mirror.
                                ; $3D    Unused / Mirror.
                                ; $3E    Unused / Mirror.
                                ; $3F    Unused / Mirror.

;------------------------------------------------------------------------------
; TIA Stella Name Compatibility
;------------------------------------------------------------------------------

            .IFNDEF        NO_STELLA_REG_NAMES

; Base Addresses

TIA_BASE_ADDRESS        :=    TIA_REG_BASE
TIA_BASE_READ_ADDRESS    :=    TIA_REG_R_BASE
TIA_BASE_WRITE_ADDRESS    :=    TIA_REG_W_BASE

            .ENDIF

;------------------------------------------------------------------------------
; CX??? Read Collision Bits.
;------------------------------------------------------------------------------

CXB_M0P1    =    7    ; CXM0P  M0-P1 Collision Bit.
CXB_M0P0    =    6    ; CXM0P  M0-P0 Collision Bit.
CXB_M1P1    =    7    ; CXM1P  M1-P1 Collision Bit.
CXB_M1P0    =    6    ; CXM1P  M1-P0 Collision Bit.
CXB_P0PF    =    7    ; CXP0FB P0-PF Collision Bit.
CXB_P0BL    =    6    ; CXP0FB P0-BL Collision Bit.
CXB_P1PF    =    7    ; CXP1FB P1-PF Collision Bit.
CXB_P1BL     =    6    ; CXP1FB P1-BL Collision Bit.
CXB_M0PF    =    7    ; CXM0FB P0-PF Collision Bit.
CXB_M0BL    =    6    ; CXM0FB P0-BL Collision Bit.
CXB_M1PF    =    7    ; CXM1FB M1-PF Collision Bit.
CXB_M1BL    =    6    ; CXM1FB M1-BL Collision Bit.
CXB_BLPF    =    7    ; CXBLPF BL-PF Collision Bit.
CXB_P0P1    =    7    ; CXPPMM P0-P1 Collision Bit.
CXB_M0M1    =    6    ; CXPPMM M0-M1 Collision Bit.

CXF_M0P1    =    $80    ; CXM0P  M0-P1 Collision Flag.
CXF_M0P0    =    $40    ; CXM0P  M0-P0 Collision Flag.
CXF_M1P1    =    $80    ; CXM1P  M1-P1 Collision Flag.
CXF_M1P0    =    $40    ; CXM1P  M1-P0 Collision Flag.
CXF_P0PF    =    $80    ; CXP0FB P0-PF Collision Flag.
CXF_P0BL    =    $40    ; CXP0FB P0-BL Collision Flag.
CXF_P1PF    =    $80    ; CXP1FB P1-PF Collision Flag.
CXF_P1BL    =    $40    ; CXP1FB P1-BL Collision Flag.
CXF_M0PF    =    $80    ; CXM0FB M0-PF Collision Flag.
CXF_M0BL    =    $40    ; CXM0FB M0-BL Collision Flag.
CXF_M1PF    =    $80    ; CXM1FB M1-PF Collision Flag.
CXF_M1BL    =    $40    ; CXM1FB M1-BL Collision Flag.
CXF_BLPF    =    $80    ; CXBLPF BL-PF Collision Flag.
CXF_P0P1    =    $80    ; CXPPMM P0-P1 Collision Flag.
CXF_M0M1    =    $40    ; CXPPMM M0-M1 Collision Flag.

;------------------------------------------------------------------------------
; INPTn Read Pot Port [Dumped/Grounded] / Read Input (Trigger) [Latched].
;------------------------------------------------------------------------------

INPTB_IN    =    7    ; INPTn In Bit.

INPTF_IN    =    $80    ; INPTn In Flag.

;------------------------------------------------------------------------------
; VSYNC Write VSYNC Vertical Sync Set-Clear.
;------------------------------------------------------------------------------

VSYNCB_ON    =    1    ; Vertical Sync On Bit.

VSYNCF_ON    =    $02    ; Vertical Sync On Flag.

VSYNC_ON    =    $02 ; Vertical Sync On Value.
VSYNC_OFF    =    $00 ; Vertical Sync Off Value.

;------------------------------------------------------------------------------
; VBLANK Write Vertical Blank Set-Clear. Input Ports Latch and Dump Control.
;------------------------------------------------------------------------------

VBLANKB_DUMP    =    7    ; Vertical Blank Dump (ground) Input I0, I1, I2, I3 Bit.
VBLANKB_LATCH    =    6    ; Vertical Blank Latch Input I4, I5 Bit.
VBLANKB_ON        =    1    ; Vertical Blank On (disable display) Bit.

VBLANKF_DUMP    =    $80    ; Vertical Blank Dump (ground) Input I0, I1, I2, I3 Flag.
VBLANKF_LATCH    =    $40    ; Vertical Blank Latch Input I4, I5 Flag.
VBLANKF_ON        =    $02    ; Vertical Blank On (disable display) Flag.

;------------------------------------------------------------------------------
; NUSIZ0 Write Number/Size Player/Missle 0.
; NUSIZ1 Write Number/Size Player/Missle 1.
;------------------------------------------------------------------------------

NUSIZM            =    $37    ; Number/Size Player/Missile (0 or 1) Mask.
NUSIZM_M        =    $30    ; Size Missile (0 or 1) Mask.
NUSIZM_P        =    $07    ; Number/Size Player (0 or 1) Mask.

NUSIZF_MS1    =    $00    ; Missile Size 1 Clocks Wide Flag.
NUSIZF_MS2    =    $10    ; Missile Size 2 Clocks Wide Flag.
NUSIZF_MS3    =    $20 ; Missile Size 4 Clocks Wide Flag.
NUSIZF_MS4    =    $30    ; Missile Size 8 Clocks Wide Flag.

NUSIZF_P1S1G0    =    $00    ; Player Number = 1, Size = 1, Gap = 0 Flag.
NUSIZF_P2S1G2    =    $01 ; Player Number = 2, Size = 1, Gap = 2 Flag.
NUSIZF_P2S1G4    =    $02    ; Player Number = 2, Size = 1, Gap = 4 Flag.
NUSIZF_P3S1G2    =    $03 ; Player Number = 3, Size = 1, Gap = 2 Flag.
NUSIZF_P2S1G8    =    $04    ; Player Number = 2, Size = 1, Gap = 8 Flag.
NUSIZF_P1S2G0    =    $05    ; Player Number = 1, Size = 2, Gap = 0 Flag.
NUSIZF_P3S1G4    =    $06 ; Player Number = 3, Size = 1, Gap = 4 Flag.
NUSIZF_P1S4G0    =    $07    ; Player Number = 1, Size = 4, Gap = 0 Flag.

;------------------------------------------------------------------------------
; COLUP0 Write Color-Luminance Player 0.
; COLUP1 Write Color-Luminance Player 1.
; COLUPF Write Color-Luminance Playfield.
; COLUBK Write Color-Luminance Background.
;------------------------------------------------------------------------------

COLUM            =    $FE    ; Colour-Luminance Mask.
COLUM_CO        =    $F0    ; Color-Luminance Colour Mask.
COLUM_LU        =    $0E    ; Colour-Luminance Luminance ($0=Dark, $E=Light) Mask.

;------------------------------------------------------------------------------
; CTRLPF Write Control Playfield, Ball Size, Collisions.
;------------------------------------------------------------------------------

CTRLPFM            =    $37    ; Control Playfield, Ball Size, Collisions Mask.
CTRLPFM_BSIZE    =    $30 ; Ball Size Mask.

CTRLPB_PFP        =    2    ; Playfield Priority Over Players Bit.
CTRLPB_SCORE    =    1    ; Left Size of Playfield Player 0 Colour Bit.
CTRLPB_REF        =    0    ; Reflect Right Copy of Playfield Bit.

CTRLPF_PFP        =    $04 ; Playfield Priority Over Players Flag.
CTRLPF_SCORE    =    $02    ; Left Size of Playfield Player 0 Colour Flag.
CTRLPF_REF        =    $01    ; Reflect Right Copy of Playfield Flag.

CTRLPF_BS1        =    $00    ; Ball Size 1 Clocks Wide Flag.
CTRLPF_BS2        =    $10    ; Ball Size 2 Clocks Wide Flag.
CTRLPF_BS4        =    $20    ; Ball Size 4 Clocks Wide Flag.
CTRLPF_BS8        =    $30    ; Ball Size 8 Clocks Wide Flag.

;------------------------------------------------------------------------------
; REFP0 Write Reflect Player 0.
; REFP1 Write Reflect Player 1.
;------------------------------------------------------------------------------

REFB_P        =     3    ; Reflect Player (0 or 1) Bit.

REFF_P        =    $08    ; Reflect Player (0 or 1) Flag.

;------------------------------------------------------------------------------
; AUDC0 Write Audio Control 0.
; AUDC1 Write Audio Control 1.
;------------------------------------------------------------------------------

AUDM_C        =    $0F    ; Audio Control (0 or 1) Mask.

;------------------------------------------------------------------------------
; AUDF0 Write Audio Frequency 0.
; AUDF1 Write Audio Frequency 1.
;------------------------------------------------------------------------------

AUDM_F        =    $1F    ; Audio Frequency (0 or 1) Mask.

;------------------------------------------------------------------------------
; AUDV0 Write Audio Volume 0.
; AUDV1 Write Audio Volume 1.
;------------------------------------------------------------------------------

AUDM_V        =    $0F    ; Audio Volume (0 or 1) Mask.

;------------------------------------------------------------------------------
; ENAM0 Write Graphics Enable Missle 0.
; ENAM1 Write Graphics Enable Missle 1.
; ENABL Write Graphics Enable Ball.
;------------------------------------------------------------------------------

ENAB        =    1    ; Graphics Enable (missile 0, missile 1, ball) Bit.

ENAF        =    $02    ; Graphics Enable (missile 0, missile 1, ball) Flag.

ENA_ON        =    2    ; Graphics Enable (missile 0, missile 1, ball) Enable.
ENA_OFF        =    0    ; Graphics Enable (missile 0, missile 1, ball) Disable.

;------------------------------------------------------------------------------
; HMP0 Write Horizontal Motion Player 0.
; HMP1 Write Horizontal Motion Player 1.
; HMM0 Write Horizontal Motion Missle 0.
; HMM1 Write Horizontal Motion Missle 1.
; HMBL Write Horizontal Motion Ball.
;------------------------------------------------------------------------------

HMM            =    $F0 ; Horizontal Motion Mask;

;------------------------------------------------------------------------------
; VDELP0 Write Vertical Delay Player 0.
; VDELP1 Write Vertical Delay Player 1.
; VDELBL Write Vertical Delay Ball.
;------------------------------------------------------------------------------

VDELB        =    0    ; Vertical Delay (player 0, player 1, or ball) Bit.

VDELF        =    $01    ; Vertical Delay (player 0, player 1, or ball) Flag.

VDEL_ON        =    1    ; Vertical Delay (player 0, player 1, or ball) On.
VDEL_OFF    =    0    ; Vertical Delay (player 0, player 1, or ball) Off.

;------------------------------------------------------------------------------
; RESMP0 Write Reset Missle 0 to Player 0.
; RESMP1 Write Reset Missle 1 to Player 1.
;------------------------------------------------------------------------------

RESB_MP        =    1    ; Reset Missile (0 or 1) to Player (0 or 1) Bit.

RESF_MP        =    $02    ; Reset Missile (0 or 1) to Player (0 or 1) Flag.

;------------------------------------------------------------------------------

            .POPSEG

;------------------------------------------------------------------------------


