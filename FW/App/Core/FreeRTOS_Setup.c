/*
 * FreeRTOS_Setup.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "vScreenTask.h"
#include "FreeRTOS_Setup.h"
#include "cmsis_os2.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function declaration ----------------------------------------------*/
static void FreeRTOSTasksCreate(void);

/* Public functions definition -----------------------------------------------*/
void InitFreeRTOS(void)
{
	osKernelInitialize();

	FreeRTOSTasksCreate();

	osKernelStart();

}

/* Private functions definition ----------------------------------------------*/
static void FreeRTOSTasksCreate(void)
{
	vScreenRefreshTask_Setup( NULL );
	vSPICommTask_Setup( NULL );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
