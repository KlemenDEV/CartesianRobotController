#include "encoders.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;

static int encoderOriginX = 0;
static int encoderOriginY = 0;

static int oldEncoderX = 0;
static int oldEncoderY = 0;

static float currentPosX = 0;
static float currentPosY = 0;

void encodersTick(void) {
	int currX = htim1.Instance->CNT;
	int currY = htim1.Instance->CNT;
	
	int dx = currX - oldEncoderX;
	int dy = currY - oldEncoderY;
	
	// check for x overflow
	if(abs(dx) > 65535/2 && dx < 0) { // positive overflow
		dx = (65535 - oldEncoderX) + currX; // dx = remaining from max + current value
	} else if(abs(dx) > 65535/2 && dx > 0) { // negative overflow
		dx = - (oldEncoderX + (65535 - currX)); // dx = old value (offset from 0) + offset of new value from max
	}
	
	// check for y overflow
	if(abs(dy) > 65535/2 && dy < 0) { // positive overflow
		dy = (65535 - oldEncoderY) + currY; // dy = remaining from max + current value
	} else if(abs(dy) > 65535/2 && dy > 0) { // negative overflow
		dy = - (oldEncoderY + (65535 - currY)); // dy = old value (offset from 0) + offset of new value from max
	}
	
	currentPosX += dx / ENCODER_FACTOR;
	currentPosY += dy / ENCODER_FACTOR;
}

float getPositionX(void) {
	return currentPosX;
}

float getPositionY(void) {
	return currentPosY;
}

void zeroX(void) {
	encoderOriginX = htim1.Instance->CNT;
	oldEncoderX = encoderOriginX;
	currentPosX = 0;
}

void zeroY(void) {
	encoderOriginY = htim8.Instance->CNT;
	oldEncoderY = encoderOriginY;
	currentPosY = 0;
}
