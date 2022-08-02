/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*
typedef uint8	Dio_ChannelType
#define Channel0_ID			0
#define Channel1_ID			1
#define Channel2_ID			2
#define Channel3_ID			3
#define Channel4_ID			4
#define Channel5_ID			5
#define Channel6_ID			6
#define Channel7_ID			7
*/ 

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


typedef enum
{
	Channel_A0=0,
	Channel_A1,
	Channel_A2,
	Channel_A3,
	Channel_A4,
	Channel_A5,
	Channel_A6,
	Channel_A7,
	
	Channel_B0,
	Channel_B1,
	Channel_B2,
	Channel_B3,
	Channel_B4,
	Channel_B5,
	Channel_B6,
	Channel_B7,
	
	Channel_C0,
	Channel_C1,
	Channel_C2,
	Channel_C3,
	Channel_C4,
	Channel_C5,
	Channel_C6,
	Channel_C7,
	
	Channel_D0,
	Channel_D1,
	Channel_D2,
	Channel_D3,
	Channel_D4,
	Channel_D5,
	Channel_D6,
	Channel_D7,
	
	Channel_E0,
	Channel_E1,
	Channel_E2,
	Channel_E3,
	Channel_E4,
	Channel_E5,
	Channel_E6,
	
	Channel_F0,
	Channel_F1,
	Channel_F2,
	Channel_F3,
	Channel_F4,
	Channel_F5
}Dio_ChannelType;



typedef enum {
	STD_LOW	 = 0,
	STD_HIGH 
}Dio_LevelType;

typedef enum{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
}Dio_PortType;

typedef uint8 Dio_PortLevelType;







 
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
 
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

void Dio_WritePort (Dio_PortType Portld, Dic_PortLevelType Level);

Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);


#endif  /* Dio_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
- *********************************************************************************************************************/

