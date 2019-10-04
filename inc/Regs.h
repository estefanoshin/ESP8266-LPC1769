/*
 * Regs.h
 *
 *  Created on: 17/04/2012
 *      Author: Mica y Chor
 */

#ifndef REGS_H_
#define REGS_H_

#include "LPC176x.h"

typedef unsigned int 	uint32_t;
typedef unsigned short 	uint16_t;
typedef unsigned char 	uint8_t;
typedef signed char 	int8_t;
typedef signed short 	int16_t;
typedef signed int 		int32_t;
typedef uint8_t			BOOL;

typedef 	volatile uint32_t 		registro;  //!< defino un tipo 'registro' uint32_t volatile.
typedef struct
{
    uint8_t    nombre[30];
    uint8_t    valor;
    uint32_t   numero;
}
_GENERICA;


#define	FALSE			0
#define	TRUE			0xff

#define	ERROR			0
#define	OK				0xff

//Estructura para manejar los GPIOs:
typedef struct
{
	uint32_t	FIODIR;
	uint32_t	RESERVED[3];
	uint32_t 	FIOMASK;
	uint32_t 	FIOPIN;
	uint32_t 	FIOSET;
	uint32_t 	FIOCLR;

} gpio_t;


//Estructura para manejar los Timers:
typedef struct
{
	uint32_t	IR;
	uint32_t	TCR;
	uint32_t 	TC;
	uint32_t 	PR;
	uint32_t 	PC;
	uint32_t 	MCR;
	uint32_t	MR0;
	uint32_t	MR1;
	uint32_t	MR2;
	uint32_t	MR3;
	uint32_t	CCR;
	uint32_t	CR0;
	uint32_t	CR1;
    uint32_t 	RESERVED0[2];
	uint32_t 	EMR;
    uint32_t 	RESERVED1[12];
	uint32_t 	CTCR;

} timer_t;



//Registros generales:
//0x4002C000UL : Direccion de inicio de los registros PINSEL
#define		PINSEL		( ( uint32_t  * ) 0x4002C000UL )
//0x2009C000UL : Direccion de inicio de los registros de GPIOs
#define		GPIOs		( ( gpio_t  * ) 0x2009C000UL )
//0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 	DIR_PCONP	( ( uint32_t  * ) 0x400FC0C4UL )
//0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los clks de los dispositivos:
#define		PCLKSEL		( ( uint32_t  * ) 0x400FC1A8UL )
//0x4002C040UL : Direccion de inicio de los registros de modo de los pines del GPIO
#define		PINMODE		( ( uint32_t  * ) 0x4002C040UL )
//0xE000E100UL : Direccion de inicio de los registros de habilitación (set) de interrupciones en el NVIC:
#define		DIR_ISER	( ( uint32_t  * ) 0xE000E100UL )
//#define		ISER		DIR_ISER[0]


#define     DIR_P213FE     ( ( uint32_t * ) 0x400280B4UL )
#define     P213FE         DIR_P213FE[0]

#define     DIR_P213CLR    ( ( uint32_t *) 0x400280ACUL )
#define     P213CLR        DIR_P213CLR[0]

//0xE000E180UL : Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones en el NVIC:
//#define		ICER		( (volatile uint32_t*)0xE000E180)  //( uint32_t  * ) 0x4002C040UL )  mal

#define     DIR_IO2IntEnF   ( ( uint32_t *) 0x400280B4UL)
#define     DIR_IO2IntClr   ( ( uint32_t *) 0x400280ACUL)
#define     IO2IntEnF       DIR_IO2IntEnF[0]
#define     IO2IntClr       DIR_IO2IntClr[0]

#define     DIR_EXTINT       ( ( uint32_t *) 0x400FC140UL)
#define     EXTINT       DIR_EXTINT[0]
#define     DIR_EXTMODE      ( ( uint32_t *) 0x400FC148UL)
#define     EXTMODE      DIR_EXTMODE[0]
#define     DIR_EXTPOLAR     ( ( uint32_t *) 0x400FC14CUL)
#define     EXPOLAR      DIR_EXTPOLAR[0]

