;==============================================================================
; Name:         Atari 2600 TIA Sprite utilities include file.
; Filename:     a2k6tspr.inc
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
; Atari 2600 TIA Sprite utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Sprite Data Description Macros.
;------------------------------------------------------------------------------

; Sprite Bitmap data byte comma separated bits (bits 7-0)

.MACRO		SPR_CSV			B7,B6,B5,B4,B3,B2,B1,B0
			BYTE_7_0_CSV	B7,B6,B5,B4,B3,B2,B1,B0
.ENDMACRO



; Sprite Bitmap data byte value (bits 7-0)

.MACRO		SPR_VAL			BV
			BYTE_VAL		BV
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


