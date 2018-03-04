#ifndef DELAY_H
#define	DELAY_H

#include <xc.h>
#include "defines.h"
#include "types.h"

#define _XTAL_FREQ          FOSC

#define Delay_Us(time)       __delay_us(time)

#define Delay_Ms(time)       __delay_ms(time)

void Delay_Sec(uint16 time);


#endif

