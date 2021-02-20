;==============================================================================
; Name:         Atari 2600 standard include test.
; Filename:     a2k6_kernel_pf0_test.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-11 18:30
; Vesion:		0.3.0
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

std_test:
		nextframe:
		JMP				nextframe
		RTS



;------------------------------------------------------------------------------
; Platform Specific Build Configuration.
;------------------------------------------------------------------------------

; Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).

		.ASSERT		TIA_HORIZ_CLKS		=	228, error
		.ASSERT		TIA_HBLANK_CLKS		=	 68, error
		.ASSERT		TIA_HVISIBLE_CLKS	=	160, error
		.ASSERT		CPU_HORIZ_CLKS		=	 76, error
		.ASSERT		CPU_HBLANK_CLKS		=	 23, error
		.ASSERT		CPU_HVISIBLE_CLKS	=	 53, error
		.ASSERT		VID_WIDTH			=	160, error
		.ASSERT		COL_BLACK			=	$00, error
		.ASSERT		COL_BLUE			=	$92, error
		.ASSERT		COL_RED				=	$44, error
		.ASSERT		COL_MAGENTA			=	$66, error
		.ASSERT		COL_GREEN			=	$78, error
		.ASSERT		COL_CYAN			=	$9A, error
		.ASSERT		COL_YELLOW			=	$2C, error
		.ASSERT		COL_WHITE			=	$0E, error
		.IF		.DEFINED(PLATFORM_PAL)
		.ASSERT		TIA_FREQ			=	3556800, error
		.ASSERT		TIA_FRAME_CLKS		=	  71136, error
		.ASSERT		TIA_VSYNC_CLKS		=	    684, error
		.ASSERT		TIA_VBLANK_CLKS		=	  10260, error
		.ASSERT		TIA_VVISIBLE_CLKS	=	  51984, error
		.ASSERT		TIA_OVERSCAN_CLKS	= 	   8208, error
		.ASSERT		CPU_FREQ			=	1185600, error
		.ASSERT		CPU_FRAME_CLKS		=	  23712, error
		.ASSERT		CPU_VSYNC_CLKS		=	    228, error
		.ASSERT		CPU_VBLANK_CLKS		=	   3420, error
		.ASSERT		CPU_VVISIBLE_CLKS	=	  17328, error
		.ASSERT		CPU_OVERSCAN_CLKS	=	   2736, error
		.ASSERT		VID_FREQ			=	     50, error
		.ASSERT		VID_FRAME_LINE		=	    312, error
		.ASSERT		VID_VSYNC_LINE		=	      3, error
		.ASSERT		VID_VBLANK_LINE		=	     45, error
		.ASSERT		VID_VVISIBLE_LINE	=	    228, error
		.ASSERT		VID_OVERSCAN_LINE	=	     36, error
		.ASSERT		VID_HEIGHT			=	    228, error
		.ELSEIF		.DEFINED(PLATFORM_NTSC)
		.ASSERT		TIA_FREQ			=	3584160, error
		.ASSERT		TIA_FRAME_CLKS		=	  59736, error
		.ASSERT		TIA_VSYNC_CLKS		=	    684, error
		.ASSERT		TIA_VBLANK_CLKS		=	   8436, error
		.ASSERT		TIA_VVISIBLE_CLKS	=	  43776, error
		.ASSERT		TIA_OVERSCAN_CLKS	= 	   6840, error
		.ASSERT		CPU_FREQ			=	1194720, error
		.ASSERT		CPU_FRAME_CLKS		=	  19912, error
		.ASSERT		CPU_VSYNC_CLKS		=	    228, error
		.ASSERT		CPU_VBLANK_CLKS		=	   2812, error
		.ASSERT		CPU_VVISIBLE_CLKS	=	  14592, error
		.ASSERT		CPU_OVERSCAN_CLKS	=	   2280, error
		.ASSERT		VID_FREQ			=	     60, error
		.ASSERT		VID_FRAME_LINE		=	    262, error
		.ASSERT		VID_VSYNC_LINE		=	      3, error
		.ASSERT		VID_VBLANK_LINE		=	     37, error
		.ASSERT		VID_VVISIBLE_LINE	=	    192, error
		.ASSERT		VID_OVERSCAN_LINE	=	     30, error
		.ASSERT		VID_HEIGHT			=	    192, error
		.ELSEIF		.DEFINED(PLATFORM_SECAM)
		.ASSERT		TIA_FREQ			=	3556800, error
		.ASSERT		TIA_FRAME_CLKS		=	  71136, error
		.ASSERT		TIA_VSYNC_CLKS		=	    684, error
		.ASSERT		TIA_VBLANK_CLKS		=	  10260, error
		.ASSERT		TIA_VVISIBLE_CLKS	=	  51984, error
		.ASSERT		TIA_OVERSCAN_CLKS	= 	   8208, error
		.ASSERT		CPU_FREQ			=	1185600, error
		.ASSERT		CPU_FRAME_CLKS		=	  23712, error
		.ASSERT		CPU_VSYNC_CLKS		=	    228, error
		.ASSERT		CPU_VBLANK_CLKS		=	   3420, error
		.ASSERT		CPU_VVISIBLE_CLKS	=	  17328, error
		.ASSERT		CPU_OVERSCAN_CLKS	=	   2736, error
		.ASSERT		VID_FREQ			=	     50, error
		.ASSERT		VID_FRAME_LINE		=	    312, error
		.ASSERT		VID_VSYNC_LINE		=	      3, error
		.ASSERT		VID_VBLANK_LINE		=	     45, error
		.ASSERT		VID_VVISIBLE_LINE	=	    228, error
		.ASSERT		VID_OVERSCAN_LINE	=	     36, error
		.ASSERT		VID_HEIGHT			=	    228, error
		.ELSE
		.ERROR		"Platform must be one of PAL, NTSC, or SECAM!"
		.ENDIF

		.RODATA

		; TIA
		.BYTE		TIA_HORIZ_CLKS		; TIA clocks per horizontal line.
		.BYTE		TIA_HBLANK_CLKS		; TIA clocks for the HBLANK.
		.BYTE		TIA_HVISIBLE_CLKS	; TIA clocks for the visible line.

		; CPU
		.BYTE		CPU_HORIZ_CLKS		; TIA_HORIZ_CLKS / 3
		.BYTE		CPU_HBLANK_CLKS		; TIA_HBLANK_CLKS / 3 (22.66 round up).
		.BYTE		CPU_HVISIBLE_CLKS	; TIA_HVISIBLE_CLKS / 3 (53.33 round down).

		; Video Display
		.BYTE		VID_WIDTH				; Same as TIA_HVISIBLE_CLKS.

		; Colours (portable approximations for PAL, NTSC, SECAM).
		; Note: brightness increases from dark to light for B&W mode.
		.BYTE		COL_BLACK
		.BYTE		COL_BLUE
		.BYTE		COL_RED
		.BYTE		COL_MAGENTA
		.BYTE		COL_GREEN
		.BYTE		COL_CYAN
		.BYTE		COL_YELLOW
		.BYTE		COL_WHITE


		; TIA
		.DWORD		TIA_FREQ			; TIA clock frequency (based on VID_FREQ).
		.DWORD		TIA_FRAME_CLKS		; TIA clocks for the whole frame.
		.DWORD		TIA_VSYNC_CLKS		; TIA clocks for the VSYNC.
		.DWORD		TIA_VBLANK_CLKS		; TIA clocks for the VBLANK.
		.DWORD		TIA_VVISIBLE_CLKS	; TIA clocks for the VVISIBLE display.
		.DWORD		TIA_OVERSCAN_CLKS	; TIA clocks for the OVERSCAN.
		; CPU
		.DWORD		CPU_FREQ			; CPU clock frequency (TIA_FREQ / 3).
		.DWORD		CPU_FRAME_CLKS		; CPU clocks for the whole frame.
		.DWORD		CPU_VSYNC_CLKS		; CPU clocks for the VSYNC.
		.DWORD		CPU_VBLANK_CLKS		; CPU clocks for the VBLANK.
		.DWORD		CPU_VVISIBLE_CLKS	; CPU clocks for the VVISIBLE display.
		.DWORD		CPU_OVERSCAN_CLKS	; CPU clocks for the OVERSCAN.
		; Video Display
		.BYTE		VID_FREQ			; Frequency of the whole frame.
		.WORD		VID_FRAME_LINE		; Video display lines for the whole frame.
		.BYTE		VID_VSYNC_LINE		; Video display lines for the VSYNC.
		.BYTE		VID_VBLANK_LINE		; Video display lines for the VBLANK.
		.BYTE		VID_VVISIBLE_LINE	; Video display lines for the VVISIBLE.
		.BYTE		VID_OVERSCAN_LINE	; Video display lines for the OVERSCAN.
		.BYTE		VID_HEIGHT			; Same as VID_VVISIBLE_LINE.





