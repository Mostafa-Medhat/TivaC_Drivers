
#include "Dio.h"
#include "mcu_hw.h"
#include "Bit_Math.h"
#include "platform_Types.h"

#define PORT_SIZE 				8u
#define NUMBER_OF_PORTS			6u

static const uint32 PortBaseAdd[NUMBER_OF_PORTS] = {
	GPIO_APB_BASE_ADDRESS_A,
	GPIO_APB_BASE_ADDRESS_B,
	GPIO_APB_BASE_ADDRESS_C,
	GPIO_APB_BASE_ADDRESS_D,
	GPIO_APB_BASE_ADDRESS_E,
	GPIO_APB_BASE_ADDRESS_F};

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	Dio_LevelType level;
	
	uint8 portIndex = ChannelId / PORT_SIZE;
	uint8 pinID = ChannelId % PORT_SIZE;
	
	uint32 portAdd = PortBaseAdd[portIndex];
	
	
	level = GET_BIT(GPIODATA(portAdd),pinID);
	
	return level;

}
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8 portIndex = ChannelId / PORT_SIZE;
	uint8 pinID = ChannelId % PORT_SIZE;
	
	uint32 portAdd = PortBaseAdd[portIndex];
	
	if(Level==STD_HIGH)
	{
		SET_BIT(GPIODATA(portAdd),pinID);
	}
	else
	{
		CLEAR_BIT(GPIODATA(portAdd),pinID);
	}
		
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
	Dio_PortLevelType portLevel;
	uint32 portAdd = PortBaseAdd[PortId];
	
	portLevel=GPIODATA(portAdd);
	
	return portLevel;
}

void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
	uint32 portAdd = PortBaseAdd[PortId];
	GPIODATA(portAdd) = Level;
}

Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
{
	Dio_LevelType level;
	
	uint8 portIndex = ChannelId / PORT_SIZE;
	uint8 pinID = ChannelId % PORT_SIZE;
	
	uint32 portAdd = PortBaseAdd[portIndex];
	
	TOGGLE_BIT(GPIODATA(portAdd),pinID);
	level = GET_BIT(GPIODATA(portAdd),pinID);
	
	return level;
}


/*******************************************************************
							OLD DESGIN
********************************************************************
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	Dio_LevelType level;
	ChannelId = ChannelId % PORT_SIZE;

	
	if(ChannelId >= Channel_A0 && ChannelId<= Channel_A7)
	{
	level = GET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_A),ChannelId);
	}
	
	else if(ChannelId >= Channel_B0 && ChannelId<= Channel_B7)
	{
		level = GET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_B),ChannelId);
	}
	
	else if(ChannelId >= Channel_C0 && ChannelId<= Channel_C7)
	{
		level = GET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_C),ChannelId);
	}
	
	else if(ChannelId >= Channel_D0 && ChannelId<= Channel_D7)
	{
		level = GET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_D),ChannelId);
	}
	
	else if(ChannelId >= Channel_E0 && ChannelId<= Channel_E6)
	{
		level = GET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_E),ChannelId);
	}
	
	else if(ChannelId >= Channel_F0 && ChannelId<= Channel_F5)
	{
		level = GET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_F),ChannelId);
	}
	
	return level;
}



void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	ChannelId = ChannelId % PORT_SIZE;

	if(ChannelId >= Channel_A0 && ChannelId<= Channel_A7)
	{
		if(Level==STD_HIGH)
		{
			SET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_A),ChannelId);
		}
		else
		{
			CLEAR_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_A),ChannelId);
		}	
	}
	
	else if(ChannelId >= Channel_B0 && ChannelId<= Channel_B7)
	{
		if(Level==STD_HIGH)
		{
			SET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_B),ChannelId);
		}
		else
		{
			CLEAR_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_B),ChannelId);
		}	
	}
	
	else if(ChannelId >= Channel_C0 && ChannelId<= Channel_C7)
	{
		if(Level==STD_HIGH)
		{
			SET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_C),ChannelId);
		}
		else
		{
		CLEAR_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_C),ChannelId);
		}	
	}
	
	else if(ChannelId >= Channel_D0 && ChannelId<= Channel_D7)
	{
		if(Level==STD_HIGH)
		{
			SET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_D),ChannelId);
		}
		else
		{
			CLEAR_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_D),ChannelId);
		}	
	}
	
	else if(ChannelId >= Channel_E0 && ChannelId<= Channel_E7)
	{
		if(Level==STD_HIGH)
		{
			SET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_E),ChannelId);
		}
		else
		{
			CLEAR_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_E),ChannelId);
		}	
	}
	
	else if(ChannelId >= Channel_F0 && ChannelId<= Channel_F7)
	{
		if(Level==STD_HIGH)
		{
			SET_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_F),ChannelId);
		}
		else
		{
			CLEAR_BIT(GPIODATA(GPIO_APB_BASE_ADDRESS_F),ChannelId);
		}	
	}
}
*/
