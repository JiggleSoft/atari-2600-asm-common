;==============================================================================
; Name:         Atari 2600 Bank Switching utilities include file.
; Filename:     a2k6bank.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-02-18 21:44
; Vesion:		1.1.1
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;						Creative Commons Attribution 4.0 International
;						http://creativecommons.org/licenses/by/4.0/
;						with an exception, see /LICENCE.txt file.
;------------------------------------------------------------------------------
; Not applicable:-
; 	2K - Atari 2 KByte (no bank switching required).
; 	4K - Atari 4 KByte (no bank switching required).
; Supported:-
; 	F6 - $0FF6/$0FF7/$0FF8/$0FF9 - 16K = 4 x 4K banks.
; 	F8 - $0FF8/$0FF9 - 8K = 2 x 4K banks.
; 	FA - $0FF8/$0FF9/$0FFA - 12K = 3 x 4K banks.
; 	E0 - $0FE0-$0FF7 - 8KB = 8 banks x 1K, 4 1K slices, slice 3 fixed bank 7.
; 	E7 - $0FE0-$0FF7 - 16KB = 8 banks x 2K, 2 2K slices, slice 1 fixed bank 7.
;                      Note slice 0 bank 7 is RAM, slice 1 is bank 7 is ROM.
; 	FE - $01FE-$11FE - 8K = 2 x 4K banks (RTS can be used to swap back bank).
; Future support:-
; 	F6S -
;	F8S -
; 	F4S -
; 	3F -
; 	3E -
; 	CV -
; 	UA -
; 	AR -
; 	DPC -
; 	084 -
; 	CU - Custom (others to be specified)
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Bank Switching utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; F6 - $0FF6/$0FF7/$0FF8/$0FF9 - 16K = 4 x 4K banks.
;------------------------------------------------------------------------------

				.IFDEF			SUPPORT_F6_BANK

; F6 bank switching base address and offsets.

F6B_BANK	:=	$0FF6	; F6 bank switching base address.
F6O_BANK_0	=	$0000	; F6 bank switching bank 0 address offset.
F6O_BANK_1	=	$0001	; F6 bank switching bank 1 address offset.
F6O_BANK_2	=	$0002	; F6 bank switching bank 2 address offset.
F6O_BANK_3	=	$0003	; F6 bank switching bank 3 address offset.


; F6 bank switching addresses.

F6_BANK_0	:=	(F6B_BANK+F6O_BANK_0)	; F6 bank switching bank 0 address.
F6_BANK_1	:=	(F6B_BANK+F6O_BANK_1)	; F6 bank switching bank 1 address.
F6_BANK_2	:=	(F6B_BANK+F6O_BANK_2)	; F6 bank switching bank 2 address.
F6_BANK_3	:=	(F6B_BANK+F6O_BANK_3)	; F6 bank switching bank 3 address.


; F6 bank switching bank 0 selection.

.MACRO		F6_BANK_0_SEL
			LDA			F6_BANK_0
.ENDMACRO


; F6 bank switching bank 1 selection.

.MACRO		F6_BANK_1_SEL
			LDA			F6_BANK_1
.ENDMACRO


; F6 bank switching bank 2 selection.

.MACRO		F6_BANK_2_SEL
			LDA			F6_BANK_2
.ENDMACRO


; F6 bank switching bank 3 selection.

.MACRO		F6_BANK_3_SEL
			LDA			F6_BANK_3
.ENDMACRO


; F6 bank switching bank selection.

.MACRO		F6_BANK_SEL		bank_num
			.IF			bank_num = 0
			F6_BANK_0_SEL
			.ELSEIF		bank_num = 1
			F6_BANK_1_SEL
			.ELSEIF		bank_num = 2
			F6_BANK_2_SEL
			.ELSEIF		bank_num = 3
			F6_BANK_3_SEL
			.ELSE
			.ERROR		"F6_BANK_SEL bank_num must be either 0, 1, 2, or 3!"
			.ENDIF
.ENDMACRO


				.ENDIF			; SUPPORT_F6_BANK



;------------------------------------------------------------------------------
; F8 - $0FF8/$0FF9 - 8K = 2 x 4K banks.
;------------------------------------------------------------------------------

				.IFDEF			SUPPORT_F8_BANK

