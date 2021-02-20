;==============================================================================
; Name:         Atari 2600 TIA Playfield utilities test include file.
; Filename:     a2k6tpf.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2018-12-30 21:06
; Vesion:		0.2.5
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
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

			.DATA

pf0csv:		PF0_CSV			B,B,_,B		; Must be $B0
pf0l0rcsv:	PF0L0R_CSV		B,B,_,B,_,_,B,B		; Must be $BC
pf1csv:		PF1_CSV			B,B,_,B,_,_,B,B
pf2csv:		PF2_CSV			B,B,_,B,_,_,B,B
pf320csv:	PF_3_20CSV		B,B,_,B,B,B,_,_,B,_,B,B,B,_,B,_,_,_,B,B
pf640csv:	PF_6_40CSV		B,B,_,B,B,B,_,_,B,_,B,B,B,_,B,_,_,_,B,B,B,B,_,B,B,B,_,_,B,_,B,B,B,_,B,_,_,_,B,_
pf540csv:	PF_5_40CSV		B,B,_,B,B,B,_,_,B,_,B,B,B,_,B,_,_,_,B,B,B,B,_,B,B,B,_,_,B,_,B,B,B,_,B,_,_,_,B,_
pf0val:		PF0_VAL			$D
pf0l0rval:	PF0L0R_VAL		$D,$3
pf1val:		PF1_VAL			$D3
pf2val:		PF2_VAL			$D3
pf33val:	PF_3_3VAL		$D,$CB,$A3
pf66val:	PF_6_6VAL		$D,$CB,$A3,$C,$CA,$A2
pf56val:	PF_5_6VAL		$D,$CB,$A3,$C,$CA,$A2
pf3val:		PF_3_VAL		$DCBA3
pf62val:	PF_6_2VAL		$DCBA3,$CCAA2
pf52val:	PF_5_2VAL		$DCBA3,$CCAA2

;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


