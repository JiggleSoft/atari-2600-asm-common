; STATUS: WORK IN PROGRESS.
;==============================================================================
; Title:        Atari 2600 TIA Video display standard extra include file.
; Filename:     a2k6-stdx-tvid.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-23 21:18
; Version:      2.0.4
;------------------------------------------------------------------------------
; Copyright (c) 2020 Justin Lane
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.
;------------------------------------------------------------------------------

                .IFNDEF     __A2K6_STDX_TVID__INC__
                            __A2K6_STDX_TVID__INC__ = 1

;==============================================================================
; Atari 2600 TIA Video display.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; FIXME: Impl.
;------------------------------------------------------------------------------

; TODO: Impl.

;------------------------------------------------------------------------------
; Horizontal Sync
;------------------------------------------------------------------------------

;  Pause CPU until the start of the horizontal sync.

.MACRO		VID_HSYNC
			STA			WSYNC
.ENDMACRO



; Repeat horizontal sync instruction for specified number of horizontal lines.

.MACRO		VID_HSYNC_REP	hlines
			.REPEAT			hlines
			VID_HSYNC
			.ENDREPEAT
.ENDMACRO



; Loop horizontal sync for register specified number of horizontal lines.
; Note: Minimum of one one line: 1 thru 255 lines, and 0 = 256 lines.
;       Exits two instructions after horizontal sync wait (DEC/X/Y&BNE)!
;		WDB = Wait, Decrement, Branch.

.MACRO		VID_HSYNC_R_WDB	reg	; reg = A, X, or Y.
			.LOCAL			loop
loop:
			VID_HSYNC
			.IF				reg = 'A'
			DEC
			.ELSEIF			reg = 'X'
			DEX
			.ELSEIF			reg = 'Y'
			DEY
			.ELSE
			.ERROR			"VID_HSYNC_R_WDB: reg must be 'A', 'X', or 'Y'!"
			.ENDIF
			BNE				loop
.ENDMACRO



; Loop horizontal sync for register specified number of horizontal lines.
; Note: Minimum of one one line: 1 thru 255 lines, and 0 = 256 lines.
;       Required extra DEC/X/Y instrution at start and exists immediately after horizontal sync wait.
;       WDB2 = Decrement, Branch, then Wait, Decrement, Branch, then Wait.

.MACRO		VID_HSYNC_R_DBWDBW	reg	; reg = A, X, or Y.
			.LOCAL			exitloop
			.IF				reg = 'A'
			DEC
			.ELSEIF			reg = 'X'
			DEX
			.ELSEIF			reg = 'Y'
			DEY
			.ELSE
			.ERROR			"VID_HSYNC_R_DBWDBW: reg must be 'A', 'X', or 'Y'!"
			.ENDIF
			BEQ				exitloop
			VID_HSYNC_R_WDB	reg
exitloop:
			VID_HSYNC
.ENDMACRO



; Loop horizontal sync for register specified number of horizontal lines.
;       Required exra DEC/X/Y&BEQ, and possibly extra DEC/X/Y instrution
;       at start and exists immediately after horizontal sync wait.

.MACRO		VID_HSYNC_REG		reg	; reg = A, X, or Y.
			.LOCAL			exitwait
			.IF				reg = 'A'
			CMP				#$00
			.ELSEIF			reg = 'X'
			CPX				#$00
			.ELSEIF			reg = 'Y'
			CPY				#$00
			.ELSE
			.ERROR			"VID_HSYNC_REG_3: reg must be 'A', 'X', or 'Y'!"
			.ENDIF
			BEQ				exitwait
			VID_HSYNC_REG_DBW2
exitwait:
.ENDMACRO



; Wait on horizontal sync for specified number of horizontal lines optimised.

.MACRO		VID_HSYNC_L_R	hlines,reg
			.IF				hlines <> 0
			.IF				hlines = 1
			VID_HSYNC
			.ELSE
			.IF				reg = 'A'
			LDA				#(hlines-1)
			.ELSEIF			reg = 'X'
			LDX				#(hlines-1)
			.ELSEIF			reg = 'Y'
			LDY				#(hlines-1)
			.ELSE
			.ERROR			"VID_HSYNC_L_R_2: reg must be 'A', 'X', or 'Y'!"
			.ENDIF
			VID_HSYNC_REG_WDB	reg
			VID_HSYNC
			.ENDIF
			.ENDIF
.ENDMACRO


; Wait on horizontal sync for specified number of horizontal lines optimised.

.MACRO		VID_HSYNC_L_R_OPT	hlines,reg
			.IF				hlines <> 0
			.IF				hlines = 1
			VID_HSYNC
			.ELSEIF			hlines < 5
			VID_HSYNC_REPEAT	hlines
			.ELSE
			.IF				reg = 'A'
			LDA				#(hlines-1)
			.ELSEIF			reg = 'X'
			LDX				#(hlines-1)
			.ELSEIF			reg = 'Y'
			LDY				#(hlines-1)
			.ELSE
			.ERROR			"VID_HSYNC_L_R_2: reg must be 'A', 'X', or 'Y'!"
			.ENDIF
			VID_HSYNC_REG_WDB	reg
			VID_HSYNC
			.ENDIF
			.ENDIF
.ENDMACRO






; Block CPU until specified number of horizontal syncs have occured.

.MACRO		VID_WAIT_HSYNC_LINES	hlines
			.LOCAL		loop
			.IF			hlines > 0
			.IF			hlines > 3
			LDX			#(hlines-1)
