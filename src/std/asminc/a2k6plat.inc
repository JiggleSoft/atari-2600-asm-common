;==============================================================================
; Name:         Atari 2600 platform specific include file.
; Filename:     a2k6plat.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-25 23:04
; Version:      2.0.0
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

                .IFNDEF     __A2K6PLAT__INC__
                .DEFINE     __A2K6PLAT__INC__

;==============================================================================
; Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Platform Specific Build Configuration Validation.
;------------------------------------------------------------------------------

; Validate that a required platform is defined.

        .IFNDEF     PLATFORM_PAL
        .IFNDEF     PLATFORM_NTSC
        .IFNDEF     PLATFORM_SECAM
        .IFNDEF     PLATFORM_CUSTOM
        .ERROR      "One platform must be defined(PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
        .ENDIF
        .ENDIF
        .ENDIF
        .ENDIF

; Validate only one platform is defined.

        .IFDEF      PLATFORM_PAL
        .IF         .DEFINED(PLATFORM_NTSC) || .DEFINED(PLATFORM_SECAM) || .DEFINED(PLATFORM_CUSTOM)
        .ERROR      "Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
        .ENDIF
        .OUT        "PLATFORM=PAL"
        .ENDIF

        .IFDEF      PLATFORM_NTSC
        .IF         .DEFINED(PLATFORM_PAL) || .DEFINED(PLATFORM_SECAM) || .DEFINED(PLATFORM_CUSTOM)
        .ERROR      "Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
        .ENDIF
        .OUT        "PLATFORM=NTSC"
        .ENDIF

        .IFDEF      PLATFORM_SECAM
        .IF         .DEFINED(PLATFORM_PAL) || .DEFINED(PLATFORM_NTSC) || .DEFINED(PLATFORM_CUSTOM)
        .ERROR      "Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
        .ENDIF
        .OUT        "PLATFORM=SECAM"
        .ENDIF

        .IFDEF      PLATFORM_CUSTOM
        .IF         .DEFINED(PLATFORM_PAL) || .DEFINED(PLATFORM_NTSC) || .DEFINED(PLATFORM_SECAM)
        .ERROR      "Only a single platform can be defined but multiple in use (PLATFORM_PAL, PLATFORM_NTSC, PLATFORM_SECAM, OR PLATFORM_CUSTOM)!"
        .ENDIF
        .OUT        "PLATFORM=CUSTOM"
        .ENDIF



;------------------------------------------------------------------------------
; Common Platform Configuration for TIA, CPU, Video, and Colours.
;------------------------------------------------------------------------------

        ; TIA
        TIA_HORIZ_CLKS    = 228 ; TIA clocks per horizontal line.
        TIA_HBLANK_CLKS   =  68 ; TIA clocks for the horizontal blank.
        TIA_HVISIBLE_CLKS = 160 ; TIA clocks for the visible line.

        ; CPU
        CPU_HORIZ_CLKS    =  76 ; CPU clocks per horizontal line (TIA_HORIZ_CLKS / 3).
        CPU_HBLANK_CLKS   =  23 ; CPU clocks for the horizontal blank (TIA_HBLANK_CLKS / 3) (22.66 round up).
        CPU_HVISIBLE_CLKS =  53 ; CPU clocks for the visible line (TIA_HVISIBLE_CLKS / 3) (53.33 round down).

        ; Video Display
        VID_WIDTH         = 160 ; Video display pixels per horizontal line (same as TIA_HVISIBLE_CLKS).

        ; Colours (portable approximations for PAL, NTSC, and SECAM).
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
; Custom Platform Build Configuration for System, Video, TIA, CPU, Colours (PLATFORM_CUSTOM).
;------------------------------------------------------------------------------

; PLATFORM_CUSTOM TEMPLATE TO BE COPIED TO YOUR CODE AND EDITED AS REQUIRED.

