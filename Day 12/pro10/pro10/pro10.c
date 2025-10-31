#define F_CPU 8000000UL
#include <avr/io.h>

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

void USART_send(unsigned char data){
	// Wait until UDRE flag = 1
	while ((UCSRA & (1<<UDRE))==0x00);	// while (!(UCSRA & (1<<UDRE)));
	// Read the received char from UDR
	UDR = data;
}

unsigned char USART_receive(void){
	// Wait until RXC flag = 1
	while ((UCSRA & (1<<RXC))==0x00);	// while (!(UCSRA & (1<<RXC)));
	// Write UDR to char for receiving
	return UDR;
}

int main(void)
{
   unsigned char data;
   USART_init();	
   while(1){
	data = USART_receive();
	USART_send(data);
   }
}