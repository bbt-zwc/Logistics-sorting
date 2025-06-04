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
***********����**********

***********tb6600***********
VCC,GND ------ 24V
ENA-,DIR-,PUL-,�̽Ӳ��ҽӵ�
DIR+ ----- A4
PUL+ ----- A3
A+   ----- �����������
A-   ----- �����������
B+   ----- �����������
B-   ----- �����������

***********���***********
���� ----- 5V
���� ----- GND
���� ----- A1

***********ѹ��������***********
VCC ----- 5V
SCK ----- B0
DOUT ---- B1
GND ----- GND

***********�������������***********
���� ---- 5V
���� ---- GND
���� ---- B14

***********oled��ʾ��***********
VCC ---- 5V
SCL ---- B8
SDA ---- B9
GND ---- GND

***********������***********
VCC ---- 3.3V
I/O ---- B13
GND ---- GND

***********����***********
K1 ---- B11
K2 ---- B12

*/
