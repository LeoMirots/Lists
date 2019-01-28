#include "list.h"

size_t llenght(list l)
{
	if (empty(l) == true)
		return 0;
	size_t c = 1;
	while (l->next != NULL)
	{
		l = tail(l);
		++c;
	}
	return c;
}

list cons(element e)
{
	list l = malloc(sizeof(item));
	l->value.value = BuildValue(e);
	l->value.type = e.type;
	l->next = NULL;
	return l;
}

element head(list l)
{
	return l->value;
}

list tail(list l)
{
	l = l->next;
	return l;
}

list insert(element e, list l)
{
	list l1 = cons(e);
	l1->next = l;
	return l1;
}

list empty_list(void)
{
	return NULL;
}

bool empty(list l)
{
	if (l == NULL)
		return true;
	return false;
}

bool detect(element e, list l)
{
	while (empty(l) == false)
	{
		if (IsEqual(e, l->value) == true)
			return true;
		l = tail(l);
	}
	return false;
}

list search(element e, list l)
{
	if (detect(e, l) == false)
		return NULL;
	while (empty(tail(l)) == false)
	{
		if (IsEqual(e, head(l)) == true)
			return l;
		l = tail(l);
	}
	if (IsEqual(e, l->value) == true)
		return l;
	return NULL; //In teoria qui non ci dovrebbe mai arrivare;
}

list search_and_destroy(element e, list l)
{
	list r = l;
	if (l == NULL)
		return NULL;
	if (detect(e, l) == false)
		return l;
	list tmp = l;
	if (IsEqual(head(l), e) == true)
		return DelFirst(l);
	while (llenght(l) != 1)
	{
		if (IsEqual(head(tail(l)), e) == true)
		{
			DeleteElement(l->next->value);
			tmp = l->next;
			l->next = l->next->next;
			free(tmp);
			return r;
		}
		l = tail(l);
	}
	return NULL;
}

list DelFirst(list l)
{
	list next = tail(l);
	DeleteElement(head(l));
	free(l);
	return next;
}

list Del(list l, item *ToDelete)
{
	list r = l;
	size_t list_size = llenght(r);
	if (l == ToDelete)
		DelFirst(l);
	for (size_t i = 0; i < list_size; ++i)
	{
		if (tail(r) == ToDelete)
		{
			r->next = ToDelete->next;
			break;
		}
		r = tail(r);
	}
	DeleteElement(head(ToDelete));
	free(ToDelete);
	return r;
}

void pop(list l, size_t element_n)
{
	if (element_n == 0)														//This function cannot delete the first element because it doesn't have return, so we would lost all the list;
	{
		fprintf(stderr, "To delete the first element use DelFirst function!");
		abort();
	}

	if (element_n > llenght(l)) {
		fprintf(stderr, "Tryng to delete an element outside the list!");
		abort();
	}
	for (size_t i = 0; i < element_n - 1; i++)
		l = tail(l);															//The l pointer is incremented untill it points to the item before the item to delete;		
	list cancellable = tail(l);												//the pointer to the next item of list l, the item to delete, is saved in "cancellable" variable;
	l->next = tail(cancellable);												//The pointer to the next element of list l, is set to the next item of cancellable; the list l is now not linked to the item to delete;
	Del(l, cancellable);													//The element to delete is deleted;
}

element getElement(list l, size_t element_n)
{
	for (size_t i = 0; i < element_n; i++) {
		if (tail(l) == NULL) {
			fprintf(stderr, "%s\n", "The list already ended!");
			abort();
		}
		l = tail(l);
	}
	return head(l);
}

list copy(list l)
{
	list c = empty_list();
	while (empty(l) == false)
	{
		c = AppendElement(head(l), c);
		l = tail(l);
	}
	return c;
}

list append(list l1, list l2)
{
	list r = l1;
	while (empty(tail(l1)) == false)
	{
		l1 = tail(l1);
	}
	l1->next = l2;
	return r;
}

list AppendElement(element e, list l)
{
	list r = l;
	if (empty(l) == true)
		return cons(e);
	while (empty(tail(l)) == false)
		l = tail(l);
	list c = cons(e);
	l->next = c;
	return r;
}

list NoRepetition(list l)
{
	list r = l;
	bool firstEl = true;
	while (empty(l) == false)
	{
		if (detect(head(l), l) == true)
		{
			if (detect(head(l), tail(l)))
			{	
				if (firstEl == true)
					r = DelFirst(l);
				else
					l = search_and_destroy(head(l), r);
			}
			else
				firstEl = false;
		}
		l = tail(l);
	}
	return r;
}

