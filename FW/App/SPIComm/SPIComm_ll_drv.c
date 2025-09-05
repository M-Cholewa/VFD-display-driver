/*
 * SPIComm_ll_drv.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Mateusz
 */

/********************** NOTES *************************************************
 ...
 *******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "cmsis_os2.h"
#include "SPIComm.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/* Private define ------------------------------------------------------------*/
#define SPI1_CS_Pin 			GPIO_PIN_1
#define SPI1_CS_GPIO_Port 		GPIOA
#define FRAME_SIZE_B			(4 * 8) // 8 grids, 4 bytes (20 segments)

/* Private macros ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private function declaration ----------------------------------------------*/

static void MX_GPDMA1_Init(void);
static void MX_SPI1_Init(void);
static ErrorStatus _Init(void *arg);
static ErrorStatus _Deinit(void *arg);
static uint32_t _GetAnodes(uint8_t grid);

/* Private variables ---------------------------------------------------------*/
static SPI_HandleTypeDef hspi1;
static DMA_HandleTypeDef handle_GPDMA1_Channel0;
static uint8_t _rxBuffer[FRAME_SIZE_B];

const SPIComm_ll_drv_t SPIComm_ll_drv_stm =
{
	.Init = _Init,
	.Deinit = _Deinit,
	.GetAnodes = _GetAnodes,
};

/* Public functions definition -----------------------------------------------*/

/* Private functions definition ----------------------------------------------*/
static ErrorStatus _Init(void *arg)
{
	MX_GPDMA1_Init();
	MX_SPI1_Init();
	HAL_SPI_Receive_DMA( &hspi1, _rxBuffer, FRAME_SIZE_B );

	return SUCCESS;
}

static ErrorStatus _Deinit(void *arg)
{
	return SUCCESS;
}

static uint32_t _GetAnodes(uint8_t grid)
{
	if ( grid > 7 )
	{
		return 0;
	}

	return ( ( uint32_t* ) _rxBuffer )[grid];
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if ( hspi->Instance == SPI1 )
	{
		HAL_SPI_Receive_DMA( &hspi1, _rxBuffer, FRAME_SIZE_B );
	}
}

/**
 * @brief GPDMA1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPDMA1_Init(void)
{
	__HAL_RCC_GPDMA1_CLK_ENABLE( );

	HAL_NVIC_SetPriority( GPDMA1_Channel0_IRQn, 5, 0 );
	HAL_NVIC_EnableIRQ( GPDMA1_Channel0_IRQn );
}

/**
 * @brief SPI1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_SPI1_Init(void)
{
	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_SLAVE;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_HARD_INPUT;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 0x7;
	hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
	hspi1.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
	hspi1.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
	hspi1.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
	hspi1.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
	hspi1.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
	hspi1.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
	hspi1.Init.IOSwap = SPI_IO_SWAP_DISABLE;
	hspi1.Init.ReadyMasterManagement = SPI_RDY_MASTER_MANAGEMENT_INTERNALLY;
	hspi1.Init.ReadyPolarity = SPI_RDY_POLARITY_HIGH;
	if ( HAL_SPI_Init( &hspi1 ) != HAL_OK )
	{
		Error_Handler();
	}
}

/**
 * Initializes the Global MSP.
 */
void HAL_MspInit(void)
{
	HAL_NVIC_SetPriority( PendSV_IRQn, 15, 0 );
}

