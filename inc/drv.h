
#ifndef MY_DRV_H_
#define MY_DRV_H_
#include "Regs.h"

void InitPLL ( void );

void SetPINSEL( uint8_t port, uint8_t pin, uint8_t mode );
void SetDIR ( uint8_t port , uint8_t pin , uint8_t dir );
void SetPIN ( uint8_t port , uint8_t pin , uint8_t val );
uint8_t GetPIN( uint8_t port , uint8_t pin , uint8_t actividad );


#endif
