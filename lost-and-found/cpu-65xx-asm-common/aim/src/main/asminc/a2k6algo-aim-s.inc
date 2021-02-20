;==============================================================================
; Name:         Atari 2600 - Algorithm - Aim Vector include file.
; Filename:     a2k6algo-aim.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-01 22:30
; Version:      2.0.0
;------------------------------------------------------------------------------
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
;------------------------------------------------------------------------------

                .IFNDEF     __A2K6ALGO_AIM__INC__
                .DEFINE     __A2K6ALGO_AIM__INC__

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

; Clear RIOT RAM (0x0080 - 0x00FF) via zero-page (A=X=$00).

.MACRO          RIOT_INIT_RAM
                ; Clear RAM (0x0080 - 0x00FF)
                .LOCAL      ram_clr
                LDX         #$80
                LDA         #$00
ram_clr:
                STA         $7F,X
                DEX
                BNE         ram_clr
.ENDMACRO



; Clear TIA registers (0x0000 - 0x002C) via zero-page (A=X=$00).

.MACRO          TIA_INIT_REG
                ; Clear TIA (0x0000 - 0x002C).
                .LOCAL      tia_clr
                LDX         #$2D
                LDA         #$00
tia_clr:
                STA         $FF,X
                DEX
                BNE         tia_clr
.ENDMACRO



; Clear TIA registers (0x0000 - 0x002C) and RIOT RAM (0x0080 - 0x00FF) (A=X=$00).

.MACRO          RIOT_INIT_RAM_TIA_REG
                ; Clear TIA regs (0x0000-0x002C) and RIOT RAM (0x0080-0x00FF).
                .LOCAL      ram_tia_clr
                LDX         #$AD
                LDA         #$00
ram_tia_clr:
                STA         $7F,X
                DEX
                BNE         ram_tia_clr
.ENDMACRO



; Initialise RIOT IO registers as inputs (same as defaults) (A=$00).

.MACRO          RIOT_INIT_IO_REG
                LDA         #$00
                ; Port B input.
                STA         DDIRREGB
                ; Port A input.
                STA         DDIRREGA
.ENDMACRO



; Initialise RIOT EDC and timer registers.

.MACRO          RIOT_INIT_EDC_TIM_REG
                ; Write Edge-Detect Control PA7, Neg Edge-Detect, Disable Int.
                STA         WEDCNEDI
                ; Write Timer, Divide by 64, Disable Int., Clear Timer Int. Flag.
                STA         WTIM64DI
.ENDMACRO



; Initialise RIOT IO, EDC, and timer registers (A=$00).

.MACRO          RIOT_INIT_REG
                RIOT_INIT_IO_REG
                RIOT_INIT_EDC_TIM_REG
.ENDMACRO



;------------------------------------------------------------------------------
; Atari 2600 Cold and Warm hardware initialisation.
;------------------------------------------------------------------------------

; Initialise Atari 2600 hardware on a cold start (power-up/reset).
; Note: CPU interrupt (I=1), decimal (D=0), stack (SP=$FF), regs (A=X=Y=$00).
;       RIOT RAM cleared. TIA initialised. RIOT Timer and IO initialised.
;       Size = 29 Bytes.

.MACRO          A2K6_INIT_COLD
.WARNING        "Macro A2K6_INIT_COLD: Consider use of the optimised variants."
                CPU_INIT
                RIOT_INIT_RAM_TIA_REG
                RIOT_INIT_REG
                TAY
.ENDMACRO



; Initialise Atari 2600 hardware on warm start (software/console switch reset).
; Note: CPU decimal (D=0), stack (SP=$FF), registers (A=X=Y=$00).
;       TIA initialised. RIOT Timer and IO initialised.
;       RIOT RAM left unchanged. CPU interrupt left unchanged.
;       Size = 28 Bytes.

.MACRO          A2K6_INIT_WARM
.WARNING        "Macro A2K6_INIT_WARM: Consider use of the optimised variants."
                CLD
                CPU_INIT_SP
                TIA_INIT_REG
                RIOT_INIT_REG
                TAY
.ENDMACRO



; Initialise Atari 2600 hardware on a cold start (power-up/reset) and
; warm start (software/console switch reset).
;
; Cold Start:
;       CPU interrupt (I=1), decimal (D=0), stack (SP=$FF), regs (A=X=$00),
;       register Y set dependent on cold or warm start (see notes below).
;       RIOT RAM cleared. TIA initialised. RIOT Timer and IO initialised.
;
; Warm Start:
;       CPU decimal (D=0), stack (SP=$FF), registers (A=X=$00),
;       register Y set dependent on cold or warm start (see notes below).
;       TIA initialised. RIOT Timer and IO initialised.
;       RIOT RAM left unchanged. CPU interrupt left unchanged.
;
; Note:
;       CPU register Y: $00 = Cold Start, $FF = Warm Start.
;       Size = 43 Bytes (some optimisations are possible by moving loop of
;       RIOT_INIT_RAM_TIA_REG and RIOT_INIT_REG to common but altering the
;       size).

