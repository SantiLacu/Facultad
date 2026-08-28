/*
 * uart_char.h
 *
 * Created: 16/7/2025 13:25:56
 *  Author: pity_
 */ 


#ifndef UART_CHAR_H_
#define UART_CHAR_H_

	#include "sys.h"

	void uart_init();
	void uart_sendChar(char);
	char uart_get_RX_BUFFER();
	void uart_sendString(const char* str);


#endif /* UART_CHAR_H_ */