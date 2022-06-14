#include "music.h"
unsigned int tone[7]={523,587,659,698,784,880,988};

void sound(unsigned int fre)
{
	TIM4->ARR=1000000/fre;
	TIM4->CCR3=500000/fre;
	
	
	
	
	
}