#include "stm32f10x.h"
#include "delay.h"

/**
  * ��     ��: ��ʼ��ʱ��
  * ��     ��: void
  * �� ��  ֵ: void
  */
  
 void Key_init(void)
 {
	 /*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		// GPIOA
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // �������� Ĭ�ϸߵ�ƽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						//  ��ʼ��
 }
 
 /**
  * ��     ��: ��ʼ��ʱ��
  * ��     ��: void
  * �� ��  ֵ: uint8_t
  */
 
uint8_t Key_Value(void)
 {
	 
	 uint8_t tempValue=0;
	 
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0)    // ��ȡ�͵�ƽ
	 {
		 Delay_ms(30);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0);
		 Delay_ms(30);
		 
		 //��ȡ��ֵ
		 tempValue=1;
	 }
		 
	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0)    // ��ȡ�͵�ƽ
	 {
		 Delay_ms(30);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0);
		 Delay_ms(30);
		 
		 //��ȡ��ֵ
		 tempValue=2;
	 }
	 return tempValue;
 }
 