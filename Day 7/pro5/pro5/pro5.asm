.INCLUDE "M32ADEF.INC" // Atmega32 microcontroller
.org $00

begin:
LDI R16,0x20
LDI R17,0x00
OUT DDRD,R16	// Set DDD5 as Output
loop:
	EOR R18,R18
	OUT PORTD,R16	// Set Output 1
	loop1:inc R18
		nop nop nop nop nop nop nop nop nop nop
		nop nop nop nop nop nop nop nop nop nop
		nop nop nop nop nop nop nop nop nop
		cpi R18,250
		brlo loop1
	EOR R18,R18
	OUT PORTD,R17	// Set Output 0
	loop2:inc R18
		nop nop nop nop nop nop nop nop nop nop
		nop nop nop nop nop nop nop nop nop nop
		nop nop nop nop nop nop nop nop nop
		cpi R18,250
		brlo loop2
	JMP loop	// Takes 3 clock cycles
END:NOP