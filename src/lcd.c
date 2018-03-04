#include "lcd.h"
#include "delay.h"
#include <string.h>


#if (!defined(LCD_TRIS_EN) || !defined(LCD_PORT_EN))
    #error "Defina LCD_TRIS_EN e LCD_PORT_EN em 'lcd.h'"
#endif
#if (!defined(LCD_TRIS_RS) || !defined(LCD_PORT_RS))
    #error "Defina LCD_TRIS_RS e LCD_PORT_RS em 'lcd.h'"
#endif
#if (!defined(LCD_TRIS_D4) || !defined(LCD_PORT_D4))
    #error "Defina LCD_TRIS_D4 e LCD_PORT_D4 em 'lcd.h'"
#endif
#if (!defined(LCD_TRIS_D5) || !defined(LCD_PORT_D5))
    #error "Defina LCD_TRIS_D5 e LCD_PORT_D5 em 'lcd.h'"
#endif
#if (!defined(LCD_TRIS_D6) || !defined(LCD_PORT_D6))
    #error "Defina LCD_TRIS_D6 e LCD_PORT_D6 em 'lcd.h'"
#endif
#if (!defined(LCD_TRIS_D7) || !defined(LCD_PORT_D7))
    #error "Defina LCD_TRIS_D7 e LCD_PORT_D7 em 'lcd.h'"
#endif

#define LCD_FIRST_ROW           0x80   //Move cursor para 1ª linha
#define LCD_SECOND_ROW          0xC0   //Move cursor para 2ª linha
#define LCD_THIRD_ROW           0x94   //Move cursor para 3ª linha
#define LCD_FOURTH_ROW          0xD4   //Move cursor para 4ª linha

#define LCD_FUNCTION_2_ROW_5X8  0x28   //Display Modo: 2 Linhas, Matiz 5x8 caracteres
#define LCD_CLEAR               0x01   //Limpa display
#define LCD_RETURN_HOME         0x02   //Retorna cursor para Home
#define LCD_CURSOR_OFF          0x0C   //Desliga cursor
#define LCD_UNDERLINE_ON        0x0E   //Cursor com underline
#define LCD_BLINK_CURSOR_ON     0x0F   //Cursor piscante
#define LCD_MOVE_CURSOR_LEFT    0x10   //Move cursor para esquerda
#define LCD_MOVE_CURSOR_RIGHT   0x14   //Move cursor para direita
#define LCD_TURN_ON             0x0C   //Liga display
#define LCD_TURN_OFF            0x08   //Desliga display
#define LCD_SHIFT_LEFT          0x1C   //Mode o display para esquerda
#define LCD_SHIFT_RIGHT         0x1A   //Mode o display para direita

static void Lcd_Delay(uint32 delay) { //us
    for (; delay > 0; delay--) {
        NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP();
    }
}
static void Lcd_Nibble(uint8 value) {
    uint8_val *byte = (uint8_val *)&value;
    LCD_PORT_D7 = byte->bits.b7;
    LCD_PORT_D6 = byte->bits.b6;
    LCD_PORT_D5 = byte->bits.b5;
    LCD_PORT_D4 = byte->bits.b4;
    LCD_PORT_EN = 1;
    Lcd_Delay(10);
    LCD_PORT_EN = 0;
    Lcd_Delay(40);
}
static void Lcd_Write(uint8 value) {
    Lcd_Nibble(value);
    Lcd_Nibble(value << 4);
}

void Lcd_Init(void) {
    char cmd[] = {0x33, 0x32, LCD_FUNCTION_2_ROW_5X8, 0x06, LCD_CLEAR, LCD_RETURN_HOME, LCD_TURN_ON, 0};
    char *value;
    LCD_TRIS_EN = 0;
    LCD_TRIS_RS = 0;
//    LCD_TRIS_RW = 0;
    LCD_TRIS_D4 = 0;
    LCD_TRIS_D5 = 0;
    LCD_TRIS_D6 = 0;
    LCD_TRIS_D7 = 0;
    LCD_PORT_EN = 0;
    LCD_PORT_RS = 0;
    value = cmd;
    while (*value) {
        Lcd_Cmd(*value);
        value++;
        Lcd_Delay(400);
    }
}
void Lcd_Cmd(char cmd) {
    LCD_PORT_RS = 0;
    Lcd_Write(cmd);
}
void Lcd_Chr(char chr) {
    LCD_PORT_RS = 1;
    Lcd_Write(chr);
}
void Lcd_Str(char *str) {
    char len;
    len = strlen(str);
    while (len > 0) {
        Lcd_Chr(*str);
        str++;
        len--;
    }
}
void Lcd_StrSize(char *str, uint8 size) {
    while (size > 0) {
        Lcd_Chr(*str);
        str++;
        size--;
    }
}
void Lcd_Pos(char column, char row) {
    char pos;
    switch(row)     {
        case 4 : pos = LCD_FOURTH_ROW; break;
        case 3 : pos = LCD_THIRD_ROW; break;
        case 2 : pos = LCD_SECOND_ROW; break;
        default: pos = LCD_FIRST_ROW; break;
    }
    pos += column - 1;
    Lcd_Cmd(pos);
}
void Lcd_PosChr(char column, char row, char chr) {
    Lcd_Pos(column, row);
    Lcd_Chr(chr);
}
void Lcd_PosStr(char column, char row, char *str) {
    Lcd_Pos(column, row);
    Lcd_Str(str);
}
void Lcd_PosStrSize(char column, char row, char *str, uint8 size) {
    Lcd_Pos(column, row);
    Lcd_StrSize(str, size);
}

