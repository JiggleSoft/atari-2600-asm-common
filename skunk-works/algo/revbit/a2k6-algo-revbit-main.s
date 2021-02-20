;==============================================================================
; Title:        JiggleSoft's Atari 2600 Escape-MCP C64 Game Remake.
; Filename:     a2k6-emcp-c64-maps.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-04 00:13
; Version:      0.0.1
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

                .INCLUDE        "a2k6std.inc"
;                .INCLUDE        "a2k6stdx.inc"

                ;.INCLUDE        "a2k6cpu.inc"

                CPU_CONFIG_VECTOR   startup

                .INCLUDE        "asminc/a2k6-algo-revbit.inc"

startup:

		nop
		nop

loop:
		nop
		nop

; REG   A+X+Y 0     0     0     44    88    Registers only.
		;lda	#%01100011
		;nop
		;REVBIT_REG
		;nop
		;nop

; STACK A     0     7     0     30    81    Stack carry.
		;lda	#%01100011
		;nop
		;REVBIT_STACK
		;nop
		;nop

; MEM   A     1     0     0     26/35 59/68 Memory (temporary byte).
		;lda	#%01100011
		;nop
		;REVBIT_MEM $C0
		;nop
		;nop

; NYBL1 A+X|Y 1     1     16    24/26 43/45 Nybble look-up v1 (2 x 4-bit).
		lda	#%01100011
		nop
		REVBIT_NLUT1_X table_16,$C1
		nop
		nop

; NLUT2 A+X|Y 1     1     32    20/22 35/37 Nybble look-up v2 (2 x 4-bit).
		;lda	#%01100011
		;nop
		;REVBIT_NLUT2_X table_32,$C2
		;nop
		;nop

; BLUT  A+X|Y 0     0     256   4     6     Byte look-up (8-bit).
		;lda	#%01100011
		;nop
		;REVBIT_BLUT_X	table_256
		;nop
		;nop


		nop
		nop

		jmp		loop


 .RODATA


table_16:	REVBIT_NLUT2_DATA


table_32:	REVBIT_NLUT2_DATA


table_256:	REVBIT_BLUT_DATA










