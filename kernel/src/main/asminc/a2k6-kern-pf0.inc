;==============================================================================
; Name:         Atari 2600 Kernel - Playfield 0.
; Filename:     a2k6kern-pf0.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-12-12 12:07
; Version:      2.0.0
;------------------------------------------------------------------------------
; Atari 2600 - Kernel - Playfield 0
;   Background Colour:  Single Value.
;   Foreground Colour:  Single Value.
;   Playfield:          Symetric or Asymetric, Repeat or Mirrored.
;   Playfield Width:    40 or 32 Playfield Blocks (4 TIA clocks each).
;   Playfield Height:   Single Value.
;   Note:               The playfield may consist of multiple regions of the
;                       above set of parameters.
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

                .IFNDEF     __A2K6KERN_PF0__INC__
                .DEFINE     __A2K6KERN_PF0__INC__

;==============================================================================
; Atari 2600 - Kernel = Playfield 0.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Kernel Runtime Data.
;------------------------------------------------------------------------------

				.DATA

				.IFNDEF		kpf0_vbcol
kpf0_vbcol:		.RES		1	; Vertical Blank Background Colour.
				.ENDIF

				.IFNDEF		kpf0_bkcol
kpf0_bkcol:		.RES		1	; Visible Display Background Colour.
				.ENDIF

				.IFNDEF		kpf0_pfcol
kpf0_pfcol:		.RES		1	; Playfield Colour.
				.ENDIF

				.IFNDEF		kpf0_oscol
kpf0_oscol:		.RES		1	; Overscan Background Colour.
				.ENDIF

				.IFNDEF		kpf0_height
kpf0_height:	.RES		1	; Number of Horizontal Lines of Playfield Data.
				.ENDIF

				.IFNDEF		kpf0_repeat
kpf0_repeat		.RES		1	; Size of each Horizontal Line (line repeat).
				.ENDIF

				.IFNDEF		kpf0_pfdat
kpf0_pfdat		.RES		2	; Playfield data address.
				.ENDIF

				.IFNDEF		kpf0_repeat
kpf0_pfptr		.RES		2	; Playfield current data pointer.
				.ENDIF



;------------------------------------------------------------------------------
; Configure the Kernel.
;------------------------------------------------------------------------------

; Configure Kernel frame data.

.MACRO		KPF0_FRAME_CONFIG_PTR		kpf0conf
			LDA			kppf0conf+0
			STA			kpf0_vbcol
			LDA			kppf0conf+1
			STA			kpf0_bkcol
			LDA			kppf0conf+2
			STA			kpf0_pfcol
			LDA			kppf0conf+3
			STA			kpf0_oscol
			LDA			kppf0conf+4
			STA			kpf0_height
			LDA			kppf0conf+5
			STA			kpf0_repeat
			LDA			#<(kpf0conf+6)
			STA			kpf0_pfdat
			STA			kpf0_pfptr
			LDA			#>(kpf0conf+6)
			STA			kpf0_pfdat+1
			STA			kpf0_pfptr+1
.ENDMACRO


; Configure Kernel

.MACRO		KPF0_FRAME_CONFIG		vpcol,bkcol,pfcol,oscol,height,repeat,pfdat
			LDA			#vbcol
			STA			kpf0_vbcol
			LDA			#bkcol
			STA			kpf0_bkcol
			LDA			#pfcol
			STA			kpf0_pfcol
			LDA			#oscal
			STA			kpf0_oscol
			LDA			#height
			STA			kpf0_height
			LDA			#repeat
			STA			kpf0_repeat
			LDA			#<pfdat
			STA			kpf0_pfdat
			STA			kpf0_pfptr
			LDA			#>pfdat
			STA			kpf0_pfdat+1
			STA			kpf0_pfptr+1
.ENDMACRO

;------------------------------------------------------------------------------
; Configure and Render Kernel to the Video Display.
;------------------------------------------------------------------------------





;------------------------------------------------------------------------------
; To Do.
;------------------------------------------------------------------------------

; EMPTY: FIX



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


