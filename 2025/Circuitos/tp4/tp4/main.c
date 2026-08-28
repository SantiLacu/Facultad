/*
 * tp4.c
 *
 * Created: 21/7/2025 16:44:40
 * Author : Santiago Lacourrege
 */ 

#include "main.h"

static volatile uint8_t value = 0;

int main(void){
	
	//Timer 0 Config
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02) | (1 << CS00);
	OCR0A = 156;							// 10ms
	TIMSK0 |= (1 << OCIE0A);
	
	adc_init();
	uart_init();
	
	INIT_TIMER1();
	INIT_TIMER2();
	
	sei();
	uart_sendString("Ingrese el comando: ");
	while(1){
		
		
		value = adc_value_isr;
		
		switch(FLGCMD){
			
			case FLG_RED:
			task_RED(value);
			break;
			case FLG_GREEN:
			task_GREEN(value);
			break;
			case FLG_BLUE:
			task_BLUE(value);
			break;
			case FLG_CIAN:
			task_CIAN(value);
			break;
			case FLG_YELLOW:
			task_YELLOW(value);
			break;
			case FLG_MAGENTA:
			task_MAGENTA(value);
			break;
			case FLG_WHITE:
			task_WHITE(value);
			break;
			case FLG_BLACK:
			task_BLACK();
			break;
			default:
				task_DEFAULT();
			break;
			
		}
		
		
		
	}
	
	
}

ISR(TIMER0_COMPA_vect){
	
	updateFlagCommand();
	
}