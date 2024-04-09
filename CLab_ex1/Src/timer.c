#include "timer.h"

void trigger_prescaler()
{

	TIM2->ARR = 0x01;
	TIM2->CNT = 0x00;
	asm("NOP");
	asm("NOP");
	asm("NOP");
	TIM2->ARR = 0xffffffff;

}

void start_timer()
{
	//let timer running
	TIM2->CR1 |= TIM_CR1_CEN;

	trigger_prescaler();

}

void timer_loop(uint32_t time_length)
{
	TIM2->CNT = 0;
	while (TIM2->CNT < time_length) {} ;
}
