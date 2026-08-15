#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void USART_init()
{
	UBRRH = 0;
	UBRRL = 51;                      // 9600 baud @ 8MHz
	UCSRB = (1<<TXEN);               // Enable transmitter
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); // 8-bit
}

void USART_send(char data)
{
	while (!(UCSRA & (1<<UDRE)));  // Wait until buffer empty
	UDR = data;
}

void USART_send_string(char *str)
{
	while (*str)
	{
		USART_send(*str++);
	}
}

ISR(INT1_vect)
{
	USART_send_string("Open Gate\n");
}

void INT1_init()
{
	MCUCR |= (1<<ISC11);    // Falling edge on INT1
	MCUCR &= ~(1<<ISC10);
	GICR |= (1<<INT1);      // Enable INT1 interrupt
	sei();
}

int main(void)
{
    USART_init();
    INT1_init();
    sei();  // Enable global interrupt	
    while (1){;}
	return 0;
}

