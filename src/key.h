#ifndef KEY_H
#define	KEY_H

#include <xc.h>
#include "types.h"

#define KEY_NUM                         4
#define KEY_CIMA                        0
#define KEY_BAIXO                       1
#define KEY_ENTRAR                      2
#define KEY_SAIR                        3

//GRAVACAO
#define KEY_CIMA_TRIS                   TRISBbits.TRISB0
#define KEY_CIMA_PIN                    PORTBbits.RB0
//SENSOR 1
#define KEY_ENTRAR_TRIS                 TRISBbits.TRISB1
#define KEY_ENTRAR_PIN                  PORTBbits.RB1
//SENSOR 2
#define KEY_SAIR_TRIS                   TRISBbits.TRISB2
#define KEY_SAIR_PIN                    PORTBbits.RB2
//BOTOEIRA
#define KEY_BAIXO_TRIS                  TRISBbits.TRISB3
#define KEY_BAIXO_PIN                   PORTBbits.RB3

#define KEY_DEBOUNCE                    100

#define KEY_NOT_PRESS                   1
#define KEY_PRESS                       0

#define KEY_CIMA_VALUE_NOT_PRESS        0x00
#define KEY_CIMA_VALUE_PRESS            0x01

#define KEY_BAIXO_VALUE_NOT_PRESS       0x00
#define KEY_BAIXO_VALUE_PRESS           0xFF

#define KEY_ENTRAR_VALUE_NOT_PRESS      0xFF
#define KEY_ENTRAR_VALUE_PRESS          0x00

#define KEY_SAIR_VALUE_NOT_PRESS        0xFF
#define KEY_SAIR_VALUE_PRESS            0x00


void Key_Init(void);
int8 Key_AnyEvent(void);
uint8 Key_Press(uint8 key_i);
uint8 Key_Value(uint8 key_i);

#endif

