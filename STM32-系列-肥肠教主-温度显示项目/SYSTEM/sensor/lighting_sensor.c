#include "stm32f10x.h"

/**
  * ��     ��: ��ʼ��ָ���˿�
  * ��     ��: void
  * �� ��  ֵ: void
  */
void Lighting_sensor_init(void)
{
	//ָ���˿ڽ��չ������������ź�
	
	GPIO_InitTypeDef GPIO_InitStructure;
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		// GPIOA

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // �������� Ĭ�ϸߵ�ƽ��������ش����������Խ��д���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;                   // GPIO_Pin_6 --> A6
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//  ��ʼ��
}

/**
  * ��     ��: ��ȡ�ض�GPIO�ڵĸߵ͵�ѹ
  * ��     ��: void
  * �� ��  ֵ: void
  */
uint8_t  Get_Sensor_singal()
{
	//���ݹ��������������ԣ���Ҫ��� �ﵽһ�� ��DO����� �͵�ƽ
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}




