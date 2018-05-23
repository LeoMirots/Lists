#include "list.h"

bool IsEqual(element a, element b)
{
	if (a.nome == b.nome)
		if(a.numero == b.numero)
			return true;
	if (strIsEqual(a.numero, b.numero) == 0)
		return true;
	if (strIsEqual(a.nome, b.nome) == 0)
		return true;
	return false;
}

void AssignElement(element *dst, element src)
{
	strcpy(dst->nome, src.nome);
	strcpy(dst->numero, src.numero);
}

int DeleteElement(element e)
{
	//free(&e);
	return EXIT_SUCCESS;
}

void PrintElement(element e)
{
	printf("%s;\n", e.nome);
	printf("%s;\n", e.numero);
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
	while (l->next != NULL)
	{
		if (IsEqual(e, l->value) == true)
			return l;
		l = tail(l);
	}
	if (IsEqual(e, l->value) == true)
		return l;
	return NULL; //In teoria qui non ci dovrebbe mai arrivare;
}

list destroy(list l)
{
	if (l == l->root)
	{
		DeleteElement(l->value);
		list tmp = l->next;
		l = SetRoot(l->next, l);
		free(l);
		return tmp;
	}
	if (l == NULL)
		return NULL;
	list tmp = l->root;
	while (tmp->next != l)
	{
		tmp = tail(tmp);
	}
	tmp->next = l->next;
	DeleteElement(l->value);
	free(l);
	return tmp;
}

list search_and_destroy(element e, list l)
{
	if (l == NULL)
		return NULL;
	if (detect(e, l) == false)
		return l;
	list tmp = l;
	int ctrl;
	if (IsEqual(l->value, e) == true)
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
		if (IsEqual(l->next->value, e) == true)
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
	while(llenght(l2) != 0)
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
		printf("La lista non ha elementi;\n");
		return EXIT_FAILURE;
	}
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
