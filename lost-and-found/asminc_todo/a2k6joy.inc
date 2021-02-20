;==============================================================================
; Name:         Atari 2600 Common Joystick/Controller utilities include file.
; Filename:     a2k6joy.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2019-10-13 22:04
; Vesion:		0.3.1
;------------------------------------------------------------------------------
; Copyright:	Copyright (c) 2018 Justin Lane.
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------
; Supported joysticks and controllers:-
;   Std  Control   A/D  Num/Port  Directions  Buttons  Models
;   Yes  Joystick  D    1         4 (+4diag)  1        CX10/CX24/CX40/CX42/CX43
;   Yes  Paddle    A    2         1 (1 axis)  1        CX30/CX30-04
;
; Future planned supported joysticks and controllers:-
;   Std  Control   A/D  Num/Port  Directions  Buttons  Models
;        Joysitck  D    1         4 (+4diag)  2        CX34/CX78
;        Joystick  D    2         4 (+4diag)  1
;        Joystick  A    1         2 (XYaxis)  1
;        Joystick  A    1         2 (XYaxis)  2-4
;	Yes  Driving   ?    1         1 (1 grey)  1        CX20/CX20-01
;   Yes  Keyboard  D    1         0           12       CX50/CX21/CX23
;   Yes  TrackBall A+D  1         2 axis      1?2?     CX22/CX80
;   Yes  Light Gun ?    1         ??????????  1        XG-1
;
; Note:-
;   CX50 = Keyboard Controller.
;   CX21 = Touch pad Controller.
;   CX23 = Kids Controller.
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 Common Joystick utilities.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; FIXME: Impl.
;------------------------------------------------------------------------------

;				.DEFINE			DDIRREGA_DEFAULT?????
;				.DEFINE			VID_DDIRREGA_TRACKED
;				.DEFINE			VID_VBLANK_READABLE


				.IFDEF			VID_VBLANK_READABLE
				.DATA
vid_vblank		.RES			1
				.CODE
				.ENDIF


; Initialise digital joystick for both player 1 and player 2 directions.

.MACRO			JOY_DIR_INIT
				LDA			#($FF&(!(JOYM_P1|JOYM_P2)))
				STA			DDIRREGA
.ENDMACRO


; Initialise digital joystick for just player 1 directions.

.MACRO			JOY_P1_DIR_INIT
				LDA			DATAREGA
				AND			#($FF&(!JOYM_P1))
				STA			DDIRREGA
.ENDMACRO


; Initialise digital joystick for just player 2 directions.

.MACRO			JOY_P2_DIR_INIT
				LDA			DATAREGA
				AND			#($FF&(!JOYM_P2))
				STA			DDIRREGA
.ENDMACRO



.MACRO			JOY_FIRE_INIT
.ENDMACRO


.MACRO			JOY_P1_FIRE_INIT
	.ENDMACRO


.MACRO			JOY_P2_FIRE_INIT
.ENDMACRO


; Reset digital joystick fire button latches for both player 1 and player 2.

.MACRO			JOY_FIRE_RESET
				LDA				vid_vblank
				AND				#($FF&(!VBLANKF_LATCH))
				STA				VBLANK
				NOP
; how long to reset (immediately? expect so)
.ENDMACRO




; Reset (dump) analogue controller charge capacitor for players 1, 2, 3, and 4.

.MACRO			JOY_POS_RESET
; how long to dump?

.ENDMACRO




;????move to paddle / fire2+3
;				LDA				vid_vblank
;				ORA				#VBLANKF_DUMP
;				STA				VBLANK
;				STA				vid_vblank

;				turn off dump

;clear latch
.MACRO			JOY_P1_FIRE_RESET
.ENDMACRO

;clear latch
.MACRO			JOY_P2_FIRE_RESET
.ENDMACRO


JOY_ANALOGUE_RESET



.MACRO			JOY_READ_DIR
				LDA			DATAREGA
				STA			joy_dir
.ENDMACRO


;.MACRO			JOY_

; TODO: add read



; TODO: move to djoy or keep all joystick in one file.  One file if possible.
; Decode digital joystick for player 1 and player 2 directions.

.MACRO			JOY_DIR_DECODE
				LDA				joy_dir
				PHA
				AND				#JOYM_P1
				STA				joy_p1_dir
				PLA
				AND				#JOYM_P2
				STA				joy_p2_dir
.ENDMACRO


; Decode digital joystick for player 1 directions.

.MACRO			JOY_DIR_DECODE
				LDA				joy_dir
				AND				#JOYM_P1
				STA				joy_p1_dir
.ENDMACRO


; Decode digital joystick for player 2 directions.

.MACRO			JOY_DIR_DECODE
				LDA				joy_dir
				AND				#JOYM_P2
				STA				joy_p2_dir
.ENDMACRO




; TODO: Impl.


				.DATA

joy_dir			.RES			1	; Last read of joystick direction.

joy_p1_dir			.RES			1	; Last read of joystick direction.

joy_p2_dir			.RES			1	; Last read of joystick direction.

joy_p1_fire		.RES			1	; Last read of the joystick player 1 fire buttons.

joy_p2_fire		.RES			1	; Last read of the joystick player 2 fire buttons.

;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


