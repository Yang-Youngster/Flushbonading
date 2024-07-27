#include <stm32f10x.h>
#include <delay.h>
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
	
	 GPIO_InitTypeDef GPIO_PC13;
	 GPIO_InitTypeDef GPIO_PA0;
	//ʹ�ÿ⺯���ķ�ʽ���
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA,ENABLE);
	 //����������ģʽ
	 GPIO_PC13.GPIO_Pin=GPIO_Pin_13;
	 GPIO_PC13.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_PC13.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOC,&GPIO_PC13);
	 GPIO_PA0.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_PA0.GPIO_Pin=GPIO_Pin_0;
	 GPIO_PA0.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA,&GPIO_PA0);
	//�����ߵ�ƽ
	 while(1)
	 {
		 //��д�ɹ�
		  GPIO_SetBits(GPIOA,GPIO_Pin_0);
		  GPIO_SetBits(GPIOC,GPIO_Pin_13);
		  Delay_s(2);
		  GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		  GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		  Delay_s(2);
	 } 
}

