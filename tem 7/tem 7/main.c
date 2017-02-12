#define F_CBU 1000000 UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA &=~ (1<<PA1) ;
	DDRB |= (1<<PB0) | (1<<PB1) ;
	volatile uint8_t adc ;
	 int x = 1;
	ADCSRA |=(1<<ADEN) ;                    
	ADCSRA |=(1<<ADPS0)|(1<<ADPS1) ;        
	ADMUX |= (1<<ADLAR) ;
	ADMUX |=(1<<MUX0) ;                     
	ADCSRA |= (1<<ADSC) ;
	while (ADCSRA&(1<<ADSC));
	adc=ADCH ;
	do
{
		while (adc>50)
		{
			PORTB |= (1<<PB0) ;
			ADCSRA |= (1<<ADSC) ;
			while (ADCSRA&(1<<ADSC));
			adc=ADCH ;
		}
		PORTB =0x00;
		while(adc<=50&&adc>45)
		{
		PORTB = 0x00 ;
		ADCSRA |= (1<<ADSC) ;
		while (ADCSRA&(1<<ADSC));
		adc=ADCH ;
	    }
	PORTB =0x00;
	while (adc<=45)
	{
		PORTB |= (1<<PINB1) ;
		ADCSRA |= (1<<ADSC) ;
		while (ADCSRA&(1<<ADSC));
		adc=ADCH ;
	}
	PORTB =0x00;
} while (x=1);
return 0 ;
}
