; STATUS: WORK IN PROGRESS
;==============================================================================
; Title:        Atari 2600 Joystick and Paddle standard extra include file.
; Filename:     a2k6-stdx-joy.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-23 21:18
; Version:      2.0.4
;------------------------------------------------------------------------------
; Supported joysticks and controllers:-
;   Std  Control   A/D  Num/Port  Directions  Buttons  Models
;   Yes  Joystick  D    1         4 (+4diag)  1        CX10/CX24/CX40/CX42/CX43
;   Yes  Paddle    A    2         1 (1 axis)  1        CX30/CX30-04
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

                .IFNDEF     __A2K6_STDX_JOY__INC__
                            __A2K6_STDX_JOY__INC__ = 1

;==============================================================================
; Atari 2600 Standard Digital Joystick and Paddle Controller.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Digital Joystick (CX10/CX24/CX40/CX42/CX43)
;------------------------------------------------------------------------------

.MACRO          DJOY_INIT
.ENDMACRO


.MACRO          DJOY_READ
.ENDMACRO

.MACRO          DJOY_STORE
.ENDMACRO

.MACRO          JOY_MEM
joy_0_dir:      .RES            1
joy_1_dir:      .RES            1
joy_0_but_0:    .RES            1
joy_1_but_0:    .RES            1
joy_0_but_1:    .RES            1
.ENDMACRO



;------------------------------------------------------------------------------
; Analogue Paddle (CX30/CX30-04)
;------------------------------------------------------------------------------

.MACRO          AJOY_MEM        num
                .IF             ((num<0||(nul>4))
                .ERROR
joy_
.ENDMACRO


;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


