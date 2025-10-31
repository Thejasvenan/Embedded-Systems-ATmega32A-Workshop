;
; New1.asm
;
; Created: 18-Sep-25 8:07:35 PM
; Author : Thejas
;


; ===========================================
; Toggle PD5 with 1 ms ON, 1 ms OFF
; F_CPU = 8 MHz
; Delay ~1 ms using nested loops
; ===========================================

.include "m32adef.inc"       ; Atmega32A definitions

.org 0x0000
    rjmp RESET

RESET:
    ; ----- I/O setup -----
    ldi r16, (1<<PD5)       ; set PD5 as output
    out DDRD, r16

MAIN_LOOP:
    ; ----- Turn PD5 HIGH -----
    sbi PORTD, PD5
    rcall DELAY_1MS

    ; ----- Turn PD5 LOW -----
    cbi PORTD, PD5
    rcall DELAY_1MS

    rjmp MAIN_LOOP           ; repeat forever


; ===========================================
; Subroutine: DELAY_1MS
; Approx 1 ms delay at 8 MHz
; 3 nested loops ? ~8000 cycles
; ===========================================
DELAY_1MS:
    ldi r18, 8              ; outer loop
L1: ldi r19, 125            ; inner loop
L2: ldi r20, 2
L3: dec r20
    brne L3                 ; 2 cycles per iteration
    dec r19
    brne L2
    dec r18
    brne L1
    ret
