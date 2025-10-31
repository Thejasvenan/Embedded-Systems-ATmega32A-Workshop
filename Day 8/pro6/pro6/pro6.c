#define F_CPU 8000000UL // 8 MHz clock frequency
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;	// set PORTB for Output
	DDRD = 0b11111100; // set 0 and 1 as input inPORTD
	int a = 0;
	do 
	{
		switch (a){
			case 0: PORTB = 0b11111100;	break;
			case 1: PORTB = 0b01100000; break;
			case 2: PORTB = 0b11011010; break;
			case 3: PORTB = 0b11110010; break;
			case 4: PORTB = 0b01100110; break;
			case 5: PORTB = 0b10110110; break;
			case 6: PORTB = 0b10111110; break;
			case 7: PORTB = 0b11100000; break;
			case 8: PORTB = 0b11111110; break;
			case 9: PORTB = 0b11110110; break;
		}
		if (PIND==1){
			_delay_ms(500);
			if (a!=9){a = a+1;}
			else
				a=0;	
		}
		if (PIND==2)
		{	_delay_ms(500);
			if (a!=0){a = a-1;}
			else
				a=9;	
		}
	} while (a<10);
	return 1;
}