#include "main.h"

#define LED1        PORTAbits.RA0
#define LED2        PORTAbits.RA1
#define LED3        PORTAbits.RA2
#define LED4        PORTAbits.RA3

#define LIGA        1U
#define DESLIGA     0U

void pausa() {
    unsigned long i;
    for (i = 0; i < 100000; i++) {
        CLRWDT();
    }
}

void mudaLed(unsigned char led, unsigned char valor) {
    switch (led) {
        case 1: LED1 = valor; break;
        case 2: LED2 = valor; break;
        case 3: LED3 = valor; break;
        case 4: LED4 = valor; break;
    }
}

void main(void) {
    ANSEL = 0;
    TRISA = 0;
    PORTA = 0xFF;
    pausa();
    PORTA = 0;
    pausa();
    unsigned char led = 1;
    unsigned char valor = LIGA;
    while (1) {
        CLRWDT();
        pausa();
        mudaLed(led, valor);
        if (led < 4) {
            led++;
        } else {
            led = 1;
            valor = (valor == LIGA) ? DESLIGA : LIGA;
        }
    }
    return;
}
