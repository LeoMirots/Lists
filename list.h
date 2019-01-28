#if !defined LIST_H
#define LIST_H

#include "el.h"

typedef struct list_element {
	element value;
	struct list_element *next;
} item;

typedef item *list;		//a list is a pointer to one memory block of the list;

extern size_t llenght(list l);									/*Riceve come parametro una lista e ritorna il numero di elementi della lista;*/
extern list cons(element e);									/*Crea una nuova lista inserendo al primo elemento il parametro e, ritorna la lista creata;*/
extern list insert(element e, list l);							/*Inserisce un nuovo elemento e in una lista l, se la lista o inesistente viene creata, ritorna la lista aggiornata;*/
extern element head(list l);									/*Ritorna l'elemento in testa alla lista;*/
extern list tail(list l);										/*Scorre in avanti la lista passata come parametro, ritornando la lista senza l'elemento in testa;*/
extern list empty_list(void);									/*Crea una lista vuota, non necessita di parametri e ritorna il puntatore alla lista creata;*/
extern bool empty(list l);										/*Ritorna true se la lista passata come parametro � vuota, altrimenti ritorna false;*/

extern bool detect(element e, list l);								/*Ritorna true se l'elemento e � presente nella lista l, altrimenti ritorna false;*/
extern list search(element e, list l);								/*Se l'elemento e � presente nella lista l, ritorna un puntatore a quell'oggetto, altrimenti ritorna NULL;*/
extern list search_and_destroy(element e, list l);					/*Cerca nella lista la prima occorrenza dell'elemento passato come input e lo cancella, ritorna la lista passata come parametro con l'elemento eliminato*/
extern list DelFirst(list l);										/*Elimina il primo elemento della lista, ritorna un puntatore all' elemento successivo;*/
extern list Del(list l, item *ToDelete);							/*Elimina il nodo puntato da l verificando che il nodo che lo precede aggiorni il puntatore al prossimo elemento;*/
extern void pop(list l, size_t element_n);							/*Elimina l'elemento n-esimo della lista l;*/
extern element getElement(list l, size_t element_n);				/*Ritorna l'n-esimo elemento della lista l;*/
extern list copy(list l);											/*Ritorna una copia della lista passata come parametro*/
extern list append(list l1, list l2);								/*Ritorna la lista 1 unita alla lista 2;*/
extern list AppendElement(element e, list l);						/*Ritorna una lista con aggiunto l'elemento e alla fine;*/
extern list NoRepetition(list l);									/*Ritorna la lista senza elementi ripetuti;*/
extern list intersect(list l1, list l2);							/*Ritorna una lista che contiene gli elementi in comune tra le liste l1 e l2 passate come parametri, se non ci sono elementi in comune viene ritornata una lista vuota(NULL);*/
extern list difference(list l1, list l2);							/*Ritorna una lista uguale a l1, che non contiene gli elementi che l1 ha in comune con l2*/
extern int PrintList(list l);										/*Stampa tutti gli elementi della lista, ritorna 0 in caso di successo, 1 nel caso contrario;*/
extern element MaxValue(list l);									/*Ritorna l'elemento dal valore maggiore presente nella lista;*/
extern element MinValue(list l);									/*Ritorna l'elemento dal valore minore presente nella lista;*/
extern list insord(element e, list l);								/*Inserisce l'elemento e nella lista l mantenendo l'ordine; */
extern void bubble_sort(list l);									/*Ordina in verso crescente la lista l;*/
extern void swap(item *a, item *b);									/*Scambia gli elementi tra due oggetti(items) della lista l;*/
extern list DeleteAll(list l);										/*Cancella tutta la lista*/

#endif //LIST_H