// Interrupt Set-Pending Registers
#define		DIR_ISPR 		( ( uint32_t  * ) 0xE000E200UL )
//#define		ISPR			DIR_ISPR[0]
#define		ISP_UART0		(1 < 5)
#define		ISP_EINT3		(1 < 21)
#define		ISP_ADC			(1 < 22)
#define		ISP_DMA			(1 < 26)
//Timers:
//0x40004000UL : Direccion de inicio de los registros del Timer0
#define		DIR_TIMER0		( ( timer_t  * ) 0x40004000UL )
//0x40008000UL : Direccion de inicio de los registros del Timer1
#define		DIR_TIMER1		( ( timer_t  * ) 0x40008000UL )
//0x40090000UL : Direccion de inicio de los registros del Timer2
#define		DIR_TIMER2		( ( timer_t  * ) 0x40090000UL )
//0x40094000UL : Direccion de inicio de los registros del Timer3
#define		DIR_TIMER3		( ( timer_t  * ) 0x40094000UL )

//UART0:
//0x4001000CUL : Registro de control de la UART0:
#define		DIR_U0FCR	( ( uint32_t  * ) 0x4000C008UL )
//0x4001000CUL : Registro de control de la UART0:
#define		DIR_U0LCR	( ( uint32_t  * ) 0x4000C00CUL )
//0x40010014UL : Registro de recepcion de la UART0:
#define		DIR_U0LSR		( ( uint32_t  * ) 0x4000C014UL )
//0x40010000UL : Parte baja del divisor de la UART0:
#define		DIR_U0DLL	( ( uint32_t  * ) 0x4000C000UL )
//0x40010004UL : Parte alta del divisor de la UART0:
#define		DIR_U0DLM	( ( uint32_t  * ) 0x4000C004UL )
//0x40010000UL : Registro de recepcion de la UART0:
#define		DIR_U0RBR	( ( uint32_t  * ) 0x4000C000UL )
//0x40010000UL : Registro de transmision de la UART0:
#define		DIR_U0THR	( ( uint32_t  * ) 0x4000C000UL )

#define		DIR_U0IIR	( ( uint32_t  * ) 0x4000C008UL )

//UART1:
//0x4001000CUL : Registro de control de la UART1:
#define		DIR_U1LCR	( ( uint32_t  * ) 0x4001000CUL )
//0x40010014UL : Registro de recepcion de la UART1:
#define		DIR_U1LSR		( ( uint32_t  * ) 0x40010014UL )
//0x40010000UL : Parte baja del divisor de la UART1:
#define		DIR_U1DLL	( ( uint32_t  * ) 0x40010000UL )
//0x40010004UL : Parte alta del divisor de la UART1:
#define		DIR_U1DLM	( ( uint32_t  * ) 0x40010004UL )
//0x40010000UL : Registro de recepcion de la UART1:
#define		DIR_U1RBR	( ( uint32_t  * ) 0x40010000UL )
//0x40010000UL : Registro de transmision de la UART1:
#define		DIR_U1THR	( ( uint32_t  * ) 0x40010000UL )
//0x400100008UL :Registro de interrupciones pendientes
#define		DIR_U1IIR	( ( uint32_t  * ) 0x40010008UL )
//0x40010004UL  :Registro de interrupciones internas
#define		DIR_U1IER	( ( uint32_t  * ) 0x40010004UL )


//0x4008C000UL : Registro de conversion del DAC:
#define		DIR_DACR	( ( uint32_t  * ) 0x4008C000UL )
//0x4008C004UL : Registro de control del DAC:
#define		DIR_DACCTRL	( ( uint32_t  * ) 0x4008C004UL )
//0x4008C008UL : Registro de contador del DAC:
#define		DIR_DACCNTVAL ( ( uint32_t  * ) 0x4008C008UL )


//0x40034000UL: Registro de control del ADC:
#define		DIR_AD0CR	( ( uint32_t  * ) 0x40034000UL )
//0x40034004UL: Registro de estado del ADC:
#define		DIR_AD0GDR	( ( uint32_t  * ) 0x40034004UL )
//0x4003400CUL: Registro de interrupcion del ADC
#define		DIR_AD0INTEN ( ( uint32_t  * ) 0x4003400CUL )
//0x40034010UL: Registros de estado de los ADCx
#define		AD0DR		( ( uint32_t  * ) 0x40034010UL )

