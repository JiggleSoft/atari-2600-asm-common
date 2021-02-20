;==============================================================================
; Title:        Atari 2600 - Kernel - PF0 - Example 01 main file.
; Filename:     a2k6-kern-pf0-example-01.s
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-12-19 21:30
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

                .PUSHSEG


                .RODATA

playfield_data:
    PF012L012R_CSV  B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B
    PF012L012R_CSV  B,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,B
    PF012L012R_CSV  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_
    PF012L012R_CSV  B,B,B,_,B,_,B,_,B,B,B,_,B,B,B,_,B,_,B,B,B,_,_,_,_,B,_,_,_,B,B,B,_,B,B,B,_,B,B,B
    PF012L012R_CSV  _,B,_,_,B,_,B,_,B,_,_,_,_,B,_,_,B,_,B,_,B,_,_,_,_,B,_,_,_,B,_,B,_,B,_,B,_,B,_,_
    PF012L012R_CSV  _,B,_,_,B,_,B,_,B,B,B,_,_,B,_,_,B,_,B,_,B,_,_,_,_,B,_,_,_,B,_,B,_,B,_,B,_,B,B,B
    PF012L012R_CSV  _,B,_,_,B,_,B,_,_,_,B,_,_,B,_,_,B,_,B,_,B,_,_,_,_,B,_,_,_,B,_,B,_,B,_,B,_,B,_,_
    PF012L012R_CSV  B,B,_,_,B,B,B,_,B,B,B,_,_,B,_,_,B,_,B,_,B,_,_,_,_,B,B,B,_,B,_,B,_,B,_,B,_,B,B,B
    PF012L012R_CSV  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_
    PF012L012R_CSV  B,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,B
    PF012L012R_CSV  B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B
    PF012L012R_CSV  B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B,_,_,B
    PF012L012R_CSV  B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B
    PF012L012R_CSV  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_
    PF012L012R_CSV  B,B,B,_,B,_,B,B,B,B,_,B,B,B,B,_,B,_,_,_,B,B,B,_,B,B,B,_,B,B,B,_,B,B,B,_,B,B,B,_
    PF012L012R_CSV  _,B,_,_,B,_,B,_,_,_,_,B,_,_,_,_,B,_,_,_,B,_,_,_,B,_,_,_,B,_,B,_,B,_,_,_,_,B,_,_
    PF012L012R_CSV  _,B,_,_,B,_,B,_,B,B,_,B,_,B,B,_,B,_,_,_,B,B,B,_,B,B,B,_,B,_,B,_,B,B,B,_,_,B,_,_
    PF012L012R_CSV  _,B,_,_,B,_,B,_,_,B,_,B,_,_,B,_,B,_,_,_,B,_,_,_,_,_,B,_,B,_,B,_,B,_,_,_,_,B,_,_
    PF012L012R_CSV  B,B,_,_,B,_,B,B,B,B,_,B,B,B,B,_,B,B,B,_,B,B,B,_,B,B,B,_,B,B,B,_,B,_,_,_,_,B,_,_
    PF012L012R_CSV  _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_
    PF012L012R_CSV  B,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,B
    PF012L012R_CSV  B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B


colour_data:
                .BYTE       $26
                .BYTE       $28
                .BYTE       $2A
                .BYTE       $2C
                .BYTE       $2E
                .BYTE       $2A
                .BYTE       $28
                .BYTE       $46
                .BYTE       $48
                .BYTE       $4A
                .BYTE       $4C
                .BYTE       $4E
                .BYTE       $4C
                .BYTE       $4A
                .BYTE       $48
                .BYTE       $86
                .BYTE       $88
                .BYTE       $8A
                .BYTE       $8C
                .BYTE       $8E
                .BYTE       $8C
                .BYTE       $8A


                .POPSEG


