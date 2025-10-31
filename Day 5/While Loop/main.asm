;
; While Loop.asm
;
; Created: 22-Aug-25 8:05:25 PM
; Author : Thejas
;


; Replace with your application code
    ldi r16, 1        ; k = 1
    ldi r17, 1        ; sum = 1
    ldi r19, 5        ; constant 5 for comparison

loop:
    mov r18, r17      ; temp = sum
    mul r18, r16      ; temp * k ? result in r0:r1
    mov r17, r0       ; store lower byte of result in sum
    clr r1            ; clear upper byte of result (r1)

    inc r16           ; k++

	cpi r16, $6       ; compare k with 6
    brge end_loop     ; if k > 5, exit loop
    rjmp loop         ; repeat loop

end_loop:
    ; sum is now in r17
