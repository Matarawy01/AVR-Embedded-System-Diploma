#ifndef FUNCTION_LIKE_MACRO_H_
#define FUNCTION_LIKE_MACRO_H_

#define Set_Bit(Reg,Bit_No)    Reg |= (1<<Bit_No)
#define Clear_Bit(Reg,Bit_No)  Reg &= ~ (1<<Bit_No)
#define Toggle_Bit(Reg,Bit_No) Reg ^= (1<<Bit_No)
#define Read_Bit(Reg,Bit_No)   ((Reg >> Bit_No) & 1)

#endif
