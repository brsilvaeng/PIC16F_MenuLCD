#ifndef DEFINES_H
#define	DEFINES_H

//#define FOSC          20000000UL       //oscilador externo 20MHz
#define FOSC            8000000UL        //oscilador interno 8MHz
#define FCY             (FOSC/4)
#define _XTAL_FREQ      FOSC            //para funcoes de __delay_xs()

#define LED1            PORTAbits.RA0
#define LED2            PORTAbits.RA1
#define LED3            PORTAbits.RA2
#define LED4            PORTAbits.RA3

#define LIGA            1U
#define DESLIGA         0U


#endif	/* DEFINES_H */

