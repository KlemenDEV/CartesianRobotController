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
	
	setSpeedX(0.25); // move towards x origin
	while(switchState(SW_X_A) == 1); // wait to reach start x endswitch
	setSpeedX(0); // stop moving towards origin
	zeroX(); // we reached start, zero encoder
	
	/*setSpeedY(0.5); // move towards y origin
	while(switchState(SW_Y_A) == 1); // wait to reach start y endswitch
	setSpeedY(0); // stop moving towards origin
	zeroY(); // we reached start, zero encoder*/
	
	disableMotors();
	
	status = IDLE;
}

int dtd;

static float ix = 0, iy = 0;

void controllerTick(uint8_t dt) {	
	
	dtd = target_x;
	
	if(status == MOVEL) {
		float ex = getPositionX() - target_x;
		float ey = getPositionY() - target_y;
		
		ix += ex * dt;
		iy += ey * dt;
		
		if(fabs(ex) < 0.01f /*&& fabs(ey) < 0.1f*/) {
			controllerIdle();
		} else {
			setSpeedX(ex * KP_X + ix * KI_X);
			setSpeedY(ey * KP_Y + iy * KI_X);
		}
	}
}

void controllerIdle(void) {
	status = IDLE;
	disableMotors();
	
	uartPrintln("Controller idle");
}

ControllerStatus getStatus(void) {
	return status;
}
