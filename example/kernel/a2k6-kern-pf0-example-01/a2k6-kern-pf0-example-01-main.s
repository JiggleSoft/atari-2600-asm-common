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

; Config

;------------------------------------------------------------------------------

                .INCLUDE        "atari2k6.inc"

;------------------------------------------------------------------------------

                CPU_CONFIG_VECTOR       cold_start

;------------------------------------------------------------------------------

                .CODE

cold_start:
                A2K6_TINY_INIT_COLD
main:
; END OF OVERSCAN
                LDA         #VSYNC_ON
                STA         WSYNC
; START OF VBLANK + VSYNC
                STA         VSYNC
                STA         WSYNC
                STA         WSYNC
                LDA         #VSYNC_OFF
                STA         WSYNC
; VBLANK + END OF VSYNC
                STA         VSYNC

.REPEAT 36
                STA         WSYNC
.ENDREP
                LDA #$C0
                STA COLUBK
 STA PF0
 TAX
                LDA #$7E
                STA COLUPF
                STA         WSYNC


                LDA         #VBLANKF_DUMP|VBLANKF_LATCH
                STA         VBLANK

                LDA #$7E
                STA COLUPF
                STA         WSYNC
                LDA #$50

 STA PF0

.REPEAT 242
                STX COLUBK
 INX
  INX
                 STA         WSYNC
.ENDREP

.REPEAT 39

                STA         WSYNC
.ENDREP
                JMP main



                ;KERN_PF0_INIT

 LDA #$C8
 STA COLUBK
 LDA #$FE
 STA COLUPF

 			STA         WSYNC
 			LDA			#VSYNC_ON
 			STA			VSYNC
 			STA         WSYNC
 			STA         WSYNC
 			STA         WSYNC
			LDA			#VSYNC_OFF
			STA			VSYNC
			LDX         #40-3
top:		STA         WSYNC
			DEX
			BNE         top


            LDX         #242
mid:		STA         WSYNC
            TXA
            STA         PF1
   			DEX
  			BNE         bot



			LDX         #30
bot:		STA         WSYNC
			DEX
			BNE         bot



main_loop:
                ;KERN_PF0_START_FRAME    0,1,1,01,01

;;;;;                PF0_LR_
                ;KERN_PF0_RENDER_FRAME   playfield_data,colour_data
                ;KERN_PF0_END_FRAME
 ;ldx #$40
 ;ldy #120
;colloop:
; STX COLUBK
; INX
; INX
; STA WSYNC
; STA WSYNC
; dey
; bne colloop
                JMP             main_loop

                ;KERN_PF0_DONE

endless_loop:
                NOP
                JMP             endless_loop


                .INCLUDE        "a2k6-kern-pf0-example-01-gfx.inc"


