/*
 * adc_interrupt.c
 *
 * Created: 21/7/2025 16:10:19
 *  Author: pity_
 */ 

#include "adc_interrupt.h"

uint16_t adc_value_isr = 0;

void adc_init(){
	
	/* Replace with your application code */
	DDRC = 0x00;			//	Port C an input
	ADCSRA = 0b10101111;	//	ADC enable, ADC auto Trigeer Enable, ADC Interrupt Enable, psk = CLK/128
	/*
	Reg. ADCSRA	-> |ADEN|ADSC|ADATE|ADIF|ADIE|ADPS2|ADPS1|ADPS0| 
	ADEN		-> ADC Enable
	ADSC		-> ADC Start Conversion
	ADATE		-> ADC auto Trigger Enable
	ADIF		-> ADC Interrupt Flag set when Conversion is complete and data reg. is update
	ADIE		-> ADC Interrupt Enable
	ADPS2-0		-> ADC Prescaler Select Bit
	*/
	
	
	ADCSRB |= (1 << ADTS1) | (1 << ADTS0); //ADCSRB = 0b00000011; //ADDC Auto Trigger Source -> TC0 Comparte Match A
	
	/*
	Reg. ADCSRB	-> | |ACME| | | |ADTS2|ADTS1|ADTS0|
	ACME		-> Analog Comparator Multiplexer Enable
	ADTS2-0		-> ADC Auto Trigger Source (Free, Analog Comparator, INT0, TC0 compare match A, TC0 overflow, TC1 compare march B, TC1 Overflow, TC1 capture event)
	*/

	ADMUX = 0b01100011;		// Vref=AVCC, l-justified, ADC3 pin
	
	/*
	Reg. ADMUX	-> |REFS1|REFS0|ADLAR|MUX3|MUX2|MUX1|MUX0|
	REFS1..0	-> Vref (00..11) (AREF, AVCC, reserved, internal)
	ADLAR		-> 1 = LEFT-Justified, 0 = RIGHT-Justified
	MUX3..0		-> ADC0..7
	*/
	
	sei();
	
}


ISR(ADC_vect){

	adc_value_isr = ADCH;
	
}
