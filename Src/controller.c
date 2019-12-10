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
	
	enableMotors();
	
	setSpeedX(-0.5); // move towards x origin
	while(switchState(SW_X_A) == 0); // wait to reach start x endswitch
	zeroX(); // we reached start, zero encoder
	setSpeedX(0); // stop moving towards origin
	
	setSpeedY(-0.5); // move towards y origin
	while(switchState(SW_Y_A) == 0); // wait to reach start y endswitch
	zeroY(); // we reached start, zero encoder
	setSpeedY(0); // stop moving towards origin
	
	disableMotors();
	
	status = IDLE;
}

void controllerTick(uint8_t dt) {
	if(status == MOVEL) {
		float ex = target_x - getPositionX();
		float ey = target_y - getPositionY();
		if(ex < 1 && ey < 1) {
			controllerIdle();
		} else {
			setSpeedX(ex * KX);
			setSpeedY(ey * KY);
		}
	}
}

void controllerIdle(void) {
	status = IDLE;
	disableMotors();
}

ControllerStatus getStatus(void) {
	return status;
}
