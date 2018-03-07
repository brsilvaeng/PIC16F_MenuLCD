#include "main.h"
#include "defines.h"
#include "types.h"
#include "delay.h"
#include "display.h"
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

void Processa_BotaoEntra(void) {
    switch (Display_Menu()) {
        case 1: Display_ChangeMenu(2); break;
        case 2: Display_ChangeMenu(3); break;
        case 3: Display_ChangeMenu(4); break;
    }
}

void Processa_BotaoSai(void) {
    switch (Display_Menu()) {
        case 4: Display_ChangeMenu(3); break;
        case 3: Display_ChangeMenu(2); break;
        case 2: Display_ChangeMenu(1); break;
        case 1: Display_ChangeMenu(0); break;
    }
}
void Processa_Botao(uint8 botao) {
    if (Display_Menu() == 0) {
        Display_ChangeMenu(1);
        return;
    }
    switch (botao) {
        case 0: Display_ChangeOptUp();  break;
        case 1: Display_ChangeOptDown(); break;
        case 2: Processa_BotaoEntra(); break;
        case 3: Processa_BotaoSai();   break;
    }
}

void init(void) {
    OSCCONbits.IRCF = 0b111;    //oscilador interno em 8MHz (default -> 4MHz)
    ANSEL = 0;
    TRISA = 0;
    PORTA = 0;
}

void main(void) {
    int8 key_event;
    init();
    Key_Init();
    Display_Init();
    while (1) {
        CLRWDT();
        Display_Ctrl();
        key_event = Key_AnyEvent();
        if (key_event < 0) {
            //se não tem evento, continua as iterações
            continue;
        }
        if (Key_Press(key_event) == KEY_NOT_PRESS) {
            Led_Muda(key_event, DESLIGA);
            continue;
        }
        Led_Muda(key_event, LIGA);
        Processa_Botao(key_event);
    }
}
