;==============================================================================
; Title:        Atari 2600 Font standard 8 x 8.
; Filename:     a2k6-font-std-8x8.inc
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

                .IFNDEF     __A2K6_FONT_STD_8X8__INC__
                            __A2K6_FONT_STD_8X8__INC__ = 1

;==============================================================================
; Atari 2600 Font Standard 8 X 8.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Glyphs
;------------------------------------------------------------------------------


.MACRO          FONT_STD_8X8_SPACE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_EXCLAMATION
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_DOUBLE_QUOTE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_HASH
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_DOLLAR
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_PERCENT
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_AMPERSAND
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_APOSTROPHE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_ROUND_OPEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_ROUND_CLOSE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_ASTERISK
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_PLUS
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_COMMA
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_HYPHEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_FULL_STOP
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_SLASH
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_0
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_1
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_2
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_3
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_4
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_5
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_6
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_7
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_8
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_9
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_COLON
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_SEMICOLON
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_LESS_THAN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_EQUALS
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_GREATER_THAN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_QUESTION
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_AT
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_A
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_B
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_C
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_D
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_E
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_F
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_G
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_H
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_I
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_J
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_K
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_L
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_M
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_N
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_O
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_P
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_Q
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_R
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_S
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_T
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_U
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_V
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_W
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_X
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_Y
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_Z
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_SQUARE_OPEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_BACKSLASH
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_SQUARE_CLOSE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_CIRCUMFLEX
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_UNDERSCORE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_GRAVE_ACCENT
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_BRACE_OPEN
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_VERTICAL_BAR
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_BRACE_CLOSE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
.ENDMACRO


.MACRO          FONT_STD_8X8_TILDE
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
    BYTE_7_0_CSV    _,_,_,_,_,_,_,_
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


