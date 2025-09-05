/*
 * SPIComm.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "SPIComm.h"
#include "HLD336WA_State.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
extern const SPIComm_ll_drv_t SPIComm_ll_drv_stm;
/* Private function declaration ----------------------------------------------*/

/* Public functions definition -----------------------------------------------*/

ErrorStatus SPIComm_Init(void)
{
	return SPIComm_ll_drv_stm.Init( NULL );
}

uint32_t SPIComm_GetAnodes(uint8_t grid)
{
	if ( grid > 7 )
	{
		return 0;
	}

	return SPIComm_ll_drv_stm.GetAnodes( grid );
}

ErrorStatus SPIComm_ProcessingTask(void)
{
	for ( uint8_t i = 0; i < 8; i++ )
	{
		uint32_t val = SPIComm_GetAnodes( i );
		HLD336WA_State_SetAnodes( i, val );
	}

	return SUCCESS;
}

/* Private functions definition ----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
