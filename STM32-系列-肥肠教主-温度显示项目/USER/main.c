#include <stm32f10x.h>
#include <delay.h>
#include <key.h>
#include <led.h>
#include <lighting_sensor.h>
#include <beep.h>
#include <oled.h>
/*********************************************
*   实验平台：STM32F103CT8
*   library version: functino
*   author : LuoYang 肥肠教主
*   deta: 2024/09/17
*   subject: 光敏传感器的使用    
**********************************************/

int main()
{
/**	Test Function
  *
  * 函     数: 按键控制流水灯
  * 参     数: void
  * 返 回  值: void
  */
	//按键初始化
	//Key_init();
	//LED
	//initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	
	//初始化BEEP
	initBEEPPort(RCC_APB2Periph_GPIOB,GPIOB);
	
	//初始化光敏
	Lighting_sensor_init();
	
	OLED_Init();
	
	/*OLED显示*/
	OLED_ShowChar(1, 1, 'A');				//1行1列显示字符A
	
	OLED_ShowString(1, 3, "HelloWorld!");	//1行3列显示字符串HelloWorld!
	
	OLED_ShowNum(2, 1, 12345, 5);			//2行1列显示十进制数字12345，长度为5
	
	OLED_ShowSignedNum(2, 7, -66, 2);		//2行7列显示有符号十进制数字-66，长度为2
	
	OLED_ShowHexNum(3, 1, 0xAA55, 4);		//3行1列显示十六进制数字0xA5A5，长度为4
	
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




