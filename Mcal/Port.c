
#include "Port.h"
#include "mcu_hw.h"
#include "portCfg.h"

#define PORT_SIZE 			8u
#define NUMBER_OF_PORTS		6u

static const PortBaseAdd[NUMBER_OF_PORTS] = {
	GPIO_APB_BASE_ADDRESS_A,
	GPIO_APB_BASE_ADDRESS_B,
	GPIO_APB_BASE_ADDRESS_C,
	GPIO_APB_BASE_ADDRESS_D,
	GPIO_APB_BASE_ADDRESS_E,
	GPIO_APB_BASE_ADDRESS_F};
	
	
void Port_Init( const Port_ConfigType *ConfigPtr)
{
	for(int i=0;i<NUMBER_OF_ACTIVATED_PINS;i++)
	{
		uint8 pinIndex = ConfigPtr[i].pinId % PORT_SIZE ;
		uint8 portIndex = ConfigPtr[i]. pinId / PORT_SIZE;
		
		uint32 portAdd = PortBaseAdd[portIndex];

		
			/*		Setting Direction 		*/
		if(ConfigPtr [i]. pinDir == OUTPUT)
		{
			GPIODIR(portAdd)|=(1<<pinIndex);
		}
		else
		{
			GPIODIR(portAdd)&=~(1<<pinIndex);
		}
		
		/*		Setting Internal Attach 		*/
		if(ConfigPtr[i].internallAttach == PULLUP)
		{
			GPIOPUR(portAdd)|=(1<<pinIndex);
		}
		else if (ConfigPtr[i].internallAttach == PULLDOWN)
		{
			GPIOPUR(portAdd)|=(1<<pinIndex);
		}
		else if (ConfigPtr[i].internallAttach == OPEN_DRAIN)
		{
			GPIOODR(portAdd) |= (1 << pinIndex);
		}
		
		/*		Setting Pin Current 		*/
		if(ConfigPtr[i].outputCurrent == TWO_mA)
		{
			GPIODR2R(portAdd) |= (1 << pinIndex);
		}
		else if(ConfigPtr[i].outputCurrent == FOUR_mA)
		{
			GPIODR4R(portAdd) |= (1 << pinIndex);
		}
		else if(ConfigPtr[i].outputCurrent == EIGHT_mA)
		{
			GPIODR8R(portAdd) |= (1 << pinIndex);
		}
	}
	
}
