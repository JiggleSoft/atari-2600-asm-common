;==============================================================================
; Title:        Atari 2600 - JiggleSoft Retro-Games Splash Screen.
; Filename:     jigglesoft-retro-games-splash.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-17 23:59
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

                .IFNDEF     __JIGGLESOFT_GFX_PF_LOGO__INC__
                            __JIGGLESOFT_GFX_PF_LOGO__INC__ = 1

;==============================================================================
; Atari 2600 - JiggleSoft Graphics - Playfield - Logo.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Graphics Data.
;------------------------------------------------------------------------------

                .CODE


.MACRO          splash_jigglesoft_show
                VID_INIT
loopy1:
                VID_VSYNC
                VID_VBLANK
                VID_VDISPLAY
                VID_OVERSCAN    loopy1
.ENDMACRO




;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


