/**
 * @file     main.c
 * @brief    Testing ADF4351 driver
 * @version  V0.00
 * @date     18. January 2016
 *
 * @note
 *
 */

#include "stm32f0xx.h"                  // Device header
#include "adf4351.h"



int main(void)
{
  static uint32_t reg0, reg1;  // static... Avoid compiler optimisation for checking values with debugger
	double calcfreq;
	#define ADF_REGISTERS_COUNT 	6
	#define RFINfreq    	100 //MHz
	#define RFout		1575.42 //MHz GPS central
	
	ADF4351_ClearRegisterBuf();
	ADF4351_Init();
	ADF4351_Reg1.b.Prescaler = ADF4351_PRESCALER_8_9;

	ADF4351_Reg2.b.RCountVal = 4;
	ADF4351_Reg2.b.CPCurrent = ADF4351_CPCURRENT_2_50;
	ADF4351_Reg2.b.RDiv2 = ADF4351_REFDIV_1;
	ADF4351_Reg2.b.RMul2 = ADF4351_REFMUL_1;
	ADF4351_Reg2.b.PhasePolarity = ADF4351_POLARITY_POSITIVE;

	ADF4351_Reg4.b.OutEnable = 1;
	ADF4351_Reg4.b.Feedback = ADF4351_FEEDBACK_DIVIDED;
	ADF4351_Reg4.b.OutPower = ADF4351_POWER_MINUS4DB;

	ADF4351_Reg5.b.LdPinMode = ADF4351_LD_PIN_DIGITAL_LOCK;

	UpdateFrequencyRegisters(RFout * 1000000.0, RFINfreq * 1000000.0, 10000.0, 0, 1, &calcfreq);
	uint32_t registers[ADF_REGISTERS_COUNT] = { 
		ADF4351_Reg0.w, 
		ADF4351_Reg1.w, 
		ADF4351_Reg2.w, 
		ADF4351_Reg3.w, 
		ADF4351_Reg4.w, 
		ADF4351_Reg5.w
	};
	
	while (1);
	
}