;------------------------------------------------------------------------------
; Hardware (RIOT) RAM and (RIOT, TIA) Registers.
;------------------------------------------------------------------------------

; Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.

;REVIEW: Anything required here?


; Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio)

;REVIEW: Anything required here?



;------------------------------------------------------------------------------
; Hardware (CPU, RIOT, TIA) Initialisation.
;------------------------------------------------------------------------------

; Atari 2600 Initialisation of Hardware following Power-up/Reset.

; CPU

cpuintdecinit:	CPU_INTDEC_INIT
				NOP
				NOP
cpustackinit:	CPU_STACK_INIT
				NOP
				NOP
cpuinit:		CPU_INIT
				NOP
				NOP
;cpuresetvec:	CPU_RESET_VEC	$1234
				NOP
				NOP
;cpuintresvec:	CPU_INTRES_VEC	$1234,$5678,$9ABC
				NOP
				NOP

; RIOT + TIA

riotraminit:	RIOT_RAM_INIT
					NOP
				NOP
tiareginit:		TIA_REG_INIT
				NOP
				NOP
riotramtiareginit:	RIOT_RAM_TIA_REG_INIT
				NOP
				NOP
riotioreginit:	RIOT_IO_REG_INIT
				NOP
				NOP
riotedctimreginit:	RIOT_EDC_TIM_REG_INIT
				NOP
				NOP
riotreginit:	RIOT_REG_INIT



;------------------------------------------------------------------------------
; Cold and Warm initialisation.
;------------------------------------------------------------------------------

a2k6coldinit:	A2K6_COLD_INIT
				NOP
				NOP
a2k6warminit:	A2K6_WARM_INIT
				NOP
				NOP



		.RODATA



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


