#include "el.h"
#include "list.h"

void test_liste()
{
	//This function is created to test and show usage of list.h library;

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
	element x = { &v[0], int_element };
	list l1 = cons(x);
	if (l1 == NULL)
	{
		printf("Ci sono stati dei problemi nel creare la lista;\n");
	}
	if (size1 > 1)
		for (size_t i = 1; i < size1; ++i)
		{
			x.value = &v[i];
			l1 = AppendElement(x, l1);
		}
	PrintList(l1);
	bubble_sort(l1);
	PrintList(l1);

	reverse(l1);
	PrintList(l1);
	
	unsigned int n = 5;
	element t = { &n, int_element };
	list check = cons(t);
	PrintElement(t);
	n = 4;
	PrintElement(t);
	PrintList(check);
	n = 5;

	item *z = search(t, l1);
	//PrintElement(z->value);
	search_and_destroy(t, l1);
	PrintList(l1);

	n = 4;
	element t1 = { &n, int_element };
	bool test = detect(t1, l1);
	item *toErase = search(t1, l1);
	Del(l1, toErase);
	PrintList(l1);
	insord(t1, l1);
	PrintList(l1);


	l1 = insert(t1, l1);
	PrintList(l1);
	element h = head(l1);
	PrintElement(h);
	l1 = NoRepetition(l1);
	PrintList(l1);
	PrintElement(MaxValue(l1));
	PrintElement(MinValue(l1));
	PrintList(l1->root);

	list lp = empty_list();
	Struct *tmp = malloc(sizeof(Struct));
	printf("\nInserisci la struct:\n");
	//for (int ctrl = 0; ctrl != EOF;)
	//{
		ctrl = scanf("%s %s %s %d", &tmp->Nome, &tmp->CF, &tmp->Referto, &tmp->CodiceAccesso);
		element zx = { tmp, struct_element };
		lp = AppendElement(zx, lp);
	//}
	PrintList(lp);
	l1 = DeleteAll(l1);
	PrintList(l1);
	return;
}

int main(void)
{
	//This main is created to test an show usage of the el.h functions;

	element e = { "Ciao come stai?", string_element };
	PrintElement(e);
	char a = '1';
	unsigned char b = 2;
	short c = 3;
	unsigned short d = 4;
	int ee = 5;
	unsigned int f = 6;
	float g = 7;
	double h = 8;
	element ch = { &a, char_element };
	element uc = { &b, uchar_element };
	element s = { &c, short_element };
	element us = { &d, ushort_element };
	element i = { &ee, int_element };
	element ui = { &f, uint_element };
	element fl = { &g, float_element };
	element db = { &h, double_element };
	
	PrintElement(ch);
	PrintElement(uc);
	PrintElement(s);
	PrintElement(us);
	PrintElement(i);
	PrintElement(ui);
	PrintElement(fl);
	PrintElement(db);
	PrintElement(e);

	int x = 3;
	int x1 = 4;
	int x2 = 2;
	element uno = { &x, int_element };
	element due = { &x, int_element };
	bool controllo = IsEqual(uno, due);
	uno.value = &x1;
	controllo = IsEqual(uno, due);
	int controllo1 = cmp(uno, due);
	uno.value = &x2;
	controllo1 = cmp(uno, due);
	
	element e2 = { "Ciao come stai?", string_element };
	cmp(e, e2);
	
	test_liste();

	system("PAUSE");
	return EXIT_SUCCESS;
}