#include <stm32f10x.h>
#include <delay.h>
#include <key.h>
#include <led.h>
#include <lighting_sensor.h>
#include <beep.h>
#include <oled.h>
/*********************************************
*   ʵ��ƽ̨��STM32F103CT8
*   library version: functino
*   author : LuoYang �ʳ�����
*   deta: 2024/09/17
*   subject: ������������ʹ��    
**********************************************/

int main()
{
/**	Test Function
  *
  * ��     ��: ����������ˮ��
  * ��     ��: void
  * �� ��  ֵ: void
  */
	//������ʼ��
	//Key_init();
	//LED
	//initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	
	//��ʼ��BEEP
	initBEEPPort(RCC_APB2Periph_GPIOB,GPIOB);
	
	//��ʼ������
	Lighting_sensor_init();
	
	OLED_Init();
	
	/*OLED��ʾ*/
	OLED_ShowChar(1, 1, 'A');				//1��1����ʾ�ַ�A
	
	OLED_ShowString(1, 3, "HelloWorld!");	//1��3����ʾ�ַ���HelloWorld!
	
	OLED_ShowNum(2, 1, 12345, 5);			//2��1����ʾʮ��������12345������Ϊ5
	
	OLED_ShowSignedNum(2, 7, -66, 2);		//2��7����ʾ�з���ʮ��������-66������Ϊ2
	
	OLED_ShowHexNum(3, 1, 0xAA55, 4);		//3��1����ʾʮ����������0xA5A5������Ϊ4
	
	OLED_ShowBinNum(4, 1, 0xAA55, 16);
	
	
	
	while(1)
	{
	   uint8_t	temp=Get_Sensor_singal();
		if(temp==1)
		{
				beepTalk();
		}
	}
}




