#include "main.h"

#define MOTOR_A GPIOA, GPIO_PIN_10
#define MOTOR_B GPIOC, GPIO_PIN_1

#define SW_X_A GPIOB, GPIO_PIN_0
#define SW_X_B GPIOB, GPIO_PIN_10

#define SW_Y_A GPIOB, GPIO_PIN_8
#define SW_Y_B GPIOB, GPIO_PIN_9

#define ENCODER_FACTOR 1.0f

#define KX 10.0f
#define KY 10.0f
