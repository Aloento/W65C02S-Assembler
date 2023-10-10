#include <stdlib.h>
#include <string.h>

struct symrec
{
  char const *name;
  int sval;
  struct symrec *next;
};

typedef struct symrec symrec;

symrec *putsym(char const *name, int val);
symrec *getsym(char const *name);
