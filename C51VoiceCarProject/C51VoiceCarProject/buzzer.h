#ifndef _BUZZER_H
#define _BUZZER_H

/********************************头文件****************************************/
#include <reg52.h>
#include "DELAY.h"
#include "TTLDefine.h"

/********************************位定义****************************************/
sbit Hummer = P1^0;

/********************************函数声明****************************************/
void Buzzer();

#endif
