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

#define KP_X 0.6f
#define KP_Y 0.6f

#define KI_X 0.0004f
#define KI_Y 0.0004f
