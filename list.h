/*	Libreria per gestire liste di dati, gli elementi della lista possono
	essere qualsiasi tipo di dato, degli interi, dei double o delle struct,
	è sufficiente definirli e modificare la definizione di elemento nella
	libreria.
*/

#if !defined LIST_H
#define LIST_H

#include "el.h"

extern size_t llenght(list l);								/*Riceve come parametro una lista e ritorna il numero di elementi della lista;*/
extern list cons(element e);								/*Crea una nuova lista inserendo al primo elemento il parametro e, ritorna la lista creata;*/
extern list insert(element e, list l);						/*Inserisce un nuovo elemento e in una lista l, se la lista o inesistente viene creata, ritorna la lista aggiornata;*/
extern element head(list l);								/*Ritorna l'elemento in testa alla lista;*/
extern list tail(list l);									/*Scorre in avanti la lista passata come parametro, ritornando la lista senza l'elemento in testa;*/
extern list empty_list(void);								/*Crea una lista vuota, non necessita di parametri e ritorna il puntatore alla lista creata;*/
extern bool empty(list l);									/*Ritorna true se la lista passata come parametro è vuota, altrimenti ritorna false;*/

extern bool detect(element e, list l);						/*Ritorna true se l'elemento e è presente nella lista l, altrimenti ritorna false;*/
extern list search(element e, list l);						/*Se l'elemento e è presente nella lista l, ritorna un puntatore a quell'oggetto, altrimenti ritorna NULL;*/
extern list search_and_destroy(element e, list l);			/*Cerca nella lista la prima occorrenza dell'elemento passato come input e lo cancella, ritorna la lista passata come parametro con l'elemento eliminato*/
extern list Del(list l);									/*Elimina il nodo puntato da l verificando che il nodo che lo precede aggiorni il puntatore al prossimo elemento, se l è il root della lista, aggiorna il root a l->next;*/
extern list DelFirst(list l);							/*Elimina il primo elemento della lista aggiornando il root a root->next, ritorna un puntatore al nuovo root;*/
extern list SetRoot(list NewRoot, list l);					/*Imposta l->root di ogni elemento della lista a NewRoot e ritorna la lista dal punto di partenza;*/
extern list copy(list l);									/*Ritorna una copia della lista passata come parametro*/
extern list append(list l1, list l2);						/*Ritorna la lista 1 unita alla lista 2;*/
extern list NoRepetition(list l);							/*Ritorna la lista senza elementi ripetuti;*/
extern list intersect(list l1, list l2);					/*Ritorna una lista che contiene gli elementi in comune tra le liste l1 e l2 passate come parametri, se non ci sono elementi in comune viene ritornata una lista vuota(NULL);*/
extern list difference(list l1, list l2);					/*Ritorna una lista uguale a l1, che però non contiene gli elementi che l1 ha in comune con l2*/
extern int PrintList(list l);								/*Stampa tutti gli elementi della lista, ritorna 0 in caso di successo, 1 nel caso contrario;*/

/*--------------Element2------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

extern size_t llenght2(list2 l);							/*Riceve come parametro una lista e ritorna il numero di elementi della lista;*/
extern list2 cons2(element2 e);								/*Crea una nuova lista inserendo al primo elemento il parametro e, ritorna la lista creata;*/
extern list2 insert2(element2 e, list2 l);					/*Inserisce un nuovo elemento e in una lista l, se la lista o inesistente viene creata, ritorna la lista aggiornata;*/
extern element2 head2(list2 l);								/*Ritorna l'elemento in testa alla lista;*/
extern list2 tail2(list2 l);								/*Scorre in avanti la lista passata come parametro, ritornando la lista senza l'elemento in testa;*/
extern list2 empty_list2(void);								/*Crea una lista vuota, non necessita di parametri e ritorna il puntatore alla lista creata;*/
extern bool empty2(list2 l);								/*Ritorna true se la lista passata come parametro è vuota, altrimenti ritorna false;*/

