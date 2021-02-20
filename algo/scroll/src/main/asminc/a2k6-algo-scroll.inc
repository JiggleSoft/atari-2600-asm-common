;==============================================================================
; Title:        Atari 2600 - Algorithm - Scroll include file.
; Filename:     a2k6-algo-scroll.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-02-13 00:10
; Version:      2.0.1
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


;------------------------------------------------------------------------------
; Shift or Rotate a Line of Memory by 1 Bit Either Left or Right.
;------------------------------------------------------------------------------

; Shift a line of memory left by 1 bit.

.MACRO      SCROLL_SHIFT_ABS_MEM_LINE_LEFT  ptr,num
            asl         ptr+num-1
            .REPEAT num-1
            rol         ptr+num-2-INDEX
            .ENDREP
.ENDMACRO


; Shift a line of memory right by 1 bit.

.MACRO      SCROLL_SHIFT_ABS_MEM_LINE_RIGHT ptr,num
            lsr         ptr
            .REPEAT num-1
            ror         ptr+1+INDEX
            .ENDREP
.ENDMACRO


; Shift a line of memory left by 1 bit with carry.

.MACRO      SCROLL_SHIFT_ABS_MEM_LINE_LEFT_CARRY  ptr,num
            .REPEAT num
            rol         ptr+num-1-INDEX
            .ENDREP
.ENDMACRO


; Shift a line of memory right by 1 bit with carry.

.MACRO      SCROLL_SHIFT_ABS_MEM_LINE_RIGHT_CARRY ptr,num
            .REPEAT num
            ror         ptr+INDEX
            .ENDREP
.ENDMACRO


; Rotate a line of memory left by 1 bit.

.MACRO      SCROLL_ROTATE_MEM_LINE_LEFT ptr,num
            lda     ptr
            asl
            .REPEAT num
            rol         ptr+num-1-INDEX
            .ENDREP
.ENDMACRO


; Rotate a line of memory right by 1 bit.

.MACRO      SCROLL_ROTATE_MEM_LINE_RIGHT ptr,num
            lda     ptr+num-1
            lsr
            .REPEAT num
            ror     ptr+INDEX
            .ENDREP
.ENDMACRO



;------------------------------------------------------------------------------
; Shift or Rotate a Block of Memory by 1 Bit Either Left or Right.
;------------------------------------------------------------------------------

; Shift a block of memory left by 1 bit.

.MACRO      SCROLL_SHIFT_ABS_MEM_BLOCK_LEFT  ptr,width,height
            .REPEAT height
            SCROLL_SHIFT_ABS_MEM_LINE_LEFT  ptr+(width*INDEX),width
            .ENDREP
.ENDMACRO


; Shift a block of memory right by 1 bit.

.MACRO      SCROLL_SHIFT_ABS_MEM_BLOCK_RIGHT ptr,width,height
            .REPEAT height
            SCROLL_SHIFT_MEM_LINE_RIGHT  ptr+(width*INDEX),width
            .ENDREP
.ENDMACRO


; Rotate a block of memory left by 1 bit.

.MACRO      SCROLL_ROTATE_ABS_MEM_BLOCK_LEFT ptr,width,height
            .REPEAT height
            SCROLL_ROTATE_ABS_MEM_LINE_LEFT  ptr+(width*INDEX),width
            .ENDREP
.ENDMACRO


; Rotate a block of memory right by 1 bit.

.MACRO      SCROLL_ROTATE_ABS_MEM_BLOCK_RIGHT ptr,width,height
            .REPEAT height
            SCROLL_ROTATE_ABS_MEM_LINE_RIGHT  ptr+(width*INDEX),width
            .ENDREP
.ENDMACRO



;------------------------------------------------------------------------------
; Shift or Rotate 20 Pixels of Playfield Memory by 1 Bit Either Left or Right.
;------------------------------------------------------------------------------

; Shift 20 pixels of playfield memory left by 1 bit.

.MACRO      SCROLL_SHIFT_ABS_MEM_PF012_LEFT    ptr
            lsr         ptr+2
            rol         ptr+1
            ror         ptr
.ENDMACRO


; Shift 20 pixels of playfield memory right by 1 bit.

.MACRO      SCROLL_SHIFT_ABS_MEM_PF012_RIGHT    ptr
            asl         ptr
            ror         ptr+1
            rol         ptr+2
.ENDMACRO


; Rotate 20 pixels of playfield memory left by 1 bit.

.MACRO      SCROLL_ROTATE_ABS_MEM_PF012_LEFT    ptr
            lda         ptr
            asl
            asl
            asl
            asl
            ror         ptr+2
            rol         ptr+1
            ror         ptr
.ENDMACRO


; Rotate 20 pixels of playfield memory right by 1 bit.

.MACRO      SCROLL_ROTATE_ABS_MEM_PF012_RIGHT    ptr
            lda         ptr+2
            lsr
            lsr
            lsr
            lsr
            ora         ptr
            asl
            sta         ptr
            ror         ptr+1
            rol         ptr+2
.ENDMACRO



;------------------------------------------------------------------------------
; Shift or Rotate 40 Pixels of Playfield Memory by 1 Bit Either Left or Right.
;------------------------------------------------------------------------------
;FIXME
;; Shift 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012012_LEFT    ptr
;            lsr         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Shift 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012012_RIGHT    ptr
;            asl         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
; Shift 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012210_LEFT    ptr
;            lsr         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Shift 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012210_RIGHT    ptr
;            asl         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012012_LEFT    ptr
;            lda         ptr
;            asl
;            asl
;            asl
;            asl
;            ror         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012102_RIGHT    ptr
;            lda         ptr+2
;            lsr
;            lsr
;            lsr
;            lsr
;            ora         ptr
;            asl
;            sta         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012210_LEFT    ptr
;            lda         ptr
;            asl
;            asl
;            asl
;            asl
;            ror         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012210_RIGHT    ptr
;            lda         ptr+2
;            lsr
;            lsr
;            lsr
;            lsr
;            ora         ptr
;            asl
;            sta         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO



;------------------------------------------------------------------------------
; Shift or Rotate Playfield 40 + Buffer Memory by 1 Bit Either Left or Right.
;------------------------------------------------------------------------------
;FIXME
;; Shift 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012012_LEFT    ptr
;            lsr         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Shift 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012012_RIGHT    ptr
;            asl         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
;FIXME
;; Shift 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012210_LEFT    ptr
;            lsr         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Shift 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_SHIFT_ABS_MEM_PF012210_RIGHT    ptr
;            asl         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012012_LEFT    ptr
;            lda         ptr
;            asl
;            asl
;            asl
;            asl
;            ror         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012102_RIGHT    ptr
;            lda         ptr+2
;            lsr
;            lsr
;            lsr
;            lsr
;            ora         ptr
;            asl
;            sta         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory left by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012210_LEFT    ptr
;            lda         ptr
;            asl
;            asl
;            asl
;            asl
;            ror         ptr+2
;            rol         ptr+1
;            ror         ptr
;.ENDMACRO
;
;
;; Rotate 40 pixels of playfield memory right by 1 bit.
;
;.MACRO      SCROLL_ROTATE_ABS_MEM_PF012210_RIGHT    ptr
;            lda         ptr+2
;            lsr
;            lsr
;            lsr
;            lsr
;            ora         ptr
;            asl
;            sta         ptr
;            ror         ptr+1
;            rol         ptr+2
;.ENDMACRO
;
;
;