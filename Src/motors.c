#include "motors.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

void enableMotors(void) {
	HAL_GPIO_WritePin(MOTOR_A, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR_B, GPIO_PIN_SET);
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void disableMotors(void) {
	HAL_GPIO_WritePin(MOTOR_A, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_B, GPIO_PIN_RESET);
	
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
}

void setSpeedX(float speed) {
	if(speed > 1)
		speed = 1;
	else if(speed < -1)
		speed = -1;
	
	if(speed > 0) {
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed * 4095);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
	} else if (speed < 0) {
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed * 4095);
	} else {
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
	}
}

void setSpeedY(float speed) {
	if(speed > 1)
		speed = 1;
	else if(speed < -1)
		speed = -1;
	
	if(speed > 0) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed * 4095);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
	} else if (speed < 0) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, speed * 4095);
	} else {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
	}
}
