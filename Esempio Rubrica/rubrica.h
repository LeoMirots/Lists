#if !defined RUBRICA_H
#define RUBRICA_H
#include "list.h"

extern list DeleteContact(list l);
extern list FindPerson(list l);
extern list AddNew(list l);
extern int AZorder(const char *str1, const char *str2);
extern list GetOrder(list l);

#endif //RUBRICA_H