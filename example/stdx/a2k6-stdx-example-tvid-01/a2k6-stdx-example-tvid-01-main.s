;==============================================================================
; Title:        Atari 2600 - STDX - TVID - Example 01 main file.
; Filename:     a2k6-stdx-example-tvid-01.s
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-14 21:42
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

                .INCLUDE        "atari2k6.inc"

;------------------------------------------------------------------------------

                CPU_CONFIG_VECTOR   cold_start

;------------------------------------------------------------------------------

                .CODE

cold_start:
                A2K6_TINY_INIT_COLD
main:
                VID_INIT
main_loop:
                VID_VSYNC
                VID_VBLANK
                VID_VDISPLAY_TEST_CARD
                VID_OVERSCAN
                JMP             main_loop



