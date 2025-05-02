#include <avr/io.h>
#include "lcd.h"

int main(void) {
	LCDinit();                      // Inicializa LCD
	LCDstring((uint8_t*)"RV1: 73%", 8);  // Muestra el valor del potenci�metro
	while (1) {
		// El potenci�metro se ajusta manualmente en Proteus
	}
}