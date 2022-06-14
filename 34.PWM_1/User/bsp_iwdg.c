#include "bsp_iwdg.h"

//ʹ��IWDG����40KHz LSI�£�Լ����ÿ��1s����IWDG��λ
void IWDG_Configuration(void)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_64);
	IWDG_SetReload(625);
	IWDG_ReloadCounter();
	IWDG_Enable();
}

void IWDG_FeedDog(void)
{
	IWDG_ReloadCounter();
}

