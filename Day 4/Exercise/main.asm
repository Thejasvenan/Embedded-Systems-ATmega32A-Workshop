;
; Exercise.asm
;
; Created: 16-Aug-25 10:08:55 AM
; Author : Thejas

// B = A + 10 + A^2
LDI R26, 10 
LDI R17, 255
ADD R26, R17 // Storing A + 10 in XL
ADC R27, R1
MUL R17, R17 // Storing A^2 in R1, R0
ADD R26, R0  // Storing XL of B
ADC R27, R1  // Storing XH of B
NOP