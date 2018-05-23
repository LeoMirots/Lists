#if !defined EL_H
#define EL_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef element unsigned int							/*Definizione del tipo di dato degli elementi;*/

/*Un oggetto contiene un elemento, l'indirizzo
dell'elemento succssivo (l->next) e l'indirizzo
del primo elemento(l->root) della lista*/
typedef struct list_element {
	element value;
	struct list_element *next;
	struct list_element *root;
} item;

typedef item* list;
extern void AssignElement(element *dst, element src);	/*Funzione di assegnamento tra 2 elementi, copia l'elemento src nell'elemento puntato da dst;*/
extern void PrintElement(element e);					/*Funzione di stampa di un elemento, il parametro � l'elemento da stampare;*/
extern bool IsEqual(element a, element b);					/*Funzione di confronto tra elementi, riceve due elementi come parametro e ritorna true se sono uguali e false nel caso contrario;*/
int cmp(element a, element b);				/*Funzione di confronto tra 2 elementi, ritorna 0 se sono uguali, -1 se a < b, 1 se a > b;*/
extern int DeleteElement(element e);					/*Funzione di cancellazione del dato, occorre modificarla se si cambia il tipo di dato, ritorna 0 se ha successo, 1 nel caso contrario;*/
extern list AppendElement(element e, list l);			/*Ritorna una lista con aggiunto l'elemento e alla fine;*/
