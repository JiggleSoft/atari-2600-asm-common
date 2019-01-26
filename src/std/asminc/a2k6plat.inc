;==============================================================================
; Name:         Atari 2600 platform specific include file.
; Filename:     a2k6plat.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-08 21:01
; Vesion:		1.0.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).
;==============================================================================


;------------------------------------------------------------------------------
; Platform Specific Build Configuration Validation.
;------------------------------------------------------------------------------

		.IFNDEF		PLATFORM_PAL
		.IFNDEF		PLATFORM_NTSC
		.IFNDEF		PLATFORM_SECAM
		.IFNDEF		PLATFORM_CUSTOM
		.ERROR		"One platform must be defined(PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
		.ENDIF
		.ENDIF
		.ENDIF
		.ENDIF

		.IFDEF		PLATFORM_PAL
		.IF			.DEFINED(PLATFORM_NTSC) || .DEFINED(PLATFORM_SECAM) || .DEFINED(PLATFORM_CUSTOM)
		.ERROR		"Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
		.ENDIF
		.OUT		"PLATFORM=PAL"
		.ENDIF
				
		.IFDEF		PLATFORM_NTSC
		.IF			.DEFINED(PLATFORM_PAL) || .DEFINED(PLATFORM_SECAM) || .DEFINED(PLATFORM_CUSTOM)
		.ERROR		"Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
		.ENDIF
		.OUT		"PLATFORM=NTSC"
		.ENDIF
				
		.IFDEF		PLATFORM_SECAM
		.IF			.DEFINED(PLATFORM_PAL) || .DEFINED(PLATFORM_NTSC) || .DEFINED(PLATFORM_CUSTOM)
		.ERROR		"Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
		.ENDIF
		.OUT		"PLATFORM=SECAM"
		.ENDIF
				
		.IFDEF		PLATFORM_CUSTOM
		.IF			.DEFINED(PLATFORM_PAL) || .DEFINED(PLATFORM_NTSC) || .DEFINED(PLATFORM_SECAM)
		.ERROR		"Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
		.ENDIF
		.OUT		"PLATFORM=CUSTOM"
		.ENDIF
	


;------------------------------------------------------------------------------
; Common Build Configuration for TIA, CPU, Video, and Colours.
;------------------------------------------------------------------------------
								
		; TIA
		TIA_HORIZ_CLKS    = 228	; TIA clocks per horizontal line.
		TIA_HBLANK_CLKS   =  68 ; TIA clocks for the HBLANK.
		TIA_HVISIBLE_CLKS = 160 ; TIA clocks for the visible line.
				
		; CPU
		CPU_HORIZ_CLKS    =  76	; TIA_HORIZ_CLKS / 3
		CPU_HBLANK_CLKS   =  23	; TIA_HBLANK_CLKS / 3 (22.66 round up).
		CPU_HVISIBLE_CLKS =  53	; TIA_HVISIBLE_CLKS / 3 (53.33 round down).

		; Video Display
		VID_WIDTH         = 160	; Same as TIA_HVISIBLE_CLKS.

		; Colours (portable approximations for PAL, NTSC, SECAM).
		; Note: brightness increases from dark to light for B&W mode.
		COL_BLACK       = $00
		COL_BLUE        = $92
		COL_RED         = $44
		COL_MAGENTA     = $66
		COL_GREEN       = $78
		COL_CYAN        = $9A
		COL_YELLOW      = $2C
		COL_WHITE       = $0E



;------------------------------------------------------------------------------
; Custom Platform Build Configuration for TIA, CPU, Video (PLATFORM_CUSTOM).
;------------------------------------------------------------------------------

; PLATFORM_CUSTOM TEMPLATE TO BE COPIED TO YOUR CODE AND EDITED AS REQUIRED.