loop:		VID_HSYNC
			DEX
			BNE			loop
			VID_HSYNC
			.ELSE
			.REPEAT		hlines
			VID_HSYNC
			.ENDREPEAT
			.ENDIF
			.ELSE
			.WARNING	"HSYNC hlines should be > 0 !"
			.ENDIF
.ENDMACRO



;------------------------------------------------------------------------------
; Vertical Sync
;------------------------------------------------------------------------------
;REVIEW: !!!!!!!!!!!!!!!!!!!!!
; Vertical Sync for Horizontal Lines Specified minus 1 on with 1 off.

.MACRO		VID_VSYNC_HL	hlines
.LOCAL		loop
			;.IF			(hlines-1) > 0
			LDA			#VSYNC_ON
			STA			VSYNC
	;		.IF			(hlines-1) > 3
			LDX			#(hlines-2)
			LDA			#VSYNC_OFF
loop:		VID_HSYNC
			DEX
			BNE			loop
	;		.ELSE
			VID_HSYNC
			LDA			#VSYNC_OFF
;		VID_HSYNC
	;		.ENDIF
			STA			VSYNC
			VID_HSYNC
			;.ELSE
			;.ERROR		"VSYNC hlines must be >= 2 !"
			;.ENDIF
.ENDMACRO



; Vertical Sync for Platform Horizontal Lines (usually 2 on, 1 off).

.MACRO		VID_VSYNC
			VID_VSYNC_HL		VID_VSYNC_LINE
.ENDMACRO



;------------------------------------------------------------------------------
; Vertical Blank
;------------------------------------------------------------------------------
;REVIEW: !!!!!!!!!!!!!!!!!!!!!

; Vertical Blank

.MACRO		VID_VBLANK	ENABLE,DUMPI0123,LATCHI4I5
.ENDMACRO


.MACRO		VID_VBLANKz

.ENDMACRO
;FIXME DUMP and LATCH are part of VBLANK !!!! disable video.
; Vertical Sync (ENABLE=1 to start, 0 to finish), DUMPI0123=0|1, LATCHI4I5=0|1.

.MACRO		VID_VSYNC_EDL	ENABLE,DUMPI0123,LATCHI4I5
			.IF			ENABLE = 0
			.IF			DUMPI0123 = 0
			.IF			LATCHI4I5 = 0
						LDA			#$00
			.ELSE
						LDA			#LATCHI4I5_MASK
			.ENDIF
			.ELSE
			.IF			LATCHI4I5 = 0
						LDA			#(DUMPI0123_MASK|LATCHI4I5_MASK)
			.ELSE
						LDA			#DUMPI0123_MASK
			.ENDIF
			.ENDIF
			.ELSE
			.IF			DUMPI0123 = 0
			.IF			LATCHI4I5 = 0
						LDA			#VBLNKSTRT_MASK
			.ELSE
						LDA			#(VBLNKSTRT_MASK|LATCHI4I5_MASK)
			.ENDIF
			.ELSE
			.IF			LATCHI4I5 = 0
						LDA			#(VBLNKSTRT_MASK|DUMPI0123_MASK|LATCHI4I5_MASK)
			.ELSE
						LDA			#(VBLNKSTRT_MASK|DUMPI0123_MASK)
			.ENDIF
			.ENDIF
			.ENDIF
			STA			VSYNC
.ENDMACRO


;.MACRO		VID_VSYNC
;			VID_VSYNC_EDL	1,0,0
;			STA				WSYNC
;			STA				WSYNC
;			VID_VSYNC_EDL	0,0,0
;			STA				WSYNC
;.ENDMACRO



; Vertical Blank for Platform Horizontal Lines (usually 37 for NTSC, 45 for PAL).

.MACRO		VID_BLANK
			VID_VBLANK_HL		VID_VBLANK_LCNT
.ENDMACRO



;------------------------------------------------------------------------------
; Vertical Visible
;------------------------------------------------------------------------------
;REVIEW: !!!!!!!!!!!!!!!!!!!!!

; Test Display

.MACRO		VID_DISPLAY_TESTCARD
 lda #$00
 sta ENABL       ; Turn off sprites: ball, missiles and players
 sta ENAM0
 sta ENAM1
 sta GRP0
 sta GRP1
 lda #$50
 sta COLUBK      ; Background colour (green)
 lda #$00
 sta PF0         ; PF0 and PF2 will be "off" - changed mind.
 sta PF2
 lda #$D0        ; Playfield colour (sort of blue	)
 sta COLUPF
 lda #$01        ; Mirror Playfield#
 sta CTRLPF

 .REPEAT 37
  STA WSYNC
  .ENDREPEAT
  LDA #77
  STA COLUBK





			.LOCAL		loop
			LDX			#VID_VVISIBLE_LCNT
 txa
loop:
 STX	PF1

 STX	PF0
 STX	PF2

 STA COLUBK      ; Background colour


			DEX
			ADC #02
			;DEC
			STA			WSYNC
			BNE			loop


			 LDA #37
			 STA COLUBK
							.REPEAT 30
			 STA WSYNC
			 .ENDREPEAT
.ENDMACRO



;------------------------------------------------------------------------------
; Vertical Overscan
;------------------------------------------------------------------------------

;REVIEW
; MAKE GENERIC FUNC  FIXME

.MACRO		VID_OVERSCAN_HL	hlines
			VID_VBLANK	0,
			VID_HSYNC	VID_OVERSCAN_LCNT
.ENDMACRO



; Overscan for Platform Horizontal Lines (usually 34 for NTSC, 41 for PAL).

.MACRO		VID_OVERSCAN
			VID_OVERSCAN_HL	VID_OVERSCAN_LCNT
.ENDMACRO

;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------

                .ENDIF


