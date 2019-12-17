#include "main.h"
#include "conf.h"

#ifndef MOTOR_H
#define MOTOR_H

void enableMotors(void);
void disableMotors(void);

void setSpeedX(float speed);
void setSpeedY(float speed);

#endif
