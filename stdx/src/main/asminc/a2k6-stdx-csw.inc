; STATUS: WORK IN PROGRESS.
;==============================================================================
; Title:        Atari 2600 Console Switches standard extra include file.
; Filename:     a2k6-std-csw.inc
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

                .IFNDEF     __A2K6_STDX_CSW__INC__
                            __A2K6_STDX_CSW__INC__ = 1

;==============================================================================
; Atari 2600 Console Switches.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Console Switch Handlers
;------------------------------------------------------------------------------

; No mechanism to initialise the console switches as they must never be output!

;.MACRO		CSW_INIT
;			LDA			#$00
;			STA			DDIRREGB
;.ENDMACRO



;

.MACRO		CSW_READ_STATE_R_M	reg,mem
			.IF		reg = 'A'
			LDA			DATAREGB
			.IF		set(mem)
			STA		mem
			.ENDIF
			.ENDIF
			.ELSEIF	reg = 'X'
			LDX			DATAREGB
			.IF		set(mem)
			STX		mem
			.ENDIF
			.ELSEIF reg = 'Y'
			LDY			DATAREGB
			.IF		set(mem)
			STY		mem
			.ENDIF
			.ELSE
			.ERROR		"FIXME:!"
			.ENDIF
.ENDMACRO



.MACRO		CSW_READ_STATE
.ENDMACRO



; Handle the state of the console switches.

.MACRO		CSW_HANDLE		resvec,selvec
			.LOCAL		notres
			.LOCAL		notsel
			LDA			DATAREGB	;	ADD TO VAR IN ZP optional as this is not ZP load $280+reg !!!!!
			AND			#$CSWF_RES
			BEQ			notres
			JMP			resvec
notres
			LDA			DATAREGB
			AND			#$CSWF_SEL
			BEQ			notres
			JSR			selvec
notsel
			LDA			DATAREGB
				CSWF_COL
				CSWF_P1D
				CSWF_P2D
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------

                .ENDIF


