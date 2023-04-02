/*
 * BitMath.h
 *
 * Created: 3/24/2023 2:24:43 PM
 *  Author: abdal
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)



#endif /* BITMATH_H_ */