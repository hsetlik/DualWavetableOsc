/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CV2_Pin GPIO_PIN_0
#define CV2_GPIO_Port GPIOA
#define MOD2_Pin GPIO_PIN_1
#define MOD2_GPIO_Port GPIOA
#define MOD1_Pin GPIO_PIN_2
#define MOD1_GPIO_Port GPIOA
#define CV1_Pin GPIO_PIN_3
#define CV1_GPIO_Port GPIOA
#define SD_CS_Pin GPIO_PIN_12
#define SD_CS_GPIO_Port GPIOB
#define CH_BTN_Pin GPIO_PIN_8
#define CH_BTN_GPIO_Port GPIOA
#define ENC2_L_Pin GPIO_PIN_9
#define ENC2_L_GPIO_Port GPIOA
#define ENC2_R_Pin GPIO_PIN_10
#define ENC2_R_GPIO_Port GPIOA
#define ENC1_L_Pin GPIO_PIN_11
#define ENC1_L_GPIO_Port GPIOA
#define ENC1_R_Pin GPIO_PIN_12
#define ENC1_R_GPIO_Port GPIOA
#define ENC2_B_Pin GPIO_PIN_4
#define ENC2_B_GPIO_Port GPIOB
#define ENC1_B_Pin GPIO_PIN_5
#define ENC1_B_GPIO_Port GPIOB
#define MODE_BTN_Pin GPIO_PIN_8
#define MODE_BTN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
