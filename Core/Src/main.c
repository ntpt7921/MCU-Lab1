/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct
{
	enum
	{
		RED, YELLOW, GREEN
	} state;
	int timeLeft;
} TrafficLED;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* this is a set of bit, representing the pattern of 7seg LED for each number
 * arranged as follow:
 * 0b	0	0	0	0	0	0	0
 *  	g	f	e	d	c	b	a
 */

#define PATTERN_0 (~((uint8_t)0b0111111))
#define PATTERN_1 (~((uint8_t)0b0000110))
#define PATTERN_2 (~((uint8_t)0b1011011))
#define PATTERN_3 (~((uint8_t)0b1001111))
#define PATTERN_4 (~((uint8_t)0b1100110))
#define PATTERN_5 (~((uint8_t)0b1101101))
#define PATTERN_6 (~((uint8_t)0b1111101))
#define PATTERN_7 (~((uint8_t)0b0000111))
#define PATTERN_8 (~((uint8_t)0b1111111))
#define PATTERN_9 (~((uint8_t)0b1101111))
#define PATTERN_E (~((uint8_t)0b1111001))
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void display7SEG(int counter);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int counter)
{
	switch(counter)
	{
		case 0:
			GPIOA->BSRR = PATTERN_0;
			GPIOA->BSRR = (~(uint32_t)PATTERN_0) << 16u;
			break;
		case 1:
			GPIOA->BSRR = PATTERN_1;
			GPIOA->BSRR = (~(uint32_t)PATTERN_1) << 16u;
			break;
		case 2:
			GPIOA->BSRR = PATTERN_2;
			GPIOA->BSRR = (~(uint32_t)PATTERN_2) << 16u;
			break;
		case 3:
			GPIOA->BSRR = PATTERN_3;
			GPIOA->BSRR = (~(uint32_t)PATTERN_3) << 16u;
			break;
		case 4:
			GPIOA->BSRR = PATTERN_4;
			GPIOA->BSRR = (~(uint32_t)PATTERN_4) << 16u;
			break;
		case 5:
			GPIOA->BSRR = PATTERN_5;
			GPIOA->BSRR = (~(uint32_t)PATTERN_5) << 16u;
			break;
		case 6:
			GPIOA->BSRR = PATTERN_6;
			GPIOA->BSRR = (~(uint32_t)PATTERN_6) << 16u;
			break;
		case 7:
			GPIOA->BSRR = PATTERN_7;
			GPIOA->BSRR = (~(uint32_t)PATTERN_7) << 16u;
			break;
		case 8:
			GPIOA->BSRR = PATTERN_8;
			GPIOA->BSRR = (~(uint32_t)PATTERN_8) << 16u;
			break;
		case 9:
			GPIOA->BSRR = PATTERN_9;
			GPIOA->BSRR = (~(uint32_t)PATTERN_9) << 16u;
			break;
		default:
			GPIOA->BSRR = PATTERN_E;
			GPIOA->BSRR = (~(uint32_t)PATTERN_E) << 16u;
			break;
	}
}

/**
 * @brief  Turn the LED1 to RED
 */
void turnRed1(TrafficLED *led)
{
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	led->state = RED;
	led->timeLeft = 5;
}

/**
 * @brief  Turn the LED1 to YELLOW
 */
void turnYellow1(TrafficLED *led)
{
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, SET);
	led->state = YELLOW;
	led->timeLeft = 2;
}

/**
 * @brief  Turn the LED1 to GREEN
 */
void turnGreen1(TrafficLED *led)
{
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, RESET);
	led->state = GREEN;
	led->timeLeft = 3;
}

/**
 * @brief  Turn the LED2 to RED
 */
void turnRed2(TrafficLED *led)
{
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
	led->state = RED;
	led->timeLeft = 5;
}

/**
 * @brief  Turn the LED2 to YELLOW
 */
void turnYellow2(TrafficLED *led)
{
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
	led->state = YELLOW;
	led->timeLeft = 2;
}

/**
 * @brief  Turn the LED2 to GREEN
 */
void turnGreen2(TrafficLED *led)
{
	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, RESET);
	led->state = GREEN;
	led->timeLeft = 3;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	TrafficLED led1;
	TrafficLED led2;
	turnRed1(&led1);
	turnGreen2(&led2);
	display7SEG(led1.timeLeft);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		HAL_Delay(1000);
		led1.timeLeft--;
		led2.timeLeft--;
		display7SEG(led1.timeLeft);

		if (led1.timeLeft <= 0)
		{
			switch (led1.state)
			{
				case RED:
					turnGreen1(&led1);
					break;
				case GREEN:
					turnYellow1(&led1);
					break;
				case YELLOW:
					turnRed1(&led1);
					break;
				default:
					;
			}
		}

		if (led2.timeLeft <= 0)
		{
			switch (led2.state)
			{
				case RED:
					turnGreen1(&led2);
					break;
				case GREEN:
					turnYellow1(&led2);
					break;
				case YELLOW:
					turnRed1(&led2);
					break;
				default:
					;
			}
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|LED2_RED_Pin|LED2_YELLOW_Pin
                          |LED2_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_RED_Pin|LED1_YELLOW_Pin|LED1_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 LED2_RED_Pin LED2_YELLOW_Pin
                           LED2_GREEN_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|LED2_RED_Pin|LED2_YELLOW_Pin
                          |LED2_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_RED_Pin LED1_YELLOW_Pin LED1_GREEN_Pin */
  GPIO_InitStruct.Pin = LED1_RED_Pin|LED1_YELLOW_Pin|LED1_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
