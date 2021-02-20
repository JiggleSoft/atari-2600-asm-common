; STATUS: WORK IN PROGRESS.
;==============================================================================
; Title:        Atari 2600 CPU standard extra include file.
; Filename:     a2k6-stdx-cpu.inc
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

                .IFNDEF     __A2K6_STDX_CPU__INC__
                            __A2K6_STDX_CPU__INC__ = 1

;==============================================================================
; Atari 2600 Central Processing Unit (CPU).
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Temporary storage.
;------------------------------------------------------------------------------

;ramtmp_0:
;cpu_src_addr:
;cpu_src_addr_l:
;            RS      1
;cpu_tmp_1:
;cpu_src_addr_h:
;            RS      1
;;cpu_tmp_0:
;;cpu_src_addr:
;cpu_src_addr_l:
;            RS      1
;cpu_tmp_1:
;cpu_src_addr_h:
;            RS      1
;cpu_tmp_0:
;cpu_src_addr:
;cpu_src_addr_l:
;            RS      1
;cpu_tmp_1:
;cpu_src_addr_h:
;            RS      1
;cpu_tmp_0:
;cpu_src_addr:
;cpu_src_addr_l:
;            RS      1
;cpu_tmp_1:
;cpu_src_addr_h:
;            RS      1



;------------------------------------------------------------------------------
; Macro Instructions.
;------------------------------------------------------------------------------

; Repeat single operation a number of times.

.MACRO          CPU_REPEAT      oper,num
                .REPEAT         num
                oper
                .ENDREPEAT
.ENDMACRO



; Store the Accumulator to multiple consecutive memory locations.

.MACRO          CPU_STAM        addr,len
                .IF (len < 1)
                .ERROR          "CPU_STAM: len must be 1 or more."
                .ENDIF
                .IF (len > 4)
                .WARNING        "CPU_STAM: len > 4 will use much storage!"
                .ENDIF
offset          .SET            0
                .REPEAT         len
                STA             addr+offset
offset          .SET            offset + 1
                .ENDREPEAT
.ENDMACRO



; Store the X register to multiple consecutive memory locations.

.MACRO          CPU_STXM        addr,len
                .IF (len < 1)
                .ERROR          "CPU_STXM: len must be 1 or more."
                .ENDIF
                .IF (len > 4)
                .WARNING        "CPU_STXM: len > 4 will use much storage!"
                .ENDIF
offset          .SET            0
                .REPEAT         len
                STX             addr+offset
offset          .SET            offset + 1
                .ENDREPEAT
.ENDMACRO



; Store the Y register to multiple consecutive memory locations.

.MACRO          CPU_STYM        addr,len
                .IF (len < 1)
                .ERROR          "CPU_STYM: len must be 1 or more."
                .ENDIF
                .IF (len > 4)
                .WARNING        "CPU_STYM: len > 4 will use much storage!"
                .ENDIF
offset          .SET            0
                .REPEAT         len
                STY             addr+offset
offset          .SET            offset + 1
                .ENDREPEAT
.ENDMACRO


; Push all registers (A,X,Y). Afterwards A=Y.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHAXY
                PHA
                TXA
                PHA
                TYA
                PHA
.ENDMACRO



; Push all registers (A,X,Y). Temporary storage used to preserve A.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHAXY_TEMP  temp
                STA             temp
                PHA
                TXA
                PHA
                TYA
                PHA
                LDA             temp
.ENDMACRO



; Push all registers (A,X,Y). Stack used to preserve A.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHAXY_PRES
                PHA
                TXA
                TSX
                PHA
                TYA
                PHA
                INX
                LDA             $100,X  ; Get pushed A
                PHA                     ; and push temporarily.
                DEX
                LDA             $100,X  ; Get pushed X
                TAX                     ; and restore X.
                PLA                     ; Restore from temporary push.
.ENDMACRO