extern bool detect2(element2 e, list2 l);					/*Ritorna true se l'elemento e è presente nella lista l, altrimenti ritorna false;*/
extern list2 search2(element2 e, list2 l);					/*Se l'elemento e è presente nella lista l, ritorna un puntatore a quell'oggetto, altrimenti ritorna NULL;*/
extern list2 search_and_destroy2(element2 e, list2 l);		/*Cerca nella lista la prima occorrenza dell'elemento passato come input e lo cancella, ritorna la lista passata come parametro con l'elemento eliminato*/
extern list2 Del2(list2 l);									/*Elimina il nodo puntato da l verificando che il nodo che lo precede aggiorni il puntatore al prossimo elemento, se l è il root della lista, aggiorna il root a l->next;*/
extern list2 DelFirst2(list2 l);							/*Elimina il primo elemento della lista aggiornando il root a root->next, ritorna un puntatore al nuovo root;*/
extern list2 SetRoot2(list2 NewRoot, list2 l);				/*Imposta l->root di ogni elemento della lista a NewRoot e ritorna la lista dal punto di partenza;*/
extern list2 copy2(list2 l);								/*Ritorna una copia della lista passata come parametro*/
extern list2 append2(list2 l1, list2 l2);					/*Ritorna la lista 1 unita alla lista 2;*/
extern list2 NoRepetition2(list2 l);						/*Ritorna la lista senza elementi ripetuti;*/
extern list2 intersect2(list2 l1, list2 l2);				/*Ritorna una lista che contiene gli elementi in comune tra le liste l1 e l2 passate come parametri, se non ci sono elementi in comune viene ritornata una lista vuota(NULL);*/
extern list2 difference2(list2 l1, list2 l2);				/*Ritorna una lista uguale a l1, che però non contiene gli elementi che l1 ha in comune con l2*/
extern int PrintList2(list2 l);								/*Stampa tutti gli elementi della lista, ritorna 0 in caso di successo, 1 nel caso contrario;*/

/*--------------Element3-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

extern size_t llenght3(list3 l);							/*Riceve come parametro una lista e ritorna il numero di elementi della lista;*/
extern list3 cons3(element3 e);								/*Crea una nuova lista inserendo al primo elemento il parametro e, ritorna la lista creata;*/
extern list3 insert3(element3 e, list3 l);					/*Inserisce un nuovo elemento e in una lista l, se la lista o inesistente viene creata, ritorna la lista aggiornata;*/
extern element3 head3(list3 l);								/*Ritorna l'elemento in testa alla lista;*/
extern list3 tail3(list3 l);								/*Scorre in avanti la lista passata come parametro, ritornando la lista senza l'elemento in testa;*/
extern list3 empty_list3(void);								/*Crea una lista vuota, non necessita di parametri e ritorna il puntatore alla lista creata;*/
extern bool empty3(list3 l);								/*Ritorna true se la lista passata come parametro è vuota, altrimenti ritorna false;*/

extern bool detect3(element3 e, list3 l);					/*Ritorna true se l'elemento e è presente nella lista l, altrimenti ritorna false;*/
extern list3 search3(element3 e, list3 l);					/*Se l'elemento e è presente nella lista l, ritorna un puntatore a quell'oggetto, altrimenti ritorna NULL;*/
extern list3 search_and_destroy3(element3 e, list3 l);		/*Cerca nella lista la prima occorrenza dell'elemento passato come input e lo cancella, ritorna la lista passata come parametro con l'elemento eliminato*/
extern list3 Del3(list3 l);									/*Elimina il nodo puntato da l verificando che il nodo che lo precede aggiorni il puntatore al prossimo elemento, se l è il root della lista, aggiorna il root a l->next;*/
extern list3 DelFirst3(list3 l);							/*Elimina il primo elemento della lista aggiornando il root a root->next, ritorna un puntatore al nuovo root;*/
extern list3 SetRoot3(list3 NewRoot, list3 l);				/*Imposta l->root di ogni elemento della lista a NewRoot e ritorna la lista dal punto di partenza;*/
extern list3 copy3(list3 l);								/*Ritorna una copia della lista passata come parametro*/
extern list3 append3(list3 l1, list3 l2);					/*Ritorna la lista 1 unita alla lista 2;*/
extern list3 NoRepetition3(list3 l);						/*Ritorna la lista senza elementi ripetuti;*/
extern list3 intersect3(list3 l1, list3 l2);				/*Ritorna una lista che contiene gli elementi in comune tra le liste l1 e l2 passate come parametri, se non ci sono elementi in comune viene ritornata una lista vuota(NULL);*/
extern list3 difference3(list3 l1, list3 l2);				/*Ritorna una lista uguale a l1, che però non contiene gli elementi che l1 ha in comune con l2*/
extern int PrintList3(list3 l);								/*Stampa tutti gli elementi della lista, ritorna 0 in caso di successo, 1 nel caso contrario;*/

#endif //LIST_H
