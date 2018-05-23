#include "list.h"

bool IsEqual(element a, element b)
{
	if (a == b)
		return true;
	return false;
}

int cmp(element a, element b)
{
	if(a == b)
		return 0;
	if(a < b)
		return -1;
	return 1;
}

void AssignElement(element *dst, element src)
{
	*dst = src;
}

int DeleteElement(element e)
{
	return EXIT_SUCCESS;
}

void PrintElement(element e)
{
	printf("%u;", e);
}

list AppendElement(element e, list l)
{
	if (l == NULL)
		return cons(e);
	while (l->next != NULL)
		l = tail(l);
	list c = cons(e);
	c->root = l->root;
	l->next = c;
	return l->root;
}
