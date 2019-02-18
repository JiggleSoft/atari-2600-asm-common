;==============================================================================
; Name:         Atari 2600 Power-up/Reset hardware initilisation include file.
; Filename:     a2k6init.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2018-12-16 20:47
; Licence:		This file is licensed under the following license:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Initialisation of Hardware following Power-up/Reset.
;==============================================================================

					.PUSHSEG

;------------------------------------------------------------------------------
; Central Processing Unit (CPU).
;------------------------------------------------------------------------------

; Initialise the CPU

.MACRO			CPU_INIT
				; Initialise CPU.
				CLD								; Clear decimal flag.
				CLC								; Clear carry flag.
.ENDMACRO



; Set the Interrupt and Reset Vectors to a single address.
; Note: fills the rest of the address space (4k)

.MACRO			CPU_RESET_VEC	RESET_VEC
				; Fills the rest of the address space (4K).
				.SEGMENT		"VECTORS"
				; Set the NMI, RESET, and IRQ vectors.
				.ADDR			RESET_VEC		; NMI (should never occur on 6507)
				.ADDR			RESET_VEC		; RESET
				.ADDR			RESET_VEC		; IRQ (only occur with BRK on 6507)
.ENDMACRO



; Set the Interrupt and Reset Vectors to three separate addresses.
; Note: fills the rest of the address space (4k)

.MACRO			CPU_INTRES_VEC	NMI_VEC,RESET_VEC,IRQ_VEC
				; Fills the rest of the address space (4K).
				.SEGMENT		"VECTORS"
				; Set the NMI, RESET, and IRQ vectors.
				.ADDR			NMI_VEC			; NMI (should never occur on 6507)
				.ADDR			RESET_VEC		; RESET
				.ADDR			IRQ_VEC			; IRQ (only occur with BRK on 6507)
.ENDMACRO



;------------------------------------------------------------------------------
; RIOT - RAM + TIA
;------------------------------------------------------------------------------

; Clear RAM (0x0080 - 0x00FF)

.MACRO			RAM_INIT
				; Clear RAM (0x0080 - 0x00FF)
				.LOCAL			ram_clr
				LDX				#$00
				LDA				#$00
ram_clr:
				STA				$80,X
				INX
				CPX				#$80
				BNE				ram_clr
.ENDMACRO



; Clear TIA (0x0000 - 0x007F).

.MACRO			TIA_INIT
				; Clear TIA (0x0000 - 0x007F).
				.LOCAL			tia_clr
				LDX				#$00
				LDA				#$00
tia_clr:
				STA				$00,X
				INX
				CPX				#$80
				BNE				tia_clr
.ENDMACRO



; Clear RAM (0x0080 - 0x00FF) and TIA (0x0000 - 0x007F).

.MACRO			RAM_TIA_INIT
				; Clear RAM (0x0080 - 0x00FF) and TIA (0x0000 - 0x007F).
				.LOCAL			ram_tia_clr
				LDX				#$00
				LDA				#$00
ram_tia_clr:
				STA				$80,X
				INX
				CPX				#$00
				BNE				ram_tia_clr
.ENDMACRO



;------------------------------------------------------------------------------
; RIOT - IO
;------------------------------------------------------------------------------

; Initialise IO

.MACRO			IO_INIT
				; Port B input.
				LDA				#00
				STA				SWBCNT
				; Port A input.
				STA				SWACNT
.ENDMACRO



;------------------------------------------------------------------------------
; RIOT - TIMER
;------------------------------------------------------------------------------

; Initialise timer.

.MACRO			TIMER_INIT
				; FIXME: ??? REQUIRED ???
.ENDMACRO



;==============================================================================
; TIA
;==============================================================================


;------------------------------------------------------------------------------
; VIDEO
;------------------------------------------------------------------------------

; Wait for (n) horizontal blanks.

.MACRO			VID_WAIT_HBLANK			NUM
				.IF				NUM <= 3
				.REPEAT			NUM
				STA				WSYNC
				.ENDREPEAT
				.ELSE
				LDY				#NUM
loop:					DEY
				BEQ	exit_loop
				STA				WSYNC
				JMP		loop
exit_loop:
				.ENDIF
.ENDMACRO



; Perform a vertical sync, thus starting a new frame.

.MACRO			VID_VSYNC
				LDA				#$02		; Vertical sync (VSYNC's bit = 1).
				STA				VSYNC
				VID_WAIT_HBLANK	3			; Vertical sync lasts 3 scanlines.
				;STA				
;WHY do this here?    lda #%00000010  ; Vertical sync is signaled by VSYNC's bit 1...
;    ;sta VSYNC
;    lda #0
;    sta VSYNC       ; Signal vertical sync by clearing the bit
				LDA				#$00		; End vertical sync (VSYNC's bit = 0).
				STA				VSYNC
.ENDMACRO



; Wait for vertical blank to complete.

