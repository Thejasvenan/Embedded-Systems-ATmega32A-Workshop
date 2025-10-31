;
; AssemblerApplication1.asm
;
; Created: 02-Aug-25 11:04:57 AM
; Author : Thejas
;

LDI R16, 95
LDI R17, 19
ADD R16, R17
LDI R17, 5
ADD R16, R17
STS 0x80, R16
LDS R17, 0x80
STS 0x81, R17
NOP
