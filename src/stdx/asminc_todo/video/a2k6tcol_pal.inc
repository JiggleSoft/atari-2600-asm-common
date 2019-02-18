;==============================================================================
; Name:         Atari 2600 TIA Colour utilities PAL include file.
; Filename:     a2k6tcol_pal.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-10-14 23:41
; Vesion:		0.3.0
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 TIA Colour utilities PAL.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Atari 2600 Colour and Luminance to and from RGB conversion.
;------------------------------------------------------------------------------

; Colour and Luminance to RGB.

.MACRO		COLU_TO_RGB		colu,dest
			.IF		(colu&$FE) = $00
			coluval =
			.ELSEIF	colu = $02
			.ELSE
			.ERROR	"COLU_TO_RGB colu must be between 0 and 255!"
			.ENDIF
			.IF		dest = 'A'
			LDA		#coluval
			.ELSEIF	dest = 'X'
			LDX		#coluval
			.ELSEIF	dest = 'Y'
			LDY		#coluval
			.ELSEIF dest = 'M'
			.BYTE	coluval
			.ELSE
			.ERROR	"COLU_TO_RGB dest must be one of 'A', 'X', 'Y', or 'M'!"
			.ENDIF
.ENDMACRO


; RGB to Colour and Luminance value.

.MACRO		RGB_TO_COLU		r,g,b
			.IF		(colu&$FE) = $00
			coluval =
			.ELSEIF	colu = $02
			.ELSE
			.ERROR	"COLU_TO_RGB colu must be between 0 and 255!"
			.ENDIF
			.IF		dest = 'A'
			LDA		#coluval
			.ELSEIF	dest = 'X'
			LDX		#coluval
			.ELSEIF	dest = 'Y'
			LDY		#coluval
			.ELSEIF dest = 'M'
			.BYTE	coluval
			.ELSE
			.ERROR	"COLU_TO_RGB dest must be one of 'A', 'X', 'Y', or 'M'!"
			.ENDIF
.ENDMACRO


.IFDEF		PLATFORM_PAL
.ELSEIFDEF	PLATFORM_NTSC
.ELSEIFDEF	PLATFORM_SECAM
.ELSEIFDEF	PLATFORM_CUSTOM

.ENDIF

; TODO: Impl.
; REVIEW: Is this include file requried?

;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------



