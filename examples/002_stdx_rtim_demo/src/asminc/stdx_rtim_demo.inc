;==============================================================================
; Name:         Atari 2600 standard extra RIOT timer include demo.
; Filename:     stdx_rtim_demo.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-02-18 21:44
; Vesion:		1.0.1
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;						Creative Commons Attribution 4.0 International
;						http://creativecommons.org/licenses/by/4.0/
;						with an exception, see /LICENCE.txt file.
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 - Standard Include Test
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------

		.CODE

run_demo:
		LDY				#$00
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

		TIM_INIT_LINE	VID_VBLANK_LINE-1
		TIM_WAIT_INT
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC
		STA				WSYNC

		;.REPEAT			VID_VBLANK_LINE-1
		;STA				WSYNC
		;.ENDREPEAT

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
		STY				COLUBK
		STX				PF1
		STX				PF0
		STX				PF2
		STA				WSYNC
		DEY
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