//Registros del CLOCK y de sistema:
//0x400FC1A0UL: Registro de control de sistema y registro de status:
#define	DIR_SCS	( (uint32_t *) 0x400FC1A0UL)
//0x400FC104UL: Registro de configuracion del clock:
#define	DIR_CCLKCFG	( (uint32_t *) 0x400FC104UL)
//0x400FC10CUL: Registro de seleccion del clock:
#define	DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
//0x400FC1C8UL: Clock Output Config register:
#define	DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
//0x400FC000UL: Flash access configuration:
#define	DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)

//Registros de los PLL:
//0x400FC080UL: Registro de control del PLL0:
#define	DIR_PLL0CON	( (uint32_t *) 0x400FC080UL)
//0x400FC084UL: Registro de configuracion del PLL0:
#define	DIR_PLL0CFG	( (uint32_t *) 0x400FC084UL)
//0x400FC088UL: Registro de estado del PLL0:
#define	DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
//0x400FC08CUL: Registro de control del PLL0:
#define	DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)
//0x400FC0A0UL: Registro de control del PLL1:
#define	DIR_PLL1CON	( (uint32_t *) 0x400FC0A0UL)
//0x400FC0A4UL: Registro de configuracion del PLL1:
#define	DIR_PLL1CFG	( (uint32_t *) 0x400FC0A4UL)
//0x400FC0A8UL: Registro de estado del PLL1:
#define	DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
//0x400FC0ACUL: Registro de control del PLL1:
#define	DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)

//Registros del RTC
#define DIR_RTC         ( (uint32_t *) 0x40024000UL)

//Registros del SysTick:
#define MAX_TICKS		0x00fffffful
//0xE000E010UL: Registro de control del SysTick:
#define DIR_STCTRL		( (uint32_t *) 0xE000E010UL)
//0xE000E014UL: Registro de recarga del SysTick:
#define DIR_STRELOAD	( (uint32_t *) 0xE000E014UL)
//0xE000E018UL: Registro de cuenta del SysTick:
#define DIR_STCURR		( (uint32_t *) 0xE000E018UL)
//0xE000E01CUL: Registro de calibracion del SysTick:
#define DIR_STCALIB		( (uint32_t *) 0xE000E01CUL)

#define ENABLE 			(0x01 << 0)
#define TICKINT			(0x01 << 1)
#define CLKSOURCE 		(0x01 << 2)

//Registros RTC
#define     RTCILR      DIR_RTC[0]
#define     RTCCCR      DIR_RTC[2]
#define     RTCCIIR     DIR_RTC[3]
#define     RTCAMR      DIR_RTC[4]
#define     RTCCTIME0   DIR_RTC[5]
#define     RTCCTIME1   DIR_RTC[6]
#define     RTCCTIME2   DIR_RTC[7]
#define     RTCSEC      DIR_RTC[8]
#define     RTCMIN      DIR_RTC[9]
#define     RTCHOUR     DIR_RTC[10]
#define     RTCDOM      DIR_RTC[11]
#define     RTCDOW      DIR_RTC[12]
#define     RTCDOY      DIR_RTC[13]
#define     RTCMONTH    DIR_RTC[14]
#define     RTCYEAR     DIR_RTC[15]
#define     RTCCALIB    DIR_RTC[16]
#define     RTCGPREG0   DIR_RTC[17]
#define     RTCGPREG1   DIR_RTC[18]
#define     RTCGPREG2   DIR_RTC[19]
#define     RTCGPREG3   DIR_RTC[20]
#define     RTCGPREG4   DIR_RTC[21]
#define     RTC_AUX     DIR_RTC[22]
#define     RTC_AUXEN   DIR_RTC[23]
#define     RTCCALSEC   DIR_RTC[24]
#define     RTCCALMIN   DIR_RTC[25]
#define     RTCCALHOUR  DIR_RTC[26]
#define     RTCCALDOM   DIR_RTC[27]
#define     RTCCALDOW   DIR_RTC[28]
#define     RTCCALDOY   DIR_RTC[29]
#define     RTCCALMON   DIR_RTC[30]
#define     RTCCALYEAR  DIR_RTC[31]


//Registros PINSEL:
#define		PINSEL0		PINSEL[0]
#define		PINSEL1		PINSEL[1]
#define		PINSEL2		PINSEL[2]
#define		PINSEL3		PINSEL[3]
#define		PINSEL4		PINSEL[4]
#define		PINSEL5		PINSEL[5]
#define		PINSEL6		PINSEL[6]
#define		PINSEL7		PINSEL[7]
#define		PINSEL8		PINSEL[8]
#define		PINSEL9		PINSEL[9]

