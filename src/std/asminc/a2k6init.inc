;==============================================================================
; Name:         Atari 2600 Power-up/Reset hardware initialisation include file.
; Filename:     a2k6init.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-10 23:22
; Vesion:		1.0.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Initialisation of Hardware following Power-up/Reset.
;==============================================================================

					.PUSHSEG

;------------------------------------------------------------------------------
; Central Processing Unit (CPU).
;------------------------------------------------------------------------------

; Initialise the CPU interrupt and decimal flag.

.MACRO			CPU_INTDEC_INIT
				; Initialise CPU.
				SEI								; Disable interrupts.
				CLD								; Clear decimal flag.
.ENDMACRO



; Initialise the CPU stack.

.MACRO			CPU_STACK_INIT
				LDX				#$FF			; Reset stack.
				TXS
.ENDMACRO



; Initialise the CPU interrupt, decimal flag, stack, and carry flag.

.MACRO			CPU_INIT
				CPU_INTDEC_INIT
				CPU_STACK_INIT
				CLC								; Clear carry flag.
.ENDMACRO



; Set the Interrupt and Reset Vectors to a single address.
; Note: fills the rest of the address space (4k)

.MACRO			CPU_RESET_VEC	RESET_VEC
				.PUSHSEG
				; Fills the rest of the address space (4K).
				.SEGMENT		"VECTORS"
				; Set the NMI, RESET, and IRQ vectors.
				.ADDR			RESET_VEC		; NMI (should never occur on 6507)
				.ADDR			RESET_VEC		; RESET
				.ADDR			RESET_VEC		; IRQ (only occur with BRK on 6507)
				.POPSEG
.ENDMACRO



; Set the Interrupt and Reset Vectors to three separate addresses.
; Note: fills the rest of the address space (4k)

.MACRO			CPU_INTRES_VEC	NMI_VEC,RESET_VEC,IRQ_VEC
				.PUSHSEG
				; Fills the rest of the address space (4K).
				.SEGMENT		"VECTORS"
				; Set the NMI, RESET, and IRQ vectors.
				.ADDR			NMI_VEC			; NMI (should never occur on 6507)
				.ADDR			RESET_VEC		; RESET
				.ADDR			IRQ_VEC			; IRQ (only occur with BRK on 6507)
				.POPSEG
.ENDMACRO



;------------------------------------------------------------------------------
; RIOT + TIA
;------------------------------------------------------------------------------

; Clear RIOT RAM (0x0080 - 0x00FF) via zero-page.

.MACRO			RIOT_RAM_INIT
				; Clear RAM (0x0080 - 0x00FF)
				.LOCAL			ram_clr
				LDX				#$00
				LDA				#$00
ram_clr:
				STA				$80,X
				INX
				CPX				#$80
				BNE				ram_clr
.ENDMACRO



; Clear TIA registers (0x0040 - 0x007F) via zero-page.

.MACRO			TIA_REG_INIT
				; Clear TIA (0x0040 - 0x007F).
				.LOCAL			tia_clr
				LDX				#$00
				LDA				#$00
tia_clr:
				STA				$40,X
				INX
				CPX				#$40
				BNE				tia_clr
.ENDMACRO



; Clear TIA registers (0x0040 - 0x007F) and RIOT RAM (0x0080 - 0x00FF).

.MACRO			RIOT_RAM_TIA_REG_INIT
				; Clear TIA regs (0x0040-0x007F) and RIOT RAM (0x0080-0x00FF).
				.LOCAL			ram_tia_clr
				LDX				#$00
				LDA				#$00
ram_tia_clr:
				STA				$40,X
				INX
				CPX				#$C0
				BNE				ram_tia_clr
.ENDMACRO



; Initialise RIOT IO registers.

.MACRO			RIOT_IO_REG_INIT
				LDA				#00
				; Port B input.
				STA				SWBCNT
				; Port A input.
				STA				SWACNT
.ENDMACRO



; Initialise RIOT EDC and timer registers.

.MACRO			RIOT_EDC_TIM_REG_INIT
				; Write Edge-Detect Control PA7, Neg Edge-Detect, Disable Int.
				STA				WEDCNEDI
				; Write Timer, Divide by 1, Disable Int., Clear Timer Int. Flag.
				STA				WTIM1DI
.ENDMACRO



; Initialise RIOT IO, EDC, and timer registers.

.MACRO			RIOT_REG_INIT
				RIOT_IO_REG_INIT
				RIOT_EDC_TIM_REG_INIT
.ENDMACRO



;------------------------------------------------------------------------------
; Cold and Warm initialisation.
;------------------------------------------------------------------------------

; Initialise Atari 2600 hardware on a cold start (power-up/reset).

.MACRO			A2K6_COLD_INIT
				CPU_INIT
				RIOT_RAM_TIA_REG_INIT
				RIOT_REG_INIT
.ENDMACRO



; Initialise Atari 2600 hardware ona warm start (software/console switch reset).

.MACRO			A2K6_WARM_INIT
				CPU_INIT
				TIA_REG_INIT
				RIOT_REG_INIT
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


