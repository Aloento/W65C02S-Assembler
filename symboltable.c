#include "symboltable.h"
#include "utils.h"

struct symrec
{
	const char* name;
	int sval;
	struct symrec* next;
};

typedef struct symrec symrec;

static symrec* symtable = NULL;


/**/
void putsym(const char* name, int val)
{
	symrec* res = malloc(sizeof(symrec));
	res->name = mystrdup(name);
	res->sval = val;
	res->next = symtable;
	symtable = res;
}

bool checksym(const char* name)
{
	for (symrec* p = symtable; p != NULL; p = p->next)
	{
		if (strcmp(p->name, name) == 0) { return true; }
	}
	return false;
}

int getsym(const char* name)
{
	for (symrec* p = symtable; p != NULL; p = p->next)
	{
		if (strcmp(p->name, name) == 0) { return p->sval; }
	}
	return -1; /*Arbitrary value, if the symbol is not found.*/
}
