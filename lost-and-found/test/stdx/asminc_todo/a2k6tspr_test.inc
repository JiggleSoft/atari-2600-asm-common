;==============================================================================
; Name:         Atari 2600 TIA Sprite utilities test include file.
; Filename:     a2k6tspr.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2018-12-30 12:02
; Vesion:		0.2.4
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 TIA Sprite utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Sprite Data Description Macros.
;------------------------------------------------------------------------------

			.DATA

sprcsv1:	SPR_CSV		1,0,1,1,1,1,0,0	; Must be $BC
sprcsv2:	SPR_CSV		0,1,0,0,0,0,1,1 ; Must be $43

sprval1:	SPR_VAL		$BC				; Must be $BC
sprval2:	SPR_VAL		$43				; Must be $43



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


