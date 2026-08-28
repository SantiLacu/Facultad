/*
 * cmd.c
 *
 * Created: 16/7/2025 13:32:14
 *  Author: pity_
 */ 

#include "cmd.h"

enum FlagCommand FLGCMD = DEFAULT;

volatile static char command = '0';

void setCommand(char c){
	
	command = c;
	
}

void updateFlagCommand(){
	
	switch(command){
		
		case '1':
			FLGCMD = FLG_RED;
			break;
		case '2':
			FLGCMD = FLG_GREEN;
			break;
		case '3':
			FLGCMD = FLG_BLUE;
			break;
		case '4':
			FLGCMD = FLG_CIAN;
			break;
		case '5':
			FLGCMD = FLG_YELLOW;
			break;
		case '6':
			FLGCMD = FLG_MAGENTA;
			break;
		case '7':
			FLGCMD = FLG_WHITE;
			break;
		case '8':
			FLGCMD = FLG_BLACK;
			break;
		default:
			FLGCMD = DEFAULT;
			break;
		
	}
	
}
void task_RED(uint8_t value){
	
	set_LED_R(255 - value);
	set_LED_G(255);
	set_LED_B(255);
	
	/*Led prendido, salida en 0
	
	modo invertido
	0% --> 255, 100% --> 0
	0 + value -> value = 0, led = 1, value = 255, led = 0
	0 -> DC = 100% -> Led = 1
	
	modo no invertido
	100% --> 255, 0% --> 0
	255 - value  -> value = 100%, value = 255, led = 0	*/
}
void task_GREEN(uint8_t value){
	
	set_LED_R(255);
	set_LED_G(255 - value);
	set_LED_B(255);
	
}
void task_BLUE(uint8_t value){
	
	set_LED_R(255);
	set_LED_G(255);
	set_LED_B(255 - value);
	
}
void task_CIAN(uint8_t value){
	
	set_LED_R(255);
	set_LED_G(255 - value);
	set_LED_B(255 - value);
	
}

void task_YELLOW(uint8_t value){
	
	set_LED_R(255 - value);
	set_LED_G(255 - value);
	set_LED_B(255);
	
}


void task_MAGENTA(uint8_t value){
	
	set_LED_R(255 - value);
	set_LED_G(255);
	set_LED_B(255 - value);

}


void task_WHITE(uint8_t value){

	set_LED_R(255 - value);
	set_LED_G(255 - value);
	set_LED_B(255 - value);

}


void task_BLACK(){

	set_LED_R(255);
	set_LED_G(255);
	set_LED_B(255);

}

void task_DEFAULT(){

	set_LED_R(255);
	set_LED_G(255);
	set_LED_B(255);

}