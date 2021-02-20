;==============================================================================
; Title:        Atari 2600 all standard and standard extra include files.
; Filename:     atari2k6.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-23 21:18
; Version:      2.0.4
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

                .IFNDEF     __ATARI2K6__INC__
                            __ATARI2K6__INC__ = 1

;==============================================================================
; Atari 2600 Standard and Standard Extra Includes.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------

; Atari 2600 standard include file.

                .INCLUDE    "a2k6-std.inc"


; Atari 2600 standard extra include file.

                .INCLUDE    "a2k6-stdx.inc"



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


