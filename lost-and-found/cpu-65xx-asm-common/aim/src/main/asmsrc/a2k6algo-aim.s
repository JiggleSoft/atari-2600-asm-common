;==============================================================================
; Name:         Atari 2600 - Algorithm - Aim Vector implementation.
; Filename:     a2k6algo-aim.s
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-01 22:30
; Version:      2.0.0
;------------------------------------------------------------------------------
; Copyright (c) 2021 Justin Lane
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



; Input is aiming from X1 and Y1 co-ordinates to X2 and Y2 co-ordinates (unsigned byte)

aim_x1:     .RES        1
aim_y1:     .RES        1

aim_x2:     .RES        1
aim_y2:     .RES        1

; Working absolute delta X and Y (reduced to sig. bits), and quadrant X bit 6 and Y bit 7

aim_adx     = $94 ;     .RES        1
aim_ady     = $95 ;     .RES        1
aim_quad    = $96 ;     .RES        1

; Output vector (4.4) delta X and Y fixed point (signed byte).

aim_vdx     = $97 ;     .RES        1
aim_vdy     = $98 ;     .RES        1




;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
aim:
    ; Calc abs delta X (aim_adx) from aim_x1 & aim_x2, also X dir (X reg).
            .LOCAL      x_dir_pos,x_dir_neg,x_dir_abs
            LDA         aim_x2
            SEC
            SBC         aim_x1
            BCC         x_dir_neg
x_dir_pos:
	        LDX         #$00        ; x delta positive (ltr)
            BCS         x_dir_abs   ; BRA (C=1)
x_dir_neg:
            LDX         #$40        ; x delta negative (rtl)
	        EOR         #$FF
            ADC		    #$01
x_dir_abs:
            STA		    aim_adx
    ; Calc abs delta X (aim_ady) from aim_y1 & aim_y2, also Y dir (Y reg).
            .LOCAL      y_dir_pos,y_dir_neg,y_dir_abs
            LDA         aim_y2
            SEC
            SBC         aim_y1
            BCC         y_dir_neg
y_dir_pos:
	        LDY         #$00        ; x delta positive (ttb)
            BCS         y_dir_abs   ; BRA (C=1)
y_dir_neg:
            LDY         #$80        ; x delta negative (btt)
	        EOR         #$FF
            ADC		    #$01
y_dir_abs:
            STA 	    aim_ady
    ; Merge X direction and Y direction flags.
            STY         aim_quad    ; store y delta direction bit 7
	        TXA                     ; x delta direction bit 6
            ORA         aim_quad    ; merge x delta direction with stored y delta direction
            STA	        aim_quad    ; store merged x and y delta direction.
    ; shift absolute delta x and absolute delta y into 3 bits of significance.
            .LOCAL      sig_div_by_2,sig_done
sig_div_by_2:
            LDA         aim_adx
            ORA         aim_ady
            AND         #%11111000
            BEQ         sig_done
            LSR         aim_adx
            LSR         aim_ady
            BPL         sig_div_by_2	; BRA (N=0)
sig_done:
;--------
    ; calculate X table offset.
;--------
            LDA         aim_ady
            ASL
            ASL
            ASL
            ORA         aim_adx
;--------
; table look up X value
;--------
	    TAX
	    LDA		aim_table,x
;--------
; correct value sign.
;--------
		BIT	aim_quad
                BPL	aim_quad_ltr
aim_quad_rtl:
                EOR	#$FF
                CLC
                ADC	#$01
aim_quad_ltr:
                STA	aim_vdx
;--------




    ; calculate Y table offset.
;--------
            LDA         aim_adx
            ASL
            ASL
            ASL
            ORA         aim_ady
;--------
; table look up Y value
;--------
	    TAX
	    LDA		aim_table,x
;--------
; correct value sign.
;--------
		BIT	aim_quad
                BVC	aim_quad_ttb
aim_quad_btt:
                EOR	#$FF
                CLC
                ADC	#$01
aim_quad_ttb:
                STA	aim_vdx
;--------



            RTS

aim_table_x:
 .byte $00,$01,$02,$03,$04,$05,$06,$07
 .byte $10,$11,$12,$13,$14,$15,$16,$17
 .byte $20,$21,$22,$23,$24,$25,$26,$27
 .byte $30,$31,$32,$33,$34,$35,$36,$37
 .byte $40,$41,$42,$43,$44,$45,$46,$47
 .byte $50,$51,$52,$53,$54,$55,$56,$57
 .byte $60,$61,$62,$63,$64,$65,$66,$67
 .byte $70,$71,$72,$73,$74,$75,$76,$77

aim_table_y:
 .byte $00,$01,$02,$03,$04,$05,$06,$07
 .byte $10,$11,$12,$13,$14,$15,$16,$17
 .byte $20,$21,$22,$23,$24,$25,$26,$27
 .byte $30,$31,$32,$33,$34,$35,$36,$37
 .byte $40,$41,$42,$43,$44,$45,$46,$47
 .byte $50,$51,$52,$53,$54,$55,$56,$57
 .byte $60,$61,$62,$63,$64,$65,$66,$67
 .byte $70,$71,$72,$73,$74,$75,$76,$77



 jmp fred





;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

.ENDIF


