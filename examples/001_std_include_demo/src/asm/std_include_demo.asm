;==============================================================================
; Name:         Standard Include Demo.
; Filename:     std_include_demo.asm
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-28 18:02
; Vesion:		1.0.1
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Standard Include Demo.
;==============================================================================

				.OUT			"Standard Include Demo."

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
				; Run demo.
				JSR				run_demo
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

stdincdemo:		.INCLUDE		"std_include_demo.inc"

;------------------------------------------------------------------------------

				.CODE

				CPU_RESET_VEC	startup

;------------------------------------------------------------------------------


