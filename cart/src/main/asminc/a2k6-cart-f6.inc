;==============================================================================
; Name:         Atari 2600 cartridge type F6 specific include file.
; Filename:     a2k6cart-f6.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-27 20:28
; Version:      1.9.0
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

                .IFNDEF     __A2K6CART_F6__INC__
                .DEFINE     __A2K6CART_F6__INC__

;==============================================================================
; Atari 2600 Legacy Atari Bank Switching Cartridge.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; F6 - Atari Standard 16K ROM (16K ROM).
;
; ROM Strobe $1FF6 = Bank 0, $1FF7 = Bank 1, $1FF8 = Bank 2, $1FF9 = Bank 3.
;------------------------------------------------------------------------------

; F6 bank switching base address and offsets.

F6_B_BANK	:=	$0FF6	; F6 bank switching base address.
F6_O_BANK_0	=	$0000	; F6 bank switching bank 0 address offset.
F6_O_BANK_1	=	$0001	; F6 bank switching bank 1 address offset.
F6_O_BANK_2	=	$0002	; F6 bank switching bank 2 address offset.
F6_O_BANK_3	=	$0003	; F6 bank switching bank 3 address offset.


; F6 bank switching addresses.

F6_BANK_0	:=	(F6_B_BANK+F6_O_BANK_0)	; F6 bank switching bank 0 address.
F6_BANK_1	:=	(F6_B_BANK+F6_O_BANK_1)	; F6 bank switching bank 1 address.
F6_BANK_2	:=	(F6_B_BANK+F6_O_BANK_2)	; F6 bank switching bank 2 address.
F6_BANK_3	:=	(F6_B_BANK+F6_O_BANK_3)	; F6 bank switching bank 3 address.


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



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


