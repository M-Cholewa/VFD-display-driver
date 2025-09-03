/*
 * HLD336WA_ll_drv.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "HLD336WA.h"
#include "stm32h5xx_hal.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/
#define IO24_Pin GPIO_PIN_13
#define IO24_GPIO_Port GPIOC
#define IO25_Pin GPIO_PIN_14
#define IO25_GPIO_Port GPIOC
#define IO26_Pin GPIO_PIN_15
#define IO26_GPIO_Port GPIOC
#define IO27_Pin GPIO_PIN_0
#define IO27_GPIO_Port GPIOH
#define IO28_Pin GPIO_PIN_1
#define IO28_GPIO_Port GPIOH
#define IO1_Pin GPIO_PIN_3
#define IO1_GPIO_Port GPIOA
#define IO2_Pin GPIO_PIN_5
#define IO2_GPIO_Port GPIOA
#define IO3_Pin GPIO_PIN_6
#define IO3_GPIO_Port GPIOA
#define IO4_Pin GPIO_PIN_7
#define IO4_GPIO_Port GPIOA
#define IO11_Pin GPIO_PIN_0
#define IO11_GPIO_Port GPIOB
#define IO12_Pin GPIO_PIN_1
#define IO12_GPIO_Port GPIOB
#define IO13_Pin GPIO_PIN_2
#define IO13_GPIO_Port GPIOB
#define IO19_Pin GPIO_PIN_10
#define IO19_GPIO_Port GPIOB
#define IO20_Pin GPIO_PIN_12
#define IO20_GPIO_Port GPIOB
#define IO21_Pin GPIO_PIN_13
#define IO21_GPIO_Port GPIOB
#define IO22_Pin GPIO_PIN_14
#define IO22_GPIO_Port GPIOB
#define IO23_Pin GPIO_PIN_15
#define IO23_GPIO_Port GPIOB
#define IO5_Pin GPIO_PIN_8
#define IO5_GPIO_Port GPIOA
#define IO6_Pin GPIO_PIN_9
#define IO6_GPIO_Port GPIOA
#define IO7_Pin GPIO_PIN_10
#define IO7_GPIO_Port GPIOA
#define IO8_Pin GPIO_PIN_11
#define IO8_GPIO_Port GPIOA
#define IO9_Pin GPIO_PIN_12
#define IO9_GPIO_Port GPIOA
#define IO10_Pin GPIO_PIN_15
#define IO10_GPIO_Port GPIOA
#define IO14_Pin GPIO_PIN_4
#define IO14_GPIO_Port GPIOB
#define IO15_Pin GPIO_PIN_5
#define IO15_GPIO_Port GPIOB
#define IO16_Pin GPIO_PIN_6
#define IO16_GPIO_Port GPIOB
#define IO17_Pin GPIO_PIN_7
#define IO17_GPIO_Port GPIOB
#define IO18_Pin GPIO_PIN_8
#define IO18_GPIO_Port GPIOB

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private function declaration ----------------------------------------------*/

static ErrorStatus _Init(void *arg);
static ErrorStatus _Deinit(void *arg);
static void _SetAllOn(void);
static void _SetAllOff(void);
static void _SetGrids(uint8_t grids);
static void _SetAnodes(uint32_t anodes);
static ErrorStatus _GPIO_Init(void);

/* Private constants ---------------------------------------------------------*/
const HLD336WA_ll_drv_t HLD336WA_ll_drv_stm =
{
	.Init = _Init,
	.Deinit = _Deinit,
	.SetAllOn = _SetAllOn,
	.SetAllOff = _SetAllOff,
	.SetGrids = _SetGrids,
	.SetAnodes = _SetAnodes, };

/* Private variables ---------------------------------------------------------*/

/* Private functions definition ----------------------------------------------*/

static ErrorStatus _Init(void *arg)
{
	ErrorStatus status = _GPIO_Init();
	_SetAllOff();

	return status;

}

static ErrorStatus _Deinit(void *arg)
{
	return SUCCESS;
}

/*
 *
 * NOTE!!!!!!!!!!!
 * LOGIC IS FLIPPED (PULL OP ON VFD LINE)
 * THAT'S WHY I CONVERT TRUE=FALSE HERE
 *
 * */

static void _SetAllOn(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA, IO1_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO2_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO3_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO4_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO5_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO6_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO7_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO8_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO9_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOA, IO10_Pin, GPIO_PIN_RESET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOB, IO11_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO12_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO13_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO14_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO15_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO16_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO17_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO18_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO19_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO20_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO21_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO22_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB, IO23_Pin, GPIO_PIN_RESET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOC, IO24_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOC, IO25_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOC, IO26_Pin, GPIO_PIN_RESET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOH, IO27_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOH, IO28_Pin, GPIO_PIN_RESET );
}

static void _SetAllOff(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA, IO1_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO2_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO3_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO4_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO5_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO6_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO7_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO8_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO9_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOA, IO10_Pin, GPIO_PIN_SET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOB, IO11_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO12_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO13_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO14_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO15_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO16_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO17_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO18_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO19_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO20_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO21_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO22_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB, IO23_Pin, GPIO_PIN_SET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOC, IO24_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOC, IO25_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOC, IO26_Pin, GPIO_PIN_SET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOH, IO27_Pin, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOH, IO28_Pin, GPIO_PIN_SET );
}

