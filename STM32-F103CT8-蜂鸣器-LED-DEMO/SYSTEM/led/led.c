#include "stm32f10x.h"
#include <delay.h>

//ȫ�ֱ���
  GPIO_TypeDef *  GPIO_X_led_global;
/**
  * @brief  ��ʼ��
  * @param  ѡ���ض��Ķ˿ڽ���ʹ��
  * @retval ��
  */
void initLEDPort(uint32_t GPIO_APB_X ,GPIO_TypeDef * GPIO_X)
{
		  //�˿�ģʽ������
	  GPIO_InitTypeDef GPIO_InitStruct;
	  //ͨ�ö˿ڽ��и�ֵ
	  GPIO_X_led_global=GPIO_X;
	  //ʹ��ʱ��
	  RCC_APB2PeriphClockCmd(GPIO_APB_X,ENABLE);
	
		GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;    //Ĭ���������
		GPIO_InitStruct.GPIO_Pin=GPIO_Pin_All;         //���� GPIO_X��ȫ���˿�
		GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	  GPIO_Init(GPIO_X,&GPIO_InitStruct);
}
/**
  * @brief  ��ˮ��Ч��
  * @param  д�����ݵĶ˿�
  * @retval ��
  */

void waterLed(void)
{
	//д������״̬ 	
	GPIO_Write(GPIO_X_led_global,~0x0001); //�� PX0 �˿� �͵�ƽ
	  Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0002); //�� PX1 �˿� �� ��ƽ
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0004); //�� PX2 �˿� �� ��ƽ
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0008); //�� PX3 �˿� �� ��ƽ
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0010); //�� PX4 �˿� �� ��ƽ
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0020); //�� PX5 �˿� �� ��ƽ
		Delay_ms(500);
  //������������ֱ�����
}
