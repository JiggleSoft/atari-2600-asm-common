;==============================================================================
; Name:         Atari 2600 kernel playfield 0.
; Filename:     a2k6_kernel_pf1.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2018-12-30 22:29
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 - Kernel
; 	Asymetric Playfield, Background Colour, Foreground Color Matrix.
;	Single stretch for Playfield, Background Colour and Foreground Colour.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
;				VID_VSYNV
;				VID_VBLANK
;				VID_VISIBLE
;				VID_OVERSCAN
;
;	0
;	1
;	2
;
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
.MACRO		KPF0_RBFPFCSV	rep,bgcol,fgcol,B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
	.BYTE		rep,bgcol,fgcol
	PFBM6CSV	B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO

.MACRO			KPF0_RBFPFVAL	rep,bgcol,fgcol,BVA,BVB
	.BYTE		rep,bgcol,fgcol
	PFBM6VAL	BVA,BVB
.ENDMACRO
;move to VID as a common structure.
;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
.MACRO			KPF1FG	len,col	
.ENDMACRO



;------------------------------------------------------------------------------
;
;------------------------------------------------------------------------------
.MACRO			KPF1BG	
.ENDMACRO




;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