static void _SetGrids(uint8_t grids)
{

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA, IO1_Pin, ( 1 & ( ~grids >> 0 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO2_Pin, ( 1 & ( ~grids >> 1 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO3_Pin, ( 1 & ( ~grids >> 2 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO4_Pin, ( 1 & ( ~grids >> 3 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO5_Pin, ( 1 & ( ~grids >> 4 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO6_Pin, ( 1 & ( ~grids >> 5 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO7_Pin, ( 1 & ( ~grids >> 6 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO8_Pin, ( 1 & ( ~grids >> 7 ) ) );

}

static void _SetAnodes(uint32_t anodes)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA, IO9_Pin, ( 1 & ( ~anodes >> 0 ) ) );
	HAL_GPIO_WritePin( GPIOA, IO10_Pin, ( 1 & ( ~anodes >> 1 ) ) );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOB, IO11_Pin, ( 1 & ( ~anodes >> 2 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO12_Pin, ( 1 & ( ~anodes >> 3 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO13_Pin, ( 1 & ( ~anodes >> 4 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO14_Pin, ( 1 & ( ~anodes >> 5 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO15_Pin, ( 1 & ( ~anodes >> 6 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO16_Pin, ( 1 & ( ~anodes >> 7 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO17_Pin, ( 1 & ( ~anodes >> 8 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO18_Pin, ( 1 & ( ~anodes >> 9 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO19_Pin, ( 1 & ( ~anodes >> 10 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO20_Pin, ( 1 & ( ~anodes >> 11 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO21_Pin, ( 1 & ( ~anodes >> 12 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO22_Pin, ( 1 & ( ~anodes >> 13 ) ) );
	HAL_GPIO_WritePin( GPIOB, IO23_Pin, ( 1 & ( ~anodes >> 14 ) ) );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOC, IO24_Pin, ( 1 & ( ~anodes >> 15 ) ) );
	HAL_GPIO_WritePin( GPIOC, IO25_Pin, ( 1 & ( ~anodes >> 16 ) ) );
	HAL_GPIO_WritePin( GPIOC, IO26_Pin, ( 1 & ( ~anodes >> 17 ) ) );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOH, IO27_Pin, ( 1 & ( ~anodes >> 18 ) ) );
	HAL_GPIO_WritePin( GPIOH, IO28_Pin, ( 1 & ( ~anodes >> 19 ) ) );
}

static ErrorStatus _GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{
		0 };
	/* USER CODE BEGIN MX_GPIO_Init_1 */

	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE( );
	__HAL_RCC_GPIOH_CLK_ENABLE( );
	__HAL_RCC_GPIOA_CLK_ENABLE( );
	__HAL_RCC_GPIOB_CLK_ENABLE( );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOC, IO24_Pin | IO25_Pin | IO26_Pin, GPIO_PIN_SET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOH, IO27_Pin | IO28_Pin, GPIO_PIN_SET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA, IO1_Pin | IO2_Pin | IO3_Pin | IO4_Pin | IO5_Pin | IO6_Pin | IO7_Pin | IO8_Pin | IO9_Pin | IO10_Pin, GPIO_PIN_SET );

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOB,
	IO11_Pin | IO12_Pin | IO13_Pin | IO19_Pin | IO20_Pin | IO21_Pin | IO22_Pin | IO23_Pin | IO14_Pin | IO15_Pin | IO16_Pin | IO17_Pin | IO18_Pin,
			GPIO_PIN_SET );

	/*Configure GPIO pins : IO24_Pin IO25_Pin IO26_Pin */
	GPIO_InitStruct.Pin = IO24_Pin | IO25_Pin | IO26_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( GPIOC, &GPIO_InitStruct );

	/*Configure GPIO pins : IO27_Pin IO28_Pin */
	GPIO_InitStruct.Pin = IO27_Pin | IO28_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( GPIOH, &GPIO_InitStruct );

	/*Configure GPIO pins : IO1_Pin IO2_Pin IO3_Pin IO4_Pin
	 IO5_Pin IO6_Pin IO7_Pin IO8_Pin
	 IO9_Pin IO10_Pin */
	GPIO_InitStruct.Pin = IO1_Pin | IO2_Pin | IO3_Pin | IO4_Pin | IO5_Pin | IO6_Pin | IO7_Pin | IO8_Pin | IO9_Pin | IO10_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

	/*Configure GPIO pins : IO11_Pin IO12_Pin IO13_Pin IO19_Pin
	 IO20_Pin IO21_Pin IO22_Pin IO23_Pin
	 IO14_Pin IO15_Pin IO16_Pin IO17_Pin
	 IO18_Pin */
	GPIO_InitStruct.Pin = IO11_Pin | IO12_Pin | IO13_Pin | IO19_Pin | IO20_Pin | IO21_Pin | IO22_Pin | IO23_Pin | IO14_Pin | IO15_Pin | IO16_Pin
			| IO17_Pin | IO18_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( GPIOB, &GPIO_InitStruct );

	return SUCCESS;
}

/* Public functions definition -----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
