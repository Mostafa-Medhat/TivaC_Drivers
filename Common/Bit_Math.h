
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT) 		(REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) 		(REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) 	(REG^=(1<<BIT))
#define GET_BIt(REG,BIT) 		((REG>>BIT)&(0x01))


#define SetBits(REG,MSK)	REG |= MSK
#define ClrBits(REG,MSK)	REG &= (~MSK)
#define TogBits(REG,MSK)	REG ^= MSK


#define SetAllBits(REG)		REG = 0xFF
#define ClrAllBits(REG)		REG = 0x00
#define TogAllBits(REG)		REG ^= 0xFF

#endif
