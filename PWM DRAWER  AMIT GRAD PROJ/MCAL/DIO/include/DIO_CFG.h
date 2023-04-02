/*
 * DIO_CFG.h
 *
 * Created: 3/24/2023 3:00:50 PM
 *  Author: abdal
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_Types.h"
#include "DIO_Private.h"

typedef struct
{
	DIO_DirTypes PinDir;
	STD_LevelTypes level;
}DIO_PinCfg;

#define PINCOUNT 32

void DIO_Init(void);





#endif /* DIO_CFG_H_ */