//Registros PINMODE
#define		PINMODE0	PINMODE[0]
#define		PINMODE1	PINMODE[1]
#define		PINMODE2	PINMODE[2]
#define		PINMODE3	PINMODE[3]
#define		PINMODE4	PINMODE[4]
#define		PINMODE5	PINMODE[5]
#define		PINMODE6	PINMODE[6]
#define		PINMODE7	PINMODE[7]
#define		PINMODE8	PINMODE[8]
#define		PINMODE9	PINMODE[9]

//Registros GPIOs:
#define		GPIO0		GPIOs[0]
#define		GPIO1		GPIOs[1]
#define		GPIO2		GPIOs[2]
#define		GPIO3		GPIOs[3]
#define		GPIO4		GPIOs[4]

#define		FIO0DIR		GPIO0.FIODIR
#define		FIO1DIR		GPIO1.FIODIR
#define		FIO2DIR		GPIO2.FIODIR
#define		FIO3DIR		GPIO3.FIODIR
#define		FIO4DIR		GPIO4.FIODIR

#define		FIO0MASK	GPIO0.FIOMASK
#define		FIO1MASK	GPIO1.FIOMASK
#define		FIO2MASK	GPIO2.FIOMASK
#define		FIO3MASK	GPIO3.FIOMASK
#define		FIO4MASK	GPIO4.FIOMASK

#define		FIO0CLR		GPIO0.FIOCLR
#define		FIO1CLR		GPIO1.FIOCLR
#define		FIO2CLR		GPIO2.FIOCLR
#define		FIO3CLR		GPIO3.FIOCLR
#define		FIO4CLR		GPIO4.FIOCLR

#define		FIO0SET		GPIO0.FIOSET
#define		FIO1SET		GPIO1.FIOSET
#define		FIO2SET		GPIO2.FIOSET
#define		FIO3SET		GPIO3.FIOSET
#define		FIO4SET		GPIO4.FIOSET

#define		FIO0PIN		GPIO0.FIOPIN
#define		FIO1PIN		GPIO1.FIOPIN
#define		FIO2PIN		GPIO2.FIOPIN
#define		FIO3PIN		GPIO3.FIOPIN
#define		FIO4PIN		GPIO4.FIOPIN

//Registros de timers:
#define		TIMER0		DIR_TIMER0[0]
#define		TIMER1		DIR_TIMER1[0]
#define		TIMER2		DIR_TIMER2[0]
#define		TIMER3		DIR_TIMER3[0]

#define		T0IR		TIMER0.IR
#define		T1IR		TIMER1.IR
#define		T2IR		TIMER2.IR
#define		T3IR		TIMER3.IR

#define		T0TCR		TIMER0.TCR
#define		T1TCR		TIMER1.TCR
#define		T2TCR		TIMER2.TCR
#define		T3TCR		TIMER3.TCR

#define		T0PC		TIMER0.PC
#define		T1PC		TIMER1.PC
#define		T2PC		TIMER2.PC
#define		T3PC		TIMER3.PC

#define		T0MCR		TIMER0.MCR
#define		T1MCR		TIMER1.MCR
#define		T2MCR		TIMER2.MCR
#define		T3MCR		TIMER3.MCR

#define		T0MR0		TIMER0.MR0
#define		T1MR0		TIMER1.MR0
#define		T2MR0		TIMER2.MR0
#define		T3MR0		TIMER3.MR0

#define		T0MR1		TIMER0.MR1
#define		T1MR1		TIMER1.MR1
#define		T2MR1		TIMER2.MR1
#define		T3MR1		TIMER3.MR1

#define		T0MR2		TIMER0.MR2
#define		T1MR2		TIMER1.MR2
#define		T2MR2		TIMER2.MR2
#define		T3MR2		TIMER3.MR2

#define		T0MR3		TIMER0.MR3
#define		T1MR3		TIMER1.MR3
#define		T2MR3		TIMER2.MR3
#define		T3MR3		TIMER3.MR3

#define		T0CCR		TIMER0.CCR
#define		T1CCR		TIMER1.CCR
#define		T2CCR		TIMER2.CCR
#define		T3CCR		TIMER3.CCR