.MACRO          A2K6_INIT_STARTUP a2k6_init_cold_label,a2k6_init_warm_label
                .LOCAL      a2k6_init_common
.WARNING        "Macro A2K6_INIT: Consider use of the optimised variants."
                .IFNBLANK   a2k6_init_cold_label
a2k6_init_cold_label:
                .ELSE
a2k6_init_cold:
                .ENDIF
                SEI
                RIOT_INIT_RAM_TIA_REG
                TAY                             ; A=Y=$00,N=0,Z=1
                BEQ         a2k6_init_common    ; BRA
                .IFNBLANK   a2k6_init_warm_label
a2k6_init_warm_label:
                .ELSE
a2k6_init_warm:
                .ENDIF
                TIA_INIT_REG
                LDY         #$FF
a2k6_init_common:
                CPU_INIT_SP
                RIOT_INIT_REG
                CLD
                TAX
.ENDMACRO



;------------------------------------------------------------------------------
; Atari 2600 Cold and Warm hardware initialisation (safe optimised).
;------------------------------------------------------------------------------

; Initialise Atari 2600 hardware on a cold start (power-up/reset).
; Note: CPU interrupt (I=1), decimal (D=0), stack (SP=$FF), regs (A=X=Y=$00).
;       RIOT RAM cleared. TIA initialised (0x0000-0x007F; includes mirrors).
;       RIOT Timer and IO initialised.
;       Size = 23 Bytes (legal opcodes) or 22 Bytes (illegal opcodes).

.MACRO          A2K6_TINY_INIT_COLD
                .LOCAL      clr_ram_tia
                CPU_INIT_SEI_CLD
                .IFDEF      NO_ILLEGAL_OPCODES
                LDX         #$00
                TXA
                .ELSE
;.WARNING        "Macro A2K6/_TINY_INIT_COLD: Using illegal opcodes."
                LAX         #$00
                .ENDIF
clr_ram_tia:
                DEX
                TXS
                PHA
                BNE         clr_ram_tia
                ; A = X = 0.
                STA         $0283   ; DDIRREGB
                STA         $0281   ; DDIRREGA
                STA         $0284   ; WEDCNEDI
                STA         $0296   ; WTIM64DI
                TAY
.ENDMACRO



; Initialise Atari 2600 hardware on warm start (software/console switch reset).
; Note: CPU decimal (D=0), stack (SP=$FF), registers (A=X=Y=$00).
;       TIA initialised. RIOT Timer and IO initialised.
;       RIOT RAM left unchanged. CPU interrupt left unchanged.
;       Size = 23 Bytes.

.MACRO          A2K6_TINY_INIT_WARM
                CLD
                .LOCAL      clr_tia
                LDA         #$00
                LDX         #$2D
clr_tia:
                DEX
                TXS
                PHA
                BNE         clr_tia
                ; A = X = 0.
                STA         $0283   ; DDIRREGB
                STA         $0281   ; DDIRREGA
                STA         $0284   ; WEDCNEDI
                STA         $0296   ; WTIM64DI
                TAY
.ENDMACRO



; Initialise Atari 2600 hardware on a cold start (power-up/reset) and
; warm start (software/console switch reset).
;
; Cold Start:
;       CPU interrupt (I=1), decimal (D=0), stack (SP=$FF), regs (A=X=$00),
;       register Y set dependent on cold or warm start (see notes below).
;       RIOT RAM cleared. TIA initialised (0x0000-0x007F; includes mirrors).
;       RIOT Timer and IO initialised.
;
; Warm Start:
;       CPU decimal (D=0), stack (SP=$FF), registers (A=X=$00),
;       register Y set dependent on cold or warm start (see notes below).
;       TIA initialised. RIOT Timer and IO initialised.
;       RIOT RAM left unchanged. CPU interrupt left unchanged.
;
; Note:
;       CPU register Y: $00 = Cold Start, $FF = Warm Start.
;       Size = 31 Bytes (legal opcodes) or 30 Bytes (illegal opcodes).

.MACRO          A2K6_TINY_INIT_STARTUP a2k6_init_cold_label,a2k6_init_warm_label
                .LOCAL      a2k6_init_common
                .LOCAL      clr_ram_tia
                .IFNBLANK   a2k6_init_cold_label
a2k6_init_cold_label:
                .ELSE
a2k6_init_cold:
                .ENDIF
                SEI
                .IFDEF      NO_ILLEGAL_OPCODES
                LDX         #$00
                TXA
                .ELSE
