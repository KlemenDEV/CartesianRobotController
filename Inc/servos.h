#include "main.h"
#include "conf.h"

#ifndef SERVO_H
#define SERVO_H

void servosInit(void);

void setServoPosition(int servo, int angle);

#endif
