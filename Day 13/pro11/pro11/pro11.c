#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void USART_init(void) {
	UCSRA = 0x00;
	UCSRB = 0x98;
	UCSRC = 0x86;
	UBRRL = 0x33;
	UBRRH = 0x00;
}

ISR(USART_RXC_vect) {
	PORTB = UDR;
}

int main(void) {
	USART_init();
	sei();
	DDRB = 0xFF;
	DDRC = 0xFF;

	while (1) {
		PORTC |= (1 << PC0);
		_delay_ms(2000);

		PORTC &= ~(1 << PC0);
		_delay_ms(2000);
	}
	return 0;
}