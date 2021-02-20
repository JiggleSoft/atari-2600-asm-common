;==============================================================================
; Name:         Atari 2600 cartridge types and bank switching include file.
; Filename:     a2k6cart.inc
; Platform:     Atari 2600
; Language:     6507 Assembly Language (https://cc65.github.io/doc/ca65.html)
; Author:       Justin Lane (atari2600@jigglesoft.co.uk)
; Date:         2020-11-26 23:47
; Version:      1.2.3
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

                .IFNDEF     __A2K6CART__INC__
                .DEFINE     __A2K6CART__INC__

;==============================================================================
; Atari 2600 Cartridge Types and Bank Switching Methods.
;
; Non-Switched:     1k, 2k, 4k, 4KSC, CV.
; Legacy Atari:     F4, F4SC, F6, F6SC, F8, F8SC.
; Legacy Other:     3F, DPC, E0, E7, E78K, F0, FA, FE, UA.
; Modern:           0840, 3E, 3E+, 3EX, AR, EF, EFSC, SB, X07.
; Experimental:     JL1, JL2, JL3, JL4.
; Future Candidate: BF, BFSC, BUS, CDF0, CDF1, CDFJ, CDFJ+, CM, CTY, DF, DFSC,
;                   DPC+, FA2, FC, MDM, TVBoy, WD.
; Unsupported:      4A50.
; Unknown:          Star Castle scheme.
;==============================================================================

                .PUSHSEG

;------------------------------------------------------------------------------
; Not Bank Switched
;------------------------------------------------------------------------------

; 1K - Atari 1 KByte (no bank switching required).

                ; Not applicable to have a specific include file.

; 2K - Atari 2 KByte (no bank switching required).

                ; Not applicable to have a specific include file.

; 4K - Atari 4 KByte (no bank switching required).

                ; Not applicable to have a specific include file.

; 4KSC - Atari 4K (no bank switching required) with SARA Super Chip RAM 128B.

                .IFDEF      CART_4KSC
                .INCLUDE    "a2k6cart-4ksc.inc"
                .ENDIF

; CV - Commavid 2 KByte ROM, 1 KByte RAM (no bank switching required).

                .IFDEF      CART_CV
                .INCLUDE    "a2k6cart-cv.inc"
                .ENDIF



;------------------------------------------------------------------------------
; Legacy Atari Bank Switching
;------------------------------------------------------------------------------

; F4 - Atari Standard 32K ROM (32K ROM)

                .IFDEF      CART_F4
                .INCLUDE    "a2k6cart-f4.inc"
                .ENDIF

; F4SC - Atari F4 with SARA Super Chip RAM (32K ROM,128B RAM)

                .IFDEF      CART_F4SC
                .INCLUDE    "a2k6cart-f4sc.inc"
                .ENDIF

; F6 - Atari Standard 16K ROM (16K ROM)

                .IFDEF      CART_F6
                .INCLUDE    "a2k6cart-f6.inc"
                .ENDIF

; F6SC - Atari F6 with SARA Super Chip RAM (16K ROM,128B RAM)

                .IFDEF      CART_F6SC
                .INCLUDE    "a2k6cart-f6sc.inc"
                .ENDIF

; F8 - Atari Standard 8K ROM (8K ROM)

                .IFDEF      CART_F8
                .INCLUDE    "a2k6cart-f8.inc"
                .ENDIF

; F8SC - Atari F8 with SARA Super Chip RAM (8K ROM,128B RAM)

                .IFDEF      CART_F8SC
                .INCLUDE    "a2k6cart-f8sc.inc"
                .ENDIF



;------------------------------------------------------------------------------
; Legacy Other Bank Switching
;------------------------------------------------------------------------------

; 3F - Tigervision 8K (8K ROM)

                .IFDEF      CART_3F
                .INCLUDE    "a2k6cart-3f.inc"
                .ENDIF

; DPC - Display Processor Chip (8K+2K ROM)

                .IFDEF      CART_DPC
                .INCLUDE    "a2k6cart-dpc.inc"
                .ENDIF

; E0 - Parker bros. 8K (8K ROM)

                .IFDEF      CART_E0
                .INCLUDE    "a2k6cart-e0.inc"
                .ENDIF

; E7 - M-network 16K (16K ROM, 2K?1K RAM)

                .IFDEF      CART_E7
                .INCLUDE    "a2k6cart-e7.inc"
                .ENDIF

; E78K - M-network 16K (8K ROM, 2K?1K RAM)

                .IFDEF      CART_E78K
                .INCLUDE    "a2k6cart-e7.inc"
                .ENDIF

; F0 - Megaboy 64K  (68K ROM)

                .IFDEF      CART_F0
                .INCLUDE    "a2k6cart-f0.inc"
                .ENDIF

; FA - CBS RAM Plus 12K (12K ROM,256B RAM)

                .IFDEF      CART_FA
                .INCLUDE    "a2k6cart-fa.inc"
                .ENDIF

; FE - Activision 8K (8K ROM)

                .IFDEF      CART_FE
                .INCLUDE    "a2k6cart-fe.inc"
                .ENDIF

; UA - UA Ltd 8K (8K ROM)

                .IFDEF      CART_UA
                .INCLUDE    "a2k6cart-ua.inc"
                .ENDIF



;------------------------------------------------------------------------------
; Modern Bank Switching
;------------------------------------------------------------------------------

; 0840 - Econobanking (?)

                .IFDEF      CART_0840
                .INCLUDE    "a2k6cart-0840.inc"
                .ENDIF

; 3E - NAME? (up to 512K ROM + 32K RAM)

                .IFDEF      CART_3E
                .INCLUDE    "a2k6cart-3e.inc"
                .ENDIF

; 3E+

                .IFDEF      CART_3EPLUS
                .INCLUDE    "a2k6cart-3eplus.inc"
                .ENDIF

; 3EX

                .IFDEF      CART_3EX
                .INCLUDE    "a2k6cart-3ex.inc"
                .ENDIF

; AR

                .IFDEF      CART_AR
                .INCLUDE    "a2k6cart-ar.inc"
                .ENDIF

; EF - NAME? (64K ROM)

                .IFDEF      CART_EF
                .INCLUDE    "a2k6cart-ef.inc"
                .ENDIF

; EFSC

                .IFDEF      CART_EFSC
                .INCLUDE    "a2k6cart-efsc.inc"
                .ENDIF

; SB - Superbanking (?)

                .IFDEF      CART_SB
                .INCLUDE    "a2k6cart-sb.inc"
                .ENDIF

; X07 - Atariage (?))

                .IFDEF      CART_X07
                .INCLUDE    "a2k6cart-x07.inc"
                .ENDIF



