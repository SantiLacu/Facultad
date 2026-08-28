#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void configurarPines();
void determinarEstado( estado* );
void incializarEstado ( estado* );
void alternarLuz( int* );

typedef enum {
    ENCENDIDO,
    PARAPADEAR
} estado;

int main(void){
    configurarPines();
    estado est = ENCENDIDO;
    int i = 0;
    incializarEstado(&est);
    while (1) {
        switch (est) {
            case 0:
                determinarEstado(&est);
                break;

            case 1:
                alternarLuz(&i);
                _delay_ms(250);
                break;

            default:
                break;
}
    }
    return 0;
}


void configurarPines(){

    //Configuro los puertos PD2 y PD3 como entrada con pull-up interno
    DDRD &= ~((1 << DDD2)|(1<<DDD3));
    PORTD |= ((1 << DDD2)|(1<<DDD3));

    //Configuro los puertos PB0 y PB1 como salida
    DDRB |= ((1 << DDB0)|(1 << DDB1));
}

void incializarEstado (int *dir){
    int est=*dir;
    if (est==ENCENDIDO){
        PORTB |= ((1 << PORTB0)|(1 << PORTB1));
    }
}

void determinarEstado(int *dir){
    int est=*dir;
    if ((!(PIND & (1 << PIND2)))||(!(PIND & (1 << PIND3)))) {
        *dir=PARAPADEAR;
    }
}

void alternarLuz(int *i){
    if (*i==0){
        PORTB &= ~(1 <<PORTB1);
        PORTB |= (1 << PORTB0);
        (*i)++;
    }
    else{
        PORTB &= ~(1 <<PORTB0);
        PORTB |= (1 << PORTB1);
        (*i)--;
    }
}