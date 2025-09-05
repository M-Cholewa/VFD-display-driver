/*
 * vSPICommTask.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Mateusz
 */


/********************** NOTES *************************************************
...
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "SPIComm.h"
#include "vSPICommTask.h"
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
static osThreadId_t SPICommHandle;

static const osThreadAttr_t SPIComm_attributes = {
  .name = "SPIComm",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

/* Private function declaration ----------------------------------------------*/
static void vSPICommTask(void *argument);

/* Private functions definition ----------------------------------------------*/

/**
 * @brief Function implementing the SPIComm thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartSPICommTask */
static void vSPICommTask(void *argument)
{
	/* USER CODE BEGIN SPIComm */
	/* Infinite loop */
	for ( ;; )
	{
		SPIComm_ProcessingTask();
		osDelay( 10 );
	}
	/* USER CODE END SPIComm */
}

/* Public functions definition -----------------------------------------------*/
void vSPICommTask_Setup(void *argument)
{
	SPICommHandle = osThreadNew( vSPICommTask, NULL, &SPIComm_attributes );
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