;		.IFDEF			PLATFORM_CUSTOM
;		TIA_FREQ          = 	; TIA clock frequency (based on VID_FREQ).
;		TIA_FRAME_CLKS    = 	; TIA clocks for the whole frame.
;		TIA_VSYNC_CLKS    = 	; TIA clocks for the VSYNC.
;		TIA_VBLANK_CLKS   = 	; TIA clocks for the VBLANK.
;		TIA_VVISIBLE_CLKS = 	; TIA clocks for the VVISIBLE display.
;		TIA_OVERSCAN_CLKS =  	; TIA clocks for the OVERSCAN.
;		; CPU
;		CPU_FREQ          = 	; CPU clock frequency (TIA_FREQ / 3).
;		CPU_FRAME_CLKS    = 	; CPU clocks for the whole frame.
;		CPU_VSYNC_CLKS    = 	; CPU clocks for the VSYNC.
;		CPU_VBLANK_CLKS   = 	; CPU clocks for the VBLANK.
;		CPU_VVISIBLE_CLKS = 	; CPU clocks for the VVISIBLE display.
;		CPU_OVERSCAN_CLKS =  	; CPU clocks for the OVERSCAN.
;		; Video Display
;		VID_FREQ          = 	; Frequency of the whole frame.
;		VID_FRAME_LINE    = 	; Video display lines for the whole frame.
;		VID_VSYNC_LINE    = 	; Video display lines for the VSYNC.
;		VID_VBLANK_LINE   = 	; Video display lines for the VBLANK.
;		VID_VVISIBLE_LINE = 	; Video display lines for the VVISIBLE.
;		VID_OVERSCAN_LINE = 	; Video display lines for the OVERSCAN.
;		VID_HEIGHT        = 	; Same as VID_VVISIBLE_LINE.
;		.ENDIF



;------------------------------------------------------------------------------
; PAL Platform Build Configuration for TIA, CPU, Video (PLATFORM_PAL).
;------------------------------------------------------------------------------

		.IFDEF			PLATFORM_PAL
		; TIA
		TIA_FREQ          = 3556800	; Clock frequency (based on VID_FREQ).
		TIA_FRAME_CLKS    =   71136	; TIA clocks for the whole frame.
		TIA_VSYNC_CLKS    =     684	; TIA clocks for the VSYNC.
		TIA_VBLANK_CLKS   =   10260	; TIA clocks for the VBLANK.
		TIA_VVISIBLE_CLKS =   51984	; TIA clocks for the VVISIBLE display.
		TIA_OVERSCAN_CLKS =    8208	; TIA clocks for the OVERSCAN.
		; CPU
		CPU_FREQ          = 1185600	; CPU clock frequency (TIA_FREQ / 3).
		CPU_FRAME_CLKS    =   23712	; CPU clocks for the whole frame.
		CPU_VSYNC_CLKS    =     228	; CPU clocks for the VSYNC.
		CPU_VBLANK_CLKS   =    3420	; CPU clocks for the VBLANK.
		CPU_VVISIBLE_CLKS =   17328	; CPU clocks for the VVISIBLE display.
		CPU_OVERSCAN_CLKS =    2736	; CPU clocks for the OVERSCAN.
		; Video Display
		VID_FREQ          =      50	; Frequency of the whole frame.
		VID_FRAME_LINE    =     312	; Video display lines for the whole frame.
		VID_VSYNC_LINE    =       3	; Video display lines for the VSYNC.
		VID_VBLANK_LINE   =      45	; Video display lines for the VBLANK.
		VID_VVISIBLE_LINE =     228	; Video display lines for the VVISIBLE.
		VID_OVERSCAN_LINE =      36	; Video display lines for the OVERSCAN.
		VID_HEIGHT        =     228	; Same as VID_VVISIBLE_LINE.
		.ENDIF



