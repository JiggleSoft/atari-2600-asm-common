;==============================================================================
; Name:         Atari 2600 Digital Joystick utilities include file.
; Filename:     a2k6djoy.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-10-13 21:31
; Vesion:		0.3.0
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Digital Joystick utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; FIXME: Impl.
;------------------------------------------------------------------------------

; TODO: Impl.

; TODO: separate P1 + P2 + combined

.MACRO		DJOY_INIT_P1_P2
			LDA		DDIRREGA
			AND		#($FF&(!JOYM_P1))
			STA		DDIRREGA

.ENDMACRO


.MACRO		JOY_NEW_FRAME
.ENDMACRO

.MACRO		JOY_READ_DIR
			LDA		DATAREGA
			STA		joy_dir
			PHA
			AND		#JOYM_P1
			STA		joy_p1_dir
			POA
			AND		#JOYM_P2
			STA		joy_p2_dir
.ENDMACRO


.MACRO		JOY_READ_DIR
			LDA		DATAREGA
			STA		joy_dir
			PHA
			AND		#JOYM_P1
			STA		joy_p1_dir
			POA
			AND		#JOYM_P2
			STA		joy_p2_dir
.ENDMACRO


.MACRO		JOY_READ_FIRE
;latched ????? need to clear latch in joy management - VSYNC
;			INPT4
;			INPTF_IN	=	$80	; INPTn In Flag.


;			LDA		DATAREGA
;			STA		joy_dir
			STA		joy_fire
.ENDMACRO


JOY_P1_DIR_C	=	$00
JOY_P1_DIR_N	=	JOYF_P1U
JOY_P1_DIR_NE	=	(JOYF_P1U|JOYF_P1R)
JOY_P1_DIR_E	=	JOYF_P1R
JOY_P1_DIR_SE	=	(JOYF_P1D|JOYF_P1R)
JOY_P1_DIR_S	=	JOYF_P1D
JOY_P1_DIR_SW	=	(JOYF_P1D|JOYF_P1L)
JOY_P1_DIR_W	=	JOYF_P1L
JOY_P1_DIR_NW	=	(JOYF_P1U|JOYF_P1L)

JOY_P1_FIRE_0	=	$00		; No fire buttons pressed.
JOY_P1_FIRE_1	=	INPTF_IN

JOY_P2_DIR_C	=	$00
JOY_P2_DIR_N	=	JOYF_P2U
JOY_P2_DIR_NE	=	(JOYF_P2U|JOYF_P2R)
JOY_P2_DIR_E	=	JOYF_P2R
JOY_P2_DIR_SE	=	(JOYF_P2D|JOYF_P2R)
JOY_P2_DIR_S	=	JOYF_P2D
JOY_P2_DIR_SW	=	(JOYF_P2D|JOYF_P2L)
JOY_P2_DIR_W	=	JOYF_P2L
JOY_P2_DIR_NW	=	(JOYF_P2U|JOYF_P2L)

				.DATA

; Last read joystick digital directions.
joy_dir			.RES		1

; Joystick player 1 direction and fire.
joy_p1_dir		.RES		1
joy_p1_fire		.RES		1

; Joystick player 1 direction and fire.
joy_p2_dir		.RES		1
joy_p2_fire		.RES		1


;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


