#include "all.h"                  // Device header

int main(void)
{	
	int a,b,c,d,e;
	OLED_Init();
	Motor_Init();
	Servo_Init();
	Serial1_Init();	
	Key_Init();
	uint8_t KeyNum;
	CountSensor_Init();		//计数传感器初始化
	Init_HX711pin();
	Init_buzzer();
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	Get_Maopi();				//称毛皮重量
	warning(1);
	Get_Maopi();				//重新获取毛皮重量
	Servo_SetAngle(90);
	OLED_ShowString(1, 1, "weight:");
	OLED_ShowString(1, 13, "g");
	OLED_ShowString(2, 1, "Count:");//2行1列显示字符串Count:
	OLED_ShowString(3, 1, "A:");
	OLED_ShowString(3, 8, "B:");
	OLED_ShowString(4, 1, "C:");
	OLED_ShowString(4, 8, "D:");
	a=0;b=0;c=0;d=0;e=0;
	old_angle=90;
	while(1)
	{
		OLED_ShowNum(2, 8, e, 4);
		OLED_ShowNum(3, 3, a, 4);
		OLED_ShowNum(3, 11, b, 4);
		OLED_ShowNum(4, 3, c, 4);
		OLED_ShowNum(4, 11, d, 4);
		//Get_Weight();
		//Delay_ms(100);
		//OLED_ShowNum(1, 8, Weight_Shiwu/2,4);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
		//if (0)
		{
			Get_Weight();
			warning(1);
			Weight_Shiwu = Weight_Shiwu/2;
			OLED_ShowNum(1, 8, Weight_Shiwu,4);
			if(Weight_Shiwu>10)
			{
				e++;
				if(10<Weight_Shiwu && Weight_Shiwu<=50)
				{
					a++;
					Motor_Run_1(1,1000,20);    //设置步进电机前进
					SetAngle(30);			//设置舵机的角度为角度变量
					Delay_ms(500);
					SetAngle(90);
					Motor_Run_1(0,1000,20);
				}
				else if(50<Weight_Shiwu && Weight_Shiwu<=100)
				{
					b++;
					Motor_Run_1(1,1000,20);    //设置步进电机前进
					SetAngle(150);			//设置舵机的角度为角度变量
					Delay_ms(500);
					SetAngle(90);
					Motor_Run_1(0,1000,20);
				}
				else if(100<Weight_Shiwu && Weight_Shiwu<=150)
				{
					c++;
					Motor_Run_1(1,7000,20);    //设置步进电机前进
					SetAngle(30);			//设置舵机的角度为角度变量
					Delay_ms(500);
					SetAngle(90);
					Motor_Run_1(0,7000,20);
				}
				else if(150<Weight_Shiwu)
				{
					d++;
					Motor_Run_1(1,7000,20);    //设置步进电机前进
					SetAngle(150);			//设置舵机的角度为角度变量
					Delay_ms(500);
					SetAngle(90);
					Motor_Run_1(0,7000,20);
				}
			}
		Weight_Shiwu = 0;
		}
		
		
		KeyNum = Key_GetNum();
		if (KeyNum == 1)			//最大值清0
		{
			
			int max = a;
			int *max_ptr = &a;

			if (b > max) {
				max = b;
				max_ptr = &b;
			}
			if (c > max) {
				max = c;
				max_ptr = &c;
			}
			if (d > max) {
				max = d;
				max_ptr = &d;
			}

			// 将最大值清零
			*max_ptr = 0;
		}
		else if (KeyNum == 2)			//全清0
		{
			a=0;b=0;c=0;d=0;e=0;
		}
		if(a>=5 | b>=5 | c>=5 | d>=5)
		{
			warning(1);
		}
	}
}