#define		T0CR0		TIMER0.CR0
#define		T1CR0		TIMER1.CR0
#define		T2CR0		TIMER2.CR0
#define		T3CR0		TIMER3.CR0

#define		T0CR1		TIMER0.CR1
#define		T1CR1		TIMER1.CR1
#define		T2CR1		TIMER2.CR1
#define		T3CR1		TIMER3.CR1

//Registros ISER:
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

//Registros ICER:
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

//Registro PCONP:
#define		PCONP		DIR_PCONP[0]

//Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

//Registros de la UART0:
#define		U0THR		DIR_U0THR[0]
#define		U0RBR		DIR_U0RBR[0]
#define		U0LCR		DIR_U0LCR[0]
#define		U0LSR		DIR_U0LSR[0]
#define		U0DLL		DIR_U0DLL[0]
#define		U0DLM		DIR_U0DLM[0]
#define		U0FCR		DIR_U0FCR[0]
#define		U0IER		DIR_U0DLM[0]
#define		U0IIR		DIR_U0IIR[0]

#define		U0RDR		(U0LSR&0x01)
#define		U0THRE		((U0LSR&0x20)>>5)

//Registros de la UART1:
#define		U1THR		DIR_U1THR[0]
#define		U1RBR		DIR_U1RBR[0]
#define		U1LCR		DIR_U1LCR[0]
#define		U1LSR		DIR_U1LSR[0]
#define		U1DLL		DIR_U1DLL[0]
#define		U1DLM		DIR_U1DLM[0]
#define     U1IIR       DIR_U1IIR[0]
#define     U1IER       DIR_U1IER[0]

#define		U1RDR		(U1LSR&0x01)
#define		U1THRE		((U1LSR&0x20)>>5)

//Registros del DAC:
#define		DACR		DIR_DACR[0]
#define		DACCTRL		DIR_DACCTRL[0]
#define		DACCNTVAL	DIR_DACCNTVAL[0]

//Registros del ADC:
#define		AD0CR		DIR_AD0CR[0]
#define		AD0GDR		DIR_AD0GDR[0]
#define		AD0INTEN	DIR_AD0INTEN[0]

#define		AD0DR0		AD0DR[0]
#define		AD0DR1		AD0DR[1]
#define		AD0DR2		AD0DR[2]
#define		AD0DR3		AD0DR[3]
#define		AD0DR4		AD0DR[4]
#define		AD0DR5		AD0DR[5]
#define		AD0DR6		AD0DR[6]
#define		AD0DR7		AD0DR[7]

//Registro de status y configuracion del sistema:
#define	SCS			DIR_SCS[0]
#define FLASHCFG	DIR_FLASHCFG[0]

//Registros de control del CLOCK:
#define	CCLKCFG		DIR_CCLKCFG[0]
#define	CLKSRCSEL	DIR_CLKSRCSEL[0]
#define	CLKOUTCFG	DIR_CLKOUTCFG[0]

//PLL0:
#define	PLL0CON		DIR_PLL0CON[0]
#define	PLL0CFG		DIR_PLL0CFG[0]
#define	PLL0STAT	DIR_PLL0STAT[0]
#define	PLL0FEED	DIR_PLL0FEED[0]

//PLL1:
#define	PLL1CON		DIR_PLL1CON[0]
#define	PLL1CFG		DIR_PLL1CFG[0]
#define	PLL1STAT	DIR_PLL1STAT[0]
#define	PLL1FEED	DIR_PLL1FEED[0]

//Systick:
#define STCTRL		DIR_STCTRL[0]
#define STCALIB		DIR_STCALIB[0]
#define STCURR		DIR_STCURR[0]
#define STRELOAD	DIR_STRELOAD[0]

//Estados de FIODIR:
#define		SALIDA	1
#define		ENTRADA	0

//Estados de PINSEL:
#define		PINSEL_GPIO		0
#define		PINSEL_FUNC1	1
#define		PINSEL_FUNC2	2
#define		PINSEL_FUNC3	3

//Estados de PINMODE
#define		PINMODE_PULLUP 		0
#define		PINMODE_REPEAT 		1
#define		PINMODE_NONE 		2
#define		PINMODE_PULLDOWN 	3

#endif /* REGS_H_ */