.WARNING        "Macro A2K6_TINY_INIT: Using illegal opcodes."
                LAX         #$00
                .ENDIF
                TAY                             ; A=Y=$00,N=0,Z=1
                BEQ         a2k6_init_common    ; BRA
                .IFNBLANK   a2k6_init_warm_label
a2k6_init_warm_label:
                .ELSE
a2k6_init_warm:
                .ENDIF
                LDA         #$00
                LDX         #$2D
                LDY         #$FF
a2k6_init_common:
                CLD
clr_ram_tia:
                DEX
                TXS
                PHA
                BNE         clr_ram_tia
                ; A = X = 0.
                STA         $0283   ; DDIRREGB
                STA         $0281   ; DDIRREGA
                STA         $0284   ; WEDCNEDI
                STA         $0296   ; WTIM64DI
.ENDMACRO



;------------------------------------------------------------------------------
; Atari 2600 Cold and Warm hardware initialisation (minimal optimised).
;------------------------------------------------------------------------------

; Initialise Atari 2600 hardware on a cold start (power-up/reset).
; Note: CPU interrupt (I=1), decimal (D=0), stack (SP=$FF), regs (A=X=$00).
;       RIOT RAM cleared. TIA initialised (0x0000-0x007F; includes mirrors).
;       CPU register Y untouched so undefined upon reset.
;       RIOT Timer untouched so undefined upon reset (REVIEW: is this true?).
;       RIOT IO untouched so set to input (DDIRREGB+A) upon reset and WEDCNEDI.
;       Size = 10 Bytes (legal opcodes) or 9 Bytes (illegal opcodes).

.MACRO          A2K6_MIN_INIT_COLD
                .LOCAL      clr_ram_tia
                CPU_INIT_SEI_CLD
                .IFDEF      NO_ILLEGAL_OPCODES
                LDX         #$00
                TXA
                .ELSE
.WARNING        "Macro A2K6_MIN_INIT_COLD: Using illegal opcodes."
                LAX         #$00
                .ENDIF
clr_ram_tia:
                DEX
                TXS
                PHA
                BNE         clr_ram_tia
.ENDMACRO



; Initialise Atari 2600 hardware on warm start (software/console switch reset).
; Note: CPU decimal (D=0), stack (SP=$FF), regs (A=X=$00).
;       TIA initialised.
;       CPU interrupt untouched, register Y untouched.
;       RIOT RAM untouched. RIOT Timer untouched. RIOT IO untouched.
;       Size = 10 Bytes.

.MACRO          A2K6_MIN_INIT_WARM
                CLD
                .LOCAL      clr_tia
                LDA         #$00
                LDX         #$2D
clr_tia:
                TXS
                PHA
                DEX
                BNE         clr_tia
.ENDMACRO



; Initialise Atari 2600 hardware on a cold start (power-up/reset) and
; warm start (software/console switch reset).
;
; Cold Start:
;       CPU interrupt (I=1), decimal (D=0), stack (SP=$FF), regs (A=X=$00).
;       RIOT RAM cleared. TIA initialised (0x0000-0x007F; includes mirrors).
;       CPU register Y untouched so undefined upon reset.
;       RIOT Timer untouched so undefined upon reset (REVIEW: is this true?).
;       RIOT IO untouched so set to input (DDIRREGB+A) upon reset and WEDCNEDI.
;
; Warm Start:
;       CPU decimal (D=0), stack (SP=$FF), regs (A=X=$00).
;       TIA initialised.
;       CPU interrupt untouched, register Y untouched.
;       RIOT RAM untouched. RIOT Timer untouched. RIOT IO untouched.
;
; Note:
;       CPU register Y: $00 = Cold Start, $FF = Warm Start.
;       Size = 16 Bytes (legal opcodes), 15 Bytes (illegal opcodes).

.MACRO          A2K6_MIN_INIT_STARTUP a2k6_init_cold_label,a2k6_init_warm_label
                .LOCAL      a2k6_init_common
                .LOCAL      clr_ram_tia
                .IFNBLANK   a2k6_init_cold_label
a2k6_init_cold_label:
                .ELSE
a2k6_init_cold:
                .ENDIF
                SEI
                .IFDEF      NO_ILLEGAL_OPCODES
                LDX         #$00
                TXA
                .ELSE
.WARNING        "Macro A2K6_TINY_INIT: Using illegal opcodes."
                LAX         #$00
                .ENDIF
                BEQ         a2k6_init_common    ; BRA (A=X=$00,N=0,Z=1)
                .IFNBLANK   a2k6_init_warm_label
a2k6_init_warm_label:
                .ELSE
a2k6_init_warm:
                .ENDIF
                LDA         #$00
                LDX         #$2D
a2k6_init_common:
                CLD
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


