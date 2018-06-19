#include "el.h"
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

/*-----------------Element2----------------------------------------------------------------------------------------------------------------------*/

bool IsEqual2(element2 a, element2 b)
{
	if (a == b)
		return true;
	return false;
}

int cmp2(element2 a, element2 b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	return 1;
}

void AssignElement2(element2 *dst, element2 src)
{
	*dst = src;
}

int DeleteElement2(element2 e)
{
	return EXIT_SUCCESS;
}

void PrintElement2(element2 e)
{
	printf("%u;", e);
}

list2 AppendElement2(element2 e, list2 l)
{
	if (l == NULL)
		return cons2(e);
	while (l->next != NULL)
		l = tail2(l);
	list2 c = cons2(e);
	c->root = l->root;
	l->next = c;
	return l->root;
}

/*-------------Element3----------------------------------------------------------------------------------------------------------------------------------------*/

bool IsEqual3(element3 a, element3 b)
{
	if (a == b)
		return true;
	return false;
}

int cmp3(element3 a, element3 b)
{
	if (a == b)
		return 0;
	if (a < b)
		return -1;
	return 1;
}

void AssignElement3(element3 *dst, element3 src)
{
	*dst = src;
}

int DeleteElement3(element3 e)
{
	return EXIT_SUCCESS;
}

void PrintElement3(element3 e)
{
	printf("%u;", e);
}

list3 AppendElement3(element3 e, list3 l)
{
	if (l == NULL)
		return cons3(e);
	while (l->next != NULL)
		l = tail3(l);
	list3 c = cons3(e);
	c->root = l->root;
	l->next = c;
	return l->root;
}