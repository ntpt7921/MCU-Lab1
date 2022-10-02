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
/* USER CODE END 0 *

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

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	int counter = 0;
	while (1)
	{
		if (counter >= 10)
			counter = 0;
		display7SEG(counter++);
		HAL_Delay(1000);
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
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

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
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
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
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
			SEG_A_Pin | SEG_B_Pin | SEG_C_Pin | SEG_D_Pin | SEG_E_Pin
					| SEG_F_Pin | SEG_G_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin SEG_D_Pin
	 SEG_E_Pin SEG_F_Pin SEG_G_Pin */
	GPIO_InitStruct.Pin = SEG_A_Pin | SEG_B_Pin | SEG_C_Pin | SEG_D_Pin
			| SEG_E_Pin | SEG_F_Pin | SEG_G_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