.MACRO			VID_WAIT_VBLANK
				STA				WSYNC
.ENDMACRO



; Wait for overscan to complete.

.MACRO			VID_WAIT_OVERSCAN
				STA				WSYNC
.ENDMACRO



; Draw a test pattern for the visible display.

.MACRO			VID_TEST_PATTERN
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
 
 
 LDX #0
.REPEAT 092 ; 192
 STX	PF1
 
 STX	PF0
 STX	PF2
 
 INX
 STA WSYNC
.ENDREPEAT
				;LDA
				
 LDA #37
 STA COLUBK
				.REPEAT 30
 STA WSYNC
 .ENDREPEAT
  
.ENDMACRO





; migrate logic to VID_WAIT_HBLANK

.MACRO			VID_WAIT_HBLANKS
				STA				WSYNC
				
    .REPEAT 3        ; ...and lasts 3 scanlines
        sta WSYNC   ; (WSYNC write => wait for end of scanline)
    .ENDREPEAT
				; will inline with repear or loop as per size
.ENDMACRO



;------------------------------------------------------------------------------
; PLAYFIELD
;------------------------------------------------------------------------------

; Playfield 0 Bitmap data byte comma separated bits (bits 0-3)

.MACRO			PF0BMCSV		B0,B1,B2,B3
				.BYTE			(B0<<4)|(B1<<5)|(B2<<6)|(B3<<7)
.ENDMACRO



; Playfield 1 Bitmap data byte comma separated bits (bits 4-11)

.MACRO			PF1BMCSV		B4,B5,B6,B7,B8,B9,B10,B11
				.BYTE			(B4<<7)|(B5<<6)|(B6<<5)|(B7<<4)|(B8<<3)|(B9<<2)|(B10<<1)|(B11)
.ENDMACRO



; Playfield 2 Bitmap data byte comma separated bits (bits 12-19)

.MACRO			PF2BMCSV		B12,B13,B14,B15,B16,B17,B18,B19
				.BYTE			(B12)|(B13<<1)|(B14<<2)|(B15<<3)|(B16<<4)|(B17<<5)|(B18<<6)|(B19<<7)
.ENDMACRO



; Playfield 0, 1, 2 Bitmap 3 data bytes comma separated bits (bits 0-19)

.MACRO			PFBM3CSV		B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19
				PF0BMCSV		B0,B1,B2,B3
				PF1BMCSV		B4,B5,B6,B7,B8,B9,B10,B11
				PF2BMCSV		B12,B13,B14,B15,B16,B17,B18,B19
.ENDMACRO



; Playfield 0, 1, 2, 0, 1, 2 Bitmap 6 data bytes comma separated bits (bits 0-39)

.MACRO			PFBM6CSV		B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
				PF0BMCSV		B0,B1,B2,B3
				PF1BMCSV		B4,B5,B6,B7,B8,B9,B10,B11
				PF2BMCSV		B12,B13,B14,B15,B16,B17,B18,B19
				PF0BMCSV		B20,B21,B22,B23
				PF1BMCSV		B24,B25,B26,B27,B28,B29,B30,B31
				PF2BMCSV		B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO



; Playfield 0(left)+0(right), 1, 2, 1, 2 Bitmap 5 data bytes comma separated bits (bits 0-39)

.MACRO			PFBM5CSV		B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
				.BYTE			(B20)|(B21<<1)|(B22<<2)|(B23<<3)|(B0<<4)|(B1<<5)|(B2<<6)|(B3<<7)
				PF1BMCSV		B4,B5,B6,B7,B8,B9,B10,B11
				PF2BMCSV		B12,B13,B14,B15,B16,B17,B18,B19
				PF1BMCSV		B24,B25,B26,B27,B28,B29,B30,B31
				PF2BMCSV		B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO



; Playfield 0 Bitmap data byte value (bits 3-0)

.MACRO			PF0BMVAL		BV
				.BYTE			((BV&$08)<<1)|((BV&$04)<<3)|((BV&$02)<<5)|((BV&$01)<<7)
.ENDMACRO



; Playfield 1 Bitmap data byte value (bits 11-4)

.MACRO			PF1BMVAL		BV
				.BYTE			(BV&$FF)
.ENDMACRO



; Playfield 2 Bitmap data byte value (bits 19-12)

.MACRO			PF2BMVAL		BV
				.BYTE			((BV&$80)>>7)|((BV&$40)>>5)|((BV&$20)>>3)|((BV&$10)>>1)|((BV&$08)<<1)|((BV&$04)<<3)|((BV&$02)<<5)|((BV&$01)<<7)
.ENDMACRO



; Playfield 0, 1, 2 Bitmap 3 data bytes value (bits 19-0)

.MACRO			PFBM3VAL		BV
				PF0BMVAL		((BV&$000F0000)>>16)
				PF1BMVAL		((BV&$0000FF00)>>8)
				PF2BMVAL		(BV&$00000FF)
