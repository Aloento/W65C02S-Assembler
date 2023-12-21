#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Puts a new symbol and an associated value to the symbol table*/
void putsym(const char* name, int val);

/*Checks if the symbol is aready in the symbol table. Returns true if yes.*/
bool checksym(const char* name);

/*Returns the value of the symbol, if it is in the symbol table.
  If the symbol is not in the table, the return value is arbitrary.*/
int getsym(const char* name);


void printsymboltable();
