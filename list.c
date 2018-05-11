#include "list.h"

bool cmp(element a, element b)
{
	if (a == b)
		return true;
	return false;
}

void PrintElement(element e)
{
	printf("%u;", e);
}

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
	l->value = e;
	l->next = NULL;
	l->root = l;
	return l;
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
	while (l->next != NULL)
	{
		if (cmp(e, l[0].value) == true)
			return true;
		l = tail(l);
	}
	if (cmp(e, l[0].value) == true)
		return true;
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
		tail(l);
	}
	if (cmp(e, l->value) == true)
		return l;
	return NULL; //In teoria qui non ci dovrebbe mai arrivare;
}

list intersect(list l1, list l2)
{
	list i = empty_list();
	bool ctrl = false;
	if (l1 == NULL || l2 == NULL)
		return NULL;

	while (l1->next != NULL)
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
	return i;
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