;==============================================================================
; Name:         Test Standard Includes.
; Filename:     teststd.asm
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (escapemcp@jigglesoft.co.uk)
; Date:         2019-01-08 21:24
; Vesion:		0.3.2
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 	CC Attribution-NonCommercial-ShareAlike 4.0 CC BY-NC-SA
;					http://creativecommons.org/licenses/by-nc-sa/4.0/license
;------------------------------------------------------------------------------


;==============================================================================
; Test Standard Includes.
;==============================================================================

				.OUT			"Test Standard Includes."

;------------------------------------------------------------------------------

				; Atari 2600 Standard Include.
				.INCLUDE		"a2k6std.inc"

;------------------------------------------------------------------------------

				.CODE

startup:
				A2K6_COLD_INIT
init:
				; Initialse application state.
				NOP
run:
				; Run test.
				JSR				run_test
main_loop:
				; Main loop.
				NOP
done:
				; Uninitialise state.
				NOP
shutdown:
				; Shutdown and halt.
				A2K6_WARM_INIT
endless:		JMP				endless



;------------------------------------------------------------------------------

run_test:
				JSR				std_test

;------------------------------------------------------------------------------

teststd:		.INCLUDE		"a2k6std_test.inc"

;------------------------------------------------------------------------------

				.CODE

				CPU_RESET_VEC	startup

;------------------------------------------------------------------------------


