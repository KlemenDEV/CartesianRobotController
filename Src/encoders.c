#include "encoders.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;

static int originX = 0;
static int originY = 0;

float getPositionX(void) {
	return (originX - htim1.Instance->CNT) / ENCODER_FACTOR;
}

float getPositionY(void) {
	return (originY - htim8.Instance->CNT) / ENCODER_FACTOR;
}


void zeroX(void) {
	originX = htim1.Instance->CNT;
}

void zeroY(void) {
	originY = htim8.Instance->CNT;
}
