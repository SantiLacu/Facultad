/*
 * adc_interrupt.h
 *
 * Created: 21/7/2025 16:10:32
 *  Author: pity_
 */ 


#ifndef ADC_INTERRUPT_H_
#define ADC_INTERRUPT_H_

	#include "sys.h"

	void adc_init();
	
	extern uint16_t adc_value_isr;


#endif /* ADC_INTERRUPT_H_ */