;------------------------------------------------------------------------------
; NTSC Platform Build Configuration for TIA, CPU, Video (PLATFORM_NTSC).
;------------------------------------------------------------------------------

		.IFDEF			PLATFORM_NTSC
		; TIA
		TIA_FREQ          = 3584160	; TIA clock frequency (based on VID_FREQ).
		TIA_FRAME_CLKS    =   59736	; TIA clocks for the whole frame.
		TIA_VSYNC_CLKS    =     684	; TIA clocks for the VSYNC.
		TIA_VBLANK_CLKS   =    8436	; TIA clocks for the VBLANK.
		TIA_VVISIBLE_CLKS =   43776	; TIA clocks for the VVISIBLE display.
		TIA_OVERSCAN_CLKS =    6840	; TIA clocks for the OVERSCAN.
		; CPU
		CPU_FREQ          = 1194720	; Frequency of the CPU clock (TIA_FREQ / 3).
		CPU_FRAME_CLKS    =   19912	; CPU clocks for the whole frame.
		CPU_VSYNC_CLKS    =     228	; CPU clocks for the VSYNC.
		CPU_VBLANK_CLKS   =    2812	; CPU clocks for the VBLANK.
		CPU_VVISIBLE_CLKS =   14592	; CPU clocks for the VVISIBLE display.
		CPU_OVERSCAN_CLKS =    2280	; CPU clocks for the OVERSCAN.
		; Video Display
		VID_FREQ          =      60	; Frequency of the whole frame.
		VID_FRAME_LINE    =     262	; Video display lines for the whole frame.
		VID_VSYNC_LINE    =       3	; Video display lines for the VSYNC.
		VID_VBLANK_LINE   =      37	; Video display lines for the VBLANK.
		VID_VVISIBLE_LINE =     192	; Video display lines for the VVISIBLE.
		VID_OVERSCAN_LINE =      30	; Video display lines for the OVERSCAN.
		VID_HEIGHT        =     192	; Same as VID_VVISIBLE_LINE.
		.ENDIF



;------------------------------------------------------------------------------
; SECAM Platform Build Configuration for TIA, CPU, Video (PLATFORM_SECAM).
;------------------------------------------------------------------------------

		.IFDEF			PLATFORM_SECAM
		; TIA
		TIA_FREQ          = 3556800	; TIA clock frequency (based on VID_FREQ).
		TIA_FRAME_CLKS    =   71136	; TIA clocks for the whole frame.
		TIA_VSYNC_CLKS    =     684	; TIA clocks for the VSYNC.
		TIA_VBLANK_CLKS   =   10260	; TIA clocks for the VBLANK.
		TIA_VVISIBLE_CLKS =   51984	; TIA clocks for the VVISIBLE display.
		TIA_OVERSCAN_CLKS =    8208	; TIA clocks for the OVERSCAN.
		; CPU
		CPU_FREQ          = 1185600	; CPU clock frequency (TIA_FREQ / 3).
		CPU_FRAME_CLKS    =   23712	; CPU clocks for the whole frame.
		CPU_VSYNC_CLKS    =     228	; CPU clocks for the VSYNC.
		CPU_VBLANK_CLKS   =    3420	; CPU clocks for the VBLANK.
		CPU_VVISIBLE_CLKS =   17328	; CPU clocks for the VVISIBLE display.
		CPU_OVERSCAN_CLKS =    2736	; CPU clocks for the OVERSCAN.
		; Video Display
		VID_FREQ          =      50	; Frequency of the whole frame.
		VID_FRAME_LINE    =     312	; Video display lines for the whole frame.
		VID_VSYNC_LINE    =       3	; Video display lines for the VSYNC.
		VID_VBLANK_LINE   =      45	; Video display lines for the VBLANK.
		VID_VVISIBLE_LINE =     228	; Video display lines for the VVISIBLE.
		VID_OVERSCAN_LINE =      36	; Video display lines for the OVERSCAN.
		VID_HEIGHT        =     228	; Same as VID_VVISIBLE_LINE.
		.ENDIF



;------------------------------------------------------------------------------


