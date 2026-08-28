/*
 * cmd.h
 *
 * Created: 16/7/2025 13:32:02
 *  Author: pity_
 */ 


#ifndef CMD_H_
#define CMD_H_

	#include "sys.h"
	#include "PWM.h"
	
	enum FlagCommand {
		
		DEFAULT, FLG_RED, FLG_GREEN, FLG_BLUE, FLG_CIAN, FLG_YELLOW, FLG_MAGENTA , FLG_WHITE, FLG_BLACK
		
	} FLGCMD;

	void setCommand(char);
	void updateFlagCommand();
	void task_RED(uint8_t);
	void task_GREEN(uint8_t);
	void task_BLUE(uint8_t);
	void task_CIAN(uint8_t);
	void task_YELLOW(uint8_t);
	void task_MAGENTA(uint8_t);
	void task_WHITE(uint8_t);
	void task_BLACK();
	void task_DEFAULT();


#endif /* CMD_H_ */