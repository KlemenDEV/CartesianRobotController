#include "controller.h"

static ControllerStatus status = IDLE;

static float target_x; // in cm
static float target_y; // in cm

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

static float ix = 0, iy = 0;
static float exold = 0, eyold = 0;

static int waittime = 0;

void controllerTick(uint8_t dt) {	
	float ex = getPositionX() - target_x;
	float ey = getPositionY() - target_y;
	
	if(status == MOVEL_IN_TARGET) {
		if(TARGET_CONDITION) { // check if we are still in target
			if(waittime > TARGET_WAIT) { // we are in target for more than wait time
				controllerIdle(); // target reached, move to idle
			} else { // if not long enough, acumulate waittime
				waittime += dt;
			}
		} else { // target overshoot, back to regulator
			status = MOVEL;
		}
	}
	
	if(status == MOVEL || status == MOVEL_IN_TARGET) {
		ix += ex * (float) dt;
		iy += ey * (float) dt;
		
		float derx = (ex - exold) / (float) dt;
		float dery = (ey - eyold) / (float) dt;
		
		setSpeedX(ex * KP_X + ix * KI_X + derx * KD_X);
		setSpeedY(ey * KP_Y + iy * KI_X + dery * KD_Y);
		
		exold = ex;
		eyold = ey;
		
		if(TARGET_CONDITION && status != MOVEL_IN_TARGET) { // if we are in target and not in MOVEL_INTARGET state yet
			waittime = 0;
			status = MOVEL_IN_TARGET;
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
