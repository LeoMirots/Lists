#include "list.h"

/*Per il test crea una lista con i primi 10 numeri;*/

/*Nel file.txt delle persone non ci devono essere spazi nella stringa di un campo solo, gli spazi separano i campi;*/

int main(void)
{
	int ctrl = 0;
	size_t size1 = 0;
	unsigned int *v = malloc(sizeof(unsigned int));

	for (size_t i = 0; 1; ++i)
	{
		printf("Inserire il %u* numero positivo della prima lista, terminare inserendo 0:\n", (size1 + 1));
		v = realloc(v, sizeof(unsigned int) * (i + 1));
	s:	ctrl = scanf(" %u", &v[i]);
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
	element x = build_element(&v[0], uint_element);
	list l1 = cons(x);
	if (l1 == NULL)
	{
		printf("Ci sono stati dei problemi nel creare la lista;\n");
		return EXIT_FAILURE;
	}
	if (size1 > 1)
		for (size_t i = 1; i < size1; ++i)
		{
			x.value = &v[i];
			l1 = AppendElement(x, l1);
		}
	DeleteElement(x);

	PrintList(l1);
	unsigned int n = 5;
	element t = build_element(&n, uint_element);
	item *z = search(t, l1);
	PrintElement(z->value);
	search_and_destroy(t, l1);
	DeleteElement(t);

	n = 4;
	element t1 = build_element(&n, uint_element);
	bool test = detect(t1, l1);
	item *toErase = search(t1, l1);
	Del(toErase);
	PrintList(l1);


	l1 = insert(t1, l1);
	DeleteElement(t1);
	PrintList(l1);
	element h = head(l1);
	PrintElement(h);
	l1 = NoRepetition(l1);
	PrintList(l1);
	PrintElement(MaxValue(l1));
	PrintElement(MinValue(l1));

	list lp = empty_list();
	Persona *tmp = malloc(sizeof(Persona));
	FILE *f = fopen("Persone.txt", "rt");
	if (f == NULL)
	{
		fprintf(stderr, "Errore in apertura del file;\n");
		return EXIT_FAILURE;
	}
	for (int ctrl = 0; ctrl != EOF;)
	{
		ctrl = fscanf(f, "%s,", &tmp->Nome);
		fscanf(f, "%s", &tmp->Cognome);
		fscanf(f, "%s", &tmp->CF);
		fscanf(f, "%s", &tmp->Referto);
		fscanf(f, "%d;\n", &tmp->CodiceAccesso);

		if(ctrl != EOF)
			lp = AppendElement(build_element(tmp, persona_element), lp); //Memory leak in this point: AppendElement e build_element creano entrambi una copia di tmp, una è superflua e andrebbe eliminata;
	}
	fclose(f);
	PrintList(lp);
	swap(lp, tail(lp));
	PrintList(lp);

	string *str = malloc(sizeof(string));
	char x[] = "Ciao";
	str->s = x;
	str->len = strlen(str->s);
	element s = build_element(str, string_element);
	list ls = cons(s);
	DeleteElement(s);
	PrintList(ls);

	system("PAUSE");
	return EXIT_SUCCESS;
}