.ENDMACRO



; Playfield 0, 1, 2, 0, 1, 2 Bitmap 6 data bytes comma separated bits (bits 0-39)

.MACRO			PFBM6VAL		BVA,BVB
				PFBM3VAL		BVA
				PFBM3VAL		BVB
.ENDMACRO



; Playfield 0(left)+0(right), 1, 2, 1, 2 Bitmap 5 data bytes comma separated bits (bits 0-39)

.MACRO			PFBM5VAL		BVA,BVB
				.BYTE			((BVA&$00080000)>>15)|((BVA&$00040000)>>13)|((BVA&$00020000)>>11)|((BVA&$00010000)>>9)|((BVB&$00080000)>>19)|((BVB&$00040000)>>17)|((BVB&$00020000)>>15)|((BVB&$00010000)>>13)
				PF1BMVAL		((BVA&$0000FF00)>>8)
				PF2BMVAL		(BVA&$00000FF)
				PF1BMVAL		((BVB&$0000FF00)>>8)
				PF2BMVAL		(BVB&$00000FF)
.ENDMACRO



;==============================================================================
; RIOT
;==============================================================================


;------------------------------------------------------------------------------
; RAM
;------------------------------------------------------------------------------

; TODO



;------------------------------------------------------------------------------
; IO
;------------------------------------------------------------------------------

; TODO

; Port B - Console Switches (read only) Port B is hardwired to be an input port only that is read by addressing SWCHB (HEX 282) to determine the status of all the console switches according to the following table:
;Data Bit            Switch               Bit Meaning D7 P1 difficulty 0 = amateur (B), 1 = pro (A) D6 P0 difficulty   0 = amateur (B), 1 = pro (A) D5/D4 (not used) D3 color - B/W 0 = B/W, 1 = color D2 (not used) D1 game select 0 = switch pressed D0 game reset 0 = switch pressed

;IO_PB_P1_DIF_B		D7 = 0
;IO_PB_P1_DIF_A		D7 = 1
;IO_PB_P0_DIF_B		D6 = 0		
;IO_PB_P0_DIF_A		D6 = 1
;D4/D5 Unused
;IO_PB_COL_BW		D3 = 0 = BW, 1 = COLOUR
;D2 Unused
;= Game Select	D1 = 0 = Pressed, 1 = not pressed
;Game RESET		D0 = 0 = Pressed, 1 = not pressed



;------------------------------------------------------------------------------
; TIMER
;------------------------------------------------------------------------------

; Timer IRQ latch: 0 = disable, 1 = enable.

.MACRO			TIM_IRQEN		IRQEN
				.IF				IRQEN == 1
				STA				
				.ELSEIF			IRQEN == 0
				
				.ELSE
				.ERROR			"TIM_IRQEN IRQEN must either be 0 or 1!"
				.ENDIF
.ENDMACRO



; Add PA7 enable latch and edge control.
; Timer IRQ latch: 0 = disable, 1 = enable.

.MACRO			TIM_IRQEN_FIXME		IRQEN
				.IF				IRQEN == 1

				.ELSEIF			IRQEN == 0
				.ELSE
				.ERROR			"TIM_IRQEN IRQEN must either be 0 or 1!"
				.ENDIF
.ENDMACRO



; Timer set value and interval (1, 8, 64, or 1024)

.MACRO			TIM_START		VALUE, INTERVAL
				LDA				#VALUE
				.IF				INTERVAL == 1
				STA				TIM1T
				.ELSEIF			INTERVAL == 8
				STA				TIM8T
				.ELSEIF			INTERVAL == 64
				STA				TIM64T
				.ELSEIF			INTERVAL == 1024
				STA				TIM1024T
				.ELSE
				.ERROR			"TIM_START INTERVAL must be either 1, 8, 64, or 1024!"
				.ENDIF
				.ENDIF
.ENDMACRO



;------------------------------------------------------------------------------
; CONTROLLERS
;------------------------------------------------------------------------------

; Initialise for one or two joysticks.

.MACRO			JOY_INIT
				LDA				#$00
				STA				SWACNT
.ENDMACRO



;JOY_P0_RIGHT		D7 = 0 = pushed, 1 = not pushed
;JOY_P0_LEFT		D6 = 0 = pushed, 1 = not pushed
;JOY_P0_DOWN		D5 = 0 = pushed, 1 = not pushed
;JOY_P0_UP		D4 = 0 = pushed, 1 = not pushed
;
;JOY_P1_RIGHT		D3 = 0 = pushed, 1 = not pushed
;JOY_P1_LEFT		D2 = 0 = pushed, 1 = not pushed
;JOY_P1_DOWN		D1 = 0 = pushed, 1 = not pushed
;JOY_P1_UP		D0 = 0 = pushed, 1 = not pushed


; Read Joystick state

.MACRO			JOY_READ
				LDA				SWCHA
;				STA				RAM??!?!?!?
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