;        .IFDEF            PLATFORM_CUSTOM
;        ; System
;        SYS_FREQ          =         ; System clock frequency (Hz).
;        ; Video Display
;        VID_FREQ          =         ; Frequency of the whole frame (rounded up).
;        VID_FRAME_LINE    =         ; Video display lines for the whole frame.
;        VID_VSYNC_LINE    =         ; Video display lines for the vertical sync (VSYNC).
;        VID_VBLANK_LINE   =         ; Video display lines for the vertical blank (VBLANK).
;        VID_VVISIBLE_LINE =         ; Video display lines for the vertical visible display (VVISIBLE).
;        VID_OVERSCAN_LINE =         ; Video display lines for the vertical overscan (OVERSCAN).
;        VID_HEIGHT        =         ; Video display lines for the vertical visible display (same as VID_VVISIBLE_LINE).
;        ; TIA
;        TIA_FREQ          =         ; TIA clock frequency (SYS_CLOCK_FREQ).
;        TIA_FRAME_CLKS    =         ; TIA clocks for the whole frame (VID_HORIZ_CLKS * VID_FRAME_LINE).
;        TIA_VSYNC_CLKS    =         ; TIA clocks for the VSYNC (VID_HORIZ_CLKS * VID_VSYNC_LINE).
;        TIA_VBLANK_CLKS   =         ; TIA clocks for the VBLANK (VID_HORIZ_CLKS * VID_VBLANK_LINE).
;        TIA_VVISIBLE_CLKS =         ; TIA clocks for the VVISIBLE display (VID_HORIZ_CLKS * VID_VVISIBLE_LINE).
;        TIA_OVERSCAN_CLKS =         ; TIA clocks for the OVERSCAN (VID_HORIZ_CLKS * VID_OVERSCAN_LINE).
;        ; CPU
;        CPU_FREQ          =         ; CPU clock frequency (TIA_FREQ / 3).
;        CPU_FRAME_CLKS    =         ; CPU clocks for the whole frame (CPU_HORIZ_CLKS * VID_FRAME_LINE).
;        CPU_VSYNC_CLKS    =         ; CPU clocks for the VSYNC (CPU_HORIZ_CLKS * VID_VSYNC_LINE).
;        CPU_VBLANK_CLKS   =         ; CPU clocks for the VBLANK (CPU_HORIZ_CLKS * VID_VBLANK_LINE).
;        CPU_VVISIBLE_CLKS =         ; CPU clocks for the VVISIBLE display (CPU_HORIZ_CLKS * VID_VVISIBLE_LINE).
;        CPU_OVERSCAN_CLKS =         ; CPU clocks for the OVERSCAN (CPU_HORIZ_CLKS * VID_OVERSCAN_LINE).
;        ; Colours
;        COL_COLOURS       =         ; Number of unique colours.
;        COL_B_AND_W       =         ; Number of unique black and white shades.
;        .ENDIF



