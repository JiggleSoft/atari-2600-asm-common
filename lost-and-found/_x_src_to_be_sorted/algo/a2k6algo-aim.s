;==============================================================================
; Name:         Atari 2600 - Algorithm - Aim Vector implementation.
; Filename:     a2k6algo-aim.s
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-12-15 00:49
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


            .BSS

; Input is aiming from and to X and Y location unsigned byte

aim_x1:     .RES        1
aim_y1:     .RES        1

aim_x2:       .RES        1
aim_y2:       .RES        1

; Working absolute delta X and Y (reduced to sig. bits), and quadrant X bit 6 and Y bit 7

aim_quad     .RES        1
aim_adx      .RES        1
aim_ady      .RES        1

; Output (4.4) delta X and Y fixed point signed byte.

aim_dx          .RES        1
aim_dy          .RES        1


            .DATA

x_table:

y_table:



delta_qxy     .RES        1   ; Delta quadrant x (bit 1) and y (bit 0)
delta_x     .RES        1   ; Absolute delta x
delta_y     .RES        1   ; Absolute delta y


; Determine delta and quadrant

            LDX         #$00
            LDY         #$00
;
            LDA         to_x
            SEC
            SBC         from_x
            BCS         ltr_x
            DEX
            DEX
            NEG         A
ltr_x:
            STA         delta_x

            LDA         to_y
            SEC
            SBC         from_y
            BCS         ttb_y
            INX
            NEG         A
ttb_y:
            STA         delta_y
            STX         delta_qxy

; Determine largest






            LDA         from_x
            SEC
            SBC         to_x
            STA         delta_x
            BCS         x_dir_l
x_dir_r:
            LDA         #00
            STA         delta_qx
            JMP         x_dir_done
x_dir_l:
            LDA         #FF
            STA         delta_qx
x_dir_done:

            LDA         from_y
            SEC
            SBC         to_y
            STA         delta_y
            BCS         y_dir_l
y_dir_r:
            LDA         #00
            STA         delta_qy
            JMP         y_dir_done
y_dir_l:
            LDA         #FF
            STA         delta_qy
y_dir_done:

shift_into_range:
            LDA         delta_x
            AND         delta_y
            AND         #$FC
            BEQ         done_shifting
            LDA         delta_x
            LSR
            STA         delta_x
            LDA         delta_y
            LSR
            STA         delta_y
            jmp         shift_into_range
done_shifting:

array_index:
            LDA         delta_y
            LSL
            LSL
            LSL
            ORA         delta_y

            RTS

