#include "dma.h"

//DMA_HandleTypeDef hdma_spi2_rx;
//DMA_HandleTypeDef hdma_spi2_tx;

DMA_HandleTypeDef hdma_uart1_rx;
DMA_HandleTypeDef hdma_uart1_tx;

DMA_HandleTypeDef hdma_usart3_tx;

DMA_HandleTypeDef hdma_sdio_rx;

DMA_HandleTypeDef hdma_adc1;
//DMA_HandleTypeDef hdma_external_adc;

DMA_HandleTypeDef hdma_dac;

DMA_HandleTypeDef hdma_m2m;

void DMA_Init(void)
{
	/* DMA controller clock enable */
	__HAL_RCC_DMA1_CLK_ENABLE();
	__HAL_RCC_DMA2_CLK_ENABLE();

	/* Configure DMA request hdma_m2m on DMA2_Stream1 */
	hdma_m2m.Instance = DMA2_Stream1;
	hdma_m2m.Init.Channel = DMA_CHANNEL_0;
	hdma_m2m.Init.Direction = DMA_MEMORY_TO_MEMORY;
	hdma_m2m.Init.PeriphInc = DMA_PINC_ENABLE;
	hdma_m2m.Init.MemInc = DMA_MINC_DISABLE;
	hdma_m2m.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	hdma_m2m.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
	hdma_m2m.Init.Mode = DMA_CIRCULAR;
	hdma_m2m.Init.Priority = DMA_PRIORITY_HIGH;
	hdma_m2m.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
	hdma_m2m.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
	hdma_m2m.Init.MemBurst = DMA_MBURST_INC4;
	hdma_m2m.Init.PeriphBurst = DMA_MBURST_INC4;
	if (HAL_DMA_Init(&hdma_m2m) != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	/* DMA interrupt init */

//	HAL_NVIC_SetPriority(DMA1_Stream2_IRQn, 0, 0);
//	HAL_NVIC_EnableIRQ(DMA1_Stream2_IRQn);

	HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 0, 2);
	HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);

	HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);

	/* DMA2_Stream2_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);
	/* DMA2_Stream3_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
	/* DMA2_Stream4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream4_IRQn);
	/* DMA2_Stream7_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);
}

/*
void DMA1_Stream2_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_external_adc);
}*/

void DMA1_Stream3_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_usart3_tx);
}

/*
void DMA1_Stream4_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_spi2_tx);
}*/

void DMA1_Stream5_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_dac);
}

void DMA2_Stream2_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_uart1_rx);
}

void DMA2_Stream3_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_sdio_rx);
}

void DMA2_Stream4_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_adc1);
}

void DMA2_Stream7_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_uart1_tx);
}
