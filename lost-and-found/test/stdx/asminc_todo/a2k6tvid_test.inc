;==============================================================================
; Name:         Atari 2600 TIA Video display utilities test include file.
; Filename:     a2k6tvid_test.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-07 18:14
; Vesion:		0.2.0
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 TIA Video display utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Horizontal Sync
;------------------------------------------------------------------------------

				.CODE

	STA WSYNC

vidhsync:		VID_HSYNC

				NOP
				NOP

vidhsyncrep:	VID_HSYNC_REP	5

				NOP
				NOP

;vidhsyncrwdbA:	VID_HSYNC_R_WDB	'A'

				NOP
				NOP

;vidhsyncrwdbX:	VID_HSYNC_R_WDB	X

				NOP
				NOP

;vidhsyncrwdbY:	VID_HSYNC_R_WDB	Y

				NOP
				NOP

;.MACRO		VID_HSYNC_R_DBWDBW	reg	; reg = A, X, or Y.


;.MACRO		VID_HSYNC_REG		reg	; reg = A, X, or Y.



;.MACRO		VID_HSYNC_L_R	hlines,reg

;.MACRO		VID_HSYNC_L_R_OPT	hlines,reg


;.MACRO		VID_WAIT_HSYNC_LINES	hlines

;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


