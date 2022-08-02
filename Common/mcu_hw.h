/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  Contains all MCU Registers Definitions     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "platform_Types.h" 

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**************************************
*   NVIC REGISTRE
***************************************/
#define APINT           				  *((volatile uint32*)0xE000ED0C)
	
#define NVIC_BASE_ADDRESS				0xE000E100
#define NVIC_PRI_BASE_ADDRESS			0xE000E400

/**************************************
*   SYSTEM CONTROL REGISTRES
***************************************/
#define SYSCTR_BASE_ADDRESS              0x400FE000
#define RESC							 *((volatile uint32*)0x400FE05C)
#define RCGCGPIO_OFFSET                  0x608
#define RCGCGPIO                         *((volatile uint32*)(SYSCTR_BASE_ADDRESS+RCGCGPIO_OFFSET))

typedef struct 
{
	uint32 MOSCDIS  :1;
	uint32          :3;
	uint32 OSCSRC   :2;
	uint32 XTAL     :5;
	uint32 BYPASS   :1;
	uint32          :1;
	uint32 PWRDN    :1;
	uint32          :3;
	uint32 PWMDIV   :3;
	uint32 USEPWMDIV:1;
	uint32          :1;
	uint32 USESYSDIV:1;
	uint32 SYSDIV   :4;
	uint32 ACG      :1;
	uint32          :4;	
}Mcu_StrBF;

typedef union 
{
	uint32  R;
	Mcu_StrBF B;
}RCC_TAG;

#define RCC									 (*((volatile RCC_TAG*)0x400FE060))	
#define RCC2								 (*((volatile RCC2_TAG*)0x400FE070))
#define PLLSTAT              				   *((volatile uint32*)0x400FE168)
#define SYSCTR_RCG_BASE_ADDR					0x400FE600						


/**************************************
*   GPIO REGISTRE
***************************************/
#define GPIO_APB_BASE_ADDRESS_A          0x40004000
#define GPIO_APB_BASE_ADDRESS_B          0x40005000
#define GPIO_APB_BASE_ADDRESS_C          0x40006000
#define GPIO_APB_BASE_ADDRESS_D          0x40007000
#define GPIO_APB_BASE_ADDRESS_E          0x40024000
#define GPIO_APB_BASE_ADDRESS_F          0x40025000

#define GPIODATA_OFFSET			0x000
#define GPIODIR_OFFSET			0x400
#define GPIOAFSEL_OFFSET		0x420						
#define GPIOLOCK_OFFSET			0x520
#define GPIOCR_OFFSET			0x524
#define GPIOPCTL_OFFSET			0x52C
#define GPIODR2R_OFFSET  	   	0x500
#define GPIODR4R_OFFSET     	0x504
#define GPIODR8R_OFFSET     	0x508
#define GPIOPUR_OFFSET      	0x510
#define GPIOPDR_OFFSET      	0x514
#define GPIOODR_OFFSET      	0x50C
#define GPIOIS_OFFSET			0x404
#define GPIOIBE_OFFSET			0x408
#define GPIOIEV_OFFSET			0x40c
#define GPIOIM_OFFSET			0x410
#define GPIORIS_OFFSET			0x414

/**************************************
*   GPT REGISTRE
***************************************/
#define GPT_16_32_BIT_TIMER0_BASE_ADDRESS					0x40030000
#define	GPT_16_32_BIT_TIMER1_BASE_ADDRESS					0x40031000
#define	GPT_16_32_BIT_TIMER2_BASE_ADDRESS					0x40032000
#define	GPT_16_32_BIT_TIMER3_BASE_ADDRESS					0x40033000
#define	GPT_16_32_BIT_TIMER4_BASE_ADDRESS					0x40034000
#define	GPT_16_32_BIT_TIMER5_BASE_ADDRESS					0x40035000
#define	GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS				0x40036000
#define	GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS				0x40037000
#define	GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS				0x4004C000
#define	GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS				0x4004D000
#define	GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS				0x4004E000
#define	GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS				0x4004F000

#define GPTMCFG_OFFSET					0x000
#define GPTMTAMR_OFFSET					0x004
#define GPTMTBMR_OFFSET					0x008
#define GPTMCTL_OFFSET					0x00C
#define GPTMIMR_OFFSET					0x018
#define GPTMTAV_OFFSET					0x050
#define GPTMTAILR_OFFSET				0x028

/**************************************
*   WDT REGISTRE
***************************************/
#define WDT_0_BASE_ADDRESS			0x40000000
#define WDT_1_BASE_ADDRESS			0x40001000

#define WDTLOAD_OFFSET				0x000
#define WDTCTL_OFFSET				0x008
#define WDTLOCK_OFFSET				0xC00

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GPIODATA(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIODATA_OFFSET))
#define GPIODIR(BaseAddr)           		*((volatile uint32*)(BaseAddr+GPIODIR_OFFSET))
#define GPIOAFSEL(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOAFSEL_OFFSET))	
#define GPIOLOCK(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOLOCK_OFFSET))		
#define GPIOCR(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOCR_OFFSET))
#define GPIOPCTL(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOPCTL_OFFSET))
#define GPIODR2R(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIODR2R_OFFSET))
#define GPIODR4R(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIODR4R_OFFSET))
#define GPIODR8R(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIODR8R_OFFSET))
#define GPIOPUR(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOPUR_OFFSET))
#define GPIOPDR(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOPDR_OFFSET))
#define GPIOODR(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOODR_OFFSET))
#define GPIOIS(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOIS_OFFSET))
#define GPIOIBE(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOIBE_OFFSET))
#define GPIOIEV(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOIEV_OFFSET))
#define GPIOIM(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIOIM_OFFSET))
#define GPIORIS(BaseAddr)					*((volatile uint32*)(BaseAddr+GPIORIS_OFFSET))

#define GET_HWREG(BaseAddress,RegOffset)		*((volatile uint32*)(BaseAddress+RegOffset))
	
#define GPTMCFG(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMCFG_OFFSET))
#define GPTMTAMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAMR_OFFSET))
#define GPTMTBMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTBMR_OFFSET))
#define GPTMCTL(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMCTL_OFFSET))	
#define GPTMIMR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMIMR_OFFSET))
#define GPTMTAV(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAV_OFFSET))
#define GPTMTAILR(BaseAddr)									*((volatile uint32*)(BaseAddr+GPTMTAILR_OFFSET))
																																
#define WDTLOAD(BaseAddr)									*((volatile uint32*)(BaseAddr+WDTLOAD_OFFSET))
#define WDTCTL(BaseAddr)									*((volatile uint32*)(BaseAddr+WDTCTL_OFFSET))
#define WDTLOCK(BaseAddr)									*((volatile uint32*)(BaseAddr+WDTLOCK_OFFSET))
	

#define BASE_ADDRESS_PRE                              0x40000000
#define BASE_ADDRESS_PRE_ALIAS                        0x42000000

#define GET_RegisterOffset(RegisterAddr)              ((RegisterAddr - BASE_ADDRESS_PRE)/4)
#define GET_BitOffset(RegisterAddr,BitPos)            ((GET_RegisterOffset(RegisterAddr)*32) + BitPos)
#define GET_BBAlIAS_PRE_REG(RegisterAddr, BitPos)     (*(volatile uint32*)((GET_BitOffset(RegisterAddr,BitPos)*4) + BASE_ADDRESS_PRE_ALIAS))
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