; F8 bank switching base address and offsets.

F8B_BANK	:=	$0FF8	; F8 bank switching base address.
F8O_BANK_0	=	$0000	; F8 bank switching bank 0 address offset.
F8O_BANK_1	=	$0001	; F8 bank switching bank 1 address offset.


; F8 bank switching addresses.

F8_BANK_0	:=	(F8B_BANK+F8O_BANK_0)	; F8 bank switching bank 0 address.
F8_BANK_1	:=	(F8B_BANK+F8O_BANK_1)	; F8 bank switching bank 1 address.


; F8 bank switching bank 0 selection.

.MACRO		F8_BANK_0_SEL
			LDA			F8_BANK_0
.ENDMACRO


; F8 bank switching bank 1 selection.

.MACRO		F8_BANK_1_SEL
			LDA			F8_BANK_1
.ENDMACRO


; F8 bank switching bank selection.

.MACRO		F8_BANK_SEL	bank_num
			.IF			bank_num = 0
			F8_BANK_0_SEL
			.ELSEIF		bank_num = 1
			F8_BANK_1_SEL
			.ELSE
			.ERROR		"F8_BANK_SEL bank_num must be either 0 or 1!"
			.ENDIF
.ENDMACRO


				.ENDIF			 ; SUPPORT_F8_BANK



;------------------------------------------------------------------------------
; FA - $0FF8/$0FF9/$0FFA - 12K = 3 x 4K banks.
;------------------------------------------------------------------------------

				.IFDEF			SUPPORT_FA_BANK

; FA bank switching base address and offsets.

FAB_BANK	:=	$0FF8	; FA bank switching base address.
FAO_BANK_0	=	$0000	; FA bank switching bank 0 address offset.
FAO_BANK_1	=	$0001	; FA bank switching bank 1 address offset.
FAO_BANK_2	=	$0002	; FA bank switching bank 2 address offset.


; FA bank switching addresses.

FA_BANK_0	:=	(FAB_BANK+FAO_BANK_0)	; FA bank switching bank 0 address.
FA_BANK_1	:=	(FAB_BANK+FAO_BANK_1)	; FA bank switching bank 1 address.
FA_BANK_2	:=	(FAB_BANK+FAO_BANK_2)	; FA bank switching bank 2 address.


; FA bank switching bank 0 selection.

.MACRO		FA_BANK_0_SEL
			LDA			FA_BANK_0
			.ENDMACRO


; FA bank switching bank 1 selection.

.MACRO		FA_BANK_1_SEL
			LDA			FA_BANK_1
			.ENDMACRO


; FA bank switching bank 2 selection.

.MACRO		FA_BANK_2_SEL
			LDA			FA_BANK_2
			.ENDMACRO


; FA bank switching bank selection.

.MACRO		FA_BANK_SEL		bank_num
			.IF			bank_num = 0
			FA_BANK_0_SEL
			.ELSEIF		bank_num = 1
			FA_BANK_1_SEL
			.ELSEIF		bank_num = 2
			FA_BANK_2_SEL
			.ELSE
			.ERROR		"FA_BANK_SEL bank_num must be either 0, 1, or 2!"
			.ENDIF
			.ENDMACRO


				.ENDIF			 ; SUPPORT_FA_BANK



;------------------------------------------------------------------------------
; E0 - $0FE0-$0FF7 - 8KB = 8 banks x 1K, 4 1K slices, slice 3 fixed bank 7.
;------------------------------------------------------------------------------

				.IFDEF			SUPPORT_E0_BANK

; E0 bank switching base address and offsets.

E0B_SLICE_BANK	:=	$0FE0	; E0 bank switching base address.
E0O_SLICE_0		=	$0000	; E0 bank switching slice 0 address offset.
E0O_SLICE_1		=	$0007	; E0 bank switching slice 1 address offset.
E0O_SLICE_2		=	$0010	; E0 bank switching slice 2 address offset.
;E0O_SLICE_3	=	$0017	; E0 bank switching slice 3 address fixed bank 7.
E0O_BANK_0		=	$0000	; E0 bank switching bank 0 address offset.
E0O_BANK_1		=	$0001	; E0 bank switching bank 1 address offset.
E0O_BANK_2		=	$0002	; E0 bank switching bank 2 address offset.
E0O_BANK_3		=	$0003	; E0 bank switching bank 3 address offset.
E0O_BANK_4		=	$0004	; E0 bank switching bank 4 address offset.
E0O_BANK_5		=	$0005	; E0 bank switching bank 5 address offset.
E0O_BANK_6		=	$0006	; E0 bank switching bank 6 address offset.
E0O_BANK_7	=	$0007	; E0 bank switching bank 7 address offset.			;FIXME: RAM???


