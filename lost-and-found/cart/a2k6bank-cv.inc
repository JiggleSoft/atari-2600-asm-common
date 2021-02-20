;==============================================================================
; Name:         Atari 2600 standard extra include file.
; Filename:     a2k6bank-f8.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-26 02:07
; Version:      1.3.0
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

                .IFNDEF     __A2K6BANK_F8__INC__
                .DEFINE     __A2K6BANK_F8__INC__

;==============================================================================
; Atari 2600 Bank Switching Scheme - F8 [+ SC].
;==============================================================================

                .PUSHSEG

|   F8   | Atari Standard 8K                  |   8K |      |     | Strobe $1FF8 = Bank 0, $1FF9 = Bank 1 |
| F8SC | Atari F8 with SARA Super Chip RAM  |   8K | 128B |     | Strobe $1FF8 = Bank 0, $1FF9 = Bank 1; RAM $1000-$107F (write), $1080-$10FF (read) |
; 	F8 - $0FF8/$0FF9 - 8K = 2 x 4K banks.
| F8   | Atari Standard 8K                  |   8K |      |     | Strobe $1FF8 = Bank 0, $1FF9 = Bank 1 |
| F8SC | Atari F8 with SARA Super Chip RAM  |   8K | 128B |     | Strobe $1FF8 = Bank 0, $1FF9 = Bank 1; RAM $1000-$107F (write), $1080-$10FF (read) |




;==============================================================================
; Atari 2600 Bank Switching utilities.
;==============================================================================

				.PUSHSEG

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

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


