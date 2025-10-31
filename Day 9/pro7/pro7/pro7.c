#define F_CPU 8000000UL	// 8 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>
#define D0 eS_PORTD0
#define D1 eS_PORTD1
#define D2 eS_PORTD2
#define D3 eS_PORTD3
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTB0
#define EN eS_PORTB1
#include "lcd.h"

int main(void){
	DDRD = 0xFF;
	DDRB = 0xFF;
	Lcd8_Init();
	while(1){
		Lcd8_Set_Cursor(1,0);	
		Lcd8_Write_String("NEW Embedded LAB 2025");	
		for (int i=0;i<21;i++)
		{
			_delay_ms(1000);
			Lcd8_Shift_Left();
		}
		_delay_ms(1000);	
		Lcd8_Clear();
		_delay_ms(100);
	}
}