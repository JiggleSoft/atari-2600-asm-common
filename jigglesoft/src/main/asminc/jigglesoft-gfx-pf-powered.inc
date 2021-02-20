;==============================================================================
; Title:        Atari 2600 - JiggleSoft Graphics - Playfield - Powered.
; Filename:     jigglesoft-gfx-pf-powered.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-16 21:21
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

                .IFNDEF     __JIGGLESOFT_GFX_PF_POWERED__INC__
                            __JIGGLESOFT_GFX_PF_POWERED__INC__ = 1

;==============================================================================
; Atari 2600 - JiggleSoft Graphics - Playfield - Powered.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Graphics Data.
;------------------------------------------------------------------------------

                .RODATA


; Playfield Data.

jigglesoft_powered_pfield:
    PF012L012R_CSV  _,_,_,_,_,B,B,B,_,B,B,B,_,B,_,_,_,B,_,B,B,B,_,B,B,B,__B,B,B,_,B,B,_,_,_,_,_,_,_
    PF012L012R_CSV  _,_,_,_,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,_,_,B,_,B,_,B,_,_,_,B,_,B,_,_,_,_,_,_
    PF012L012R_CSV  _,_,_,_,_,B,B,B,_,B,_,B,_,B,B,B,B,B,_,B,B,B,_,B,B,_,_,B,B,B,_,B,_,B,_,_,_,_,_,_
    PF012L012R_CSV  _,_,_,_,_,B,_,_,_,B,_,B,_,B,B,_,B,B,_,B,_,_,_,B,_,B,_,B,_,_,_,B,_,B,_,_,_,_,_,_
    PF012L012R_CSV  _,_,_,_,_,B,_,_,_,B,B,B,_,B,_,_,_,B,_,B,B,B,_,B,_,B,_,B,B,B,_,B,B,_,_,_,_,_,_,_
jigglesoft_powered_pfield_end:


; Background Colour Data.

jigglesoft_powered_colubk:
                .BYTE           $00
jigglesoft_powered_colubk_end:


; Playfield Colour Data.

jigglesoft_powered_colupf:
                .BYTE           $FE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
jigglesoft_powered_colupf_end:



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


