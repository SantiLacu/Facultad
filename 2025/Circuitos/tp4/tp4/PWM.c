/*
 * PWM.c
 *
 * Created: 18/7/2025 13:43:37
 *  Author: pity_
 */ 

#include "PWM.h"

volatile uint8_t PWM_position = 0;
volatile uint8_t PWM_DELTA = 255 ; //va de 0 a 255 __> 100% 

void INIT_TIMER1(){
	DDRB |= (1 << PB1) | (1<<PB2); //OC1A
	TCCR1A |= (1 << COM1A1); // Modo no invertido
	TCCR1A |= (1 << COM1B1); //Modo no invertido
	TCCR1A |= (1 << WGM10); // Modo 5
	TCCR1B |= (1 << WGM12); //fast pwm 8 bits
	TCCR1B |= (1<<CS12); //Prescaler en 256 PARA GENERAR FRECUENCIA 244Hz
}
void INIT_TIMER2(){
	DDRB |= (1<<PB5);
	TCCR2A |= (1<<WGM21); // CTC
	TCCR2B |= (1<<CS21); //PRESCALER 8
	TIMSK2 |= (1<<OCIE2A);
	OCR2A = 31; //16 micro segundos por interrupcion. para poder tener 256 valores posibles y matchear con el adc. el periodo total es 256 x 16 microseg= 4ms
}

void set_LED_R(uint8_t DC){
	
	OCR1A = DC;
	
}

void set_LED_G(uint8_t DC){
	
	OCR1B = DC;
	
}

void set_LED_B(uint8_t DC){
 	
	PWM_DELTA = DC;
	
}

ISR(TIMER2_COMPA_vect){
	
	if (++PWM_position >= PWM_PERIOD){
		PWM_position=0;
	}
	if (PWM_position<PWM_DELTA){
		LED_OFF;
		} else {
		LED_ON;}
	
}