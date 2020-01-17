#include "servos.h"

void servosInit(void) {
	HAL_GPIO_WritePin(SERVO1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SERVO2, GPIO_PIN_SET);
}

void setServoPosition(int servo, int angle) {
	if(servo == 0) {
		if(angle == TOOL_POS_DROP) {
			HAL_GPIO_WritePin(SERVO1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SERVO2, GPIO_PIN_SET);
		} else if(angle == TOOL_POS_COLLECT) {
			HAL_GPIO_WritePin(SERVO1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SERVO2, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(SERVO1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SERVO2, GPIO_PIN_SET);
		}
	}
}
