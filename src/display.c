#include <stdio.h>

#include "display.h"
#include "lcd.h"

#define DISPLAY_NUM_NIVEL           2

#define DISPLAY_MENU1_OPT_NUM       2
#define DISPLAY_MENU1_OPT_NUM       5
#define DISPLAY_MENU2_OPT_NUM       4
#define DISPLAY_MENU3_OPT_NUM       3
#define DISPLAY_MENU4_OPT_NUM       3

const char display_menu0[2][LCD_NUM_COL+1] = {
    " TELA EM        ",
    " REPOUSO        "
};
const char display_menu1[DISPLAY_MENU1_OPT_NUM][LCD_NUM_COL+1] = {
    "  Menu 1 Opcao 1",
    "  Menu 1 Opcao 2",
    "  Menu 1 Opcao 3",
    "  Menu 1 Opcao 4",
    "  Menu 1 Opcao 5"
};

const char display_menu2[DISPLAY_MENU2_OPT_NUM][LCD_NUM_COL+1] = {
    "  Menu 2 Opcao 1",
    "  Menu 2 Opcao 2",
    "  Menu 2 Opcao 3",
    "  Menu 2 Opcao 4"
};
const char display_menu3[DISPLAY_MENU3_OPT_NUM][LCD_NUM_COL+1] = {
    "  Menu 3 Opcao 1",
    "  Menu 3 Opcao 2",
    "  Menu 3 Opcao 3"
};
const char display_menu4[DISPLAY_MENU4_OPT_NUM][LCD_NUM_COL+1] = {
    "  Menu 4 Opcao 1",
    "  Menu 4 Opcao 2",
    "  Menu 4 Opcao 3"
};

typedef struct sDisplay {
    char menu;
    char change;
    char opt;
    char row0;
    char row1;
} TDisplay;

TDisplay display;

char *Display_getMsg(uint8 menu, uint8 row) {
    char *msg;
    switch (menu) {
        case 0: msg = (char *)display_menu0[row]; break;
        case 1: msg = (char *)display_menu1[row]; break;
        case 2: msg = (char *)display_menu2[row]; break;
        case 3: msg = (char *)display_menu3[row]; break;
        case 4: msg = (char *)display_menu4[row]; break;
    }
    return msg;
}

uint8 Display_getNumOpt(uint8 menu) {
    uint8 num = 2;
    switch (menu) {
        case 1: num = DISPLAY_MENU1_OPT_NUM; break;
        case 2: num = DISPLAY_MENU2_OPT_NUM; break;
        case 3: num = DISPLAY_MENU3_OPT_NUM; break;
        case 4: num = DISPLAY_MENU4_OPT_NUM; break;
    }
    return num;
}


void Display_Init(void) {
    Lcd_Init();
    Display_ChangeMenu(0);
}

void Display_Ctrl(void) {
    if (display.change == 0) {
        return;
    }
    char *lcd_row1 = Display_getMsg(display.menu, display.row0);
    char *lcd_row2 = Display_getMsg(display.menu, display.row1);
    Lcd_PosStr(1, 1, lcd_row1);
    Lcd_PosStr(1, 2, lcd_row2);
    if (display.menu != 0) {
        Lcd_PosChr(1, display.opt, '>');
    }
    display.change = 0;
}

char Display_Menu(void) {
    return display.menu;
}

void Display_ChangeMenu(char menu) {
    display.menu = menu;
    display.opt = 1;
    display.row0 = 0;
    display.row1 = 1;
    display.change = 1;
}

void Display_ChangeOptDown(void) {
    if (display.opt == 1) {
        display.opt = 2;
    } else {
        display.row0 = display.row1;
        display.row1 = (display.row1 + 1) % Display_getNumOpt(display.menu);
    }
    display.change = 1;
}

void Display_ChangeOptUp(void) {
    if (display.opt == 2) {
        display.opt = 1;
    } else if (display.row0 > 0) {
        display.row1 = display.row0;
        display.row0--;
    } else {
        display.row0 = Display_getNumOpt(display.menu) - 1;
        display.row1 = 0;
    }
    display.change = 1;
}
