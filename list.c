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
	AssignElement(&l->value, e);
	l->next = NULL;
	l->root = l;
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
	if (l == NULL)
		return l1;
	while (l->next != NULL)
	{
		l->root = l1;
		l = tail(l);
	}
	l->root = l1;
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
		if (cmp(e, l->value) == true)
			return true;
		l = tail(l);
	}
	return false;
}

list search(element e, list l)
{
	if (detect(e, l) == false)
		return NULL;
	while (l->next != NULL)
	{
		if (cmp(e, l->value) == true)
			return l;
		l = tail(l);
	}
	if (cmp(e, l->value) == true)
		return l;
	return NULL; //In teoria qui non ci dovrebbe mai arrivare;
}

list search_and_destroy(element e, list l)
{
	if (l == NULL)
		return NULL;
	if (detect(e, l) == false)
		return l;
	list tmp = l;
	int ctrl;
	if (cmp(l->value, e) == true)
	{
		l = l->next;
		ctrl = DeleteElement(tmp->value);
		if (ctrl == 1)
		{
			printf("Errore cancellazione elemento;\n");
			abort();
		}
		SetRoot(l, l);
		free(tmp);
		return l;
	}
	while (llenght(l) != 1)
	{
		if (cmp(l->next->value, e) == true)
		{
			ctrl = DeleteElement(l->next->value);
			if (ctrl == 1)
			{
				printf("Errore nella cancellazione del file;\n");
				abort();
			}
			tmp = l->next;
			l->next = l->next->next;
			free(tmp);
			return l->root;
		}
		l = tail(l);
	}
	return NULL;
}

list SetRoot(list NewRoot, list l)
{
	while (llenght(l) != 0)
	{
		l->root = NewRoot;
		l = tail(l);
	}
	return NewRoot;
}

list copy(list l)
{
	list c = empty_list();
	while (l != NULL)
	{
		c = AppendElement(head(l), c);
		l = tail(l);
	}
	return c;
}

list append(list l1, list l2)
{
	while (l1->next != NULL)
	{
		l1 = tail(l1);
	}
	l1->next = l2;
	while (l2 != NULL)
	{
		l2->root = l1->root;
		l2 = tail(l2);
	}
	return l1->root;
}

list NoRepetition(list l)
{
	while (l->next != NULL)
	{
		if (detect(l->value, l) == true)
		{
			if (detect(l->value, tail(l)))
			{
				l = search_and_destroy(l->value, l);
			}
		}
		l = tail(l);
	}
	return l->root;
}

