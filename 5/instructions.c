#include <stdio.h>
#include "instructions.h"
#include "symboltable.h"

extern int bytesSoFar;

int printinstruction1(const enum opcode_t opc)
{
    if (opc == OP_NOP)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0xea, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else if (opc == OP_RET)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0x60, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else if (opc == OP_RETI)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0x40, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else if (opc == OP_SEC)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0x38, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else if (opc == OP_CLC)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0x18, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else if (opc == OP_SEI)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0x58, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else if (opc == OP_CLV)
    {
        file_ast *ast = ast_new(IT_ONEBYTE, 0xB8, NULL);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 1;
    }
    else
    {
        printf("ERROR: wrong number of arguments\n");
        return 1;
    }
    return 0;
}

int printinstruction2(const enum opcode_t opc, struct argument_t argval)
{
    if (opc == OP_JMP && argval.a_type == AT_NUM)
    {
        file_ast *ast = ast_new(IT_THREEBYTE, 0x4c, argval.a_expr);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 3;
    }
    else if (opc == OP_JMP && argval.a_expr->exp_type == ET_IDENT)
    {
        symrec *val = getsym(argval.a_expr->identval);
        if (val == 0)
        {
            printf("ERROR: unknown label\n");
        }
        file_ast *ast = ast_new(IT_THREEBYTE, 0x4c, argval.a_expr);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 3;
    }
    else if (opc == OP_CALL && argval.a_type == AT_PTR)
    {
        file_ast *ast = ast_new(IT_THREEBYTE, 0x20, argval.a_expr);
        ast_append(ast);
        bytesSoFar = bytesSoFar + 3;
    }
    else if (opc == OP_INC)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // INC A
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x1A, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        if (argval.a_type == AT_REG && argval.a_reg == 1) // INC X
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0xE8, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        if (argval.a_type == AT_REG && argval.a_reg == 2) // INC Y
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0xC8, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        if (argval.a_type == AT_PTR)
        {
            file_ast *ast = ast_new(IT_THREEBYTE, 0xEE, argval.a_expr);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 3;
        }
    }
    else if (opc == OP_DEC)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // DEC A
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x3A, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        if (argval.a_type == AT_REG && argval.a_reg == 1) // DEC X
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0xCA, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        if (argval.a_type == AT_REG && argval.a_reg == 2) // DEC Y
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x88, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        if (argval.a_type == AT_PTR)
        {
            file_ast *ast = ast_new(IT_THREEBYTE, 0xCE, argval.a_expr);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 3;
        }
    }
    else if (opc == OP_BZS)
    {
        if (argval.a_type == AT_NUM)
        {
            file_ast *ast = ast_new(IT_TWOBYTE, 0xF0, argval.a_expr);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 2;
        }
    }
    else if (opc == OP_BZC)
    {
        if (argval.a_type == AT_NUM)
        {
            file_ast *ast = ast_new(IT_TWOBYTE, 0xD0, argval.a_expr);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 2;
        }
    }
    else if (opc == OP_BCS)
    {
        if (argval.a_type == AT_NUM)
        {
            file_ast *ast = ast_new(IT_TWOBYTE, 0xB0, argval.a_expr);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 2;
        }
    }
    else if (opc == OP_BCC)
    {
        if (argval.a_type == AT_NUM)
        {
            file_ast *ast = ast_new(IT_TWOBYTE, 0x90, argval.a_expr);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 2;
        }
    }
    else if (opc == OP_ROTL)
    {
        if (argval.a_reg == 0)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x2a, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
    }
    else if (opc == OP_ROTR)
    {
        if (argval.a_reg == 0)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x6a, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
    }
    else if (opc == OP_PUSH)
    {
        if (argval.a_reg == 0)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x48, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        else if (argval.a_reg == 1)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0xda, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        else if (argval.a_reg == 2)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x5a, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        else if (argval.a_reg == 3)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x08, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
    }
    else if (opc == OP_POP)
    {
        if (argval.a_reg == 0)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x68, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        else if (argval.a_reg == 1)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0xfa, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        else if (argval.a_reg == 2)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x7a, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
        else if (argval.a_reg == 3)
        {
            file_ast *ast = ast_new(IT_ONEBYTE, 0x28, NULL);
            ast_append(ast);
            bytesSoFar = bytesSoFar + 1;
        }
    }
    else
    {
        printf("ERROR: wrong number or type of arguments\n");
        return 1;
    }
    return 0;
}