;------------------------------------------------------------------------------
; PAL Platform Build Configuration for System, Video, TIA, CPU, Colours (PLATFORM_PAL).
;------------------------------------------------------------------------------

        .IFDEF            PLATFORM_PAL
        ; System
        SYS_FREQ          = 3546894 ; System clock frequency (Hz).
        ; Video Display
        VID_FREQ          =      50 ; Frequency of the whole frame (rounded up).
        VID_FRAME_LINE    =     312 ; Video display lines for the whole frame.
        VID_VSYNC_LINE    =       3 ; Video display lines for the vertical sync (VSYNC).
        VID_VBLANK_LINE   =      37 ; Video display lines for the vertical blank (VBLANK).
        VID_VVISIBLE_LINE =     242 ; Video display lines for the vertical visible display (VVISIBLE).
        VID_OVERSCAN_LINE =      30 ; Video display lines for the vertical overscan (OVERSCAN).
        VID_HEIGHT        =     242 ; Video display lines for the vertical visible display (same as VID_VVISIBLE_LINE).
        ; TIA
        TIA_FREQ          = 3556800 ; TIA clock frequency (SYS_CLOCK_FREQ).
        TIA_FRAME_CLKS    =   71136 ; TIA clocks for the whole frame (VID_HORIZ_CLKS * VID_FRAME_LINE).
        TIA_VSYNC_CLKS    =     684 ; TIA clocks for the VSYNC (VID_HORIZ_CLKS * VID_VSYNC_LINE).
        TIA_VBLANK_CLKS   =    8436 ; TIA clocks for the VBLANK (VID_HORIZ_CLKS * VID_VBLANK_LINE).
        TIA_VVISIBLE_CLKS =   55176 ; TIA clocks for the VVISIBLE display (VID_HORIZ_CLKS * VID_VVISIBLE_LINE).
        TIA_OVERSCAN_CLKS =    6840 ; TIA clocks for the OVERSCAN (VID_HORIZ_CLKS * VID_OVERSCAN_LINE).
        ; CPU
        CPU_FREQ          = 1185600 ; CPU clock frequency (TIA_FREQ / 3).
        CPU_FRAME_CLKS    =   23712 ; CPU clocks for the whole frame (CPU_HORIZ_CLKS * VID_FRAME_LINE).
        CPU_VSYNC_CLKS    =     228 ; CPU clocks for the VSYNC (CPU_HORIZ_CLKS * VID_VSYNC_LINE).
        CPU_VBLANK_CLKS   =    2812 ; CPU clocks for the VBLANK (CPU_HORIZ_CLKS * VID_VBLANK_LINE).
        CPU_VVISIBLE_CLKS =   18392 ; CPU clocks for the VVISIBLE display (CPU_HORIZ_CLKS * VID_VVISIBLE_LINE).
        CPU_OVERSCAN_CLKS =    2280 ; CPU clocks for the OVERSCAN (CPU_HORIZ_CLKS * VID_OVERSCAN_LINE).
        ; Colours
        COL_COLOURS       =     104 ; Number of unique colours.
        COL_B_AND_W       =       8 ; Number of unique black and white shades.
        .ENDIF



;------------------------------------------------------------------------------
; NTSC Platform Build Configuration for System, Video, TIA, CPU, Colours (PLATFORM_NTSC).
;------------------------------------------------------------------------------

        .IFDEF            PLATFORM_NTSC
        ; System
        SYS_FREQ          = 3579575 ; System clock frequency (Hz).
        ; Video Display
        VID_FREQ          =      60 ; Frequency of the whole frame (rounded down).
        VID_FRAME_LINE    =     262 ; Video display lines for the whole frame.
        VID_VSYNC_LINE    =       3 ; Video display lines for the vertical sync (VSYNC).
        VID_VBLANK_LINE   =      37 ; Video display lines for the vertical blank (VBLANK).
        VID_VVISIBLE_LINE =     192 ; Video display lines for the vertical visible display (VVISIBLE).
        VID_OVERSCAN_LINE =      30 ; Video display lines for the vertical overscan (OVERSCAN).
        VID_HEIGHT        =     192 ; Video display lines for the vertical visible display (same as VID_VVISIBLE_LINE).
        ; TIA
        TIA_FREQ          = 3579575 ; TIA clock frequency (SYS_CLOCK_FREQ).
        TIA_FRAME_CLKS    =   59736 ; TIA clocks for the whole frame (VID_HORIZ_CLKS * VID_FRAME_LINE).
        TIA_VSYNC_CLKS    =     684 ; TIA clocks for the VSYNC (VID_HORIZ_CLKS * VID_VSYNC_LINE).
        TIA_VBLANK_CLKS   =    8436 ; TIA clocks for the VBLANK (VID_HORIZ_CLKS * VID_VBLANK_LINE).
        TIA_VVISIBLE_CLKS =   43776 ; TIA clocks for the VVISIBLE display (VID_HORIZ_CLKS * VID_VVISIBLE_LINE).
        TIA_OVERSCAN_CLKS =    6840 ; TIA clocks for the OVERSCAN (VID_HORIZ_CLKS * VID_OVERSCAN_LINE).
        ; CPU
        CPU_FREQ          = 1193192 ; CPU clock frequency (TIA_FREQ / 3) (rounded up).
        CPU_FRAME_CLKS    =   19912 ; CPU clocks for the whole frame (CPU_HORIZ_CLKS * VID_FRAME_LINE).
        CPU_VSYNC_CLKS    =     228 ; CPU clocks for the VSYNC (CPU_HORIZ_CLKS * VID_VSYNC_LINE).
        CPU_VBLANK_CLKS   =    2812 ; CPU clocks for the VBLANK (CPU_HORIZ_CLKS * VID_VBLANK_LINE).
        CPU_VVISIBLE_CLKS =   14592 ; CPU clocks for the VVISIBLE display (CPU_HORIZ_CLKS * VID_VVISIBLE_LINE).
        CPU_OVERSCAN_CLKS =    2280 ; CPU clocks for the OVERSCAN (CPU_HORIZ_CLKS * VID_OVERSCAN_LINE).
        ; Colours
        COL_COLOURS       =     128 ; Number of unique colours.
        COL_B_AND_W       =       8 ; Number of unique black and white shades.
        .ENDIF



