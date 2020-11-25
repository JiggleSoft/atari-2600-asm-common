;==============================================================================
; Name:         Atari 2600 standard extra include file.
; Filename:     a2k6stdx.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-11 01:10
; Version:      1.2.0
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

                .IFNDEF     __A2K6STDX__INC__
                .DEFINE     __A2K6STDX__INC__

;==============================================================================
; Atari 2600 Standard Extra Include.
;==============================================================================

                .PUSHSEG

                .OUT        "Atari 2600 Standard Extra Includes."

;------------------------------------------------------------------------------
; CPU Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 CPU utilities.
;FIXME:			.INCLUDE	"a2k6cpu.inc"	; REVIEW: Is this required?

;------------------------------------------------------------------------------
; Atari 2600 Utilities Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 utilities.
			.INCLUDE	"a2k6util.inc"

;------------------------------------------------------------------------------
; RIOT Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 RIOT RAM utilities.
;REVIEW;			.INCLUDE	"a2k6rram.inc"	; REVIEW: Is this required?

; Atari 2600 RIOT IO utilities.
;REVIEW;			.INCLUDE	"a2k6rio.inc"	; REVIEW: Is this required?

; Atari 2600 RIOT Timer utilities.
			.INCLUDE	"a2k6rtim.inc"

;------------------------------------------------------------------------------
; TIA Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 TIA IO utilities.
;REVIEW;			.INCLUDE	"a2k6tio.inc"	; REVIEW: Is this required?

; Atari 2600 TIA Audio utilities.
;REVIEW;			.INCLUDE	"a2k6taud.inc"	; REVIEW: Is this required?

; Atari 2600 TIA Colour utilities.
;REVIEW;			.INCLUDE	"a2k6tcol.inc"	; REVIEW: Is this required?

; Atari 2600 TIA Video display utilities.
;REVIEW;			.INCLUDE	"a2k6tvid.inc"	; FIXME: temporarily disabled as build failing!

; Atari 2600 TIA Playfield utilities.
			.INCLUDE	"a2k6tpf.inc"

; Atari 2600 TIA Sprite utilities.
			.INCLUDE	"a2k6tspr.inc"

;------------------------------------------------------------------------------
; Expansion Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 Bank Switching utilities.
			.INCLUDE	"a2k6bank.inc"

; Atari 2600 Expansion RAM utilities.
;REVIEW;			.INCLUDE	"a2k6xram.inc"	; REVIEW: Is this required?

;------------------------------------------------------------------------------
; Joystick and Controller Extra Include.
;------------------------------------------------------------------------------

; Atari 2600 Common Joystick utilities.
;REVIEW:			.INCLUDE	"a2k6joy.inc"	; TODO: Impl.

; Atari 2600 Digital Joystick utilities.
;REVIEW:			.INCLUDE	"a2k6djoy.inc"	; TODO: Impl.

; Atari 2600 Analogue Joystick / Paddle utilities.
;REVIEW:			.INCLUDE	"a2k6ajoy.inc"	; TODO: Impl.

; Atari 2600 Driving Controller utilities.
;REVIEW:			.INCLUDE	"a2k6driv.inc"	; TODO: Impl.

; Atari 2600 Keyboard / Keypad utilities.
;REVIEW:			.INCLUDE	"a2k6keyb.inc"	; TODO: Impl.

; Atari 2600 Track Ball utilities.
;REVIEW:			.INCLUDE	"a2k6trak.inc"	; TODO: Impl.

; Atari 2600 Light Gun utilities.
;REVIEW:			.INCLUDE	"a2k6lgun.inc"	; TODO: Impl.

;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF



