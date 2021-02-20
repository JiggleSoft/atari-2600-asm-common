;==============================================================================
; Title:        Atari 2600 Font standard 6-4 x 5.
; Filename:     a2k6-font-std-6-4x5.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-19 21:17
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

                .IFNDEF     __A2K6_FONT_STD_6_4X5__INC__
                            __A2K6_FONT_STD_6_4X5__INC__ = 1

;==============================================================================
; Atari 2600 Font Standard 6-4 X 5.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Glyphs
;------------------------------------------------------------------------------


.MACRO          FONT_STD_6_4X5_SPACE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_EXCLAMATION
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_DOUBLE_QUOTE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_HASH
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_DOLLAR
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_PERCENT
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_AMPERSAND
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_APOSTROPHE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_ROUND_OPEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_ROUND_CLOSE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_ASTERISK
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_PLUS
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_COMMA
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_HYPHEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_FULL_STOP
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_SLASH
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_0
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_1
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_2
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_3
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_4
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_5
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_6
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_7
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_8
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_9
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_COLON
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_SEMICOLON
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_LESS_THAN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_EQUALS
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_GREATER_THAN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_QUESTION
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_AT
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_A
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_B
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_C
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_D
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_E
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_F
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_G
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_H
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_I
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_J
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_K
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_L
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_M
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_N
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_O
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_P
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_Q
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_R
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_S
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_T
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_U
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_V
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_W
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_X
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_Y
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_Z
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_SQUARE_OPEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_BACKSLASH
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_SQUARE_CLOSE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_CIRCUMFLEX
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_UNDERSCORE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_GRAVE_ACCENT
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_BRACE_OPEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_VERTICAL_BAR
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_BRACE_CLOSE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_6_4X5_TILDE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


