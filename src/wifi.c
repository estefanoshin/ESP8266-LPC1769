#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include "drv.h"
#include "Regs.h"
#include "FW_Timertick.h"
#include "My_Uart.h"

extern volatile uint8_t f_1seg;

void InitMyHW();
void UART1_Init(uint32_t);
int GetUart_1();
int SendStrUart_1(const char * str);

int main(void) {
	uint8_t val = 0;
	InitPLL();
	InitMyHW();
	InitSystick();	// 2,5ms
	UART1_Init(9600);

	SendStrUart_1("AT\r\n");

	while (1) {
		if (GetUart_1() != -1) {
			for (int var = 0; var < 20; ++var) {
			}
		}

		if (f_1seg) {
			f_1seg = 0;

			SetPIN(0, 22, val);
			val = !val;
		}

	}
	return 0;
}

void InitMyHW() {
	SetPINSEL(0, 22, 0); // al reset, por defecto en cero.
	SetDIR(0, 22, SALIDA); // ín 22 como salida. Led del lpc

}
