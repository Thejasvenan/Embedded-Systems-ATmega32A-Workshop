#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void USART_init(void) {
	UCSRA = 0x00;
	UCSRB = 0b00011000;
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
		while((UCSRA & (1<<RXC)) == 0x00){	
			PORTC = 1;
			_delay_ms(1000);
			PORTC = 0;
			_delay_ms(1000);
		}
		PORTB = UDR;
		_delay_ms(1000);
	}
	return 0;
}