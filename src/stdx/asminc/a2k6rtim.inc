;==============================================================================
; Name:         Atari 2600 RIOT Timer utilities include file.
; Filename:     a2k6rtim.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-28 19:32
; Vesion:		1.1.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 RIOT Timer utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Common Timer Macros.
;------------------------------------------------------------------------------

; Initialise timer with count value, divide by 64, timer interrupt enabled.

.MACRO		TIM_INIT_CNT		cnt
			LDA					#cnt		; 2 cycles
			STA					WTIM64EI	; 4 cycles
.ENDMACRO



; Initialise timer with line count value, div by 64, timer interrupt enabled.

.macro		TIM_INIT_LINE		line
			.IF (CPU_HORIZ_CLKS*line/64) != (CPU_HORIZ_CLKS*line/64+8)
			.WARNING "Line count and time wait for interrupt may trigger on more than one line!"
			.ENDIF
			LDA					#(CPU_HORIZ_CLKS*line/64)
			STA					WTIM64EI
.ENDMACRO



; Wait for timer interrupt to occur. Uses Accummulator as temporary storage.

.MACRO		TIM_WAIT_INT
			.LOCAL				loop
loop:		LDA					RINTFLAG	; 4 cycles.
			BPL					loop		; 2 cycles+1 branch+1 cross page.
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


