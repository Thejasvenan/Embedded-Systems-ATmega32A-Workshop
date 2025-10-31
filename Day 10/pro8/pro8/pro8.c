#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#define D0 eS_PORTD0
#define D1 eS_PORTD1
#define D2 eS_PORTD2
#define D3 eS_PORTD3
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7
#include "lcd.h"

int factorial(int n);
int main(void)
{	DDRD = 0xFF;
	DDRC = 0xFF;
	DDRA = 0x00;
	Lcd8_Init();
	char Stri[4];
	while(1){
		int n = PINA;
		_delay_ms(500);
		int v = factorial(n);
		itoa(n,Stri,10);
		Lcd8_Set_Cursor(1,0);
		Lcd8_Write_String("Fibonacci of ");
		Lcd8_Write_String(Stri);
		Lcd8_Set_Cursor(2,6);
		itoa(v,Stri,10);
		Lcd8_Write_String(Stri);
		_delay_ms(1000);
		Lcd8_Clear();
		_delay_ms(500);
	}
}

int factorial(int n){
	int product = 1;
	for (int i = 1; i<=n; i++)
	product = product * i;
	return product;
}