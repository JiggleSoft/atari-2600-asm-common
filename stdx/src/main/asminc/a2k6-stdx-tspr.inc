; STATUS: WORK IN PROGRESS.
;==============================================================================
; TItle:        Atari 2600 TIA Sprite standard extra include file.
; Filename:     a2k6-stdx-tspr.inc
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

                .IFNDEF     __A2K6_STDX_TSPR__INC__
                            __A2K6_STDX_TSPR__INC__ = 1

;==============================================================================
; Atari 2600 TIA Sprite.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Sprite Data Description Macros.
;------------------------------------------------------------------------------

; Sprite Bitmap data byte comma separated bits (bits 7-0)

.MACRO		SPR_CSV			B7,B6,B5,B4,B3,B2,B1,B0
			BYTE_7_0_CSV	B7,B6,B5,B4,B3,B2,B1,B0
.ENDMACRO



; Sprite Bitmap data byte value (bits 7-0)

.MACRO		SPR_VAL			BV
			BYTE_VAL		BV
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------

                .ENDIF


