/*
 * HLD336WA_Dev.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "HLD336WA_Dev.h"
#include "HLD336WA_State.h"
#include "HLD336WA_Segm.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

extern const HLD336WA_ll_drv_t HLD336WA_ll_drv_stm;
static HLD336WA_Dev_t HLD336WA_Dev;

static uint8_t displayedGrid = 0;

/* Private function declaration ----------------------------------------------*/

/* Public functions definition -----------------------------------------------*/
ErrorStatus HLD336WADev_Init(void)
{
	HLD336WA_State_SetAnodes(7, FourteenSegmentASCII['P']);
	HLD336WA_State_SetAnodes(6, FourteenSegmentASCII['I']);
	HLD336WA_State_SetAnodes(5, FourteenSegmentASCII['W']);
	HLD336WA_State_SetAnodes(4, FourteenSegmentASCII['O']);
	HLD336WA_State_SetAnodes(3, FourteenSegmentASCII['\0']);
	HLD336WA_State_SetAnodes(2, FourteenSegmentASCII['\0']);
	HLD336WA_State_SetAnodes(1, FourteenSegmentASCII['\0']);
	HLD336WA_State_SetAnodes(0, FourteenSegmentASCII['\0']);
	return HLD336WA_Init(&HLD336WA_Dev, &HLD336WA_ll_drv_stm, NULL);
}

ErrorStatus HLD336WADev_ProcessingTask(void)
{
	displayedGrid %= 8;

	uint32_t anodes = HLD336WA_State_GetAnodes(displayedGrid);

	HLD336WA_SetGrids(&HLD336WA_Dev, 1 << displayedGrid);
	HLD336WA_SetAnodes(&HLD336WA_Dev, anodes);

	displayedGrid += 1;

	return SUCCESS;
}

/* Private functions definition ----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
