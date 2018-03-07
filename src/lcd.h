#ifndef LCD_H
#define	LCD_H

#include "types.h"

//TRIS
#define LCD_TRIS_EN             TRISCbits.TRISC1
#define LCD_TRIS_RS             TRISCbits.TRISC0
#define LCD_TRIS_D4             TRISCbits.TRISC2
#define LCD_TRIS_D5             TRISCbits.TRISC3
#define LCD_TRIS_D6             TRISCbits.TRISC4
#define LCD_TRIS_D7             TRISCbits.TRISC5
//PORT
#define LCD_PORT_EN             PORTCbits.RC1
#define LCD_PORT_RS             PORTCbits.RC0
#define LCD_PORT_D4             PORTCbits.RC2
#define LCD_PORT_D5             PORTCbits.RC3
#define LCD_PORT_D6             PORTCbits.RC4
#define LCD_PORT_D7             PORTCbits.RC5


#define LCD_NUM_COL             16
#define LCD_NUM_ROW             2

void Lcd_Init(void);
void Lcd_Cmd(char cmd);
void Lcd_Chr(char chr);
void Lcd_Str(char *str);
void Lcd_StrSize(char *str, uint8 size);
void Lcd_Pos(char column, char row);
void Lcd_PosChr(char column, char row, char chr);
void Lcd_PosStr(char column, char row, char *str);
void Lcd_PosStrSize(char column, char row, char *str, uint8 size);


#endif

