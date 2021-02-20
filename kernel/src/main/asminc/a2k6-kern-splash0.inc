;==============================================================================
; Name:         Atari 2600 Kernel - JiggleSoft Splash 0.
; Filename:     a2k6-kern-splash0.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-16 20:55
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

                .IFNDEF     __A2K6_KERN_SPLASH0__INC__
                            __A2K6_KERN_SPLASH0__INC__ = 1

;==============================================================================
; Atari 2600 - Kernel = JiggleSoft Splash 0.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; ...
;------------------------------------------------------------------------------

KERN_SPLASH_



;------------------------------------------------------------------------------
; Test Card
;------------------------------------------------------------------------------

KERN_TEST_CARD      .MACRO
.ENDMACRO


;------------------------------------------------------------------------------
; Test Card
;------------------------------------------------------------------------------

KERN_TEST_BORDER



;------------------------------------------------------------------------------
; To Do.
;------------------------------------------------------------------------------

.MACRO          KERN_SPLASH0_JIGGLESOFT_PF
kern_splash0_logo_1_pfield:
    PF012L012R_CSV  _,_,_,B,_,B,_,_,_,_,_,_,_,_,_,B,_,_,_,___,B,B,B,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_
    PF012L012R_CSV  _,_,_,B,_,_,_,_,_,_,_,_,_,_,_,B,_,_,_,___,B,_,_,_,_,_,_,_,_,_,B,B,B,B,_,B,_,_,_
    PF012L012R_CSV  _,_,_,B,_,B,_,_,_,_,_,_,_,_,_,B,_,B,B,B,_,B,_,_,_,_,_,_,_,_,_,B,_,_,_,_,B,_,_,_
    PF012L012R_CSV  _,_,_,B,_,B,_,B,B,B,_,B,B,B,_,B,_,B,_,B,_,B,B,B,_,B,B,B,B,_,_,B,_,_,_,B,B,B,_,_
    PF012L012R_CSV  _,_,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,B,B,B,_,_,_,B,_,B,_,_,B,_,B,B,B,_,_,_,B,_,_,_
    PF012L012R_CSV  B,_,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,_,_,_,_,B,_,B,_,_,B,_,_,B,_,_,_,_,B,_,_,_
    PF012L012R_CSV  B,B,B,B,_,B,_,B,B,B,_,B,B,B,_,B,_,B,B,B,_,B,B,B,_,B,B,B,B,_,_,B,_,_,_,_,B,B,B,B
    PF012L012R_CSV  _,_,_,_,_,_,_,_,_,B,_,_,_,B,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_
    PF012L012R_CSV  _,_,_,_,_,_,_,B,B,B,_,B,B,B,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_z


splash_1_colubk:
                .BYTE           $00


splash_1_colupf:
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
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
                .BYTE           $EE
.ENDMACRO


.MACRO          KERN_SPLASH0_LOGO_PF
splash_2_pfield:
    PF012L012R_CSV  B,B,B,_,B,B,_,B,B,B,_,B,B,B,_,B,B,B,_,_,B,B_B,_,B,B,B,_,B,_,_,_,B,_,B,B,_,B,B,B
    PF012L012R_CSV  B,_,B,_,B,_,_,_,B,_,_,B,_,B,_,B,_,B,_,_,B,_,_,_,B,_,B,_,B,B,_,B,B,_,B,_,_,B,_,_
    PF012L012R_CSV  B,B,_,_,B,B,_,_,B,_,_,B,B,_,_,B,_,B,_,_,B,_,B,_,B,B,B,_,B,B,B,B,B,_,B,B,_,B,B,B
    PF012L012R_CSV  B,_,B,_,B,_,_,_,B,_,_,B,_,B,_,B,_,B,_,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,B,_,_,_,_,B
    PF012L012R_CSV  B,_,B,_,B,B,_,_,B,_,_,B,_,B,_,B,B,B,_,_,B,B,B,_,B,_,B,_,B,_,_,_,B,_,B,B,_,B,B,B

splash_2_colubk:
                .BYTE           $00


splash_2_colupf:
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





;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


