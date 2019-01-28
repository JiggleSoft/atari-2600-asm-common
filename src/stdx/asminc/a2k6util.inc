;==============================================================================
; Name:         Atari 2600 utilities include file.
; Filename:     a2k6util.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-28 19:34
; Vesion:		1.1.0
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Utilities.
;==============================================================================

		.PUSHSEG

;------------------------------------------------------------------------------
; Common Variables
;------------------------------------------------------------------------------

; 0 = Not running, < 0 = Not running mode number e.g. screen saveer, hi score > 0 = running.

;? REVIEW; method to enable/disable???
;.IFNDEF		game_mode
;			.PUSHSEG
;			.DATA
;game_mode	.BYTE		1
;			.POPSEG
;.ENDIF



;------------------------------------------------------------------------------
; Common Constant Values.
;------------------------------------------------------------------------------

NULL	=		$0000	; Null.
FALSE	=		0		; Unset bit (zero).
TRUE	=		$FF		; All bits set (minus one).



;------------------------------------------------------------------------------
; Common Constant Data Values For Use In CSV Bitmaps.
;------------------------------------------------------------------------------

_		=		0	; Unset bit (zero).
B		=		1	; Set bit (one).



;------------------------------------------------------------------------------
; Data Byte 8-bits of Data.
;------------------------------------------------------------------------------

; Data byte bitmap comma separated bits (ordered bits 7-0).

.MACRO	BYTE_7_0_CSV	B7,B6,B5,B4,B3,B2,B1,B0
		.BYTE	(B7<<7)|(B6<<6)|(B5<<5)|(B4<<4)|(B3<<3)|(B2<<2)|(B1<<1)|(B0)
.ENDMACRO



; Data byte bitmap comma separated bits (ordered bits 0-7).

.MACRO	BYTE_0_7_CSV	B0,B1,B2,B3,B4,B5,B6,B7
		.BYTE	(B7<<7)|(B6<<6)|(B5<<5)|(B4<<4)|(B3<<3)|(B2<<2)|(B1<<1)|(B0)
.ENDMACRO



; Data byte bitmap value (8-bits)

.MACRO	BYTE_VAL		BV
		.BYTE	(BV&$FF)
.ENDMACRO



; Data byte bitmap value (bits 7-0 populated from value hi to lo).

.MACRO	BYTE_7_0_VAL	BV
		.BYTE	(BV&$FF)
.ENDMACRO



; Data byte bitmap value (bits 0-7 populated from value hi to lo).

.MACRO	BYTE_0_7_VAL	BV
		.BYTE	((BV&$80)>>7)|((BV&$40)>>5)|((BV&$20)>>3)|((BV&$10)>>1)|((BV&$08)<<1)|((BV&$04)<<3)|((BV&$02)<<5)|((BV&$01)<<7)
.ENDMACRO



;------------------------------------------------------------------------------
; Data Byte 8-bits of Data Populated by 4-bits (nybble) of Data.
;------------------------------------------------------------------------------

; Data byte bitmap comma separated nybble of bits (bits 3-0) with fill bit.

.MACRO	BYTE_3_0_F_CSV	B3,B2,B1,B0,BF
		.BYTE	(BF<<7)|(BF<<6)|(BF<<5)|(BF<<4)|(B3<<3)|(B2<<2)|(B1<<1)|(B0)
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 0-3) with fill bit.

.MACRO	BYTE_0_3_F_CSV	B0,B1,B2,B3,BF
		.BYTE	(BF<<7)|(BF<<6)|(BF<<5)|(BF<<4)|(B3<<3)|(B2<<2)|(B1<<1)|(B0)
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 7-4) with fill bit.

.MACRO	BYTE_7_4_F_CSV	B7,B6,B5,B4,BF
		.BYTE	(B7<<7)|(B6<<6)|(B5<<5)|(B4<<4)|(BF<<3)|(BF<<2)|(BF<<1)|(BF)
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 4-7) with fill bit.

.MACRO	BYTE_4_7_F_CSV	B4,B5,B6,B7,BF
		.BYTE	(B7<<7)|(B6<<6)|(B5<<5)|(B4<<4)|(BF<<3)|(BF<<2)|(BF<<1)|(BF)
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 3-0) filled with 0.

.MACRO	BYTE_3_0_CSV	B3,B2,B1,B0
		BYTE_3_0_F_CSV	B3,B2,B1,B0,0
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 0-3) filled with 0.

