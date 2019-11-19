/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define LED_CAMERA_Pin GPIO_PIN_0
#define LED_CAMERA_GPIO_Port GPIOC
#define MOT_B_Pin GPIO_PIN_1
#define MOT_B_GPIO_Port GPIOC
#define MOT_IN1B_Pin GPIO_PIN_0
#define MOT_IN1B_GPIO_Port GPIOA
#define MOT_IN2B_Pin GPIO_PIN_1
#define MOT_IN2B_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define AUX_IN1_Pin GPIO_PIN_4
#define AUX_IN1_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define SERVO1_Pin GPIO_PIN_6
#define SERVO1_GPIO_Port GPIOA
#define SERVO2_Pin GPIO_PIN_7
#define SERVO2_GPIO_Port GPIOA
#define SW_X_A_Pin GPIO_PIN_0
#define SW_X_A_GPIO_Port GPIOB
#define SW_X_B_Pin GPIO_PIN_10
#define SW_X_B_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_13
#define LED_B_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_14
#define LED_G_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_15
#define LED_R_GPIO_Port GPIOB
#define MOT_B_ENCB_Pin GPIO_PIN_6
#define MOT_B_ENCB_GPIO_Port GPIOC
#define MOT_B_ENCA_Pin GPIO_PIN_7
#define MOT_B_ENCA_GPIO_Port GPIOC
#define MOT_A_ENCB_Pin GPIO_PIN_8
#define MOT_A_ENCB_GPIO_Port GPIOA
#define MOT_A_ENCA_Pin GPIO_PIN_9
#define MOT_A_ENCA_GPIO_Port GPIOA
#define MOT_A_Pin GPIO_PIN_10
#define MOT_A_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define MOT_IN1A_Pin GPIO_PIN_4
#define MOT_IN1A_GPIO_Port GPIOB
#define MOT_IN2A_Pin GPIO_PIN_5
#define MOT_IN2A_GPIO_Port GPIOB
#define SW_Y_A_Pin GPIO_PIN_8
#define SW_Y_A_GPIO_Port GPIOB
#define SW_Y_B_Pin GPIO_PIN_9
#define SW_Y_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
