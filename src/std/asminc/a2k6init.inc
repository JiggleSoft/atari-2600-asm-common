;==============================================================================
; Name:         Atari 2600 Power-up/Reset hardware initialisation include file.
; Filename:     a2k6init.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-11 01:06
; Version:      1.2.1
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

                .IFNDEF     __A2K6INIT__INC__
                .DEFINE     __A2K6INIT__INC__

;==============================================================================
; Atari 2600 Initialisation of Hardware following Power-up/Reset.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Central Processing Unit (CPU).
;------------------------------------------------------------------------------

; Initialise the CPU interrupt disable (I=1) and clear decimal flag (D=0).

.MACRO          CPU_INIT_SEI_CLD
                ; Initialise CPU interrupt disable and clear decimal flag.
                SEI                 ; Disable interrupts (I=1).
                CLD                 ; Clear decimal flag (D=0).
.ENDMACRO



; Initialise the CPU stack pointer (X=SP=$FF).

.MACRO          CPU_INIT_SP
                ; Initialise CPU stack pointer (SP).
                LDX         #$FF    ; Reset stack pointer (SP=$FF).
                TXS
.ENDMACRO



; Initialise the CPU interrupt (I=1), decimal (D=0), and stack (X=SP=$FF).

.MACRO          CPU_INIT
                CPU_INIT_SEI_CLD
                CPU_INIT_SP
.ENDMACRO



; Set the Interrupt and Reset Vectors to a single address.
; Note: fills the rest of the address space (4k)

.MACRO          CPU_CONFIG_VECTOR   RESET_ADDR
                .PUSHSEG
                ; Fills the rest of the address space (4K).
                .SEGMENT    "VECTORS"
                ; Set the NMI, RESET, and IRQ vectors.
                .ADDR       RESET_ADDR  ; NMI (never occur on 6507).
                .ADDR       RESET_ADDR  ; RESET.
                .ADDR       RESET_ADDR  ; IRQ (only with BRK on 6507).
                .POPSEG
.ENDMACRO



; Set the Interrupt and Reset Vectors to three separate addresses.
; Note: fills the rest of the address space (4k)

.MACRO          CPU_CONFIG_VECTORS  NMI_ADDR,RESET_ADDR,IRQ_ADDR
                .PUSHSEG
                ; Fills the rest of the address space (4K).
                .SEGMENT    "VECTORS"
                ; Set the NMI, RESET, and IRQ vectors.
                .ADDR       NMI_ADDR    ; NMI (never occur on 6507).
                .ADDR       RESET_ADDR  ; RESET.
                .ADDR       IRQ_ADDR    ; IRQ (only with BRK on 6507).
                .POPSEG
.ENDMACRO



;------------------------------------------------------------------------------
; RAM, Input/Output, and Timer (RIOT) + Television Interface Adapter (TIA).
;------------------------------------------------------------------------------

; Clear RIOT RAM (0x0080 - 0x00FF) via zero-page.

.MACRO          RIOT_RAM_INIT
                ; Clear RAM (0x0080 - 0x00FF)
                .LOCAL      ram_clr
                LDX         #$00
                LDA         #$00
ram_clr:
                STA         $80,X
                INX
                CPX         #$80
                BNE         ram_clr
.ENDMACRO



; Clear TIA registers (0x0040 - 0x007F) via zero-page.

.MACRO          TIA_INIT_REG
                ; Clear TIA (0x0040 - 0x007F).
                .LOCAL      tia_clr
                LDX         #$00
                LDA         #$00
tia_clr:
                STA         $40,X
                INX
                CPX         #$40
                BNE         tia_clr
.ENDMACRO



; Clear TIA registers (0x0040 - 0x007F) and RIOT RAM (0x0080 - 0x00FF).

.MACRO          RIOT_INIT_RAM_TIA_REG
                ; Clear TIA regs (0x0040-0x007F) and RIOT RAM (0x0080-0x00FF).
                .LOCAL      ram_tia_clr
                LDX         #$00
                LDA         #$00
ram_tia_clr:
                STA         $40,X
                INX
                CPX         #$C0
                BNE         ram_tia_clr
.ENDMACRO



; Initialise RIOT IO registers.

.MACRO          RIOT_INIT_IO_REG
                LDA         #$00
                ; Port B input.
                STA         SWBCNT
                ; Port A input.
                STA         SWACNT
.ENDMACRO



; Initialise RIOT EDC and timer registers.

.MACRO          RIOT_INIT_EDC_TIM_REG
                ; Write Edge-Detect Control PA7, Neg Edge-Detect, Disable Int.
                STA         WEDCNEDI
                ; Write Timer, Divide by 1, Disable Int., Clear Timer Int. Flag.
                STA         WTIM1DI
.ENDMACRO



; Initialise RIOT IO, EDC, and timer registers.

.MACRO          RIOT_INIT_REG
                RIOT_INIT_IO_REG
                RIOT_INIT_EDC_TIM_REG
.ENDMACRO



;------------------------------------------------------------------------------
; Atari 2600 Cold and Warm hardware initialisation.
;------------------------------------------------------------------------------

; Initialise Atari 2600 hardware on a cold start (power-up/reset).

.MACRO          A2K6_INIT_COLD
.WARNING        "Consider use of the optimised variants."
                CPU_INIT
                RIOT_RAM_TIA_REG_INIT
                RIOT_REG_INIT
.ENDMACRO



; Initialise Atari 2600 hardware on warm start (software/console switch reset).

.MACRO          A2K6_INIT_WARM
.WARNING        "Consider use of the optimised variants."
                CPU_INIT
                TIA_REG_INIT
                RIOT_REG_INIT
.ENDMACRO



;------------------------------------------------------------------------------
; Atari 2600 Cold and Warm hardware initialisation (optimised).
;------------------------------------------------------------------------------

; Initialise Atari 2600 hardware on a cold start (power-up/reset).
; Note: Interrupt disable (I=1), decimal (D=0), stack (SP=$FF), RAM+TIA clear,
;       X=A=0. Size = 10 Bytes.

.MACRO          A2K6_TINY_INIT_COLD
                SEI
                CLD
                LDX         #$00
                TXA
.clr_ram_tia
                DEX
                TXS
                PHA
                BNE         .clr_ram_tia
.ENDMACRO



; Initialise Atari 2600 hardware on warm start (software/console switch reset).
; Note: Stack (SP=$FF), TIA clear, X=A=0. Size = 10 Bytes.

; Note: 9 Bytes.

.MACRO          A2K6_TINY_INIT_WARM
                LDA         #$00
                LDX         #$3E
clr_tia
                TXS
                PHA
                DEX
                BNE         .clr_tia
.ENDMACRO



; Initialise Atari 2600 hardware on a cold start (power-up/reset).!!!!!!!!!!!!!!!!!!!!!!
; Note: Interrupt disable (I=1), decimal (D=0), stack (SP=$FF), RAM+TIA clear,
;       X=A=0. Size = 10 Bytes. Y == $00 for cold start, Y != 0 for warm start.
; Note: 18 Bytes

.MACRO          A2K6_TINY_INIT
                .LOCAL      clr_ram_tia
ResetCold:
                SEI
                CLD
                LDX         #$00
                TXA
                TAY
                BRA         clr_ram_tia
ResetWarm:
                DEY
                LDA         #$00
                LDX         #$3F
clr_ram_tia:
                DEX
                TXS
                PHA
                BNE         clr_ram_tia
.ENDMACRO



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

.ENDIF


