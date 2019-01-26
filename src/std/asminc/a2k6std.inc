;==============================================================================
; Name:         Atari 2600 standard include file.
; Filename:     a2k6std.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-12 14:27
; Vesion:		1.0.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Standard Include.
;==============================================================================

				.OUT		"Atari 2600 Standard Includes."

;------------------------------------------------------------------------------
; Platform Specific Build Configuration.
;------------------------------------------------------------------------------

; Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).

				.INCLUDE		"a2k6plat.inc"



;------------------------------------------------------------------------------
; Hardware (RIOT) RAM and (RIOT, TIA) Registers.
;------------------------------------------------------------------------------

; Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.

				.INCLUDE		"a2k6riot.inc"


; Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio)

				.INCLUDE		"a2k6tia.inc"



;------------------------------------------------------------------------------
; Hardware (CPU, RIOT, TIA) Initialisation.
;------------------------------------------------------------------------------

; Atari 2600 Initialisation of Hardware following Power-up/Reset.

				.INCLUDE		"a2k6init.inc"



;------------------------------------------------------------------------------


