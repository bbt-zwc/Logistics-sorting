#ifndef __all_H
#define __all_H

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Motor.h"
#include "Key.h"
#include "Serial.h"
#include "OLED.h"
#include "Servo.h"
#include "position.h"
#include "function.h"
#include "HX711.h"
#include "sys.h"
#include "CountSensor.h"

#endif
/*
***********接线**********

***********tb6600***********
VCC,GND ------ 24V
ENA-,DIR-,PUL-,短接并且接地
DIR+ ----- A4
PUL+ ----- A3
A+   ----- 步进电机红线
A-   ----- 步进电机蓝线
B+   ----- 步进电机绿线
B-   ----- 步进电机黑线

***********舵机***********
红线 ----- 5V
棕线 ----- GND
黄线 ----- A1

***********压力传感器***********
VCC ----- 5V
SCK ----- B0
DOUT ---- B1
GND ----- GND

***********红外计数传感器***********
红线 ---- 5V
黑线 ---- GND
白线 ---- B14

***********oled显示屏***********
VCC ---- 5V
SCL ---- B8
SDA ---- B9
GND ---- GND

***********蜂鸣器***********
VCC ---- 3.3V
I/O ---- B13
GND ---- GND

***********按键***********
K1 ---- B11
K2 ---- B12

*/