;------------------------------------------------------------------------------
; JiggleSoft's Experimental Bank Switching
;------------------------------------------------------------------------------

; JL1 - JiggleSoft Basic Bank Switched (128,256,512K ROM,optional 32K RAM)

                .IFDEF      CART_JL1
                .INCLUDE    "a2k6cart-jl1.inc"
                .ENDIF

; JL2 - JiggleSoft Fat Bank Switched Cartridge (16M ROM,256K RAM,Memory Stream)

                .IFDEF      CART_JL2
                .INCLUDE    "a2k6cart-jl2.inc"
                .ENDIF

; JL3 - JiggleSoft Jr Titan Cartridge (16M ROM,256K RAM,6502,Co-proc.)

                .IFDEF      CART_JL3
                .INCLUDE    "a2k6cart-jl3.inc"
                .ENDIF

; JL4 - JiggleSoft Titan Cartridge (16M ROM,256K RAM,2xSID/WAV,6502,Co-proc,SD,USB,WiFi)

                .IFDEF      CART_JL4
                .INCLUDE    "a2k6cart-jl4.inc"
                .ENDIF



;------------------------------------------------------------------------------
; Future Candidates.
;------------------------------------------------------------------------------

; BF, BFSC, BUS, CDF0, CDF1, CDFJ, CDFJ+, CM, CTY, DF, DFSC, DPC+, FA2, FC, MDM, TVBoy, WD.



;------------------------------------------------------------------------------
; Unsupported.
;------------------------------------------------------------------------------

; 4A50.



;------------------------------------------------------------------------------
; Unknown.
;------------------------------------------------------------------------------

; Star Castle scheme.



;------------------------------------------------------------------------------

                .POPSEG

;------------------------------------------------------------------------------

                .ENDIF


