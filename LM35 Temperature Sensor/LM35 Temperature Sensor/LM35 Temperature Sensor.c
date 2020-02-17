// this program reads the sensor and displays it on PortD

#include <avr/io.h>

int main(void){
	DDRD   = 0xFF;	// make Port D an output
	DDRA   = 0X00;	// make Port A an input
	ADCSRA = 0x87;	// make ADC enable and select CLK/128
	ADMUX  = 0xE0;	// 2.56V Vref and ADC0
					// data will be left-justified
					
					//If we use the internal 2.56V reference voltage,
					//the step size would be 2.56 V/1024 = 2.5 mV.
					//(10 mV/2.5 mV = 4) This is four times the real temperature
	while(1){
	ADCSRA |= (1<<ADSC) ;            // start conversion
	while( (ADCSRA&(1<<ADIF))==0 );  // wait for end
	PORTD = ADCH;	       		     // give the high byte to PortD
	}
	return 0;
}