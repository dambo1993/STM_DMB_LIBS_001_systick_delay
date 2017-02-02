#include "stm32f0xx.h"
#include "DMB/rejestry.h"
#include "DMB/debug.h"
#include "RCC/RCC.h"
#include "delay_systick/delay_systick.h"

void _delay(unsigned int x)
{
	while (x--);
}

int main(void)
{
	RCC_init();
	delay_init();
	// wlaczenie zegara dla portu A i B
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	DEBUG_LED1_OUT;
	DEBUG_LED2_OUT;
	while (1)
	{
		DEBUG_LED2_TOG;
		_delay_ms(1000);
	}
}