/**
 * @brief SPI MSP Initialization
 * This function configures the hardware resources used in this example
 * @param hspi: SPI handle pointer
 * @retval None
 */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{
		0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct =
	{
		0 };
	if ( hspi->Instance == SPI1 )
	{

		/** Initializes the peripherals clock
		 */
		PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI1;
		PeriphClkInitStruct.Spi1ClockSelection = RCC_SPI1CLKSOURCE_PLL1Q;
		if ( HAL_RCCEx_PeriphCLKConfig( &PeriphClkInitStruct ) != HAL_OK )
		{
			Error_Handler();
		}

		__HAL_RCC_SPI1_CLK_ENABLE( );

		__HAL_RCC_GPIOA_CLK_ENABLE( );
		/**SPI1 GPIO Configuration
		 PA0     ------> SPI1_MISO
		 PA1     ------> SPI1_NSS
		 PA2     ------> SPI1_SCK
		 PA4     ------> SPI1_MOSI
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF12_SPI1;
		HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

		GPIO_InitStruct.Pin = SPI1_CS_Pin | GPIO_PIN_2 | GPIO_PIN_4;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF4_SPI1;
		HAL_GPIO_Init( GPIOA, &GPIO_InitStruct );

		handle_GPDMA1_Channel0.Instance = GPDMA1_Channel0;
		handle_GPDMA1_Channel0.Init.Request = GPDMA1_REQUEST_SPI1_RX;
		handle_GPDMA1_Channel0.Init.BlkHWRequest = DMA_BREQ_SINGLE_BURST;
		handle_GPDMA1_Channel0.Init.Direction = DMA_PERIPH_TO_MEMORY;
		handle_GPDMA1_Channel0.Init.SrcInc = DMA_SINC_FIXED;
		handle_GPDMA1_Channel0.Init.DestInc = DMA_DINC_INCREMENTED;
		handle_GPDMA1_Channel0.Init.SrcDataWidth = DMA_SRC_DATAWIDTH_BYTE;
		handle_GPDMA1_Channel0.Init.DestDataWidth = DMA_DEST_DATAWIDTH_BYTE;
		handle_GPDMA1_Channel0.Init.Priority = DMA_LOW_PRIORITY_LOW_WEIGHT;
		handle_GPDMA1_Channel0.Init.SrcBurstLength = 1;
		handle_GPDMA1_Channel0.Init.DestBurstLength = 1;
		handle_GPDMA1_Channel0.Init.TransferAllocatedPort = DMA_SRC_ALLOCATED_PORT0 | DMA_DEST_ALLOCATED_PORT0;
		handle_GPDMA1_Channel0.Init.TransferEventMode = DMA_TCEM_BLOCK_TRANSFER;
		handle_GPDMA1_Channel0.Init.Mode = DMA_NORMAL;
		if ( HAL_DMA_Init( &handle_GPDMA1_Channel0 ) != HAL_OK )
		{
			Error_Handler();
		}

		__HAL_LINKDMA( hspi, hdmarx, handle_GPDMA1_Channel0 );

		if ( HAL_DMA_ConfigChannelAttributes( &handle_GPDMA1_Channel0, DMA_CHANNEL_NPRIV ) != HAL_OK )
		{
			Error_Handler();
		}

		HAL_NVIC_SetPriority( SPI1_IRQn, 5, 0 );
		HAL_NVIC_EnableIRQ( SPI1_IRQn );

	}

}

/**
 * @brief SPI MSP De-Initialization
 * This function freeze the hardware resources used in this example
 * @param hspi: SPI handle pointer
 * @retval None
 */
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi)
{
	if ( hspi->Instance == SPI1 )
	{

		__HAL_RCC_SPI1_CLK_DISABLE( );

		/**SPI1 GPIO Configuration
		 PA0     ------> SPI1_MISO
		 PA1     ------> SPI1_NSS
		 PA2     ------> SPI1_SCK
		 PA4     ------> SPI1_MOSI
		 */
		HAL_GPIO_DeInit( GPIOA, GPIO_PIN_0 | SPI1_CS_Pin | GPIO_PIN_2 | GPIO_PIN_4 );

		HAL_DMA_DeInit( hspi->hdmarx );

		HAL_NVIC_DisableIRQ( SPI1_IRQn );

	}
}

/**
 * @brief This function handles SPI1 global interrupt.
 */
void SPI1_IRQHandler(void)
{
	HAL_SPI_IRQHandler( &hspi1 );
}

/**
 * @brief This function handles GPDMA1 Channel 0 global interrupt.
 */
void GPDMA1_Channel0_IRQHandler(void)
{
	HAL_DMA_IRQHandler( &handle_GPDMA1_Channel0 );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
