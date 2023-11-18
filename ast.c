#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include <string.h>

lines_node_t *addline(lines_node_t *oldlines, line_node_t *newline)
{
  if (oldlines && newline)
  {
    if (oldlines->lastlines)
    {
      lines_node_t *newnode = newlines();
      newnode->currentline = newline;
      oldlines->lastlines->nextlines = newnode;
      oldlines->lastlines = newnode;
    }
    else
    {
      oldlines->currentline = newline;
      oldlines->lastlines = oldlines;
      oldlines->nextlines = NULL;
    }
  }
  return oldlines;
}

lines_node_t *newlines()
{
  lines_node_t *retval = (lines_node_t *)malloc(sizeof(lines_node_t));
  retval->currentline = NULL;
  retval->nextlines = NULL;
  retval->lastlines = NULL;
  return retval;
}

line_node_t *newline_label(char *ident, YYLTYPE loc)
{
  line_node_t *retval = (line_node_t *)malloc(sizeof(line_node_t));
  retval->lt = LT_LABEL;
  retval->location = loc;
  retval->ident = ident;
  return retval;
}

line_node_t *newline_instruction(opcode_t opcode, argument_type_t arg1, argument_type_t arg2, expr_node_t *expr1,expr_node_t *expr2, YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_INSTRUCTION;
  newline->location = loc;
  newline->opcode = opcode;
  newline->arg1 = arg1;
  newline->arg2 = arg2;
  newline->expr1 = expr1;
  newline->expr2 = expr2;

  return newline;
}
line_node_t *newline_label_instruction(char * ident ,opcode_t opcode, argument_type_t arg1, argument_type_t arg2, expr_node_t *expr1,expr_node_t *expr2, YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_LABEL_PLUS_INSTRUCTION;
  newline->location = loc;
  newline->ident = ident;
  newline->opcode = opcode;
  newline->arg1 = arg1;
  newline->arg2 = arg2;
  newline->expr1 = expr1;
  newline->expr2 = expr2;

  return newline;
}
line_node_t *newline_section(char* ident, int num , YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_SECTION;
  newline->location = loc;
  newline->ident = ident;
  newline->bytepos= num;
  
  return newline;
}
line_node_t *newline_definition(char* ident, expr_node_t *expr , YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_DEFINITION;
  newline->location = loc;
  newline->ident = ident;
  newline->expr1= expr;

  
  return newline;
}
line_node_t *newline_label_db(char* ident, expr_list *elist , YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_LABEL_PLUS_DB;
  newline->location = loc;
  newline->ident = ident;
  newline->elist= elist;

  
  return newline;
}
line_node_t *newline_label_dw(char* ident, expr_list *elist , YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_LABEL_PLUS_DW;
  newline->location = loc;
  newline->ident = ident;
  newline->elist= elist;

  
  return newline;
}

line_node_t *newline_db(expr_list *elist , YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_DB;
  newline->location = loc;
  
  newline->elist= elist;

  
  return newline;
}
line_node_t *newline_dw( expr_list *elist , YYLTYPE loc)
{
  line_node_t *newline = (line_node_t *)malloc(sizeof(line_node_t));
  newline->lt = LT_DW;
  newline->location = loc;
  
  newline->elist= elist;

  
  return newline;
}

expr_list *new_dbarg(expr_node_t *expr)
{
  expr_list *newarg = (expr_list *)malloc(sizeof(expr_list));
  newarg->expr = expr;
  newarg->next = NULL;
  return newarg;
}

expr_list *dbarg_append(expr_list *elist, expr_node_t *expr)
{
  expr_list *newarg = (expr_list *)malloc(sizeof(expr_list));
  newarg->expr = expr;
  newarg->next = NULL;
  expr_list *currarg = elist;
  while (currarg->next)
  {
    currarg = currarg->next;
  }
  currarg->next = newarg;
  return elist;
}

// Implement the expr_node_t functions

