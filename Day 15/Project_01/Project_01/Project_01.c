#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t flag = 0;

ISR(INT1_vect)
{
	flag = 1;
}

void pwm_init()
{	
	DDRD |= (1 << PD5);       // OC1A output

	// Fast PWM, Mode 14: WGM13:0 = 1110
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11); // Prescaler = 8

	ICR1 = 20000;   // 20 ms period (50 Hz)
}

void move_servo(int start, int end, int step)
{
	if (start < end)
	{
		for (int i = start; i <= end; i += step)
		{
			OCR1A = i;
			_delay_ms(5);
		}
	}
	else
	{
		for (int i = start; i >= end; i -= step)
		{
			OCR1A = i;
			_delay_ms(5);
		}
	}
}

int main(void)
{
	OCR1A = 1000;
	pwm_init();
	PORTD |= (1 << PD3);   // Enable pull-up on INT1
	GICR = (1<<INT1);
	MCUCR = (1<<ISC11);
	sei();
	
	while (1){
		if (flag)
		{
			flag = 0;
			// Open smoothly (0° ? 90°)
			move_servo(1000, 2000, 1);

			// Hold open 10 seconds
			_delay_ms(10000);

			// Controlled Closing

			// Close 40°
			move_servo(2000, 1556, 1);
			_delay_ms(500);

			// Close 30°
			move_servo(1556, 1222, 1);
			_delay_ms(500);

			// Close 20°
			move_servo(1222, 1000, 1);
		}
	}
		
	return(1);
}
