/*
 * Trabajo_Practico_Numero_2.c
 *
 * Created: 28/4/2025 12:55:23
 * Author : gonzalo iloro
 */ 


#include "main.h"
#include "keypad.h"
#define LCD_4bit
const char keymap[16] = {
	'1','2','3','A',
	'4','5','6','B',
	'7','8','9','C',
	'*','0','#','D'
}; 

int main(void)
{
	uint8_t lectura = 0xFF;

	LCDinit();          // Inicializá el LCD una sola vez fuera del loop
	_delay_ms(100);
	LCDGotoXY(0,0);
	int imp=48;
	int i;
	for (i=0;i<10;i++)
	{	
		imp+=1;
		LCDsendChar(imp);
		_delay_ms(1000);
		LCDclr();
		LCDGotoXY(0,0);
	}
	
}

