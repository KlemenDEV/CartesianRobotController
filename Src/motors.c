#include "motors.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

static float speedXval, speedYval;

void enableMotors(void) {
	speedXval = 0;
	speedYval = 0;
	
	HAL_GPIO_WritePin(MOTOR_A, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR_B, GPIO_PIN_SET);
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void disableMotors(void) {
	speedXval = 0;
	speedYval = 0;
	
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
	
	speedXval = speed;
}

void setSpeedY(float speed) {
	if(speed > 1)
		speed = 1;
	else if(speed < -1)
		speed = -1;
	
	speedYval = speed;
}

void motorsSpeedTick(void) {
	float speedX = speedXval;
	float speedY = speedYval;
	
	if(speedX > 0 && switchState(SW_X_A) == 0)
		speedX = 0;
	else if(speedX < 0 && switchState(SW_X_B) == 0)
		speedX = 0;
	
	if(speedY > 0 && switchState(SW_Y_A) == 0)
		speedY = 0;
	else if(speedY < 0 && switchState(SW_Y_B) == 0)
		speedY = 0;
	
	if(speedX > 0) {
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speedX * 4095);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
	} else if (speedX < 0) {
		speedX *= -1;
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speedX * 4095);
	} else {
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
	}
	
	if(speedY > 0) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speedY * 4095);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
	} else if (speedY < 0) {
		speedY *= -1;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, speedY * 4095);
	} else {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
	}
}
