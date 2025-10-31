#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define D0 eS_PORTA0
#define D1 eS_PORTA1
#define D2 eS_PORTA2
#define D3 eS_PORTA3
#define D4 eS_PORTA4
#define D5 eS_PORTA5
#define D6 eS_PORTA6
#define D7 eS_PORTA7
#define RS eS_PORTB0
#define EN eS_PORTB1
#include "lcd.h"

void USART_init(void){
	// Asynchronous mode, no parity, 1 stop bit, 8 data bits
	UCSRC = 0b10000110;
	// Normal speed, disable multi-proc
	UCSRA = 0b00000000;
	// Baud rate 9600 bps, assuming 8 MHz clock
	UBRRL = 0x33;
	UBRRH = 0x00;
	// Enable Tx and Rx, disable interrupts
	UCSRB = 0b00011000;
}

unsigned char USART_receive(void){
	// Wait until RXC flag = 1
	while ((UCSRA & (1<<RXC))==0x00);	// while (!(UCSRA & (1<<RXC)));
	// Write UDR to char for receiving
	return UDR;
}

int main(void)
{	DDRA = 0xFF;
	DDRB = 0xFF;
	Lcd8_Init();
	unsigned char data;
	USART_init();
	while (1){
		data = USART_receive();
		Lcd8_Set_Cursor(1,0);
		if (data == 'M')
		{	
			Lcd8_Clear();
			Lcd8_Write_String("Good Morning");
		}
		if (data == 'A')
		{
			Lcd8_Clear();
			Lcd8_Write_String("Good Afternoon");
		}
		if (data == 'E')
		{
			Lcd8_Clear();
			Lcd8_Write_String("Good Evening");
		}
		_delay_ms(1000);
	}
}