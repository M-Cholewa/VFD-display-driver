/*
 * HLD336WA.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

#ifndef HLD336WA_INC_HLD336WA_C_
#define HLD336WA_INC_HLD336WA_C_

#ifdef __cplusplus // plik.h
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx.h"

/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/
typedef struct
{
	ErrorStatus (*Init)(void *arg);
	ErrorStatus (*Deinit)(void *arg);
	void (*SetAllOn)(void);
	void (*SetAllOff)(void);
	void (*SetGrids)(uint8_t grids);
	void (*SetAnodes)(uint32_t anodes);
} HLD336WA_ll_drv_t;

typedef struct
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	void *arg; /*!< User custom argument */
	const HLD336WA_ll_drv_t *ll_drv; /*!< Low-level functions driver */
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	FlagStatus initFlag;

} HLD336WA_Dev_t;

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/
ErrorStatus HLD336WA_Init(HLD336WA_Dev_t *const _pDev, const HLD336WA_ll_drv_t *const _ll_drv, void *_arg);
ErrorStatus HLD336WA_SetAllOn(HLD336WA_Dev_t *const _pDev);
ErrorStatus HLD336WA_SetAllOff(HLD336WA_Dev_t *const _pDev);
ErrorStatus HLD336WA_SetGrids(HLD336WA_Dev_t *const _pDev, uint8_t grids);
ErrorStatus HLD336WA_SetAnodes(HLD336WA_Dev_t *const _pDev, uint32_t anodes);

#ifdef __cplusplus // plik.h
}
#endif

#endif /* HLD336WA_INC_HLD336WA_C_ */