; E0 bank switching addresses.

E0_SLICE_0_BANK_0	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_0)	; E0 address.
E0_SLICE_0_BANK_1	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_1)	; E0 address.
E0_SLICE_0_BANK_2	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_2)	; E0 address.
E0_SLICE_0_BANK_3	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_3)	; E0 address.
E0_SLICE_0_BANK_4	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_4)	; E0 address.
E0_SLICE_0_BANK_5	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_5)	; E0 address.
E0_SLICE_0_BANK_6	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_6)	; E0 address.
E0_SLICE_0_BANK_7	:=	(E0B_SLICE_BANK+E0O_SLICE_0+E0O_BANK_7)	; E0 address.
E0_SLICE_1_BANK_0	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_0)	; E0 address.
E0_SLICE_1_BANK_1	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_1)	; E0 address.
E0_SLICE_1_BANK_2	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_2)	; E0 address.
E0_SLICE_1_BANK_3	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_3)	; E0 address.
E0_SLICE_1_BANK_4	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_4)	; E0 address.
E0_SLICE_1_BANK_5	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_5)	; E0 address.
E0_SLICE_1_BANK_6	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_6)	; E0 address.
E0_SLICE_1_BANK_7	:=	(E0B_SLICE_BANK+E0O_SLICE_1+E0O_BANK_7)	; E0 address.
E0_SLICE_2_BANK_0	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_0)	; E0 address.
E0_SLICE_2_BANK_1	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_1)	; E0 address.
E0_SLICE_2_BANK_2	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_2)	; E0 address.
E0_SLICE_2_BANK_3	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_3)	; E0 address.
E0_SLICE_2_BANK_4	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_4)	; E0 address.
E0_SLICE_2_BANK_5	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_5)	; E0 address.
E0_SLICE_2_BANK_6	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_6)	; E0 address.
E0_SLICE_2_BANK_7	:=	(E0B_SLICE_BANK+E0O_SLICE_2+E0O_BANK_7)	; E0 address.


; E0 bank switching slice 0 bank 0 selection.

.MACRO		E0_SLICE_0_BANK_0_SEL
			LDA			E0_SLICE_0_BANK_0
.ENDMACRO


; E0 bank switching slice 0 bank 1 selection.

.MACRO		E0_SLICE_0_BANK_1_SEL
			LDA			E0_SLICE_0_BANK_1
.ENDMACRO


; E0 bank switching slice 0 bank 2 selection.

.MACRO		E0_SLICE_0_BANK_2_SEL
			LDA			E0_SLICE_0_BANK_2
.ENDMACRO


; E0 bank switching slice 0 bank 3 selection.

.MACRO		E0_SLICE_0_BANK_3_SEL
			LDA			E0_SLICE_0_BANK_3
.ENDMACRO


; E0 bank switching slice 0 bank 4 selection.

.MACRO		E0_SLICE_0_BANK_4_SEL
			LDA			E0_SLICE_0_BANK_4
.ENDMACRO


; E0 bank switching slice 0 bank 5 selection.

.MACRO		E0_SLICE_0_BANK_5_SEL
			LDA			E0_SLICE_0_BANK_5
.ENDMACRO


; E0 bank switching slice 0 bank 6 selection.

.MACRO		E0_SLICE_0_BANK_6_SEL
			LDA			E0_SLICE_0_BANK_6
.ENDMACRO


; E0 bank switching slice 0 bank 7 selection.

.MACRO		E0_SLICE_0_BANK_7_SEL
			LDA			E0_SLICE_0_BANK_7
.ENDMACRO


; E0 bank switching slice 1 bank 0 selection.

.MACRO		E0_SLICE_1_BANK_0_SEL
			LDA			E0_SLICE_1_BANK_0
