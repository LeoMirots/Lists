#include "list.h"

int main(void)
{
	int ctrl = 0;
	size_t size1 = 0;
	unsigned int *v = malloc(sizeof(unsigned int));

	for (size_t i = 0; 1; ++i)
	{
		printf("Inserire il %u* numero positivo della prima lista, terminare inserendo 0:\n", (size1 + 1));
		v = realloc(v, sizeof(unsigned int) * (i + 1));
	s:		ctrl = scanf(" %u", &v[i]);
		if (ctrl != 1)
		{
			printf("Errore nell'inserimento del numero, riprovare;\n");
			goto s;
		}
		++size1;
		if (v[i] == 0)
			break;
	}
	--size1;
	list l1 = cons(v[0]);
	if (l1 == NULL)
	{
		printf("Ci sono stati dei problemi nel creare la lista;\n");
		return EXIT_FAILURE;
	}
	if (size1 > 1)
		for (size_t i = 1; i < size1; ++i)
			l1 = insert(v[i], l1);
	free(v);

	size_t size2 = 0;
	unsigned int *z = malloc(sizeof(unsigned int));
	ctrl = 0;
	for (size_t i = 0; 1; ++i)
	{
		printf("Inserire il %u* numero positivo della seconda lista, terminare inserendo 0:\n", (size2 + 1));
		z = realloc(z, sizeof(unsigned int) * (i + 1));
	t:		ctrl = scanf(" %u", &z[i]);
		if (ctrl != 1)
		{
			printf("Errore nell'inserimento del numero, riprovare;\n");
			goto t;
		}
		++size2;
		if (z[i] == 0)
			break;
	}
	--size2;
	list l2 = cons(z[0]);
	if (l2 == NULL)
	{
		printf("Ci sono stati dei problemi nel creare la lista;\n");
		return EXIT_FAILURE;
	}
	if (size2 > 1)
		for (size_t i = 1; i < size2; ++i)
			l2 = insert(v[i], l2);
	free(z);
	list l3 = intersect(l1, l2);
	list l4 = difference(l1, l2);
	PrintList(l3);
	PrintList(l4);

	l1 = search_and_destroy(3, l1);
	l2 = search_and_destroy(4, l2);
	return EXIT_SUCCESS;
}