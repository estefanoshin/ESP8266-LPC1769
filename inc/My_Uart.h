
#ifndef MY_UART_H_
#define MY_UART_H_

#include "Regs.h"

//--- flags de habilitación de interrupciones UART
#define IER_RBR		0x01
#define IER_THRE	0x02
#define IER_ERR		0x04

//--- flags de interrupciones UART
#define UART_IIR_ERR		0x06
#define UART_IIR_RDA		0x04
#define UART_IIR_THRE		0x02
#define UART_IIR_PEND		0x01



void UART1_Init(uint32_t);

int GetUart_1 ();
int SendStrUart_1 (const char * str);


#endif /*UART_H_*/
