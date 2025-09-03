/*
 * vScreenTask.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "HLD336WA_Dev.h"
#include "vScreenTask.h"
#include "FreeRTOS.h"
#include "cmsis_os2.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static osThreadId_t ScreenRefreshHandle;

static const osThreadAttr_t ScreenRefresh_attributes = {
  .name = "ScreenRefresh",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

/* Private function declaration ----------------------------------------------*/
static void vScreenRefreshTask(void *argument);

/* Private functions definition ----------------------------------------------*/

/**
 * @brief Function implementing the ScreenRefresh thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartScreenRefreshTask */
static void vScreenRefreshTask(void *argument)
{
	/* USER CODE BEGIN ScreenRefresh */
	/* Infinite loop */
	for ( ;; )
	{
		HLD336WADev_ProcessingTask();
		osDelay( 1 );
	}
	/* USER CODE END ScreenRefresh */
}

/* Public functions definition -----------------------------------------------*/
void vScreenRefreshTask_Setup(void *argument)
{
	ScreenRefreshHandle = osThreadNew( vScreenRefreshTask, NULL, &ScreenRefresh_attributes );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