; Push all registers (A,X,Y). Stack used to preserve A.
; Reduced code size compared to CPU_PHAXY_PRES.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHAXY_PRES_MIN
                PHA
                TXA
                TSX
                PHA
                TYA
                PHA
                LDA             a:$101,X    ; Get pushed A
                PHA                         ; and push temporarily.
                LDA             a:$FF,X     ; Get pushed X
                TAX                         ; and restore X.
                PLA                         ; Restore from temporary push.
.ENDMACRO



; Atari 2600 specific push all registers (A,X,Y) as stack memory mirror in ZP.
; Stack used to preserve A.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          A2K6_PHAXY_PRES
                PHA
                TXA
                TSX
                PHA
                TYA
                PHA
                LDA             z:$01,X     ; Get pushed A
                PHA                         ; and push temporarily.
                LDA             z:$00,X     ; Get pushed X
                TAX                         ; and restore X.
                PLA                         ; Restore from temporary push.
.ENDMACRO



; Pop all registers (Y, X, A).
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PLYXA
                PLA
                TAY
                PLA
                TAX
                PLA
.ENDMACRO



; Pop all registers (Y, X, A) and return from sub-routine.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PLYXA_RTS
                CPU_PLYXA
                RTS
.ENDMACRO



; Pop all registers (Y, X, A) and return from interrupt.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PLYXA_RTI
                CPU_PLYXA
                RTI
.ENDMACRO



; Push all registers (P,A,X,Y). Afterwards A=Y.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHPAXY
                PHP
                CPU_PHAXY
.ENDMACRO



; Push all registers (P,A,X,Y). Temporary storage used to preserve A.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHPAXY_TEMP temp
                PHP
                CPU_PHAXY_TEMP  temp
.ENDMACRO



; Push all registers (P,A,X,Y). Stack used to preserve A.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHPAXY_PRES
                PHP
                CPU_PHAXY_PRES
.ENDMACRO



; Push all registers (P,A,X,Y). Stack used to preserve A.
; Reduced code size compared to CPU_PHPAXY_PRES.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PHPAXY_PRES_MIN
                PHP
                CPU_PHAXY_PRES_MIN
.ENDMACRO



; Push all registers (P,A,X,Y). Stack used to preserve A.
; Atari 2600 specific push all registers (P,A,X,Y) as stack memory mirror in ZP.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          A2K6_PHPAXY_PRES
                PHP
                A2K6_PHAXY_PRES
.ENDMACRO



; Pop all registers (Y, X, A, P).
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PLYXAP
                CPU_PLYXA
                PLP
.ENDMACRO



; Pop all registers (Y, X, A, P) and return from sub-routine.
; Note: The 65C02 has dedicated push/pull for X and Y and not available 6502.

.MACRO          CPU_PLYXAP_RTS
                CPU_PLYXAP
                RTS
.ENDMACRO



;------------------------------------------------------------------------------
; CPU Spinning Delay Routines.
;------------------------------------------------------------------------------

; Delay by repeated NOP instructions.

.MACRO          CPU_DELAY_NOP   cycles
                .IF cycles < 2
                .ERROR      "CPU_DELAY_NOP: cycles must be 2 or more!"
                .ENDIF
                .IF (cycles .MOD 2) = 1
                .ERROR      "CPU_DELAY_NOP: cycles must be multiples of 2!"
                .ENDIF
                ;.ELSE
                .IF (cycles > 15)
                .WARNING    "CPU_DELAY_NOP: cycles > 15 will use much storage!"
                .ENDIF
                .REPEAT     (cycles/2)
                NOP
                .ENDREPEAT
                ;.ENDIF
.ENDMACRO



;.MACRO          CPU_DELAY   cycles
                ;.IF         cycles <2
                ;.ERROR      "CPU_DELAY: cycles must be 2 or more!"
                ;.ELSE
                ;.IF         cycles > 15
                ;.WARNING    "CPU_DELAY: cycles > 15 will use much storage!"
                ;.ENDIF
                ;.REPEAT     (cycles-2) / 3
                ;;CPU_NOP3
                ;.ENDREPEAT
                ;;.IF cycles % 2 == 1 fixme
                ;NOP
                ;.ENDIF
                ;.ENDIF
