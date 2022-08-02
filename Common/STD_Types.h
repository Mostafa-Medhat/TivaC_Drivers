#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL_PTR       ((void *)0)
#define NULL					  0


typedef enum{
	E_NOT_OK,
	E_OK
}Std_ReturnType;


typedef enum{
	FALSE,
	TRUE
}ConditionReturn;

typedef enum{
	DISABLE,
	ENABLE
}boolean;

#endif
