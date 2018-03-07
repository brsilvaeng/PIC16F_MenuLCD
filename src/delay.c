#include "delay.h"
#include "types.h"

void Delay_Sec(uint16 time) {
    while (time--) {
        __delay_ms(1000);
        CLRWDT();
    }
}


