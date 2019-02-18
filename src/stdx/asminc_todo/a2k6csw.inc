;==============================================================================
; Name:         Atari 2600 Console Switches utilities include file.
; Filename:     a2k6csw.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-01-18 18:19
; Vesion:		0.3.0
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Console Switches utilities.
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
			BEQ			.notres
			JMP			resvec
.notres
			LDA			DATAREGB
			AND			#$CSWF_SEL
			BEQ			.notres
			JSR			selvec
.notsel
			LDA			DATAREGB
				CSWF_COL
				CSWF_P1D
				CSWF_P2D
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


