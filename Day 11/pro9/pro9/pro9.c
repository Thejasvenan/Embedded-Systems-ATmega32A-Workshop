#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdint.h>
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

void adc_init(){
	ADMUX = (1<<REFS0);	// AREF = A Vcc
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);	// ADC Enable and prescaler of 128
}

uint16_t ReadADC(uint8_t ch){
	ch &= 0b00000111;
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	ADCSRA |= (1<<ADSC);	// Single start conversion
	while (!(ADCSRA & (1<<ADIF)));	// Wait for conversion
	// ADCSRA |= (1<<ADIF);
	return (ADC);
}

int main(void){
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0xFF;
	Lcd8_Init();
	adc_init();
	int tempC;
	int threshC;
	uint16_t temp_adc;
	uint16_t thresh_adc;
	char strVal[4];	
    while(1){
		temp_adc = ReadADC(1);	// LM35 connected with ADC1
		thresh_adc = ReadADC(2);	// POT connected with ADC2
		tempC = temp_adc*5000UL/1023/10;	// 10 mV/C
		threshC = thresh_adc*100UL/1023;	// Mapped to 0-100 C
		itoa(tempC, strVal, 10);
		Lcd8_Clear();
		Lcd8_Set_Cursor(1,0);
		Lcd8_Write_String("Temp=");
		Lcd8_Write_String(strVal);
		Lcd8_Write_String("C");
		itoa(threshC,strVal,10);
		Lcd8_Write_String("Set= ");
		Lcd8_Write_String(strVal);
		Lcd8_Write_String("C");
		if (tempC>threshC)
		{
			Lcd8_Set_Cursor(2,4);
			Lcd8_Write_String("*ALERT*");
			PORTC |= (1>>PC0);	// Set LED ON
		} 
		else
		{	
			PORTC &= (0>>PC0);	// Set LED OFF
		}
		_delay_ms(500);
    }
}