.MACRO	BYTE_0_3_CSV	B0,B1,B2,B3
		BYTE_0_3_F_CSV	B0,B1,B2,B3,0
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 7-4) filled with 0.

.MACRO	BYTE_7_4_CSV	B7,B6,B5,B4
		BYTE_7_4_F_CSV	B7,B6,B5,B4,0
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 4-7) filled with 0.

.MACRO	BYTE_4_7_CSV	B4,B5,B6,B7
		BYTE_4_7_F_CSV	B4,B5,B6,B7,0
.ENDMACRO



; Data byte from nybble value (bits 3-0 populated from hi to lo) with fill bit.

.MACRO	BYTE_3_0_F_VAL	NV,BF
		.BYTE	(BF<<7)|(BF<<6)|(BF<<5)|(BF<<4)|(NV&$0F)
.ENDMACRO



; Data byte from nybble value (bits 0-3 populated from hi to lo) with fill bit.

.MACRO	BYTE_0_3_F_VAL	NV,BF
		.BYTE	(BF<<7)|(BF<<6)|(BF<<5)|(BF<<4)|((NV&$08)>>3)|((NV&$04)>>1)|((NV&$02)<<1)|((NV&$01)<<3)
.ENDMACRO



; Data byte from nybble value (bits 7-4 populated from hi to lo) with fill bit.

.MACRO	BYTE_7_4_F_VAL	NV,BF
		.BYTE	((NV&$0F)<<4)|(BF<<3)|(BF<<2)|(BF<<1)|(BF)
.ENDMACRO



; Data byte from nybble value (bits 4-7 populated from hi to lo) with fill bit.

.MACRO	BYTE_4_7_F_VAL	NV,BF
		.BYTE	((NV&$08)<<1)|((NV&$04)<<3)|((NV&$02)<<5)|((NV&$01)<<7);|(BF<<3)|(BF<<2)|(BF<<1)|(BF)
.ENDMACRO



; Data byte from nybble value (bits 3-0 populated from hi to lo) filled with 0.

.MACRO	BYTE_3_0_VAL	NV
		BYTE_3_0_F_VAL	NV,0
.ENDMACRO



; Data byte from nybble value (bits 0-3 populated from hi to lo) filled with 0.

.MACRO	BYTE_0_3_VAL	NV
		BYTE_0_3_F_VAL	NV,0
.ENDMACRO



; Data byte from nybble value (bits 7-4 populated from hi to lo) filled with 0.

.MACRO	BYTE_7_4_VAL	NV
		BYTE_7_4_F_VAL	NV,0
.ENDMACRO



; Data byte from nybble value (bits 4-7 populated from hi to lo) filled with 0.

.MACRO	BYTE_4_7_VAL	NV
		BYTE_4_7_F_VAL	NV,0
.ENDMACRO



; Data byte bitmap comma separated nybble of bits (bits 4-7,0-3).

.MACRO	BYTE_4_7_0_3_CSV	B4,B5,B6,B7,B0,B1,B2,B3
		.BYTE	(B7<<7)|(B6<<6)|(B5<<5)|(B4<<4)|(B3<<3)|(B2<<2)|(B1<<1)|(B0)
.ENDMACRO



; Data byte from two nybble values (bits 7-4, 3-0 populated from hi to lo).

.MACRO	BYTE_H_L_VAL	NVH,NVL
		.BYTE	((NVH&$0F)<<4)|(NVL&$0F)
.ENDMACRO



; Data byte from two nybble values (bits 7-4, 3-0 populated from hi to lo).

.MACRO	BYTE_7_4_3_0_VAL	NVH,NVL
		.BYTE	((NVH&$0F)<<4)|(NVL&$0F)
.ENDMACRO



; Data byte from two nybble values (bits 4-7, 0-3 populated from hi to lo).

.MACRO	BYTE_4_7_0_3_VAL	NVH,NVL
		.BYTE	((NVH&$08)<<1)|((NVH&$04)<3)|((NVH&$02)<<5)|((NVH&$01)<<7)|((NVL&$08)>>3)|((NVL&$04)>>1)|((NVL&$02)<<1)|((NVL&$01)<<3)
.ENDMACRO



;------------------------------------------------------------------------------

		.POPSEG

;------------------------------------------------------------------------------


