#include <stm32f10x.h>
#include <delay.h>
#include <led.h>
#include <beep.h>

/*********************************************/
//*   ʵ��ƽ̨��STM32F103CT8
//*   library version: register
//*   author : �ʳ�����-LuoYang
//*   deta: 2024/07/27
//*   subject:
//*          ����ģ�壬���ڹ����İ汾
//*
/**********************************************/
int main()
{
	//��ʼ��-LED
	initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	//��ʼ��-BEEP
	initLEDPort(RCC_APB2Periph_GPIOB,GPIOB);
	while(1)
	{
		waterLed();
		beepTalk();
	}
}

