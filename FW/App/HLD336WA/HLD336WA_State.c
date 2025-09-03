/*
 * HLD336WA_State.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "HLD336WA_State.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static ScreenAnode_u _screenState[8];
/* Private function declaration ----------------------------------------------*/

/* Public functions definition -----------------------------------------------*/

void HLD336WA_State_SetAnodes(uint8_t grid, uint32_t val)
{
	if ( grid > 7 )
	{
		return;
	}

	_screenState[grid].Val = val;
}

uint32_t HLD336WA_State_GetAnodes(uint8_t grid)
{
	if ( grid > 7 )
	{
		return 0;
	}

	return _screenState[grid].Val;
}

/* Private functions definition ----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
