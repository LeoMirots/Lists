#include "rubrica.h"

list DeleteContact(list l)
{
	element e;
	//e.numero[0] = NULL;
	printf("Se conosciuto digitare il nome del contatto da eliminare, altrimenti digitare NULL:\n");
	scanf(" %s", e.nome);
	list tmp = l;
	if (strcmp(e.nome, "NULL") != 0)
	{
		printf("I contatti presenti in rubrica con questo nome sono:\n");
		for (size_t i = 0; i < llenght(l); ++i)
		{
			l = search(e, l);
			PrintElement(l->value);
			l = tail(l);
		}
		l = tmp;
	}

	printf("Inserire il numero del contatto da eliminare:\n");
	scanf(" %s", e.numero);
	l = search(e, l);
	printf("Trovato:\n");
	PrintElement(l->value);

conferma:
	printf("Eliminare questo elemento[S/n]:");
	char c = fgetc(stdin);
	if (c == 'n' || c == 'N')
	{
		printf("Operazione annullata;\n");
		return (l->root);
	}
	if (c == 's' || c == 'S')
	{
		l = destroy(l);
		printf("Operazione completata;\n");
		return l;
	}
	goto conferma;
}

list FindPerson(list l)
{
	contatto *tmp = malloc(sizeof(contatto));
	printf("Se conosciuto inserire un nome da cercare, altrimenti scrivere NULL:\n");
	int ctrl = scanf(" %s", tmp->nome);
	if (ctrl != 1)
	{
		printf("Errore di inserimento;\n");
		return NULL;
	}
	if (strcmp("NULL", tmp->nome) == 0)
	{
		printf("Inserire un numero da cercare:\n");
		ctrl = scanf(" %s", tmp->numero);
		if (ctrl != 1)
		{
			printf("Errore di inserimento;\n");
			return NULL;
		}
	}
	if (detect(*tmp, l) == true)
		l = search(*tmp, l);
	else
	{
		printf("Contatto non presente nella rubrica;\n");
		system("pause");
		return NULL;
	}
	printf("Contatto trovato, stampo i dati:\n");
	PrintElement(l->value);
	system("pause");
	return l;
}

list AddNew(list l)
{
	int ctrl1, ctrl2;
	element *tmp = malloc(sizeof(contatto));
n:	printf("Inserire il nome del nuovo contatto:\n");
	ctrl1 = scanf(" %s", tmp->nome);
	if (ctrl1 != 1)
	{
		printf("Errore di inserimento, riprovare;\n");
		goto n;
	}
m:	printf("Inserire il numero telefonico:\n");
	ctrl2 = scanf(" %s", tmp->numero);
	if (ctrl1 != 1)
	{
		printf("Errore di inserimento, riprovare;\n");
		goto m;
	}
	l = AppendElement(*tmp, l);
	free(tmp);
	printf("Operazione completata\n");
	return l;
}

int AZorder(const char *str1, const char *str2)
{
	for (size_t i = 0; i < 50; ++i)
	{
		if (str1[i] == str2[i])
			continue;
		if (str1[i] < str2[i])
			return -1;
		return 1;
	}
	return 0;
}

list GetOrder(list l)
{
	list tmp = l;
	size_t size = llenght(l);
	char *v = malloc(sizeof(char) * 50 * size);
	for (size_t i = 0; llenght(l) >= 1; ++i)
	{
		strcpy(&v[50 * i], l->value.nome);
		l = tail(l);
	}
	l = tmp;
	qsort(v, size, 50 * sizeof(char), AZorder);
	element e;
	list r = empty_list();
	bool ctrl = false;
	for (size_t i = 0; i < size; ++i)
	{
		strcpy(e.nome, &v[50 * i]);
		e.numero[0] = NULL;
		l = search(e, tmp);
		r = AppendElement(l->value, r);
		destroy(l);
	}
	printf("Operazione completata;\n");
	return r->root;
}