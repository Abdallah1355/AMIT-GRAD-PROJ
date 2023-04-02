/*
 * DIO.h
 *
 * Created: 3/24/2023 3:01:44 PM
 *  Author: abdal
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes channelId,STD_LevelTypes level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes channelId);
void DIO_ToggleChannel(DIO_ChannelTypes channelId);
u8 DIO_ReadPort(DIO_PortTypes portId);
void DIO_WritePort(DIO_PortTypes portId,u8 data);
void DIO_ConfigChannel(DIO_ChannelTypes channelId,DIO_DirTypes direction);
void DIO_WriteChannelGroup(DIO_PortTypes portId,u8 mask,u8 data);





#endif /* DIO_H_ */