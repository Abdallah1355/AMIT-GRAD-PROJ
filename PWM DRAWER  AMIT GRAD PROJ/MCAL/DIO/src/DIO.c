/*
 * DIO.c
 *
 * Created: 3/24/2023 3:08:57 PM
 *  Author: abdal
 */ 

#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch(Portx){
		case DIO_PortA:
		if (level == STD_High)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (level == STD_High)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (level == STD_High)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (level == STD_High)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(Portx){
		case DIO_PortA:
		BitValue = GetBit(PINA_Reg,BitNo);
		break;
		case DIO_PortB:
		BitValue = GetBit(PINB_Reg,BitNo);
		break;
		case DIO_PortC:
		BitValue = GetBit(PINC_Reg,BitNo);
		break;
		case DIO_PortD:
		BitValue = GetBit(PIND_Reg,BitNo);
		break;
	}
	return BitValue;
}

void DIO_ToggleChannel(DIO_ChannelTypes channelId){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch(Portx){
		case DIO_PortA:
		ToggleBit(PORTA_Reg,BitNo);
		break;
		case DIO_PortB:
		ToggleBit(PORTB_Reg,BitNo);
		break;
		case DIO_PortC:
		ToggleBit(PORTC_Reg,BitNo);
		break;
		case DIO_PortD:
		ToggleBit(PORTD_Reg,BitNo);
		break;
	}
}

u8 DIO_ReadPort(DIO_PortTypes portId){
	u8 PortValue = STD_Low;
	switch(portId){
		case DIO_PortA:
		PortValue = PORTA_Reg;
		break;
		case DIO_PortB:
		PortValue = PORTB_Reg;
		break;
		case DIO_PortC:
		PortValue = PORTC_Reg;
		break;
		case DIO_PortD:
		PortValue = PORTD_Reg;
		break;
	}
	return PortValue;
}
void DIO_WritePort(DIO_PortTypes portId,u8 data){
	switch(portId){
		case DIO_PortA:
		PORTA_Reg = data;
		break;
		case DIO_PortB:
		PORTB_Reg = data;
		break;
		case DIO_PortC:
		PORTC_Reg = data;
		break;
		case DIO_PortD:
		PORTD_Reg = data;
		break;
	}
}

void DIO_ConfigChannel(DIO_ChannelTypes channelId,DIO_DirTypes direction){
	DIO_PortTypes Portx = channelId/8;
	DIO_ChannelTypes BitNo = channelId%8;
	switch(Portx){
		case DIO_PortA:
		if (direction == Input)
		{
			ClearBit(DDRA_Reg,BitNo);
		}
		else
		{
			SetBit(DDRA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (direction == Input)
		{
			ClearBit(DDRB_Reg,BitNo);
		}
		else
		{
			SetBit(DDRB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (direction == Input)
		{
			ClearBit(DDRC_Reg,BitNo);
		}
		else
		{
			SetBit(DDRC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (direction == Input)
		{
			ClearBit(DDRD_Reg,BitNo);
		}
		else
		{
			SetBit(DDRD_Reg,BitNo);
		}
		break;
	}
}

void DIO_WriteChannelGroup(DIO_PortTypes portId,u8 mask,u8 data){
	switch(portId){
		case DIO_PortA:
		PORTA_Reg = (PORTA_Reg & ~mask)|(data & mask);
		break;
		case DIO_PortB:
		PORTB_Reg = (PORTB_Reg & ~mask)|(data & mask);
		break;
		case DIO_PortC:
		PORTC_Reg = (PORTC_Reg & ~mask)|(data & mask);
		break;
		case DIO_PortD:
		PORTD_Reg = (PORTD_Reg & ~mask)|(data & mask);
		break;
	}
}