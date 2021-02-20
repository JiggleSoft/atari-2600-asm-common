;==============================================================================
; Name:         Atari 2600 utilities test include file.
; Filename:     a2k6util_test.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2018-12-30 21:29
; Vesion:		0.2.5
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------

		.PUSHSEG

;------------------------------------------------------------------------------

			.DATA

nullz:		.BYTE				NULL				; Must be $00
falsez:		.BYTE				FALSE				; Must be $00
truez:		.BYTE				TRUE				; Must be $FF

zero:		.BYTE				_					; Must be $00
one:		.BYTE				B					; Must be $01

b70csv:		BYTE_7_0_CSV		1,0,1,1,1,1,0,0		; Must be $BC
b07csv:		BYTE_0_7_CSV		1,0,1,1,1,1,0,0		; Must be $3D
bval:		BYTE_VAL			$BC					; Must be $BC
b70val:		BYTE_7_0_VAL		$BC					; Must be $BC
b07val:		BYTE_0_7_VAL		$BC					; Must be $3D


b30fcsv:	BYTE_3_0_F_CSV		1,0,1,1,1			; Must be $FB
b03fcsv:	BYTE_0_3_F_CSV		1,0,1,1,1			; Must be $FD
b74fcsv:	BYTE_7_4_F_CSV		1,0,1,1,1			; Must be $BF
b47fcsv:	BYTE_4_7_F_CSV		1,0,1,1,1			; Must be $DF

b30csv:		BYTE_3_0_CSV		1,0,1,1				; Must be $0B
b03csv:		BYTE_0_3_CSV		1,0,1,1				; Must be $0D
b74csv:		BYTE_7_4_CSV		1,0,1,1				; Must be $B0
b47csv:		BYTE_4_7_CSV		1,0,1,1				; Must be $D0


b30fval:	BYTE_3_0_F_VAL		$B,1				; Must be $FB
b03fval:	BYTE_0_3_F_VAL		$B,1				; Must be $FD
b74fval:	BYTE_7_4_F_VAL		$B,1				; Must be $BF
b47fval:	BYTE_4_7_F_VAL		$B,1				; Must be $DF

b30val:		BYTE_3_0_VAL		$B					; Must be $0B
b03val:		BYTE_0_3_VAL		$B					; Must be $0D
b74val:		BYTE_7_4_VAL		$B					; Must be $B0
b47val:		BYTE_4_7_VAL		$B					; Must be $D0

b4703csv:	BYTE_4_7_0_3_CSV	1,0,1,1,1,1,0,0		; Must be $D3

bhlval:		BYTE_H_L_VAL		$B,$C				; Must be $BC
b7430val:	BYTE_7_4_3_0_VAL	$B,$C				; Must be $BC
b4703val:	BYTE_4_7_0_3_VAL	$B,$C				; Must be $D3

;------------------------------------------------------------------------------

		.POPSEG

;------------------------------------------------------------------------------


