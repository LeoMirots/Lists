/*	Libreria per gestire liste di dati, gli elementi della lista possono
	essere qualsiasi tipo di dato, degli interi, dei double o delle struct,
	è sufficiente definirli e modificare la definizione di elemento nella
	libreria.
*/

#if !defined LIST_H
#define LIST_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define element unsigned int							/*Definizione del tipo di dato degli elementi;*/

typedef struct list_element { 
	element value;
	struct list_element *next;
	struct list_element *root;
} item;
	
typedef item* list;
extern void PrintElement(element e);					/*Funzione di stampa di un elemento, il parametro è l'elemento da stampare;*/
extern bool cmp(element a, element b);					/*Funzione di confronto tra elementi, riceve due elementi come parametro e ritorna true se sono uguali e false nel caso contrario;*/
int DeleteElement(element e);							/*Funzione di cancellazione del dato, occorre modificarla se si cambia il tipo di dato, ritorna 0 se ha successo, 1 nel caso contrario;*/

extern size_t llenght(list l);							/*Riceve come parametro una lista e ritorna il numero di elementi della lista;*/
extern list cons(element e);							/*Crea una nuova lista inserendo al primo elemento il parametro e, ritorna la lista creata;*/
extern list insert(element e, list l);					/*Inserisce un nuovo elemento e in una lista l, se la lista o inesistente viene creata, ritorna la lista aggiornata;*/
extern list tail(list l);								/*Scorre in avanti la lista passata come parametro, ritornando la lista senza l'elemento in testa;*/
extern list empty_list(void);							/*Crea una lista vuota, non necessita di parametri e ritorna il puntatore alla lista creata;*/
extern bool empty(list l);								/*Ritorna true se la lista passata come parametro è vuota, altrimenti ritorna false;*/

extern bool detect(element e, list l);					/*Ritorna true se l'elemento e è presente nella lista l, altrimenti ritorna false;*/
extern list search(element e, list l);					/*Se l'elemento e è presente nella lista l, ritorna un puntatore a quell'oggetto, altrimenti ritorna NULL;*/
extern list search_and_destroy(element e, list l);		/*Cerca nella lista la prima occorrenza dell'elemento passato come input e lo cancella, ritorna la lista passata come parametro con l'elemento eliminato*/
extern list copy(list l);										/*Ritorna una copia della lista passata come parametro*/
extern list intersect(list l1, list l2);				/*Ritorna una lista che contiene gli elementi in comune tra le liste l1 e l2 passate come parametri, se non ci sono elementi in comune viene ritornata una lista vuota(NULL);*/
extern list difference(list l1, list l2);				/*Ritorna una lista uguale a l1, che però non contiene gli elementi che l1 ha in comune con l2*/
extern int PrintList(list l);							/*Stampa tutti gli elementi della lista, ritorna 0 in caso di successo, 1 nel caso contrario;*/

#endif //LIST_H