;.ENDMACRO


;------------------------------------------------------------------------------
; Memory Clear.
;------------------------------------------------------------------------------

; Clear memory via repeated store (A=0).

.MACRO zzz
.ENDMACRO
; Clear memory via repeated store (A=0).

.MACRO xxx
.ENDMACRO





;------------------------------------------------------------------------------
; Memory Copy.
;------------------------------------------------------------------------------

;mem cpy unwrap
;mem cpy immediate
;mem cpy zp reg
;8 bit offset
;zp,abs
;> 256 bytes
.MACRO          CPU_MEMCPY  dst,src,len
.ENDMACRO

cpu_memcpy:


;------------------------------------------------------------------------------
; Memory Compare.
;------------------------------------------------------------------------------



;------------------------------------------------------------------------------
; 8-bit Integer.
;------------------------------------------------------------------------------

; Add without carry.

.MACRO          CPU_ADD     oper
                CLC
                ADC         oper
.ENDMACRO


; Subtract without carry.

.MACRO          CPU_SUB     oper
                SEC
                SBC         oper
.ENDMACRO



;------------------------------------------------------------------------------
; 16-bit Integer.
;------------------------------------------------------------------------------

; Increment 16-bit memory value by one with carry.

.MACRO          CPU_INCC16      addr
                LDA             addr
                ADC             #$01
                STA             addr
                LDA             addr+1
                ADC             #$00
                STA             addr+1
.ENDMACRO



; Increment 16-bit memory value by one.

.MACRO          CPU_INC16       addr
                CLC
                CPU_INCC16      addr
.ENDMACRO



; Decrement 16-bit memory value by one with carry.

.MACRO          CPU_DECC16      addr
                LDA             addr
                SBC             #$01
                STA             addr
                LDA             addr+1
                SBC             #$00
                STA             addr+1
.ENDMACRO



; Decrement 16-bit memory value by one.

.MACRO          CPU_DEC16       addr
                SEC
                CPU_DECC16      addr
.ENDMACRO



; Add immediate 16-bit value to memory value with carry.

.MACRO          CPU_ADC16_IM    val,addr
.ENDMACRO

; Add immediate 16-bit value to memory value.

.MACRO          CPU_ADD16_IM    val,addr
                CPU_ADD         #val lo
                STA             addr
                LDA             addr+1
                ADC             #val hi
                STA             addr+1
.ENDMACRO



; Add 16-bit memory value to another 16-bit memory value.

;.MACRO          CPU_ADD16_IM
;.ENDMACRO

; Subtract immediate 16-bit value to memory value.

.MACRO          CPU_SBC16       val,addr
.ENDMACRO



; Subtract 16-bit memory value from another 16-bit memory value.


; Compare immediate 16-bit memory valye with memory value.

; Compare 16-bit memory value to memory value.

; Clear 16 bit memory valye

; Copy 16-bit memory value




;------------------------------------------------------------------------------

;                .POPSEG

;------------------------------------------------------------------------------

;.ENDIF



;==============================================================================
; Atari 2600 CPU utilities.
;==============================================================================


;------------------------------------------------------------------------------
; CPU Time Spinning Macros.
;------------------------------------------------------------------------------

;

.MACRO		CPU_NOP_REP		rep
			.REPEAT
			NOP
			.ENDREPEAT
.ENDMACRO




; Delay n cycles (2 <= n <= TODO)

.MACRO		CPU_DELAY		cyc
.ENDMACRO



;------------------------------------------------------------------------------
; CPU Illegal Instructions.
;------------------------------------------------------------------------------

; NOP read address??? 1 or 2 bytes? ZP?



;------------------------------------------------------------------------------


;------------------------------------------------------------------------------




;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


