/*
 * uart_char.c
 *
 * Created: 16/7/2025 13:26:12
 *  Author: pity_
 */ 

#include "uart_char.h"

volatile char TX_BUFFER;
volatile char RX_BUFFER;

void uart_init(){
	
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);		// Enable Rx & Tx
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);	// 8 bits Size no Parity
	UBRR0L = 103;								// BaudRate = 9600bps
	DDRD |= (1 << PIND1);						// PIND1 OUTPUT (TX)
	DDRD &= ~(1 << PIND0);						// PIND0 INPUT(RX)
	
	UCSR0B |= (1 << RXCIE0);
	
	sei();
	
}

void uart_sendChar(char c){
	
	TX_BUFFER = c;
	
	UCSR0B |= (1 << UDRIE0);
}
void uart_sendString(const char* str) {
	while (*str) {
		uart_sendChar(*str++);
	}
}
char uart_get_RX_BUFFER(){
	
	return RX_BUFFER;
	
}


ISR(USART_RX_vect){
	
	RX_BUFFER = UDR0; 
	
	uart_sendChar(RX_BUFFER);
	
	setCommand(RX_BUFFER);
	
}

ISR(USART_UDRE_vect){
	
	UDR0 = TX_BUFFER;
	
	UCSR0B &= ~(1 << UDRIE0); 

}