#include "symboltable.h"

static symrec *symtable;

symrec *putsym(char const *name, int val)
{
  symrec *res = (symrec *) malloc(sizeof(symrec));
  res->name = strdup(name);
  res->sval = val;
  res->next = symtable;
  symtable = res;
  return res;
}

symrec *getsym(char const *name)
{
  for (symrec *p = symtable; p!=NULL; p = p->next)
  {
    if (strcmp(p->name, name) == 0) { return p;}
  }
  return NULL;
}
