;==============================================================================
; Name:         Atari 2600 standard extra include test.
; Filename:     a2k6_kernel_pf0_test.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-12 14:25
; Vesion:		0.3.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 - Standard Extra Include Test
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------

		.CODE

stdx_test:
		nextframe:
		JMP				nextframe
		RTS



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Expansion Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 Bank Switching utilities.

; F6

f6bank0sel:	F6_BANK_0_SEL
			NOP
			NOP
f6bank1sel:	F6_BANK_1_SEL
			NOP
			NOP
f6bank2sel:	F6_BANK_2_SEL
			NOP
			NOP
f6bank3sel:	F6_BANK_3_SEL
			NOP
			NOP
f6banksel0:	F6_BANK_SEL		0
			NOP
			NOP
f6banksel1:	F6_BANK_SEL		1
			NOP
			NOP
f6banksel2:	F6_BANK_SEL		2
			NOP
			NOP
f6banksel3:	F6_BANK_SEL		3
			NOP
			NOP

;FIXME: complete tests

;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


