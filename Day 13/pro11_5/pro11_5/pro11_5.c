#define F_CPU 10000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void timer0_init()
{
	TCCR0 |= (1 <<CS02);	// prescaler 256
	TCNT0 = 0;
}

int main(void){
	DDRC |= (1 << 0);
	timer0_init();
	while(1){
		if (TCNT0 >= 249)
		{
			PORTC ^= (1<<0);
			TCNT0 = 0;
		}
	}
}