#include "controller.h"

static ControllerStatus status = IDLE;

static float target_x; // in mm
static float target_y; // in mm

void moveL(float x, float y) {
	if(status != IDLE)
		return;
	
	target_x = x;
	target_y = y;
	status = MOVEL;
	enableMotors();
}

void controllerInit(void) {
	status = INIT;
	
	// TODO: init sequence to calibrate encoders
	
	status = IDLE;
}

void controllerIdle(void) {
	status = IDLE;
	disableMotors();
}

ControllerStatus getStatus(void) {
	return status;
}

void controllerTick(uint8_t dt) {
	if(status == MOVEL) {
		float ex = target_x - getPositionX();
		float ey = target_y - getPositionY();
		if(ex < 1 && ey < 1) {
			controllerIdle();
		} else {
			setSpeedX(ex * KX);
			setSpeedX(ey * KY);
		}
	}
}
