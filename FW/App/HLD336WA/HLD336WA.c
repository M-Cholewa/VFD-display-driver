/*
 * HLD336WA.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "HLD336WA.h"
#include "AssertUtils.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function declaration ----------------------------------------------*/

/* Public functions definition -----------------------------------------------*/

ErrorStatus HLD336WA_Init(HLD336WA_Dev_t *const _pDev, const HLD336WA_ll_drv_t *const _ll_drv, void *_arg)
{
	ASSERT_PARAM( "_pDev != NULL", _pDev != NULL );

	_pDev->arg = _arg;
	_pDev->ll_drv = _ll_drv; /* Assign low-level driver */

	if ( _pDev->ll_drv->Init( _pDev->arg ) != SUCCESS )
	{ /* Init low-level directly */
		return ERROR;
	}

	_pDev->initFlag = SET;

	return SUCCESS;
}

ErrorStatus HLD336WA_SetAllOn(HLD336WA_Dev_t *const _pDev)
{
	if ( _pDev->initFlag != SET )
	{
		return ERROR;
	}
	_pDev->ll_drv->SetAllOn();
	return SUCCESS;
}

ErrorStatus HLD336WA_SetAllOff(HLD336WA_Dev_t *const _pDev)
{
	if ( _pDev->initFlag != SET )
	{
		return ERROR;
	}
	_pDev->ll_drv->SetAllOff();
	return SUCCESS;
}

ErrorStatus HLD336WA_SetGrids(HLD336WA_Dev_t *const _pDev, uint8_t grids)
{
	if ( _pDev->initFlag != SET )
	{
		return ERROR;
	}
	_pDev->ll_drv->SetGrids( grids );
	return SUCCESS;
}

ErrorStatus HLD336WA_SetAnodes(HLD336WA_Dev_t *const _pDev, uint32_t anodes)
{
	if ( _pDev->initFlag != SET )
	{
		return ERROR;
	}
	_pDev->ll_drv->SetAnodes( anodes );
	return SUCCESS;
}

/* Private functions definition ----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
