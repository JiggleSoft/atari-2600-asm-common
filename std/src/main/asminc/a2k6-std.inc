;==============================================================================
; Title:        Atari 2600 include all standard include files.
; Filename:     a2k6-std.inc
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

                .IFNDEF     __A2K6_STD__INC__
                            __A2K6_STD__INC__ = 1

;==============================================================================
; Atari 2600 Standard Includes.
;==============================================================================

                .PUSHSEG

                .OUT        "Atari 2600 Standard Includes."

;------------------------------------------------------------------------------
; Platform Specific Build Configuration.
;------------------------------------------------------------------------------

; Atari 2600 Platform Specific Build Configurations (PAL, NTSC, SECAM, CUSTOM).

                .INCLUDE    "a2k6-std-plat.inc"



;------------------------------------------------------------------------------
; Hardware (RIOT) RAM and (RIOT, TIA) Registers.
;------------------------------------------------------------------------------

; Atari 2600 RIOT chip; Random Access Memory (RAM), Input Output(I/O), & Timer.

                .INCLUDE    "a2k6-std-riot.inc"


; Atari 2600 TIA chip; Television Interface Adapter (Display, IO, Audio).

                .INCLUDE    "a2k6-std-tia.inc"



;------------------------------------------------------------------------------
; Hardware (CPU, RIOT, TIA) Initialisation.
;------------------------------------------------------------------------------

; Atari 2600 Initialise Hardware following Power-up/Reset (CPU, RIOT, TIA).

                .INCLUDE    "a2k6-std-init.inc"



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


