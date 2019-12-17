#include "servos.h"

extern TIM_HandleTypeDef htim16; //PA6/CH1 - servo 0 - in use
extern TIM_HandleTypeDef htim17; //PA7/CH1 - servo 1

void servosInit(void) {
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
	
	setServoPosition(0, 0);
	setServoPosition(1, 0);
}

// 0 deg = 50 - 1 ms
// 90 deg - 75 - 1.5ms
// 180 deg = 100 - 2 ms
void setServoPosition(int servo, float angle) {
	if(servo == 0) {
		__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, (int) (50 + (angle / 3.6f)));
	} else if(servo == 1) {
		__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, (int) (50 + (angle / 3.6f)));
	}
}
