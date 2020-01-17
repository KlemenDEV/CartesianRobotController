#include "main.h"

// physical parameters
#define ENCODER_FACTOR (395.12f * (5.0f / 5.6f)) * (25.0f/27.0f)

#define KP_X 1.50f
#define KP_Y 1.20f

#define KI_X 0.002f
#define KI_Y 0.001f

#define TARGET_WAIT 250
#define TARGET_RANGE 0.035f
#define TARGET_CONDITION (fabs(ex) < TARGET_RANGE && fabs(ey) < TARGET_RANGE)

#define TOOL_POS_DROP 180
#define TOOL_POS_CARRY 90
#define TOOL_POS_COLLECT 0

#define CONTAINER_POSITION 5, 28

// pin mappings
#define MOTOR_A GPIOA, GPIO_PIN_10
#define MOTOR_B GPIOC, GPIO_PIN_1

#define SERVO1 GPIOA, GPIO_PIN_6
#define SERVO2 GPIOA, GPIO_PIN_7

#define SW_X_A GPIOB, GPIO_PIN_0
#define SW_X_B GPIOB, GPIO_PIN_10

#define SW_Y_A GPIOB, GPIO_PIN_9
#define SW_Y_B GPIOB, GPIO_PIN_8

#define LED_STATUS_R GPIOB, GPIO_PIN_15
#define LED_STATUS_G GPIOB, GPIO_PIN_14
#define LED_STATUS_B GPIOB, GPIO_PIN_13
