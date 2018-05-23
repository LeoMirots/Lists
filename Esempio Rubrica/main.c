#include "rubrica.h"

int main(void)
{
	list rubrica = empty_list();
	printf("Gestore rubrica monco in azione...\n");
menu:
	printf("Selezionare l'operazione desiderata:\n");
	printf("1) Inserisci un nuovo contatto;\n");
	printf("2) Stampa tutti i contatti;\n");
	printf("3) Cerca un contatto;\n");
	printf("4) Elimina un contatto;\n");
	printf("5) Ordina i contatti in ordine alfabetico;\n");
	printf("0) Esci;\n");

	printf("Inserire indice:\n");
	int ctrl = 0;
	size_t selection = 0;
	ctrl = scanf(" %u", &selection);
	switch (selection)
	{
	case 0:
		return EXIT_SUCCESS;
	case 1:
	{	
		rubrica = AddNew(rubrica);
		system("pause");
		goto menu;
	}
	case 2:
	{
		PrintList(rubrica);
		system("pause");
		goto menu;
	}
	case 3:
	{
		FindPerson(rubrica);
		goto menu;
	}
	case 4:
	{
		rubrica = DeleteContact(rubrica);
		system("pause");
		goto menu;
	}
	case 5:
	{
		rubrica = GetOrder(rubrica);
		system("pause");
		goto menu;
	}
	default:
		printf("Inserire un indice valido, riprovare;\n");
		system("pause");
		goto menu;
	}
	return EXIT_SUCCESS;
}