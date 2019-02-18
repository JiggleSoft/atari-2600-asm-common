;==============================================================================
; Name:         Atari 2600 standard extra include file.
; Filename:     a2k6stdx.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-02-18 21:44
; Vesion:		1.1.1
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;						Creative Commons Attribution 4.0 International
;						http://creativecommons.org/licenses/by/4.0/
;						with an exception, see /LICENCE.txt file.
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Standard Extra Include.
;==============================================================================

			.OUT		"Atari 2600 Standard Extra Includes."

;------------------------------------------------------------------------------
; CPU Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 CPU utilities.
;FIXME:			.INCLUDE	"a2k6cpu.inc"	; REVIEW: Is this required?

;------------------------------------------------------------------------------
; Atari 2600 Utilities Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 utilities.
			.INCLUDE	"a2k6util.inc"

;------------------------------------------------------------------------------
; RIOT Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 RIOT RAM utilities.
;REVIEW;			.INCLUDE	"a2k6rram.inc"	; REVIEW: Is this required?

; Atari 2600 RIOT IO utilities.
;REVIEW;			.INCLUDE	"a2k6rio.inc"	; REVIEW: Is this required?

; Atari 2600 RIOT Timer utilities.
			.INCLUDE	"a2k6rtim.inc"

;------------------------------------------------------------------------------
; TIA Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 TIA IO utilities.
;REVIEW;			.INCLUDE	"a2k6tio.inc"	; REVIEW: Is this required?

; Atari 2600 TIA Audio utilities.
;REVIEW;			.INCLUDE	"a2k6taud.inc"	; REVIEW: Is this required?

; Atari 2600 TIA Colour utilities.
;REVIEW;			.INCLUDE	"a2k6tcol.inc"	; REVIEW: Is this required?

; Atari 2600 TIA Video display utilities.
;REVIEW;			.INCLUDE	"a2k6tvid.inc"	; FIXME: temporarily disabled as build failing!

; Atari 2600 TIA Playfield utilities.
			.INCLUDE	"a2k6tpf.inc"

; Atari 2600 TIA Sprite utilities.
			.INCLUDE	"a2k6tspr.inc"

;------------------------------------------------------------------------------
; Expansion Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 Bank Switching utilities.
			.INCLUDE	"a2k6bank.inc"

; Atari 2600 Expansion RAM utilities.
;REVIEW;			.INCLUDE	"a2k6xram.inc"	; REVIEW: Is this required?

;------------------------------------------------------------------------------
; Joystick and Controller Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 Common Joystick utilities.
;REVIEW:			.INCLUDE	"a2k6joy.inc"	; TODO: Impl.

; Atari 2600 Digital Joystick utilities.
;REVIEW:			.INCLUDE	"a2k6djoy.inc"	; TODO: Impl.

; Atari 2600 Analogue Joystick / Paddle utilities.
;REVIEW:			.INCLUDE	"a2k6ajoy.inc"	; TODO: Impl.

; Atari 2600 Driving Controller utilities.
;REVIEW:			.INCLUDE	"a2k6driv.inc"	; TODO: Impl.

; Atari 2600 Keyboard / Keypad utilities.
;REVIEW:			.INCLUDE	"a2k6keyb.inc"	; TODO: Impl.

; Atari 2600 Track Ball utilities.
;REVIEW:			.INCLUDE	"a2k6trak.inc"	; TODO: Impl.

; Atari 2600 Light Gun utilities.
;REVIEW:			.INCLUDE	"a2k6lgun.inc"	; TODO: Impl.

;------------------------------------------------------------------------------


