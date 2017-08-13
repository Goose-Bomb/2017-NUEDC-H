#pragma once
#include <stm32f4xx_hal.h>

#define TRRIGER_HIGH	GPIOG->BSRR = GPIO_PIN_6
#define TRRIGER_LOW		GPIOG->BSRR = (uint32_t)GPIO_PIN_6	<< 16U

#define GRID_X			40
#define GRID_Y			10
#define GRID_WIDTH		500
#define GRID_HEIGHT		400

static const uint8_t* StatusTag[4] = { "��Ƶ���", "����ɨƵ", "��Ƶ����","�ȴ�ָ��" };

static const uint8_t* StatusLabel[4][3] = {
	{ "˥���ȼ�", "���Ƶ��", "" },
	{ "�ο���ƽ", "Ƶ�ʲ���", "" },
	{ "�ο���ƽ", "Ƶ�ʵ�", "������" },
	{ "", "", "" },
};

typedef enum {
	FREQ_POINT_OUTPUT, LINEAR_FREQ_SWEEP, CURVE_TRACE, CHI_GUA
} RUN_STATUS;


void FreqSweep_Init(void);
void FreqSweep_Test(void);

void FreqSweep_Start(void);
void FreqPoint_Output(void);


void Curve_Trace(void);
static void Curve_Trace_DrawLine(void);
static void Curve_Trace_RecoverLine(void);

static void Update_StatusDisplay(uint8_t status);
static inline void Draw_Curve(uint16_t Color);
static inline void Recover_Grid(void);
static inline void Recover_GridPixel(uint16_t x0, uint16_t y0);
