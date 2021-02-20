; STATUS: WORK IN PROGRESS.
;==============================================================================
; Title:        Atari 2600 RIOT Timer standard extra include file.
; Filename:     a2k6-stdx-rtim.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-15 20:48
; Version:      2.0.5
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

                .IFNDEF     __A2K6_STDX_RTIM__INC__
                            __A2K6_STDX_RTIM__INC__ = 1

;==============================================================================
; Atari 2600 RIOT Timer.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Write and Read Timer Macros.
;------------------------------------------------------------------------------

; Set the timer with an immediate value, with a division, and interrupt enable.
; Note: clears interrupt flag.
; Example: TIM_SET_TDI_IM $43,WTIMO_DIV_64,WTIMO_INT_E

.MACRO      TIM_SET_TDI_IM      time_val,time_div,time_int
            LDA                 #time_val
            STA                 WTIMB+time_div+time_int
.ENDMACRO


; Set the timer with immediate value, div by 64, int enabled, clear int flag.

.MACRO      TIM_SET_IM          time_val
            TIM_SET_TDI_IM      time_val,WTIMO_DIV_64,WTIMO_INT_E
.ENDMACRO


; Get the timer value, interrupt enable, clears interrupt flag.
; Example: TIM_GET_I RTIMO_INT_E

.MACRO      TIM_GET_I           time_int
            LDA                 RTIMB+time_int
.ENDMACRO


; Get the timer value, interrupt enable, clears interrupt flag.

.MACRO      TIM_GET
            TIM_GET_I RTIMO_INT_E
.ENDMACRO



;------------------------------------------------------------------------------
; Wait Timer Macros.
;------------------------------------------------------------------------------

; Wait for exact timer value, enables interrupt, clears interrupt flag.

.MACRO      TIM_WAIT_VAL_IM     time_val
            .LOCAL              wait_loop
wait_loop:
            CMP                 RTIMEINT
            BNE                 wait_loop
.ENDMACRO


; Wait for timer to go negative < 0 (bit 7 set).

.MACRO      TIM_WAIT_NEG
            .LOCAL              wait_loop
wait_loop:
            CMP                 RTIMEINT
            BPL                 wait_loop
.ENDMACRO


; Wait for timer interrupt flag. Clears PA7 interrupt flag.

.MACRO      TIM_WAIT_INT
            .LOCAL              wait_loop
wait_loop:
            BIT                 RTIMEINT
            BPL                 wait_loop
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------

                .ENDIF


