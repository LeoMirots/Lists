#include "el.h"
#include "list.h"

element build_element(void* el, int tipo)
{
	/*
	 * BISOGNA ricordarsi poi ch c'è il problema dell'allocamento di memoria.
	 * Infatti,  ogni volta che si crea un nuovo elemento si alloca memoria per il valore dell'elemento,
	 * e quella memoria va pur sempre e comunque svuotata!
	 * Nel copiare un elemento nell'altro non si fa altro che copiare la vecchia memoria allocandone di nuova. Quindi,
	 * CI SI DEVE SEMPRE RICORDARE DI USARE ELEMENT DEL!
	 */
	element out;
	out.type = tipo;
	switch (tipo) {
	case char_element:
	case uchar_element:
		out.value = malloc(sizeof(char));
		memcpy(out.value, el, sizeof(char));
		break;
	case short_element:
	case ushort_element:
		out.value = malloc(sizeof(short));
		memcpy(out.value, el, sizeof(short));
		break;
	case float_element:
		out.value = malloc(sizeof(float));
		memcpy(out.value, el, sizeof(float));
		break;
	case double_element:
		out.value = malloc(sizeof(double));
		memcpy(out.value, el, sizeof(double));
		break;
	case int_element:
	case uint_element:
		out.value = malloc(sizeof(int));
		memcpy(out.value, el, sizeof(int));
		break;
	case string_element:
		out.value = string_copy(el);
		break;
	case persona_element:
		out.value = persona_copy(el);
		break;
	default:
		fprintf(stderr, "What do you want to make me build?\n Do you think you are jedi waving  your mouse?\nWrong types are not accepted, only right ones \n(or money)\n");
		break;
	}
	return out;
}

bool IsEqual(element a, element b)
{
	if (cmp(&a, &b) == 0)
		return true;
	return false;
}

int cmp(element *a, element *b)
{
	if (a->type != b->type) {
		fprintf(stderr, "Tentativo di confronto tra elementi di tipo differente! Errore!\n");
		abort();
	}
	int out;
	switch (a->type) {
	case ushort_element:
		out = (int)(*((ushort*)(a->value)) - *((ushort*)(b->value)));
		break;
	case uchar_element:
		out = (int)(*((uchar*)(a->value)) - *((uchar*)(b->value)));
		break;
	case uint_element:
		out = (int)(*((uint*)(a->value)) - (*(uint*)(b->value)));
		break;
	case int_element:
		out = (int)(*((int*)(a->value)) - *((int*)(b->value)));
		break;
	case char_element:
		out = (int)(*((char*)(a->value)) - *((char*)(b->value)));
		break;
	case short_element:
		out = (int)(*((short*)(a->value)) - *((short*)(b->value)));
		break;
	case float_element:
		out = (int)(*((float*)(a->value)) - *((float*)(b->value)));
		break;
	case double_element:
		out = (int)(*((double*)(a->value)) - *((double*)(b->value)));
		break;
	case string_element:
		out = (int)strcmp(((string*)a->value)->s, ((string*)b->value)->s);
		break;
	default:
		printf("Unknow type inserted!");
		abort();
		break;
	}
	return out;
}

void AssignElement(element *dst, element src)
{
	if (src.type == string_element)
	{
		dst->type = string_element;
		strcpy(((string *)dst->value)->s, ((string *)src.value)->s);
		return;
	}

	if (src.type == persona_element)
	{
		dst->type = persona_element;
		strcpy(((Persona *)dst->value)->Nome, ((Persona *)src.value)->Nome);
		strcpy(((Persona *)dst->value)->Cognome, ((Persona *)src.value)->Cognome);
		strcpy(((Persona *)dst->value)->CF, ((Persona *)src.value)->CF);
		strcpy(((Persona *)dst->value)->Referto, ((Persona *)src.value)->Referto);
		((Persona *)dst->value)->CodiceAccesso = ((Persona *)src.value)->CodiceAccesso;
		return;
	}

	dst->value = src.value;
	dst->type = src.type;
}

void DeleteElement(element e)
{
	switch (e.type) {
	case string_element:
		str_del(*((string*)e.value));
		break;
	case persona_element:
		free(e.value);
		break;
	default:
		break;
	}
}

void PrintElement(element e)
{
	switch (e.type) {
	case ushort_element:
		printf("%u", (*(unsigned short*)e.value));
		break;
	case uchar_element:
		printf("%u", (*(unsigned char*)e.value));
		break;
	case uint_element:
		printf("%u", (*(unsigned int*)e.value));
		break;
	case int_element:
		printf("%d", (*(int*)e.value));
		break;
	case char_element:
		printf("%d", (*(char*)e.value));
		break;
	case short_element:
		printf("%d", (*(short*)e.value));
		break;
	case float_element:
		printf("%f", (*(float*)e.value));
		break;
	case double_element:
		printf("%lf", (*(double*)e.value));
		break;
	case string_element:
		printf("%s", ((string*)e.value)->s);
		break;
	case persona_element:
		printf("Nome: %s\n", ((Persona*)e.value)->Nome);
		printf("Cognome: %s\n", ((Persona *)e.value)->Cognome);
		printf("CF: %s\n", ((Persona*)e.value)->CF);
		printf("Referto: %s\n", ((Persona*)e.value)->Referto);
		printf("Codice Accesso: %d\n", ((Persona*)e.value)->CodiceAccesso);
		break;
	default:
		printf("tipo del dato non specificato;");
		break;
	}
}


string* string_copy(void *str_in)
{
	string *str_out = malloc(sizeof(string));
	*str_out = build_string(((string*)str_in)->s, ((string*)str_in)->len);
	//str_out->s = strcpy(&str_out->s, str_in);
	//str_out->len = strlen(str_in);
	return str_out;
}
string build_string(char* str_in, size_t len)
{
	char* str_out = calloc(len + 1, sizeof(char));
	str_out = strcpy(str_out, str_in);
	string *st = malloc(sizeof(string));
	st->s = str_out;
	st->len = len;
	return *st;
}
string string_append(char* add_str, string str)
{
	size_t len = strlen(add_str);
	str.len += len;
	strcat(str.s, add_str);
	return str;
}
void str_del(string str)
{
	free(str.s);
}

Persona build_persona(char* nome, char *cognome, char* cf, char* referto, int codiceAccesso)
{
	Persona p;
	strcpy(p.CF, cf);
	strcpy(p.Nome, nome);
	strcpy(p.Cognome, cognome);
	strcpy(p.Referto, referto);
	p.CodiceAccesso = codiceAccesso;
	return p;
}

Persona* persona_copy(void* p)
{
	Persona* pout = malloc(sizeof(Persona));
	*pout = build_persona(((Persona*)p)->Nome, ((Persona *)p)->Cognome, ((Persona*)p)->CF, ((Persona*)p)->Referto, ((Persona*)p)->CodiceAccesso);
	return pout;
}