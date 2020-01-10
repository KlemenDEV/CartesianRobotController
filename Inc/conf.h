#include "main.h"

#define MOTOR_A GPIOA, GPIO_PIN_10
#define MOTOR_B GPIOC, GPIO_PIN_1

#define SW_X_A GPIOB, GPIO_PIN_0
#define SW_X_B GPIOB, GPIO_PIN_10

#define SW_Y_A GPIOB, GPIO_PIN_8
#define SW_Y_B GPIOB, GPIO_PIN_9

#define LED_STATUS_R GPIOB, GPIO_PIN_15
#define LED_STATUS_G GPIOB, GPIO_PIN_14
#define LED_STATUS_B GPIOB, GPIO_PIN_13

#define ENCODER_FACTOR (395.12f * (5.0f / 5.6f))

#define KP_X 0.85f
#define KP_Y 0.85f

#define KI_X 0.001f
#define KI_Y 0.001f

#define KD_X 0.0f
#define KD_Y 0.0f

#define TARGET_WAIT 500
#define TARGET_RANGE 0.05f
#define TARGET_CONDITION (fabs(ex) < TARGET_RANGE /*&& fabs(ey) < TARGET_RANGE*/)
