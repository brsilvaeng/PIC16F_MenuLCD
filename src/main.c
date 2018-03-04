#include "main.h"
#include "defines.h"
#include "types.h"
#include "delay.h"
#include "lcd.h"

void mudaLed(uint8 led, uint8 valor) {
    switch (led) {
        case 1: LED1 = valor; break;
        case 2: LED2 = valor; break;
        case 3: LED3 = valor; break;
        case 4: LED4 = valor; break;
    }
}

void init(void) {
    OSCCONbits.IRCF = 0b111;    //oscilador interno em 8MHz (default -> 4MHz)
    ANSEL = 0;
    TRISA = 0;
    PORTA = 0;
}

void tela(void) {
    Lcd_PosStr(1, 1, " TELA DE        ");
    Lcd_PosStr(1, 2, " REPOUSO        ");
}

void main(void) {
    init();
    Lcd_Init();
    tela();
    uint8 led = 1;
    uint8 valor = LIGA;
    while (1) {
        CLRWDT();
        Delay_Sec(1);        
        mudaLed(led, valor);
        if (led < 4) {
            led++;
        } else {
            led = 1;
            valor = (valor == LIGA) ? DESLIGA : LIGA;
        }
    }
}
