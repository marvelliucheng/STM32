#include "music.h"
//---------------------Do Re Mi Fa So La Si
unsigned int tone[7]={523,587,659,698,784,880,988};

//unsigned int music_little_star[]=
//{
//	523,523,784,784,880,880,784,
//     698,698,659,659,587,587,523,
//	784,784,698,698,659,659,587,
//	784,784,698,698,659,659,587,
//    523,523,784,784,880,880,784,
//	690,690,659,659,587,587,523,
//		
//};
unsigned int music_liitle_star[][2]={
	
	{523,400000},{523,400000},{784,400000},{784,400000},{880,400000},{880,400000},{784,800000},
	{698,400000},{698,400000},{659,400000},{659,400000},{587,400000},{587,400000},{523,800000},
	{784,400000},{784,400000},{698,400000},{698,400000},{659,400000},{659,400000},{587,800000},
	{784,400000},{784,400000},{698,400000},{698,400000},{659,400000},{659,400000},{587,800000},
	{523,400000},{523,400000},{784,400000},{784,400000},{880,400000},{880,400000},{784,800000},
	{690,400000},{690,400000},{659,400000},{659,400000},{587,400000},{587,400000},{523,800000},
	{0,0}
};


			  
void sound(unsigned int fre)
{
	TIM4->ARR=1000000/fre;
	TIM4->CCR3=500000/fre;
	
	
}