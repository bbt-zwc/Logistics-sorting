#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngle(float Angle)
{
	PWM_SetCompare2(Angle / 180 * 2000 + 500);
	//Delay_ms(1000);
}

float old_angle;
void SetAngle(float Angle)
{
	if(Angle<old_angle)
	{
		while(Angle<old_angle)
		{
			old_angle-=2;
			Servo_SetAngle(old_angle);
			Delay_ms(50);
		}
	}
	else if(Angle>old_angle)
	{
		while(Angle>old_angle)
		{
			old_angle+=2;
			Servo_SetAngle(old_angle);
			Delay_ms(50);
		}
	}
}
