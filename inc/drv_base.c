#include "Regs.h"

 void SetPINSEL( uint8_t port, uint8_t pin, uint8_t mode )
{
	  port = ( 2 * port + pin / 16 ) ;
	  pin = ( pin % 16 ) * 2;
	  PINSEL[ port ] &= ~( 0x03 << pin);
	  PINSEL[ port ] |= ( mode << pin );
}


/**
  void SetDIR ( uint8_t puerto , uint8_t bit , uint8_t dir )
    determona si el GPIO sera entrada o salida
        dir seleccion entre entrada o salida

*/
void SetDIR ( uint8_t port , uint8_t pin , uint8_t dir )
{
	gpio_t *p = GPIOs + port;
	uint32_t *p_mdo = (uint32_t *) 0x4002C068UL + port;
	uint32_t *p_mde = PINMODE + 2*port;

	if ( dir )
	{
		p->FIODIR |= ( 1 << pin );		//SALIDA
		*p_mdo &= ~(1<<pin);
	}
	else
	{
		p->FIODIR  &=  ( ~ ( 1 << pin ) );	//ENTRADA
		if (pin > 15)
		{
			p_mde++;
			pin-=16;
		}
		*p_mde &= ~(0x03<<(pin*2));
	}
}


void SetPIN ( uint8_t port , uint8_t pin , uint8_t val )
{

	gpio_t *p = GPIOs + port;

	if (val)
		p->FIOSET |=( 1 << pin );
	else
		p->FIOCLR |=( 1 << pin );

}



uint8_t GetPIN( uint8_t port , uint8_t pin , uint8_t actividad ) // el tercer campo, actividad, es si quiero el valor actual o negado.
{
	gpio_t *p = GPIOs + port;

	uint8_t r;

	r = ( p->FIOPIN >> pin ) & 0x01;
	if ( actividad )
		return r;
	return !r;
}

