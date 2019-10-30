#include "main.h"
#include "conf.h"
#include "encoders.h"
#include "motors.h"
#include "switches.h"

typedef enum {
	IDLE, INIT, MOVEL
} ControllerStatus;

void controllerInit(void);
void moveL(float x, float y);

ControllerStatus getStatus(void);

void controllerIdle(void);

void controllerTick(uint8_t dt);
