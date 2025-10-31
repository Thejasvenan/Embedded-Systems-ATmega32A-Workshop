#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint16_t tot_overflow;

void timer0_init()
{
	TCCR0 |= (1 << CS01)|(1 << CS00);	// prescaler = 64
	TCNT0 = 0;	// Initialize counter
	TIMSK |= (1 << TOIE0);	//
	sei();	// enable global interrupt
	tot_overflow = 0;	// set number of overflow to 0
}

ISR(TIMER0_OVF_vect){
	tot_overflow++;	// keep a track of number of overflows
}

void step_count(int num, int *iteration, int *steps) {
	int count = num * 125 - 1;    // for prescaler 64
	*iteration = count / 256;
	*steps = count % 256;
}

ISR (INT0_vect)
{
	if (PORTB!=10){PORTB = PORTB+1;}
	else
	PORTB=0;
}

ISR (INT1_vect)
{
	if (PORTB!=0){PORTB = PORTB-1;}
	else
	PORTB=10;
}

int main(void){
	sei();
	DDRB = 0xFF;
	GICR = (1<<INT1) | (1<<INT0);
	MCUCR = (1<<ISC10) | (1<<ISC11);
	int num = 0;
	DDRC = 0xFF;
	DDRC |= (1 << 0);	// connect led to pin PC0
	timer0_init();
	do{	
		num = PORTB;
		int on_i, on_s, off_i, off_s;
		step_count(num, &on_i, &on_s);
		step_count(10-num, &off_i, &off_s);
		if (tot_overflow >= on_i && PORTC == 1)
		{	
			if (TCNT0 >= on_s )
			{	
				PORTC = (0<<0);	// On the led
				TCNT0 = 0;	//reset counter
				tot_overflow = 0;	// reset overflow count			
			}
		}
		if (tot_overflow >= off_i && PORTC == 0)	
		{
			if (TCNT0 >= off_s )	
			{
				PORTC = (1<<0);	// Off the led
				TCNT0 = 0;	//reset counter
				tot_overflow = 0;	// reset overflow count
			}
		}
	}while(PORTB<11);
}