.ENDMACRO


; E0 bank switching slice 1 bank 1 selection.

.MACRO		E0_SLICE_1_BANK_1_SEL
			LDA			E0_SLICE_1_BANK_1
.ENDMACRO


; E0 bank switching slice 1 bank 2 selection.

.MACRO		E0_SLICE_1_BANK_2_SEL
			LDA			E0_SLICE_1_BANK_2
.ENDMACRO


; E0 bank switching slice 1 bank 3 selection.

.MACRO		E0_SLICE_1_BANK_3_SEL
			LDA			E0_SLICE_1_BANK_3
.ENDMACRO


; E0 bank switching slice 1 bank 4 selection.

.MACRO		E0_SLICE_1_BANK_4_SEL
			LDA			E0_SLICE_1_BANK_4
.ENDMACRO


; E0 bank switching slice 1 bank 5 selection.

.MACRO		E0_SLICE_1_BANK_5_SEL
			LDA			E0_SLICE_1_BANK_5
.ENDMACRO


; E0 bank switching slice 1 bank 6 selection.

.MACRO		E0_SLICE_1_BANK_6_SEL
			LDA			E0_SLICE_1_BANK_6
.ENDMACRO


; E0 bank switching slice 1 bank 7 selection.

.MACRO		E0_SLICE_1_BANK_7_SEL
			LDA			E0_SLICE_1_BANK_7
.ENDMACRO


; E0 bank switching slice 2 bank 0 selection.

.MACRO		E0_SLICE_2_BANK_0_SEL
			LDA			E0_SLICE_2_BANK_0
.ENDMACRO


; E0 bank switching slice 2 bank 1 selection.

.MACRO		E0_SLICE_2_BANK_1_SEL
			LDA			E0_SLICE_2_BANK_1
.ENDMACRO


; E0 bank switching slice 2 bank 2 selection.

.MACRO		E0_SLICE_2_BANK_2_SEL
			LDA			E0_SLICE_2_BANK_2
.ENDMACRO


; E0 bank switching slice 2 bank 3 selection.

.MACRO		E0_SLICE_3_BANK_3_SEL
			LDA			E0_SLICE_3_BANK_3
.ENDMACRO


; E0 bank switching slice 2 bank 4 selection.

.MACRO		E0_SLICE_2_BANK_4_SEL
			LDA			E0_SLICE_2_BANK_4
.ENDMACRO


; E0 bank switching slice 2 bank 5 selection.

.MACRO		E0_SLICE_2_BANK_5_SEL
			LDA			E0_SLICE_2_BANK_5
.ENDMACRO


; E0 bank switching slice 2 bank 6 selection.

.MACRO		E0_SLICE_2_BANK_6_SEL
			LDA			E0_SLICE_2_BANK_6
.ENDMACRO


; E0 bank switching slice 2 bank 7 selection.

.MACRO		E0_SLICE_2_BANK_7_SEL
			LDA			E0_SLICE_2_BANK_7
.ENDMACRO


; E0 bank switching slice bank selection.

