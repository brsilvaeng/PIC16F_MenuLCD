#include "main.h"
#include "defines.h"
#include "types.h"
#include "delay.h"
#include "lcd.h"
#include "key.h"
#include <stdio.h>

void Led_Muda(uint8 led, uint8 valor) {
    switch (led) {
        case 0: LED0 = valor; break;
        case 1: LED1 = valor; break;
        case 2: LED2 = valor; break;
        case 3: LED3 = valor; break;
    }
}


void Tela(const char *str1, const char *str2) {
    Lcd_PosStr(1, 1, (char *)str1);
    Lcd_PosStr(1, 2, (char *)str2);
}


void Processa_BotaoCima(void) {
    Tela(" APORTOU BOTAO  ", " E FOI O CIMA   ");
    Led_Muda(0, LIGA);
}

void Processa_BotaoBaixo(void) {
    Tela(" APORTOU BOTAO  ", " E FOI O BAIXO  ");
    Led_Muda(1, LIGA);
}

void Processa_BotaoEntra(void) {
    Tela(" APORTOU BOTAO  ", " E FOI O ENTRA  ");
    Led_Muda(2, LIGA);
}

void Processa_BotaoSai(void) {
    Tela(" APORTOU BOTAO  ", " E FOI O SAI    ");
    Led_Muda(3, LIGA);
}

void init(void) {
    OSCCONbits.IRCF = 0b111;    //oscilador interno em 8MHz (default -> 4MHz)
    ANSEL = 0;
    TRISA = 0;
    PORTA = 0;
}

void main(void) {
//    char str1[20], str2[20];
    int8 key_event;
    init();
    Lcd_Init();
    Key_Init();
    Tela(" TELA DE        ", " REPOUSO        ");
    while (1) {
        CLRWDT();
        key_event = Key_AnyEvent();
        if (key_event < 0) {
            //se não tem evento, continua as iterações
            continue;
        }
        if (Key_Press(key_event) == KEY_NOT_PRESS) {
            Led_Muda(key_event, DESLIGA);
            continue;
        }
        switch (key_event) {
            case 0: Processa_BotaoCima();  break;
            case 1: Processa_BotaoBaixo(); break;
            case 2: Processa_BotaoEntra(); break;
            case 3: Processa_BotaoSai();   break;
        }
    }
}