int printinstruction3(enum opcode_t opc, struct argument_t argval, struct argument_t argval2)
{
    if (opc == OP_MOV)
    {
        if (argval.a_type == AT_REG && argval2.a_type == AT_REG)
        {
            if (argval.a_reg == 0 && argval2.a_reg == 1)
            {
                file_ast *ast = ast_new(IT_ONEBYTE, 0x8a, NULL);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 1;
                return 0;
            }
            if (argval.a_reg == 0 && argval2.a_reg == 2)
            {
                file_ast *ast = ast_new(IT_ONEBYTE, 0x98, NULL);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 1;
                return 0;
            }
            if (argval.a_reg == 1 && argval2.a_reg == 0)
            {
                file_ast *ast = ast_new(IT_ONEBYTE, 0xAA, NULL);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 1;
                return 0;
            }
            if (argval.a_reg == 2 && argval2.a_reg == 0)
            {
                file_ast *ast = ast_new(IT_ONEBYTE, 0xA8, NULL);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 1;
                return 0;
            }
            if (argval.a_reg == 4 && argval2.a_reg == 1)
            {
                file_ast *ast = ast_new(IT_ONEBYTE, 0x9a, NULL);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 1;
                return 0;
            }
            if (argval.a_reg == 1 && argval2.a_reg == 4)
            {
                file_ast *ast = ast_new(IT_ONEBYTE, 0xba, NULL);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 1;
                return 0;
            }
        }

        if (argval.a_type == AT_PTR && argval2.a_type == AT_REG)
        {
            if (argval2.a_reg == 0)
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x8D, argval.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
            if (argval2.a_reg == 1)
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x8E, argval.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
            if (argval2.a_reg == 2)
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x8C, argval.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }

        if (argval.a_type == AT_REG && argval.a_reg == 2) // want to load to Y
        {
            if (argval2.a_type == AT_NUM) // immediate load to Y
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xA0, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute load to Y
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xAC, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }

        if (argval.a_type == AT_REG && argval.a_reg == 1) // want to load to X
        {
            if (argval2.a_type == AT_NUM) // immediate load to X
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xA2, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute load to X
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xAE, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }

        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to load to A
        {
            if (argval2.a_type == AT_NUM) // immediate load to A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xA9, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute load to A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xAD, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
            if (argval2.a_expr->exp_type == ET_IDENT) // absolute load to A
            {
                symrec *val = getsym(argval2.a_expr->identval);
                if (val == 0)
                {
                    printf("ERROR: unknown mov label\n");
                }
                file_ast *ast = ast_new(IT_THREEBYTE, 0xAD, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else if (opc == OP_ADDC)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to add to A
        {
            if (argval2.a_type == AT_NUM) // immediate add to A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0x69, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute add to A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x6D, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else if (opc == OP_SUBC)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to sub from A
        {
            if (argval2.a_type == AT_NUM) // immediate sub from A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xE9, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute sub from A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xED, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else if (opc == OP_AND)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to AND with A
        {
            if (argval2.a_type == AT_NUM) // immediate AND with A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0x29, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute AND with A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x2D, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else if (opc == OP_OR)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to OR with A
        {
            if (argval2.a_type == AT_NUM) // immediate OR with A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0x09, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute OR with A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x0D, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else if (opc == OP_XOR)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to XOR with A
        {
            if (argval2.a_type == AT_NUM) // immediate XOR with A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0x49, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute XOR with A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0x4D, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else if (opc == OP_CMP)
    {
        if (argval.a_type == AT_REG && argval.a_reg == 0) // want to compare A
        {
            if (argval2.a_type == AT_NUM) // immediate compare A
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xC9, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute compare A
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xCD, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }

        if (argval.a_type == AT_REG && argval.a_reg == 1) // want to compare X
        {
            if (argval2.a_type == AT_NUM) // immediate compare X
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xE0, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute compare X
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xEC, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }

        if (argval.a_type == AT_REG && argval.a_reg == 2) // want to compare Y
        {
            if (argval2.a_type == AT_NUM) // immediate compare Y
            {
                file_ast *ast = ast_new(IT_TWOBYTE, 0xC0, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 2;
                return 0;
            }
            if (argval2.a_type == AT_PTR) // absolute compare Y
            {
                file_ast *ast = ast_new(IT_THREEBYTE, 0xCC, argval2.a_expr);
                ast_append(ast);
                bytesSoFar = bytesSoFar + 3;
                return 0;
            }
        }
    }

    else
    {
        printf("ERROR: wrong number or type of arguments\n");
        return 1;
    }

    return 0;
}

struct llist_t *llist_add(struct llist_t *list, int value)
{
    struct llist_t *head = list;
    struct llist_t *new = malloc(sizeof(struct llist_t));
    while (list->next != NULL)
    {
        list = list->next;
    }

    list->next = new;
    new->value = value;
    new->next = NULL;

    return head;
}

struct llist_t *llist_new(int value)
{
    struct llist_t *new = malloc(sizeof(struct llist_t));
    new->value = value;
    new->next = NULL;
    return new;
}

void printDB(struct llist_t *list)
{
    while (list != NULL)
    {
        printf("%02x ", list->value);
        list = list->next;
        bytesSoFar++;
    }
    printf("\n");
}