list intersect(list l1, list l2)
{
	list i = empty_list();
	if (l1 == NULL || l2 == NULL)
		return NULL;

	while (empty(l1) == false)
	{
		if (detect(head(l1), l2) == true)
		{
			i = insert(head(l1), i);
		}
		l1 = tail(l1);
	}
	i = NoRepetition(i);
	return i;
}

list difference(list l1, list l2)
{
	if (l1 == NULL)
		return NULL;
	list diff = copy(l1);
	if (l2 == NULL)
		return diff;
	while (llenght(l2) != 0)
	{
		if (detect(l2->value, l1) == true)
			for (size_t c = 0; c < llenght(l1); ++c)
				diff = search_and_destroy(l2->value, diff);
		l2 = tail(l2);
	}
	return diff;
}

int PrintList(list l)
{
	if (l == NULL)
	{
		fprintf(stderr, "Lista vuota!\n");
		return EXIT_FAILURE;
	}

	printf("Stampo gli elementi della lista...\n");
	while (empty(tail(l)) == false)
	{
		PrintElement(l->value);
		printf("\n");
		l = tail(l);
	}
	PrintElement(l->value);
	printf("\n");
	printf("Elementi terminati;\n");
	return EXIT_SUCCESS;
}

element MaxValue(list l)
{
	element x = { BuildValue(head(l)), head(l).type };
	while (empty(tail(l)) == false)
	{
		if (cmp(x, (head(tail(l)))) < 0)
			AssignElement(&x, head(tail(l)));
		l = tail(l);
	}
	return x;
}

element MinValue(list l)
{
	element x = { BuildValue(head(l)), head(l).type };
	for (size_t i = 0; tail(l) != NULL; ++i)
	{
		if (cmp(x, (head(tail(l)))) > 0)
			AssignElement(&x, head(tail(l)));
		l = tail(l);
	}
	return x;
}

list insord(element e, list l)
{
	if (empty(l) == true)													//If the list is empty, the function add the element at the head of the lists;
		return cons(e);
	list prev = empty_list();												//prev is a pointer to the previous item, it points to the item before the item pointed by l;
	list root = l;
	while (empty(l) == false) {												//While list l is not empty:
		if (cmp(head(l), e) > 0 || IsEqual(head(l), e) == true) {		//If the element to add is bigger or equal at the element in the item pointed by l;
			l = insert(e, l);															//The function insert the element e at the head of list l;
			if (prev == NULL)														//If l points to the firts item of the list, no more operations needed:
				return l;																//So l pointer is returned;
			prev->next = l;															//Else, if l was not pointing the first item of the list, the item before l, pointed by prev, is linked to the new item created now pointed by l;
			return root;																//The first item of the list is returned;
		}
		prev = l;																//We need to explore the next element, so prev is set pointing l;											
		l = l->next;															//Then l is incremented pointing to next item;
	}
	return AppendElement(e, root);											//If any element present in the items of the list l are bigger than the element e, the element to add is copied into an item linked at the end of the list; 
}

void bubble_sort(list l)
{
	bool inorder;
	list ptr1;
	list lptr = empty_list();
	if (empty(l) == true)
		return;
	do
	{
		inorder = true;														//I choose to consider the list alredy in order;
		ptr1 = l;

		while (tail(ptr1) != lptr)											//While it has not checked all the element of the list untill lptr:
		{
			if (cmp(head(ptr1), head(tail(ptr1))) > 0)					//If one single pair of element are not in orde:
			{
				swap(ptr1, tail(ptr1));												//It swap these elements;
				inorder = false;													//And set the inorder flag to false, it cannot still say the list is in order;
			}
			ptr1 = tail(ptr1);													//ptr1 is incremented to check the next pair of element;
		}
		lptr = ptr1;														//lptr is set to ptr1, to exclude the last element of the list, that surely is the maximum value of the whole list;
	} while (inorder == false);											//Do these operations untill the list is not in order;
}

void swap(item *a, item *b)
{
	element tmp;
	tmp.type = a->value.type;
	AssignElement(&tmp, a->value);
	AssignElement(&a->value, b->value);
	AssignElement(&b->value, tmp);
}

list DeleteAll(list l)
{
	while (empty(l) == false) {
		l = DelFirst(l);
	}
	return l;
}