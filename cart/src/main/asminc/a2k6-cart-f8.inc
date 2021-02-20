;==============================================================================
; Title:        Atari 2600 cartridge type F8 specific include file.
; Filename:     a2k6cart-f8.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-27 20:08
; Version:      1.9.0
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

                .IFNDEF     __A2K6CART_F8__INC__
                .DEFINE     __A2K6CART_F8__INC__

;==============================================================================
; Atari 2600 Legacy Atari Bank Switching Cartridge.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; F8 - Atari Standard 8K ROM (8K ROM).
;
; ROM Strobe $1FF8 = Bank 0, $1FF9 = Bank 1.
;------------------------------------------------------------------------------

; !Not implemented!

.ERROR  "!!!NOT IMPLEMENTED!!!"



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


