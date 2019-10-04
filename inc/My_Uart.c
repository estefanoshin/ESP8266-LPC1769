
//#include "defines.h"
#include "Regs.h"
#include "drv.h"
#include "My_Uart.h"
#include "KitInfo2.h"
#include <string.h>

#define	F_CCLK		100000000	/* cclk frequency */
#define F_PCLK		25000000	/* pclk frequency for the UART modules */
#define	DIVADD		1			/* See below */
#define	MULVAL		8
#define PCLKDIV	    PCLKDIV_4

void UART1_Init ( uint32_t baudrate )
{
	int pclk;
	unsigned long int Fdiv;

    // PCLK_UART1 is being set to 1/4 of SystemCoreClock
    pclk = CORE_CLK / 4;
	//1.- Registro PCONP (0x400FC0C4) - bit 4 en 1 prende la UART:
	PCONP |= 0x00000010;
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 8 y 9 en 0 seleccionan que el clk de la UART1 sea 1MHz:
	PCLKSEL0 &= ~(0x03<<6);
	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U1LCR =0x0083;

	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) en 0xA2:
	Fdiv = ( pclk / 16 ) / baudrate ;		// Set baud rate
	U1DLM = Fdiv / 256;
	U1DLL = Fdiv % 256;

	//5.- Registro U1LCR, pongo DLAB en 0:
	U1LCR &= 0xFFFFFF7F;

	//6.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:


	SetPINSEL ( 0, 15, 1);
//	SetDIR    ( 0, 15, SALIDA ); No es necesario
	SetPINSEL ( 0, 16, 1 );
//	SetDIR    ( 0, 16, ENTRADA );No es necesario

	ISER |= (1 << 6);						// Habilito la interrupcion de la UART1 global. -> Interrupciones en LPC

	U1IER = IER_RBR | IER_THRE ;	// /* Enable UART1 interrupt*/ -> Interrupcion de la uart1
}


volatile int DataIn_Uart1=-1;

#define UART_STR_SIZE 20
static volatile uint8_t Flag_Uart1_Busy=0;
static volatile char Str_Uart1[UART_STR_SIZE];
 volatile uint8_t Idx_Send_Uart1=0;

int GetUart_1 ()//cada ves que la llamo, retorno el valor. Cada ves le guardo un menos uno. Si cuando llego la interrucion no vale -1, hay dato.
{
int aux;
	aux=DataIn_Uart1;
	DataIn_Uart1=-1;

return aux;
}


int SendStrUart_1 (const char * str) //Tomo un string
{
int aux;
	if (Flag_Uart1_Busy) // error si todavia estaba tranmitiendo
		return 0;

	Flag_Uart1_Busy=1; // flag en 1 para que otro envio de error.

	aux=strlen (str);
	if (aux>=UART_STR_SIZE-1)
		aux=UART_STR_SIZE-1;

	strncpy((char *)Str_Uart1,str,aux);
	Str_Uart1[aux]=0;
	U1THR=*Str_Uart1; //escribo primer dato a transmitir
	Idx_Send_Uart1=1;

	return 1;
}

void UART1_IRQHandler (void)
{
	unsigned char irrVal;

	irrVal = U1IIR;		//IIR es reset por HW, una vez que lo lei se resetea.
	do
	{
		switch (irrVal&0x0F)
		{
		case UART_IIR_RDA: //Receive Data Ready
			DataIn_Uart1 = U1RBR;
			break;

		case UART_IIR_THRE: // THRE, transmit holding register empty
			if (Str_Uart1[Idx_Send_Uart1])
			{
				U1THR=Str_Uart1[Idx_Send_Uart1];
				Idx_Send_Uart1++;
			}
			else
				Flag_Uart1_Busy=0;
			break;

		case UART_IIR_ERR: // Error
				// se debe analizar el LSR para determinar el error
			break;

		}

		irrVal = U1IIR;

	}
	while( ! ( irrVal & UART_IIR_PEND ) );
}


