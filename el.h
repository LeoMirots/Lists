#if !defined EL_H
#define EL_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int element;							/*Definizione del tipo di dato degli elementi;*/
typedef bool element2;
typedef short element3;
/*Un oggetto contiene un elemento, l'indirizzo
dell'elemento succssivo (l->next) e l'indirizzo
del primo elemento(l->root) della lista*/
typedef struct list_element {
	element value;
	struct list_element *next;
	struct list_element *root;
} item;

typedef struct list_element2 {
	element2 value;
	struct list_element2 *next;
	struct list_element2 *root;
} item2;

typedef struct list_element3 {
	element3 value;
	struct list_element3 *next;
	struct list_element3 *root;
} item3;

typedef item* list;
typedef item2 *list2;
typedef item3 *list3;

extern void AssignElement(element *dst, element src);	/*Funzione di assegnamento tra 2 elementi, copia l'elemento src nell'elemento puntato da dst;*/
extern void PrintElement(element e);					/*Funzione di stampa di un elemento, il parametro � l'elemento da stampare;*/
extern bool IsEqual(element a, element b);					/*Funzione di confronto tra elementi, riceve due elementi come parametro e ritorna true se sono uguali e false nel caso contrario;*/
extern int cmp(element a, element b);				/*Funzione di confronto tra 2 elementi, ritorna 0 se sono uguali, -1 se a < b, 1 se a > b;*/
extern int DeleteElement(element e);					/*Funzione di cancellazione del dato, occorre modificarla se si cambia il tipo di dato, ritorna 0 se ha successo, 1 nel caso contrario;*/
extern list AppendElement(element e, list l);			/*Ritorna una lista con aggiunto l'elemento e alla fine;*/

/*----------------Element2-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

extern void AssignElement2(element2 *dst, element2 src);	/*Funzione di assegnamento tra 2 elementi, copia l'elemento src nell'elemento puntato da dst;*/
extern void PrintElement2(element2 e);					/*Funzione di stampa di un elemento, il parametro � l'elemento da stampare;*/
extern bool IsEqual2(element2 a, element2 b);					/*Funzione di confronto tra elementi, riceve due elementi come parametro e ritorna true se sono uguali e false nel caso contrario;*/
extern int cmp2(element2 a, element2 b);				/*Funzione di confronto tra 2 elementi, ritorna 0 se sono uguali, -1 se a < b, 1 se a > b;*/
extern int DeleteElement2(element2 e);					/*Funzione di cancellazione del dato, occorre modificarla se si cambia il tipo di dato, ritorna 0 se ha successo, 1 nel caso contrario;*/
extern list2 AppendElement2(element2 e, list2 l);			/*Ritorna una lista con aggiunto l'elemento e alla fine;*/

/*----------------Element3----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

extern void AssignElement3(element3 *dst, element3 src);	/*Funzione di assegnamento tra 2 elementi, copia l'elemento src nell'elemento puntato da dst;*/
extern void PrintElement3(element3 e);					/*Funzione di stampa di un elemento, il parametro � l'elemento da stampare;*/
extern bool IsEqual3(element3 a, element3 b);					/*Funzione di confronto tra elementi, riceve due elementi come parametro e ritorna true se sono uguali e false nel caso contrario;*/
extern int cmp3(element3 a, element3 b);				/*Funzione di confronto tra 2 elementi, ritorna 0 se sono uguali, -1 se a < b, 1 se a > b;*/
extern int DeleteElement3(element3 e);					/*Funzione di cancellazione del dato, occorre modificarla se si cambia il tipo di dato, ritorna 0 se ha successo, 1 nel caso contrario;*/
extern list3 AppendElement3(element3 e, list3 l);			/*Ritorna una lista con aggiunto l'elemento e alla fine;*/

#endif //EL_H