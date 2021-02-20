;==============================================================================
; Title:        Atari 2600 all standard extra include files.
; Filename:     a2k6-stdx.inc
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

                .IFNDEF     __A2K6_STDX__INC__
                            __A2K6_STDX__INC__ = 1

;==============================================================================
; Atari 2600 Standard Extra Includes.
;==============================================================================

                .PUSHSEG

                .OUT        "Atari 2600 Standard Extra Includes."

;------------------------------------------------------------------------------
; Central Processing Unit (CPU).
;------------------------------------------------------------------------------

; Atari 2600 Central Processing Unit (CPU).

                .INCLUDE    "a2k6-stdx-cpu.inc"


; Atari 2600 Standard Library.

                .INCLUDE    "a2k6-stdx-lib.inc"



;------------------------------------------------------------------------------
; Atari 2600 Utilities.
;------------------------------------------------------------------------------

; Atari 2600 Utilities.

            .INCLUDE    "a2k6-stdx-util.inc"



;------------------------------------------------------------------------------
; Atari 2600 RIOT (RAM, I/O, Timer).
;------------------------------------------------------------------------------

; Atari 2600 RIOT RAM.

            .INCLUDE    "a2k6-stdx-rram.inc"


; Atari 2600 RIOT IO.

            .INCLUDE    "a2k6-stdx-rio.inc"


; Atari 2600 RIOT Timer.

            .INCLUDE    "a2k6-stdx-rtim.inc"



;------------------------------------------------------------------------------
; Atari 2600 TIA Extra Include (Display, I/O, Audio).
;------------------------------------------------------------------------------

; Atari 2600 TIA Colour.

            .INCLUDE    "a2k6-stdx-tcol.inc"


; Atari 2600 TIA Video display utilities.

            .INCLUDE    "a2k6-stdx-tvid.inc"


; Atari 2600 TIA Playfield utilities.

            .INCLUDE    "a2k6-stdx-tpf.inc"


; Atari 2600 TIA Sprite.

            .INCLUDE    "a2k6-stdx-tspr.inc"


; Atari 2600 TIA IO.

            .INCLUDE    "a2k6-stdx-tio.inc"


; Atari 2600 TIA Audio.

            .INCLUDE    "a2k6-stdx-taud.inc"



;------------------------------------------------------------------------------
; Atari 2600 Standard Controllers.
;------------------------------------------------------------------------------

; Atari 2600 Console Switches.

            .INCLUDE    "a2k6-stdx-csw.inc"


; Atari 2600 Standard Digital Joystick / Paddle Controller.

            .INCLUDE    "a2k6-stdx-joy.inc"



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


