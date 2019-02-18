;==============================================================================
; Name:         Atari 2600 standard include file.
; Filename:     a2k6std.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-02-18 21:44
; Vesion:		1.0.2
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;						Creative Commons Attribution 4.0 International
;						http://creativecommons.org/licenses/by/4.0/
;						with an exception, see /LICENCE.txt file.
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


; Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio).

				.INCLUDE		"a2k6tia.inc"



;------------------------------------------------------------------------------
; Hardware (CPU, RIOT, TIA) Initialisation.
;------------------------------------------------------------------------------

; Atari 2600 Initialise Hardware following Power-up/Reset (CPU, RIOT, TIA).

				.INCLUDE		"a2k6init.inc"



;------------------------------------------------------------------------------


