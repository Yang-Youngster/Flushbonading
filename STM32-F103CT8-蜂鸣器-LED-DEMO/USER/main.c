#include <stm32f10x.h>
#include <delay.h>
#include <led.h>
#include <beep.h>

/*********************************************/
//*   实验平台：STM32F103CT8
//*   library version: register
//*   author : 肥肠教主-LuoYang
//*   deta: 2024/07/27
//*   subject:
//*          基本模板，基于官网的版本
//*
/**********************************************/
int main()
{
	//初始化-LED
	initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	//初始化-BEEP
	initLEDPort(RCC_APB2Periph_GPIOB,GPIOB);
	while(1)
	{
		waterLed();
		beepTalk();
	}
}