list intersect(list l1, list l2)
{
	list i = empty_list();
	bool ctrl = false;
	if (l1 == NULL || l2 == NULL)
		return NULL;

	while (empty(l1) == false)
	{
		if (detect(l1->value, l2) == true)
		{
			if (ctrl == false)
			{
				i = cons(l1->value);
				ctrl = true;
			}
			else
				i = insert(l1->value, i);
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

void bubble_sort(list l)
{
	int swapped;
	list ptr1;
	list lptr = NULL;
	if (l == NULL)
		return;
	do
	{
		swapped = 0;
		ptr1 = l;

		while (ptr1->next != lptr)
		{
			if (cmp(ptr1->value, ptr1->next->value) == 1)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(list a, list b) // va miglioratore
{
	element tmp;
	memcpy(&tmp, &(a->value), sizeof(element));
	memcpy(&(a->value), &(b->value), sizeof(element));
	memcpy(&(b->value), &tmp, sizeof(element));
}

int PrintList(list l)
{
	if (l == NULL)
		return EXIT_FAILURE;
	printf("Stampo gli elementi della lista...\n");
	while (l->next != NULL)
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

/*------------------Element2--------------------------------------------------------------------------------------------------------------------------------*/

size_t llenght2(list2 l)
{
	if (empty2(l) == true)
		return 0;
	size_t c = 1;
	while (l->next != NULL)
	{
		l = tail2(l);
		++c;
	}
	return c;
}

list2 cons2(element2 e)
{
	list2 l = malloc(sizeof(item));
	AssignElement2(&l->value, e);
	l->next = NULL;
	l->root = l;
	return l;
}

element2 head2(list2 l)
{
	return l->value;
}

list2 tail2(list2 l)
{
	l = l->next;
	return l;
}

list2 insert2(element2 e, list2 l)
{
	list2 l1 = cons2(e);
	l1->next = l;
	if (l == NULL)
		return l1;
	while (l->next != NULL)
	{
		l->root = l1;
		l = tail2(l);
	}
	l->root = l1;
	return l1;
}

list2 empty_list2(void)
{
	return NULL;
}

bool empty2(list2 l)
{
	if (l == NULL)
		return true;
	return false;
}

bool detect2(element2 e, list2 l)
{
	while (empty2(l) == false)
	{
		if (cmp(e, l->value) == true)
			return true;
		l = tail2(l);
	}
	return false;
}

list2 search2(element2 e, list2 l)
{
	if (detect2(e, l) == false)
		return NULL;
	while (l->next != NULL)
	{
		if (cmp(e, l->value) == true)
			return l;
		l = tail2(l);
	}
	if (cmp(e, l->value) == true)
		return l;
	return NULL; //In teoria qui non ci dovrebbe mai arrivare;
}

list2 search_and_destroy2(element2 e, list2 l)
{
	if (l == NULL)
		return NULL;
	if (detect2(e, l) == false)
		return l;
	list2 tmp = l;
	int ctrl;
	if (cmp2(l->value, e) == true)
	{
		l = l->next;
		ctrl = DeleteElement(tmp->value);
		if (ctrl == 1)
		{
			printf("Errore cancellazione elemento;\n");
			abort();
		}
		SetRoot2(l, l);
		free(tmp);
		return l;
	}
	while (llenght2(l) != 1)
	{
		if (cmp2(l->next->value, e) == true)
		{
			ctrl = DeleteElement2(l->next->value);
			if (ctrl == 1)
			{
				printf("Errore nella cancellazione del file;\n");
				abort();
			}
			tmp = l->next;
			l->next = l->next->next;
			free(tmp);
			return l->root;
		}
		l = tail2(l);
	}
	return NULL;
}

list2 SetRoot2(list2 NewRoot, list2 l)
{
	while (llenght2(l) != 0)
	{
		l->root = NewRoot;
		l = tail2(l);
	}
	return NewRoot;
}

list2 copy2(list2 l)
{
	list2 c = empty_list2();
	while (l != NULL)
	{
		c = AppendElement2(head2(l), c);
		l = tail2(l);
	}
	return c;
}

list2 append2(list2 l1, list2 l2)
{
	while (l1->next != NULL)
	{
		l1 = tail2(l1);
	}
	l1->next = l2;
	while (l2 != NULL)
	{
		l2->root = l1->root;
		l2 = tail2(l2);
	}
	return l1->root;
}

list2 NoRepetition2(list2 l)
{
	while (l->next != NULL)
	{
		if (detect2(l->value, l) == true)
		{
			if (detect2(l->value, tail2(l)))
			{
				l = search_and_destroy2(l->value, l);
			}
		}
		l = tail2(l);
	}
	return l->root;
}

list2 intersect2(list2 l1, list2 l2)
{
	list2 i = empty_list2();
	bool ctrl = false;
	if (l1 == NULL || l2 == NULL)
		return NULL;

	while (empty2(l1) == false)
	{
		if (detect2(l1->value, l2) == true)
		{
			if (ctrl == false)
			{
				i = cons2(l1->value);
				ctrl = true;
			}
			else
				i = insert2(l1->value, i);
		}
		l1 = tail2(l1);
	}
	i = NoRepetition2(i);
	return i;
}

list2 difference2(list2 l1, list2 l2)
{
	if (l1 == NULL)
		return NULL;
	list2 diff = copy2(l1);
	if (l2 == NULL)
		return diff;
	while (llenght2(l2) != 0)
	{
		if (detect2(l2->value, l1) == true)
			for (size_t c = 0; c < llenght2(l1); ++c)
				diff = search_and_destroy2(l2->value, diff);
		l2 = tail2(l2);
	}
	return diff;
}

int PrintList2(list2 l)
{
	if (l == NULL)
		return EXIT_FAILURE;
	printf("Stampo gli elementi della lista...\n");
	while (l->next != NULL)
	{
		PrintElement2(l->value);
		printf("\n");
		l = tail2(l);
	}
	PrintElement2(l->value);
	printf("\n");
	printf("Elementi terminati;\n");
	return EXIT_SUCCESS;
}

/*------------------Element3--------------------------------------------------------------------------------------------------------------------------------*/

size_t llenght3(list3 l)
{
	if (empty3(l) == true)
		return 0;
	size_t c = 1;
	while (l->next != NULL)
	{
		l = tail3(l);
		++c;
	}
	return c;
}

list3 cons3(element3 e)
{
	list3 l = malloc(sizeof(item));
	AssignElement3(&l->value, e);
	l->next = NULL;
	l->root = l;
	return l;
}

element3 head3(list3 l)
{
	return l->value;
}

list3 tail3(list3 l)
{
	l = l->next;
	return l;
}

list3 insert3(element3 e, list3 l)
{
	list3 l1 = cons3(e);
	l1->next = l;
	if (l == NULL)
		return l1;
	while (l->next != NULL)
	{
		l->root = l1;
		l = tail3(l);
	}
	l->root = l1;
	return l1;
}

list3 empty_list3(void)
{
	return NULL;
}

bool empty3(list3 l)
{
	if (l == NULL)
		return true;
	return false;
}

bool detect3(element3 e, list3 l)
{
	while (empty3(l) == false)
	{
		if (cmp3(e, l->value) == true)
			return true;
		l = tail3(l);
	}
	return false;
}

list3 search3(element3 e, list3 l)
{
	if (detect3(e, l) == false)
		return NULL;
	while (l->next != NULL)
	{
		if (cmp3(e, l->value) == true)
			return l;
		l = tail3(l);
	}
	if (cmp3(e, l->value) == true)
		return l;
	return NULL; //In teoria qui non ci dovrebbe mai arrivare;
}

list3 search_and_destroy3(element3 e, list3 l)
{
	if (l == NULL)
		return NULL;
	if (detect3(e, l) == false)
		return l;
	list3 tmp = l;
	int ctrl;
	if (cmp3(l->value, e) == true)
	{
		l = l->next;
		ctrl = DeleteElement3(tmp->value);
		if (ctrl == 1)
		{
			printf("Errore cancellazione elemento;\n");
			abort();
		}
		SetRoot3(l, l);
		free(tmp);
		return l;
	}
	while (llenght3(l) != 1)
	{
		if (cmp3(l->next->value, e) == true)
		{
			ctrl = DeleteElement3(l->next->value);
			if (ctrl == 1)
			{
				printf("Errore nella cancellazione del file;\n");
				abort();
			}
			tmp = l->next;
			l->next = l->next->next;
			free(tmp);
			return l->root;
		}
		l = tail3(l);
	}
	return NULL;
}

list3 SetRoot3(list3 NewRoot, list3 l)
{
	while (llenght3(l) != 0)
	{
		l->root = NewRoot;
		l = tail3(l);
	}
	return NewRoot;
}

list3 copy3(list3 l)
{
	list3 c = empty_list3();
	while (l != NULL)
	{
		c = AppendElement3(head3(l), c);
		l = tail3(l);
	}
	return c;
}

list3 append3(list3 l1, list3 l2)
{
	while (l1->next != NULL)
	{
		l1 = tail3(l1);
	}
	l1->next = l2;
	while (l2 != NULL)
	{
		l2->root = l1->root;
		l2 = tail3(l2);
	}
	return l1->root;
}

list3 NoRepetition3(list3 l)
{
	while (l->next != NULL)
	{
		if (detect3(l->value, l) == true)
		{
			if (detect3(l->value, tail3(l)))
			{
				l = search_and_destroy3(l->value, l);
			}
		}
		l = tail3(l);
	}
	return l->root;
}

list3 intersect3(list3 l1, list3 l2)
{
	list3 i = empty_list3();
	bool ctrl = false;
	if (l1 == NULL || l2 == NULL)
		return NULL;

	while (empty3(l1) == false)
	{
		if (detect3(l1->value, l2) == true)
		{
			if (ctrl == false)
			{
				i = cons3(l1->value);
				ctrl = true;
			}
			else
				i = insert3(l1->value, i);
		}
		l1 = tail3(l1);
	}
	i = NoRepetition3(i);
	return i;
}

list3 difference3(list3 l1, list3 l2)
{
	if (l1 == NULL)
		return NULL;
	list3 diff = copy3(l1);
	if (l2 == NULL)
		return diff;
	while(llenght3(l2) != 0)
	{
		if (detect3(l2->value, l1) == true)
			for (size_t c = 0; c < llenght3(l1); ++c)
				diff = search_and_destroy3(l2->value, diff);
		l2 = tail3(l2);
	}
	return diff;
}

int PrintList3(list3 l)
{
	if (l == NULL)
		return EXIT_FAILURE;
	printf("Stampo gli elementi della lista...\n");
	while (l->next != NULL)
	{
		PrintElement3(l->value);
		printf("\n");
		l = tail3(l);
	}
	PrintElement3(l->value);
	printf("\n");
	printf("Elementi terminati;\n");
	return EXIT_SUCCESS;
}
