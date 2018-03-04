#include "main.h"
#include "defines.h"
#include "types.h"
#include "delay.h"
#include "lcd.h"
#include "key.h"
#include <stdio.h>

void Led_Muda(uint8 led, uint8 valor) {
    switch (led) {
        case 1: LED1 = valor; break;
        case 2: LED2 = valor; break;
        case 3: LED3 = valor; break;
        case 4: LED4 = valor; break;
    }
}

void Led_Oscila(void) {
    static uint8 valor = LIGA;
    valor = (valor == LIGA) ? DESLIGA : LIGA;
    Led_Muda(1, valor);
}



void init(void) {
    OSCCONbits.IRCF = 0b111;    //oscilador interno em 8MHz (default -> 4MHz)
    ANSEL = 0;
    TRISA = 0;
    PORTA = 0;
}

void Tela(char *str1, char *str2) {
    Lcd_PosStr(1, 1, str1);
    Lcd_PosStr(1, 2, str2);
}



void main(void) {
    uint32 count = 0;
    char str1[20], str2[20];
    uint8 key_event;
    init();
    Lcd_Init();
    Key_Init();
    while (1) {
        CLRWDT();
        key_event = Key_AnyEvent();
        if (key_event >= 0) {
            sprintf(str1, " APORTOU BOTAO  ");
            switch (key_event) {
                case 0: sprintf(str2, " E FOI O CIMA   "); break;
                case 1: sprintf(str2, " E FOI O BAIXO  "); break;
                case 2: sprintf(str2, " E FOI O ENTRA  "); break;
                case 3: sprintf(str2, " E FOI O SAI    "); break;
            }
            Led_Muda(2, LIGA);
            Tela(str1, str2);
        } else {
            if (count > 0) {
                count--;
            } else {
                Tela(" TELA DE        ", " REPOUSO        ");
                Led_Muda(2, DESLIGA);
                Led_Muda(3, DESLIGA);
                Led_Muda(4, DESLIGA);
                count = 1000;
            }
        }
    }
}