expr_node_t *num_expression(int num)
{
  expr_node_t *node = (expr_node_t *)malloc(sizeof(expr_node_t));
  node->et = ET_NUM;
  node->num = num;
  node->ident = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

expr_node_t *ident_expression(char *ident)
{
  expr_node_t *node = (expr_node_t *)malloc(sizeof(expr_node_t));
  node->et = ET_IDENT;
  node->num = 0; 
  node->ident = strdup(ident); // Make a copy of the identifier.
  node->left = NULL;
  node->right = NULL;
  return node;
}

expr_node_t *binary_expression(expr_type_t et, expr_node_t *left, expr_node_t *right)
{
  expr_node_t *node = (expr_node_t *)malloc(sizeof(expr_node_t));
  node->et = et;
  node->num = 0; // You may want to set this to a meaningful value.
  node->ident = NULL;
  node->left = left;
  node->right = right;
  return node;
}

// Implement the argument_node_t functions

argument_node_t *immediate_argument(expr_node_t *expr)
{
  argument_node_t *arg = (argument_node_t *)malloc(sizeof(argument_node_t));
  arg->at = AT_IMMEDIATE;
  arg->expr = expr;
  return arg;
}

argument_node_t *absolute_argument(expr_node_t *expr)
{
  argument_node_t *arg = (argument_node_t *)malloc(sizeof(argument_node_t));
  arg->at = AT_ABSOLUTE;
  arg->expr = expr;
  return arg;
}

argument_node_t *register_argument(argument_type_t at)
{
  argument_node_t *arg = (argument_node_t *)malloc(sizeof(argument_node_t));
  arg->at = at;
  arg->expr = NULL;
  return arg;
}

void printexpression(expr_node_t *node)
{
  if (node)
  {
    switch (node->et)
    {
      case
      ET_NUM: printf("EXPR: num, num=%d\n", node->num);
      break;
      case
      ET_IDENT: printf("EXPR: ident, ident=%s\n", node->ident);
      break;
      case
      ET_PLUS: printf("EXPR: plus\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_MINUS: printf("EXPR: minus\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_TIMES: printf("EXPR: times\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_MODULO: printf("EXPR: modulo\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_DIVISON: printf("EXPR: division\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_EQUALS: printf("EXPR: equals\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_NOT_EQUAL: printf("EXPR: not equal\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_AND: printf("EXPR: and\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      case
      ET_OR: printf("EXPR: or\n");
      printexpression(node->left);
      printexpression(node->right);
      break;
      default:
      printf("Expression type not yet implemented\n");
       ;
      }

  }
  else
  {
    printf("Empty EXPR node\n");
}
}


void printlinenode(line_node_t *node)
{
  if (node)
  {
    switch (node->lt)
    {
    case LT_LABEL:
      printf("LINE: label, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
      break;
    case LT_INSTRUCTION:
      printf("LINE: instruction, opcode=%d, arg1=%d, arg2=%d\n", node->opcode, node->arg1, node->arg2);
      printexpression(node->expr1);
      printexpression(node->expr2);
      break;
    case LT_DEFINITION:
      printf("LINE: definition, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
      break;
    case LT_SECTION:
      printf("LINE: section, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
      break;
    case LT_DB:
      printf("LINE: db, bytepos=%d, ident=%s\n", node->bytepos, node->ident);

      break;
    case LT_DW:
      printf("LINE: dw, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
      break;
    case LT_LABEL_PLUS_INSTRUCTION:
      printf("LINE: label + instruction, opcode=%d, arg1=%d, arg2=%d\n", node->opcode, node->arg1, node->arg2);
      break;
    case LT_LABEL_PLUS_DB:
      printf("LINE: label + db, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
      break;
      case LT_LABEL_PLUS_DW:
      printf("LINE: label + dw, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
      break;
    default:
      printf("Line type not yet implemented\n");
      break;
    }
  }
  else
  {
    printf("Empty LINE node\n");
  }
}

void printlinesnode(lines_node_t *node)
{
  lines_node_t *currnode = node;
  while (currnode)
  {
    printlinenode(currnode->currentline);
    currnode = currnode->nextlines;
  }
}

void printast(astroot_t root)
{
  printf("Abstract syntax tree\n");
  if (root)
  {
    printlinesnode(root);
  }
  else
  {
    printf("Empty AST\n");
  }
}
