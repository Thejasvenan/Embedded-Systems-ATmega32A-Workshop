#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR (INT1_vect)
{
	PORTB = (~PORTB);
}

int main(void)
{
	GICR = (1<<INT1);
	MCUCR = (1<<ISC10) | (1<<ISC11);
	sei();
	DDRB = 0xFF;
	DDRC = 0X0;
	PORTB = 0b01010101;
	while (1){;}
	return 0;
}