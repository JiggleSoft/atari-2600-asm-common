;==============================================================================
; Name:         Atari 2600 kernel playfield 0.
; Filename:     a2k6_kernel_pf0.inc
; Platform:     Atari 2600
; Language:		6507 Assembly Language (https://www.cc65.org/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2018-12-30 22:28
;------------------------------------------------------------------------------
; Licence:		This file is licensed under the following licence:-
;				 		CC Attribution 3.0 Unported
;						http://creativecommons.org/licenses/by/3.0/
;------------------------------------------------------------------------------


;==============================================================================
; Atari 2600 - Kernel
;	Single Background Colour and Foreground Color.
;	Fixed Pixel Height.
; 	Asymetric Playfield Matrix.
;==============================================================================

				.PUSHSEG

;------------------------------------------------------------------------------
; Kernel Runtime Data.
;------------------------------------------------------------------------------

				.DATA

				.IFNDEF		kpf0_vbcol
kpf0_vbcol:		.RES		1	; Vertical Blank Background Colour.
				.ENDIF

				.IFNDEF		kpf0_bkcol
kpf0_bkcol:		.RES		1	; Visible Display Background Colour.
				.ENDIF

				.IFNDEF		kpf0_pfcol
kpf0_pfcol:		.RES		1	; Playfield Colour.
				.ENDIF

				.IFNDEF		kpf0_oscol
kpf0_oscol:		.RES		1	; Overscan Background Colour.
				.ENDIF

				.IFNDEF		kpf0_height
kpf0_height:	.RES		1	; Number of Horizontal Lines of Playfield Data.
				.ENDIF

				.IFNDEF		kpf0_repeat
kpf0_repeat		.RES		1	; Size of each Horizontal Line (line repeat).
				.ENDIF

				.IFNDEF		kpf0_pfdat
kpf0_pfdat		.RES		2	; Playfield data address.
				.ENDIF

				.IFNDEF		kpf0_repeat
kpf0_pfptr		.RES		2	; Playfield current data pointer.
				.ENDIF


;------------------------------------------------------------------------------
; Configure and Render Kernel to the Video Display.
;------------------------------------------------------------------------------

; Configure Kernel frame data.

.MACRO		KPF0_FRAME_CONFIG_PTR		kpf0conf
			LDA			kppf0conf+0
			STA			kpf0_vbcol
			LDA			kppf0conf+1
			STA			kpf0_bkcol
			LDA			kppf0conf+2
			STA			kpf0_pfcol
			LDA			kppf0conf+3
			STA			kpf0_oscol
			LDA			kppf0conf+4
			STA			kpf0_height
			LDA			kppf0conf+5
			STA			kpf0_repeat
			LDA			#<(kpf0conf+6)
			STA			kpf0_pfdat
			STA			kpf0_pfptr
			LDA			#>(kpf0conf+6)
			STA			kpf0_pfdat+1
			STA			kpf0_pfptr+1
.ENDMACRO


;

.MACRO		KPF0_FRAME_CONFIG		vpcol,bkcol,pfcol,oscol,height,repeat,pfdat
			LDA			#vbcol
			STA			kpf0_vbcol
			LDA			#bkcol
			STA			kpf0_bkcol
			LDA			#pfcol
			STA			kpf0_pfcol
			LDA			#oscal
			STA			kpf0_oscol
			LDA			#height
			STA			kpf0_height
			LDA			#repeat
			STA			kpf0_repeat
			LDA			#<pfdat
			STA			kpf0_pfdat
			STA			kpf0_pfptr
			LDA			#>pfdat
			STA			kpf0_pfdat+1
			STA			kpf0_pfptr+1
.ENDMACRO



; Initialise Kernel before first frame.

.MACRO		KPF0_FRAME_INIT
			NOP	; TODO: Impl.!
.ENDMACRO



; Begin Kernel frame.

.MACRO		KPF0_FRAME_BEGIN
			NOP	; TODO: Impl.!
.ENDMACRO



; Show Kernel frame.

.MACRO		KPF0_FRAME_SHOW
			NOP	; TODO: Impl.!
.ENDMACRO



; End Kernel frame.

.MACRO		KPF0_FRAME_END
			NOP	; TODO: Impl.!
.ENDMACRO



; Uninitialise Kernal after last frame.

.MACRO		KPF0_FRAME_DONE
.ENDMACRO



; Show splash screen for given number of frames.

.MACRO		KPF0_SPLASH_SHOW		frame_count
			.LOCAL			nextframe
			.LOCAL			exitframe
            ; <<< Start Up >>>
			KPF0_FRAME_INIT
nextframe:
			KPF0_FRAME_BEGIN
			; <<< Vertical Blank >>>
			KPF0_FRAME_SHOW
			; <<< Overscan >>>
		JMP exitframe ; FIXME: count for frame_count frames!!!!
			KPF0_FRAME_END
			JMP				nextframe
exitframe:
			KPF0_FRAME_DONE
            ; <<< Clean Up >>>
.ENDMACRO



;------------------------------------------------------------------------------
; Playfield Data.
;------------------------------------------------------------------------------

; Define Start of Playfield Data

.MACRO		KPF0_BEGIN	vbcol,bkcol,pfcol,oscol,height,repeat
			.BYTE		vbcol	; Vertical Blank Background Colour.
			.BYTE		bkcol	; Visible Display Background Colour.
			.BYTE		pfcol	; Playfield Colour.
			.BYTE		oscol	; Overscan Background Colour.
			.BYTE		height	; Number of Horizontal Lines of Playfield Data.
			.BYTE		repeat	; Size of each Horizontal Line (line repeat).
.ENDMACRO



; Define Data for a Horizontal Line of an Asymetric Playfield

.MACRO		KPF0_PFCSV	B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
	PF_6_40CSV	B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,B16,B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31,B32,B33,B34,B35,B36,B37,B38,B39
.ENDMACRO



; Define End of Playfield Data

.MACRO		KPF0_END
			; Empty.
.ENDMACRO



;------------------------------------------------------------------------------

				.POPSEG

;------------------------------------------------------------------------------


