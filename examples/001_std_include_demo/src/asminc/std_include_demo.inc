;==============================================================================
; Name:         Atari 2600 standard include demo.
; Filename:     std_include_demo.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-28 18:05
; Vesion:		1.0.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 - Standard Include Test
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------

		.CODE

run_demo:
		LDA				#COL_MAGENTA
		STA				COLUPF
firstframe:
		LDA				#VSYNC_ON
		STA				WSYNC
nextframe:
vsync:
		STA				VSYNC
		LDA				#COL_RED
		STA				COLUBK
		.REPEAT			VID_VSYNC_LINE-1
		STA				WSYNC
		.ENDREPEAT
		LDA				#VSYNC_OFF
		STA				WSYNC
vblank:
		STA				VSYNC
		.REPEAT			VID_VBLANK_LINE-1
		STA				WSYNC
		.ENDREPEAT
		LDA				#$00
		STA				WSYNC
visible_top:
		STA				VBLANK
		LDA				#COL_WHITE
		STA				COLUBK
		STA				WSYNC
visible_mid:
		LDA				#COL_YELLOW
		STA				COLUBK
		LDX				#VID_VVISIBLE_LINE-3
nextline:
		STX				COLUBK
		STX				PF1
		STX				PF0
		STX				PF2
		STA				WSYNC
		DEX
		BNE				nextline
visible_bot:
		LDA				#COL_WHITE
		STA				COLUBK
		LDA				#COL_BLUE
		STA				WSYNC
		STA				COLUBK
		LDA				#VBLANKF_ON
		STA				VBLANK
		STA				WSYNC
		.REPEAT			VID_OVERSCAN_LINE-1
		STA				WSYNC
		.ENDREPEAT
		LDA				#VSYNC_ON
		STA				WSYNC
		JMP				nextframe
		RTS



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


