/*
 * PWM.h
 *
 * Created: 18/7/2025 13:43:50
 *  Author: gonza
 */ 


#ifndef PWM_H_
#define PWM_H_

//#include <avr/io.h>
//#include <avr/interrupt.h>
//#define F_CPU 16000000UL
//#include <stdint.h>
//#include <util/delay.h>
	#include "sys.h"

	#define PWM_PERIOD 256 //ticks
	#define LED_OFF PORTB |= (1<<PB5)
	#define LED_ON PORTB &= ~(1<<PB5)
	
	void INIT_TIMER2();
	void INIT_TIMER1();
	
	void set_LED_R(uint8_t);
	void set_LED_G(uint8_t);
	void set_LED_B(uint8_t);
	

#endif /* PWM_H_ */