.MACRO		E0_SLICE_BANK_SEL	slice_num,bank_num
			.IF			slice_num = 0
			.IF			bank_num = 0
			E0_SLICE_0_BANK_0_SEL
			.ELSEIF		bank_num = 1
			E0_SLICE_0_BANK_1_SEL
			.ELSEIF		bank_num = 2
			E0_SLICE_0_BANK_2_SEL
			.ELSEIF		bank_num = 3
			E0_SLICE_0_BANK_3_SEL
			.ELSEIF		bank_num = 4
			E0_SLICE_0_BANK_4_SEL
			.ELSEIF		bank_num = 5
			E0_SLICE_0_BANK_5_SEL
			.ELSEIF		bank_num = 6
			E0_SLICE_0_BANK_6_SEL
			.ELSEIF		bank_num = 7
			E0_SLICE_0_BANK_7_SEL
			.ELSE
			.ERROR		"E0_SLICE_BANK_SEL bank_num must be either 0, 1, 2, 3, 4, 5, 6, or 7!"
			.ENDIF
			.ELSEIF		slice_num = 1
			.IF			bank_num = 0
			E0_SLICE_1_BANK_0_SEL
			.ELSEIF		bank_num = 1
			E0_SLICE_1_BANK_1_SEL
			.ELSEIF		bank_num = 2
			E0_SLICE_1_BANK_2_SEL
			.ELSEIF		bank_num = 3
			E0_SLICE_1_BANK_3_SEL
			.ELSEIF		bank_num = 4
			E0_SLICE_1_BANK_4_SEL
			.ELSEIF		bank_num = 5
			E0_SLICE_1_BANK_5_SEL
			.ELSEIF		bank_num = 6
			E0_SLICE_1_BANK_6_SEL
			.ELSEIF		bank_num = 7
			E0_SLICE_1_BANK_7_SEL
			.ELSE
			.ERROR		"E0_SLICE_BANK_SEL bank_num must be either 0, 1, 2, 3, 4, 5, 6, or 7!"
			.ENDIF
			.ELSEIF		slice_num = 2
			.IF			bank_num = 0
			E0_SLICE_2_BANK_0_SEL
			.ELSEIF		bank_num = 1
			E0_SLICE_2_BANK_1_SEL
			.ELSEIF		bank_num = 2
			E0_SLICE_2_BANK_2_SEL
			.ELSEIF		bank_num = 3
			E0_SLICE_2_BANK_3_SEL
			.ELSEIF		bank_num = 4
			E0_SLICE_2_BANK_4_SEL
			.ELSEIF		bank_num = 5
			E0_SLICE_2_BANK_5_SEL
			.ELSEIF		bank_num = 6
			E0_SLICE_2_BANK_6_SEL
			.ELSEIF		bank_num = 7
			E0_SLICE_2_BANK_7_SEL
			.ELSE
			.ERROR		"E0_SLICE_BANK_SEL bank_num must be either 0, 1, 2, 3, 4, 5, 6, or 7!"
			.ENDIF
			.ELSE
			.ERROR		"E0_SLICE_BANK_SEL slice_num must be either 0, 1, or 2!"
			.ENDIF
			.ENDMACRO


				.ENDIF			; SUPPORT_E0_BANK



;------------------------------------------------------------------------------
; E7 - $0FE0-$0FF7 - 16KB = 8 banks x 2K, 2 2K slices, slice 1 fixed bank 7.
; Note slice 0 bank 7 is RAM, slice 1 is bank 7 is ROM.
;------------------------------------------------------------------------------

				.IFDEF			SUPPORT_E7_BANK

; E7 bank switching base address and offsets.

E7B_SLICE_BANK	:=	$1FE0	; E7 bank switching base address.
E7O_SLICE_0		=	$0000	; E7 bank switching slice 0 address offset.
;E7O_SLICE_1	=	$0007	; E7 bank switching slice 1 address fixed bank 7.
E7O_BANK_0		=	$0000	; E7 bank switching bank 0 address offset.
E7O_BANK_1		=	$0001	; E7 bank switching bank 1 address offset.
E7O_BANK_2		=	$0002	; E7 bank switching bank 2 address offset.
E7O_BANK_3		=	$0003	; E7 bank switching bank 3 address offset.
E7O_BANK_4		=	$0004	; E7 bank switching bank 4 address offset.
E7O_BANK_5		=	$0005	; E7 bank switching bank 5 address offset.
E7O_BANK_6		=	$0006	; E7 bank switching bank 6 address offset.
E7O_BANK_RAM	=	$0007	; E7 bank switching bank 7 RAM address offset.


; E7 bank switching addresses.

E7_SLICE_0_BANK_0	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_0)	; E7 address.
E7_SLICE_0_BANK_1	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_1)	; E7 address.
E7_SLICE_0_BANK_2	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_2)	; E7 address.
E7_SLICE_0_BANK_3	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_3)	; E7 address.
E7_SLICE_0_BANK_4	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_4)	; E7 address.
E7_SLICE_0_BANK_5	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_5)	; E7 address.
E7_SLICE_0_BANK_6	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_6)	; E7 address.
E7_SLICE_0_BANK_RAM	:=	(E7B_SLICE_BANK+E7O_SLICE_0+E7O_BANK_RAM) ; E7 address.


; E7 bank switching slice 0 bank 0 selection.

.MACRO		E7_SLICE_0_BANK_0_SEL
			LDA			E7_SLICE_0_BANK_0
