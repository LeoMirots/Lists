#include "el.h"

void *BuildValue(element e)
{
	if (e.value == NULL)
	{
		fprintf(stderr, "Elemento non esistente!");
		abort();
	}

	size_t size = 0;
	void *object = NULL;
	switch (e.type)
	{
	case char_element:
		object = malloc(sizeof(char));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(char *)object = *(char *)e.value;
		break;
	case uchar_element:
		object = malloc(sizeof(unsigned char));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(unsigned char *)object = *(unsigned char *)e.value;
		break;
	case short_element:
		object = malloc(sizeof(short));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(short *)object = *(short *)e.value;
		break;
	case ushort_element:
		object = malloc(sizeof(unsigned short));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(unsigned short *)object = *(unsigned short *)e.value;
		break;
	case int_element:
		object = malloc(sizeof(int));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(int *)object = *(int *)e.value;
		break;
	case uint_element:
		object = malloc(sizeof(unsigned int));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(unsigned int *)object = *(unsigned int *)e.value;
		break;
	case float_element:
		object = malloc(sizeof(float));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(float *)object = *(float *)e.value;
		break;
	case double_element:
		object = malloc(sizeof(double));
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		*(double *)object = *(double *)e.value;
		break;
	case string_element:
		size = strlen((char *)e.value);
		object = malloc(sizeof(char) * size + 1);
		if (object == NULL)
		{
			fprintf(stderr, "Errore in allocazione di memoria!\n");
			abort();
		}
		strcpy((char *)object, (char *)e.value);
		break;
	case struct_element:
		object = malloc(sizeof(Struct));
		strcpy(((Struct *)object)->Nome, ((Struct *)e.value)->Nome);
		strcpy(((Struct *)object)->CF, ((Struct *)e.value)->CF);
		strcpy(((Struct *)object)->Referto, ((Struct *)e.value)->Referto);
		((Struct *)object)->CodiceAccesso = ((Struct *)e.value)->CodiceAccesso;
	}
	return object;
}

void DeleteElement(element ToDelete)
{
	free(ToDelete.value);
}

bool AssignElement(element *dst, element src)
{
	if (dst->type != src.type)
	{
		fprintf(stderr, "Tentativo di assegnamento tra tipi di dato differenti!\n");
		return false;
	}

	switch (src.type)
	{
	case string_element:
		strcpy(dst->value, src.value);
		
	default:
		*dst = src;
		break;
	}
	dst->type = src.type;
	return true;
}

void PrintElement(element e)
{
	switch (e.type) {
	case ushort_element:
		printf("%hu ", (*(unsigned short*)e.value));
		break;
	case uchar_element:
		printf("%hhu ", (*(unsigned char*)e.value));
		break;
	case uint_element:
		printf("%u ", (*(unsigned int*)e.value));
		break;
	case int_element:
		printf("%d ", (*(int*)e.value));
		break;
	case char_element:
		printf("%c ", (*(char*)e.value));
		break;
	case short_element:
		printf("%hd ", (*(short*)e.value));
		break;
	case float_element:
		printf("%f ", (*(float*)e.value));
		break;
	case double_element:
		printf("%lf ", (*(double*)e.value));
		break;
	case string_element:
		printf("%s\n", (char *)e.value);
		break;
	case struct_element:
		printf("Nome: %s\n", ((Struct *)e.value)->Nome);
		printf("CF: %s\n", ((Struct *)e.value)->CF);
		printf("Referto: %s\n", ((Struct *)e.value)->Referto);
		printf("Codice Accesso: %d\n", ((Struct *)e.value)->CodiceAccesso);
		break;
	default:
		fprintf(stderr, "tipo del dato non specificato!");
		break;
	}
}

bool IsEqual(element a, element b)
{
	if (a.type != b.type)
	{
		fprintf(stderr, "Tentativo di confronto tra diversi tipi di dato!");
		abort();
	}
	
	switch (a.type)
	{
	case char_element:
		if (*(char *)(a.value) == *(char *)(b.value))
			return true;
		break;
	case uchar_element:
		if (*(unsigned char *)(a.value) == *(unsigned char *)(b.value))
			return true;
		break;
	case short_element:
		if (*(short *)(a.value) == *(short *)(b.value))
			return true;
		break;
	case ushort_element:
		if (*(unsigned short *)(a.value) == *(unsigned short *)(b.value))
			return true;
		break;
	case int_element:
		if (*(int *)(a.value) == *(int *)(b.value))
			return true;
		break;
	case uint_element:
		if (*(unsigned int *)(a.value) == *(unsigned int *)(b.value))
			return true;
		break;
	case float_element:
		if (*(float *)(a.value) == *(float *)(b.value))
			return true;
		break;
	case double_element:
		if (*(double *)(a.value) == *(double *)(b.value))
			return true;
		break;
	case string_element:
		if (strcmp((char *)a.value, (char *)b.value) == 0)
			return true;
		break;
	case struct_element:
		if (((Struct *)(a.value))->CodiceAccesso == ((Struct *)(b.value))->CodiceAccesso)
			return true;
		break;
	}
	return false;
}

int cmp(element a, element b)
{
	if (a.type != b.type)
	{
		fprintf(stderr, "Tentativo di confronto tra elementi di tipo differente!\n");
		abort();
	}

	if (IsEqual(a, b) == true)
		return 0;

	switch (a.type)
	{
	case char_element:
		if (*(char *)(a.value) > *(char *)(b.value))
			return 1;
		break;
	case uchar_element:
		if (*(unsigned char *)(a.value) > *(unsigned char *)(b.value))
			return 1;
		break;
	case short_element:
		if (*(short *)(a.value) > *(short *)(b.value))
			return 1;
		break;
	case ushort_element:
		if (*(unsigned short *)(a.value) > *(unsigned short *)(b.value))
			return 1;
		break;
	case int_element:
		if (*(int *)(a.value) > *(int *)(b.value))
			return 1;
		break;
	case uint_element:
		if (*(unsigned int *)(a.value) > *(unsigned int *)(b.value))
			return 1;
		break;
	case float_element:
		if (*(float *)(a.value) > *(float *)(b.value))
			return true;
		break;
	case double_element:
		if (*(double *)(a.value) > *(double *)(b.value))
			return 1;
		break;
	case string_element:
		return strcmp((char *)a.value, (char *)b.value);
		break;
	case struct_element:
		if (((Struct *)(a.value))->CodiceAccesso > ((Struct *)(b.value))->CodiceAccesso)
			return 1;
		break;
	}
	return -1;
}

