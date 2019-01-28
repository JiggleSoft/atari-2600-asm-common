;==============================================================================
; Name:         Atari 2600 TIA Playfield utilities include file.
; Filename:     a2k6tpf.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-28 19:33
; Vesion:		1.1.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 TIA Playfield utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Playfield Data Description Macros.
;------------------------------------------------------------------------------

; Playfield 0 bitmap data byte comma separated bits (displayed bits 0-3).

.MACRO		PF0_CSV			B0,B1,B2,B3
			BYTE_4_7_CSV	B0,B1,B2,B3
.ENDMACRO



; Playfield 0(left)+0(right) nybble data byte comma separated (bits 0-3,20-23).

.MACRO		PF0L0R_CSV			B0,B1,B2,B3,B20,B21,B22,B23
			BYTE_4_7_0_3_CSV	B0,B1,B2,B3,B20,B21,B22,B23
.ENDMACRO



; Playfield 1 bitmap data byte comma separated bits (display bits 4-11).

.MACRO		PF1_CSV			B4,B5,B6,B7,B8,B9,B10,B11
			BYTE_7_0_CSV	B4,B5,B6,B7,B8,B9,B10,B11
.ENDMACRO



; Playfield 2 bitmap data byte comma separated bits (display bits 12-19).

.MACRO		PF2_CSV			B12,B13,B14,B15,B16,B17,B18,B19
			BYTE_0_7_CSV	B12,B13,B14,B15,B16,B17,B18,B19
.ENDMACRO



; Playfield 0,1,2 bitmap 3 data bytes comma separated bits (display bits 0-19).

.MACRO		PF_3_20CSV	B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19
			PF0_CSV		B0,B1,B2,B3
			PF1_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2_CSV		B12,B13,B14,B15,B16,B17,B18,B19
.ENDMACRO



; Playfield 0,1,2,0,1,2 bitmap 6 data bytes comma separated bits (bits 0-39).

.MACRO		PF_6_40CSV	B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
			PF0_CSV		B0,B1,B2,B3
			PF1_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2_CSV		B12,B13,B14,B15,B16,B17,B18,B19
			PF0_CSV		B20,B21,B22,B23
			PF1_CSV		B24,B25,B26,B27,B28,B29,B30,B31
			PF2_CSV		B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO



; Playfield 0(left)+0(right),1,2,1,2 bitmap 5 data bytes comma sep.(bits 0-39).

.MACRO		PF_5_40CSV		B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
			PF0L0R_CSV		B0,B1,B2,B3,B20,B21,B22,B23
			PF1_CSV			B4,B5,B6,B7,B8,B9,B10,B11
			PF2_CSV			B12,B13,B14,B15,B16,B17,B18,B19
			PF1_CSV			B24,B25,B26,B27,B28,B29,B30,B31
			PF2_CSV			B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO



; Playfield 0 bitmap data byte value (display bits 0-3).

.MACRO		PF0_VAL			NV
			BYTE_4_7_VAL	NV
.ENDMACRO



; Playfield 0 (left) + 0 (right) compressed data byte value (bits 0-3, 20-23).

.MACRO		PF0L0R_VAL			NVL,NVR
			BYTE_4_7_0_3_VAL	NVL,NVR
.ENDMACRO



; Playfield 1 bitmap data byte value (display bits 4-11).

.MACRO		PF1_VAL			BV
			BYTE_7_0_VAL	BV
.ENDMACRO



; Playfield 2 bitmap data byte value (display bits 12-19).

.MACRO		PF2_VAL			BV
			BYTE_0_7_VAL	BV
.ENDMACRO



; Playfield 0,1,2 bitmap 3 data byte values (display bits 0-19).

.MACRO		PF_3_3VAL		NV0,BV1,BV2
			PF0_VAL			NV0
			PF1_VAL			BV1
			PF2_VAL			BV2
.ENDMACRO



; Playfield 0,1,2 (left), 0,1,2 (right) bitmap 6 data byte values (bits 0-19).

.MACRO		PF_6_6VAL		NV0L,BV1L,BV2L,NV0R,BV1R,BV2R
			PF_3_3VAL		NV0L,BV1L,BV2L
			PF_3_3VAL		NV0R,BV1R,BV2R
.ENDMACRO



; Playfield 0(left)+0(right),1,2(left),1,2(right) bitmap 5 bytes (bits 0-39).

.MACRO		PF_5_6VAL		NV0L,BV1L,BV2L,NV0R,BV1R,BV2R
			PF0L0R_VAL		NV0L,NV0R
			PF1_VAL			BV1L
			PF2_VAL			BV2L
			PF1_VAL			BV1R
			PF2_VAL			BV2R
.ENDMACRO



; Playfield 0, 1, 2 bitmap 3 data byte values (display bits 0-19).

.MACRO		PF_3_VAL		BV
			PF0_VAL			((BV&$000F0000)>>16)
			PF1_VAL			((BV&$0000FF00)>>8)
			PF2_VAL			(BV&$00000FF)
.ENDMACRO



; Playfield 0,1,2 (left), 0,1,2 (right) bitmap 6 data byte values (bits 0-39).

.MACRO		PF_6_2VAL		BVL,BVR
			PF_3_VAL		BVL
			PF_3_VAL		BVR
.ENDMACRO



; Playfield 0(left)+0(right),1,2(left),1,2(right) bitmap 5 bytes (bits 0-39).

.MACRO		PF_5_2VAL		BVL,BVR
			PF0L0R_VAL		((BVL&$000F0000)>>16),((BVR&$000F0000)>>16)
			PF1_VAL			((BVL&$0000FF00)>>8)
			PF2_VAL			(BVL&$00000FF)
			PF1_VAL			((BVR&$0000FF00)>>8)
			PF2_VAL			(BVR&$00000FF)
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


