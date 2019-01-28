#if !defined EL_H		//Include guard;
#define EL_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>		//Include some methods of standard library;
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum types {
	char_element,
	uchar_element,
	short_element,
	ushort_element,
	int_element,
	uint_element,
	float_element,
	double_element,
	string_element,			//Le stringhe NON sono allocate dinamicamente;
	struct_element,
} types;		//types is a new type of data, a integer that can be from 0 to 9, in this case;

typedef struct {
	void *value;
	types type;
} element;		//Defined element data type;

typedef struct {
	char Nome[20];
	char CF[17];
	char Referto[100];
	int CodiceAccesso;
} Struct;		//Struct example data type;

extern void *BuildValue(element e);							//Allocates memory to storage an element;
extern void DeleteElement(element ToDelete);				//Delete the element, deallocates allocated memory;
extern bool AssignElement(element *dst, element src);		//dst = src;
extern void PrintElement(element e);						//Print theelement;
extern bool IsEqual(element a, element b);					//Returns true if a == b;
extern int cmp(element a, element b);						//Returns 1 if a > b, 0 if a == b, -1 if a < b;


#endif //EL_H