#include "bsp_rtc.h"

unsigned int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct rtc_tm tm;

unsigned int time_counter=0;

void Set_Time(void)
{
	
	unsigned int i;
	
	for(i=1970;i<tm.year;i++)
	time_counter+=days_in_year(i)*86400;
	if(leapyear(i))
		days_in_month[2] = 29;
	else
		days_in_month[2] = 28;
	for(i=1;i<tm.month;i++)
	time_counter+=days_in_month[i]*86400;

	time_counter+=(tm.day-1)*86400;
	time_counter+=tm.hour*3600+tm.minute*60+tm.second;
	RTC_SetCounter(time_counter);
	
}
//返回值=1，代表已经配置过RTC，则无需重新配置时间   若返回值=0，表示未配置时间，则需要指定时间
int RTC_Configuration(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP | RCC_APB1Periph_PWR, ENABLE);
	PWR_BackupAccessCmd(ENABLE);
	if(BKP_ReadBackupRegister(BKP_DR1) != 0xABCD)
	{
		BKP_DeInit();
		RCC_LSEConfig(RCC_LSE_ON);
		while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
		RCC_RTCCLKCmd(ENABLE);
		RTC_WaitForLastTask();
		RTC_WaitForSynchro();
		RTC_SetPrescaler(32767);
		RTC_WaitForLastTask();
		
		printf("Please enter year:\n");
		Uart1_scan(&tm.year,4);
		printf("year=%d",tm.year);
	
		printf("Please enter month:\n");
		Uart1_scan(&tm.month,2);
		printf("month=%d",tm.month);
		
		printf("Please enter day:\n");
		Uart1_scan(&tm.day,2);
		printf("days=%d",tm.day);
		
		printf("Please enter hour:\n");
		Uart1_scan(&tm.hour,2);
		printf("hour=%d",tm.hour);
		
		printf("Please enter minute:\n");
		Uart1_scan(&tm.minute,2);
		printf("minute=%d",tm.minute);
		
		
		printf("Please enter second:\n");
		Uart1_scan(&tm.second,2);
		printf("minute=%d",tm.second);
		
		Set_Time();	
		BKP_WriteBackupRegister(BKP_DR1, 0xABCD);
		RTC_WaitForLastTask();
		
		return 0;
	}
	else
		return 1;
}

void Time_Display(u32 TimeVal)
{
	struct rtc_tm tm;
	unsigned int days, hms;
	unsigned int i;
	
	days = TimeVal / 86400;
	hms = TimeVal % 86400;
	
	tm.hour = hms / 3600;
	tm.minute = (hms % 3600) / 60;
	tm.second = (hms % 3600) % 60;
	
	for(i = 1970; days >= days_in_year(i); i++)
		days -= days_in_year(i);
	tm.year = i;
	
	if(leapyear(i))
		days_in_month[2] = 29;
	else
		days_in_month[2] = 28;
	for(i = 1; days >= days_in_month[i]; i++)
		days -= days_in_month[i];
	tm.month = i;
	
	tm.day = days + 1;

	printf("%d-%d-%d: %d:%d:%d\n", tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);	
}

//void Set_Time(void)
//{
//	//printf("Please enter year");
//	RTC_SetCounter(0xFFFF5555);
//}
