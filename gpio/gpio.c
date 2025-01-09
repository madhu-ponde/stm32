#include "header.h"
#include "GPIO.h"


void GPIO_config()
{
	RCC->CR |= (1 << 0);   //system clock=8Mhz
    while(! (RCC->CR & 	(1<<1)));
    RCC->CFGR = 0X00;    

    RCC->APB2ENR |= (1 << 2);     //GPIOA
   GPIOA->CRL &= ~(0xFFFF);          
  	GPIOA->CRL |= (0x3333);           

}


void led_state(int state)
{
    if(state)
		{
        GPIOA->ODR |= (1 << 0);
	}else
        GPIOA->ODR &= ~(1 << 0);
}