;------------------------------------------------------------------------------
; SECAM Platform Build Configuration for System, Video, TIA, CPU, Colours (PLATFORM_SECAM).
;------------------------------------------------------------------------------

        .IFDEF            PLATFORM_SECAM
        ; System
        SYS_FREQ          = 3546894 ; System clock frequency (Hz).
        ; Video Display
        VID_FREQ          =      50 ; Frequency of the whole frame (rounded up).
        VID_FRAME_LINE    =     312 ; Video display lines for the whole frame.
        VID_VSYNC_LINE    =       3 ; Video display lines for the vertical sync (VSYNC).
        VID_VBLANK_LINE   =      37 ; Video display lines for the vertical blank (VBLANK).
        VID_VVISIBLE_LINE =     242 ; Video display lines for the vertical visible display (VVISIBLE).
        VID_OVERSCAN_LINE =      30 ; Video display lines for the vertical overscan (OVERSCAN).
        VID_HEIGHT        =     242 ; Video display lines for the vertical visible display (same as VID_VVISIBLE_LINE).
        ; TIA
        TIA_FREQ          = 3556800 ; TIA clock frequency (SYS_CLOCK_FREQ).
        TIA_FRAME_CLKS    =   71136 ; TIA clocks for the whole frame (VID_HORIZ_CLKS * VID_FRAME_LINE).
        TIA_VSYNC_CLKS    =     684 ; TIA clocks for the VSYNC (VID_HORIZ_CLKS * VID_VSYNC_LINE).
        TIA_VBLANK_CLKS   =    8436 ; TIA clocks for the VBLANK (VID_HORIZ_CLKS * VID_VBLANK_LINE).
        TIA_VVISIBLE_CLKS =   55176 ; TIA clocks for the VVISIBLE display (VID_HORIZ_CLKS * VID_VVISIBLE_LINE).
        TIA_OVERSCAN_CLKS =    6840 ; TIA clocks for the OVERSCAN (VID_HORIZ_CLKS * VID_OVERSCAN_LINE).
        ; CPU
        CPU_FREQ          = 1185600 ; CPU clock frequency (TIA_FREQ / 3).
        CPU_FRAME_CLKS    =   23712 ; CPU clocks for the whole frame (CPU_HORIZ_CLKS * VID_FRAME_LINE).
        CPU_VSYNC_CLKS    =     228 ; CPU clocks for the VSYNC (CPU_HORIZ_CLKS * VID_VSYNC_LINE).
        CPU_VBLANK_CLKS   =    2812 ; CPU clocks for the VBLANK (CPU_HORIZ_CLKS * VID_VBLANK_LINE).
        CPU_VVISIBLE_CLKS =   18392 ; CPU clocks for the VVISIBLE display (CPU_HORIZ_CLKS * VID_VVISIBLE_LINE).
        CPU_OVERSCAN_CLKS =    2280 ; CPU clocks for the OVERSCAN (CPU_HORIZ_CLKS * VID_OVERSCAN_LINE).
        ; Colours
        COL_COLOURS       =       8 ; Number of unique colours.
        COL_B_AND_W       =       8 ; Number of unique black and white shades.
        .ENDIF



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


