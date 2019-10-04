#include "Regs.h"

volatile uint8_t f_1seg=0;



void InitSystick ( void )
{

	STRELOAD  = ( STCALIB / 4 ) - 1 ; //para quwe sea cada 2,5 segundos
	STCURR = 0;

	STCTRL = 0x00000007; // 3 bit mas significativos en 1. Activa interrupciones, timers y algo mas.
}

void SysTick_Handler(void) // interrupcion. Enlace devil. EL codigo se sobreescribe.
{
	static uint32_t cent = 200;

	cent--;
	if(!cent)
	{
		cent = 200;

		f_1seg=1;
	}

}

