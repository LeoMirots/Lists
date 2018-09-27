#if !defined EL_H
#define EL_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ushort unsigned short
#define uchar unsigned char
#define uint unsigned int

enum types {
	char_element,
	uchar_element,
	ushort_element,
	short_element,
	uint_element,
	int_element,
	float_element,
	double_element,
	string_element,
	persona_element,
};

typedef struct {
	void *value;
	int type;
}element;							/*Definizione del tipo di dato degli elementi;*/

typedef struct {
	char* s;
	size_t len;
} string;
typedef struct {
	char Nome[20];
	char CF[17];
	char Referto[100];
	int CodiceAccesso;
} Persona;

typedef bool element2;
typedef short element3;

/*Un oggetto contiene un elemento, l'indirizzo
dell'elemento succssivo (l->next) e l'indirizzo
del primo elemento(l->root) della lista*/


extern element build_element(void* el, int tipo);
extern void AssignElement(element *dst, element src);	/*Funzione di assegnamento tra 2 elementi, copia l'elemento src nell'elemento puntato da dst;*/
extern void PrintElement(element e);					/*Funzione di stampa di un elemento, il parametro � l'elemento da stampare;*/
extern bool IsEqual(element a, element b);					/*Funzione di confronto tra elementi, riceve due elementi come parametro e ritorna true se sono uguali e false nel caso contrario;*/
extern int cmp(element *a, element *b);				/*Funzione di confronto tra 2 elementi, ritorna 0 se sono uguali, un valore negativo se a < b, positivo se a > b;*/
#define copy_element(/*element*/ el)	build_element((el).value, (el).type)
extern void DeleteElement(element e);					/*Funzione di cancellazione del dato, occorre modificarla se si cambia il tipo di dato;*/

/*------------------------------------------------Used inside the library---------------------------------------------------------------------------------------------------------------------------*/

extern void str_del(string str);
extern string string_append(char* add_str, string str);
extern string build_string(char* str_in, size_t len);
extern string* string_copy(void* str_in);
extern Persona build_persona(char* nome, char* cf, char* referto, int codiceAccesso);
extern Persona* persona_copy(void* p);

#endif //EL_H