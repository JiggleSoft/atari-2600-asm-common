;==============================================================================
; Title:        Atari 2600 Font standard 4 x 5.
; Filename:     a2k6-font-std-4X4.inc
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
; distributed under the License is distributed on an "AS IS" BASIS
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.
;------------------------------------------------------------------------------

                .IFNDEF     __A2K6_FONT_STD_4X4__INC__
                            __A2K6_FONT_STD_4X4__INC__ = 1

;==============================================================================
; Atari 2600 Font Standard 4 X 5.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Both High and Low Nybbles
;------------------------------------------------------------------------------

; Glyphs

.MACRO          FONT_STD_4X4_SPACE
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_EXCLAMATION
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,B,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_DOUBLE_QUOTE
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_APOSTROPHE
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_ROUND_OPEN
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_ROUND_CLOSE
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_PLUS
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_HYPHEN
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_FULL_STOP
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,B,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_SLASH
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    B,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_0
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_1
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_2
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    B,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_3
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    B,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_4
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_5
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    B,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_6
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_7
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_8
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_9
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_COLON
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_LESS_THAN
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_EQUALS
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    B,B,B,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_GREATER_THAN
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    B,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_SQUARE_OPEN
    BYTE_7_0_CSV    _,B,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_BACKSLASH
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_SQUARE_CLOSE
    BYTE_7_0_CSV    _,B,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_CIRCUMFLEX
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    B,_,B,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_UNDERSCORE
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    B,B,B,B
.ENDMACRO


.MACRO          FONT_STD_4X4_BRACE_OPEN
    BYTE_7_0_CSV    _,B,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    B,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,B,_
.ENDMACRO


.MACRO          FONT_STD_4X4_VERTICAL_BAR
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,B,_,_
.ENDMACRO


.MACRO          FONT_STD_4X4_BRACE_CLOSE
    BYTE_7_0_CSV    B,B,_,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    _,_,B,_
    BYTE_7_0_CSV    _,B,_,_
    BYTE_7_0_CSV    B,B,_,_
.ENDMACRO



;------------------------------------------------------------------------------
; High Nybble Only
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Low Nybble Only
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Both High and Low Nybbles; Inverted X
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; High Nybble Only; Inverted X
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Low Nybble Only; Inverted X
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Both High and Low Nybbles; Inverted Y
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; High Nybble Only; Inverted Y
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Low Nybble Only; Inverted Y
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Both High and Low Nybbles; Inverted X; Inverted Y
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; High Nybble Only; Inverted X; Inverted Y
;------------------------------------------------------------------------------

; Glyphs


;------------------------------------------------------------------------------
; Low Nybble Only; Inverted X; Inverted Y
;------------------------------------------------------------------------------

; Glyphs



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


