; STATUS: WORK IN PROGRESS.
;==============================================================================
; Title:        Atari 2600 TIA Playfield standard extra include file.
; Filename:     a2k6-stdx-tpf.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2021-01-23 21:18
; Version:      2.0.4
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

                .IFNDEF     __A2K6_STDX_TPF__INC__
                            __A2K6_STDX_TPF__INC__ = 1

;==============================================================================
; Atari 2600 TIA Playfield.
;==============================================================================

                .INCLUDE    "a2k6-stdx-util.inc"

				.PUSHSEG

;------------------------------------------------------------------------------
; Playfield Data Description Macros.
;------------------------------------------------------------------------------

; Playfield 0 left or right byte comma separated 4 bits (display 0-3 or 20-23).

.MACRO		PF0LR_CSV			B0,B1,B2,B3
			BYTE_4_7_CSV	    B0,B1,B2,B3
.ENDMACRO


; Playfield 0 right mirrored byte comma separated 4 bits (display 36-39).

.MACRO		PF0RM_CSV	    	B0,B1,B2,B3
            BYTE_7_4_CSV        B0,B1,B2,B3
.ENDMACRO


; Playfield 1 left or right byte comma separated 8 bits (display 4-11 or 24-31).

.MACRO		PF1LR_CSV		    B4,B5,B6,B7,B8,B9,B10,B11
			BYTE_7_0_CSV	    B4,B5,B6,B7,B8,B9,B10,B11
.ENDMACRO


; Playfield 1 right mirrored byte comma separated 8 bits (display 28-35).

.MACRO		PF1RM_CSV		    B28,B29,B30,B31,B32,B33,B34,B35
			BYTE_0_7_CSV	    B28,B29,B30,B31,B32,B33,B34,B35
.ENDMACRO


; Playfield 2 left or right byte comma separated 8 bits (display 12-19 or 32-39).

.MACRO		PF2LR_CSV		    B12,B13,B14,B15,B16,B17,B18,B19
			BYTE_0_7_CSV	    B12,B13,B14,B15,B16,B17,B18,B19
.ENDMACRO


; Playfield 2 right mirrored byte comma separated 8 bits (display 20-27).

.MACRO		PF2RM_CSV		B20,B21,B22,B23,B24,B25,B26,B27
			BYTE_7_0_CSV	B20,B21,B22,B23,B24,B25,B26,B27
.ENDMACRO



;------------------------------------------------------------------------------

; Playfield 0 left and right byte comma separated 8 bits (display 0-3 and 20-23).
; Note that the right bits need to be ASL 4 to allow the bits to be used.

.MACRO		PF0L0R_CSV			B0,B1,B2,B3,B20,B21,B22,B23
			BYTE_4_7_0_3_CSV	B0,B1,B2,B3,B20,B21,B22,B23
.ENDMACRO


; Playfield 0 left and right mirrored byte comma separated 8 bits (display 0-3 and 36-39).
; Note that the right bits need to be ASL 4 to allow the bits to be used.

.MACRO		PF0L0RM_CSV			B0,B1,B2,B3,B36,B37,B38,B39
			BYTE_4_7_3_0_CSV	B0,B1,B2,B3,B36,B37,B38,B39
.ENDMACRO



;------------------------------------------------------------------------------

; Playfield 1+2 left or right 2 bytes comma separated 16 bits (display 4-19 or 20-35).

.MACRO		PF12LR_CSV	    B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19
			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
.ENDMACRO


; Playfield 2+1 right mirrored 2 bytes comma separated 20 bits (display 20-35).

.MACRO		PF21LR_CSV	    B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35
            PF2RM_CSV       B20,B21,B22,B23,B24,B25,B26,B27
			PF1RM_CSV	    B28,B29,B30,B31,B32,B33,B34,B35
.ENDMACRO


; Playfield 0+1+2 left or right 3 bytes comma separated 20 bits (display 0-19 or 20-39).

.MACRO		PF012LR_CSV	    B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19
			PF0LR_CSV		B0,B1,B2,B3
			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
.ENDMACRO


; Playfield 2+1+0 right mirrored 3 bytes comma separated 20 bits (display 20-39).

.MACRO      PF210RM_CSV	    B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
            PF2RM_CSV       B20,B21,B22,B23,B24,B25,B26,B27
			PF1RM_CSV	    B28,B29,B30,B31,B32,B33,B34,B35
			PF0RM_CSV	    B36,B37,B38,B39
.ENDMACRO



;------------------------------------------------------------------------------

; Playfield 1+2+1+2 left and right 4 bytes comma separated 32 bits (display 4-19-20-35).

.MACRO		PF12L12R_CSV    B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35
			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
			PF1LR_CSV		B20,B21,B22,B23,B24,B25,B26,B27
			PF2LR_CSV		B28,B29,B30,B31,B32,B33,B34,B35
.ENDMACRO


; Playfield 1+2+2+1 left standard and right mirrored 4 bytes comma separated 32 bits (display 4-19-20-35).

.MACRO		PF12L21RM_CSV    B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35
			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
            PF2RM_CSV       B20,B21,B22,B23,B24,B25,B26,B27
			PF1RM_CSV	    B28,B29,B30,B31,B32,B33,B34,B35
.ENDMACRO


; Playfield 0+1+2+0+1+2 left and right 6 bytes comma separated 40 bits (display 0-19-20-39).

.MACRO		PF012L012R_CSV  B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
			PF0LR_CSV		B0,B1,B2,B3
			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
			PF0LR_CSV		B20,B21,B22,B23
			PF1LR_CSV		B24,B25,B26,B27,B28,B29,B30,B31
			PF2LR_CSV		B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO


; Playfield 0+1+2+2+1+0 right mirrored 3 bytes comma separated 40 bits (display 0-39).

.MACRO		PF012L210RM_CSV B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
			PF0LR_CSV		B0,B1,B2,B3
			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
            PF2RM_CSV       B20,B21,B22,B23,B24,B25,B26,B27
			PF1RM_CSV	    B28,B29,B30,B31,B32,B33,B34,B35
			PF0RM_CSV	    B36,B37,B38,B39
.ENDMACRO



;------------------------------------------------------------------------------
;FIXME

;; Playfield 00+1+2+1+2 left or right 3 bytes comma separated 20 bits (display 0-19 or 20-30).
;
;.MACRO		PF0L0R1212R_CSV B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19
;			PF0LR_CSV		B0,B1,B2,B3
;			PF1LR_CSV		B4,B5,B6,B7,B8,B9,B10,B11
;			PF2LR_CSV		B12,B13,B14,B15,B16,B17,B18,B19
;.ENDMACRO
;
;
;; Playfield 00+1+2+2+1 right mirrored 3 bytes comma separated 20 bits (display 20-39).
;
;.MACRO		PF0L0RM12L21RM_CSV  B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
;            PF2RM_CSV       B20,B21,B22,B23,B24,B25,B26,B27
;			PF1RM_CSV	    B28,B29,B30,B31,B32,B33,B34,B35
;			PF0RM_CSV	    B36,B37,B38,B39
;.ENDMACRO



;------------------------------------------------------------------------------
;FIXME: REVIEW !!!!!!!!!!!!!

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

                .ENDIF


