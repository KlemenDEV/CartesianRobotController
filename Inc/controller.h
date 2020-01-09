#include "main.h"
#include "conf.h"
#include "encoders.h"
#include "motors.h"
#include "switches.h"
#include "print.h"

#include <math.h>
#include <stdio.h>

#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef enum {
	IDLE, INIT, MOVEL, MOVEL_IN_TARGET
} ControllerStatus;

void controllerInit(void);
void moveL(float x, float y);

ControllerStatus getStatus(void);

void controllerIdle(void);

void controllerTick(uint8_t dt);

#endif