.ENDMACRO


; E7 bank switching slice 0 bank 1 selection.

.MACRO		E7_SLICE_0_BANK_1_SEL
			LDA			E7_SLICE_0_BANK_1
.ENDMACRO


; E7 bank switching slice 0 bank 2 selection.

.MACRO		E7_SLICE_0_BANK_2_SEL
			LDA			E7_SLICE_0_BANK_2
.ENDMACRO


; E7 bank switching slice 0 bank 3 selection.

.MACRO		E7_SLICE_0_BANK_3_SEL
			LDA			E7_SLICE_0_BANK_3
.ENDMACRO


; E7 bank switching slice 0 bank 4 selection.

.MACRO		E7_SLICE_0_BANK_4_SEL
			LDA			E7_SLICE_0_BANK_4
.ENDMACRO


; E7 bank switching slice 0 bank 5 selection.

.MACRO		E7_SLICE_0_BANK_5_SEL
			LDA			E7_SLICE_0_BANK_5
.ENDMACRO


; E7 bank switching slice 0 bank 6 selection.

.MACRO		E7_SLICE_0_BANK_6_SEL
			LDA			E7_SLICE_0_BANK_6
.ENDMACRO


; E7 bank switching slice 0 bank RAM selection.

.MACRO		E7_SLICE_0_BANK_RAM_SEL
			LDA				E7_SLICE_0_BANK_RAM
.ENDMACRO


; E7 bank switching slice bank selection.

.MACRO		E7_SLICE_BANK_SEL	slice_num,bank_num
			.IF			slice_num = 0
			.IF			bank_num = 0
			E7_SLICE_0_BANK_0_SEL
			.ELSEIF		bank_num = 1
			E7_SLICE_0_BANK_1_SEL
			.ELSEIF		bank_num = 2
			E7_SLICE_0_BANK_2_SEL
			.ELSEIF		bank_num = 3
			E7_SLICE_0_BANK_3_SEL
			.ELSEIF		bank_num = 4
			E7_SLICE_0_BANK_4_SEL
			.ELSEIF		bank_num = 5
			E7_SLICE_0_BANK_5_SEL
			.ELSEIF		bank_num = 6
			E7_SLICE_0_BANK_6_SEL
			.ELSEIF		bank_num = 7
			E7_SLICE_0_BANK_RAM_SEL
			.ELSE
			.ERROR		"E7_SLICE_BANK_SEL bank_num must be either 0, 1, 2, 3, 4, 5, 6, or 7!"
			.ENDIF
			.ELSE
			.ERROR		"E7_SLICE_BANK_SEL slice_num must be 0!"
			.ENDIF
			.ENDMACRO


				.ENDIF			; SUPPORT_E7_BANK



;------------------------------------------------------------------------------
; FE - $01FE-$11FE - 8K = 2 x 4K banks (RTS can be used to swap back bank).
;------------------------------------------------------------------------------

				.IFDEF			SUPPORT_FE_BANK

; FE bank switching base address and offsets.

FEB_BANK	:=	$01FE	; FE bank switching base address.
FEO_BANK_0	=	$0000	; FE bank switching bank 0 address offset.
FEO_BANK_1	=	$1000	; FE bank switching bank 1 address offset.


; FE bank switching addresses.

FE_BANK_0	:=	(FEB_BANK+FEO_BANK_0)	; FE bank switching bank 0 address.
FE_BANK_1	:=	(FEB_BANK+FEO_BANK_1)	; FE bank switching bank 1 address.


; FE bank switching bank 0 selection.

.MACRO		FE_BANK_SEL_0
			LDA			FE_BANK_0
.ENDMACRO


; FE bank switching bank 1 selection.

.MACRO		FE_BANK_SEL_1
			LDA			FE_BANK_1
.ENDMACRO


; FE bank switching bank selection.

.MACRO		FE_BANK_SEL	bank_num
			.IF			bank_num = 0
			FE_BANK_SEL_0
			.ELSEIF		bank_num = 1
			FE_BANK_SEL_1
			.ELSE
			.ERROR		"FE_BANK_SEL bank_num must be either 0 or 1!"
			.ENDIF
.ENDMACRO


				.ENDIF			; SUPPORT_FE_BANK



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


