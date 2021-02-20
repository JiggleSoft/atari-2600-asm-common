;==============================================================================
; Title:        Atari 2600 include all font pack include files.
; Filename:     a2k6-font.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-19 19:35
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

                .IFNDEF     __A2K6_FONT__INC__
                            __A2K6_FONT__INC__ = 1

;==============================================================================
; Atari 2600 Font Includes.
;==============================================================================

                .PUSHSEG

                .OUT        "Atari 2600 Font Includes."

;------------------------------------------------------------------------------
; Font Packs.
;------------------------------------------------------------------------------

; Standard fonts.

                .INCLUDE    "a2k6-font-std.inc"



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF

