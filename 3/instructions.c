#include <stdio.h>
#include <stdbool.h>
#include "instructions.h"
#include "symboltable.h"

extern int bytesSoFar;

int printinstruction1(enum opcode_t opc)
{
    if (opc == OP_NOP)
    {
        printf("ea\n");
        bytesSoFar = bytesSoFar + 1;
    }
    else
    {
        printf("ERROR: wrong number of arguments\n");
        return 1;
    }
    return 0;
}

int printinstruction2(enum opcode_t opc, struct argument_t argval)
{
    if (opc == OP_JMP && argval.a_type == AT_NUM)
    {
        printf("4c %02x %02x\n", argval.a_value % 256, argval.a_value / 256);
        bytesSoFar = bytesSoFar + 3;
    }
    else
    {
        if (opc == OP_JMP && argval.a_type == AT_IDE)
        {
            symrec *val = getsym(argval.a_string);
            if (val == 0)
            {
                printf("ERROR: unknown label\n");
            }
            printf("4c %02x %02x\n", val->sval % 256, val->sval / 256);
            bytesSoFar = bytesSoFar + 3;
        }
        else if (opc == OP_INC)
        {
            if (argval.a_type == AT_REG && argval.a_value == 0) // INC A
            {
                printf("1A\n");
                bytesSoFar = bytesSoFar + 1;
            }
            if (argval.a_type == AT_REG && argval.a_value == 1) // INC X
            {
                printf("E8\n");
                bytesSoFar = bytesSoFar + 1;
            }
            if (argval.a_type == AT_REG && argval.a_value == 2) // INC Y
            {
                printf("C8\n");
                bytesSoFar = bytesSoFar + 1;
            }
            if (argval.a_type == AT_PTR)
            {
                printf("EE %02x %02x\n", argval.a_value % 256, argval.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }
        else if (opc == OP_DEC)
        {
            if (argval.a_type == AT_REG && argval.a_value == 0) // DEC A
            {
                printf("3A\n");
                bytesSoFar = bytesSoFar - 1;
            }
            if (argval.a_type == AT_REG && argval.a_value == 1) // DEC X
            {
                printf("CA\n");
                bytesSoFar = bytesSoFar - 1;
            }
            if (argval.a_type == AT_REG && argval.a_value == 2) // DEC Y
            {
                printf("88\n");
                bytesSoFar = bytesSoFar - 1;
            }
            if (argval.a_type == AT_PTR)
            {
                printf("CE %02x %02x\n", argval.a_value % 256, argval.a_value / 256);
                bytesSoFar = bytesSoFar - 3;
            }
        }
        else if (opc == OP_BZS)
        {
            if (argval.a_type == AT_NUM)
            {
                printf("F0 %02x\n", argval.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
        }
        else if (opc == OP_BZC)
        {
            if (argval.a_type == AT_NUM)
            {
                printf("D0 %02x\n", argval.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
        }
        else if (opc == OP_BCS)
        {
            if (argval.a_type == AT_NUM)
            {
                printf("B0 %02x\n", argval.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
        }
        else if (opc == OP_BCC)
        {
            if (argval.a_type == AT_NUM)
            {
                printf("90 %02x\n", argval.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
        }
        else
        {
            printf("ERROR: wrong number or type of arguments\n");
            return 1;
        }
        return 0;
    }
}

int printinstruction3(enum opcode_t opc, struct argument_t argval, struct argument_t argval2)
{
    if (opc == OP_MOV)
    {
        if (argval.a_type == AT_REG && argval2.a_type == AT_REG)
        {
            if (argval.a_value == 0 && argval2.a_value == 1)
            {
                printf("8A\n");
                bytesSoFar = bytesSoFar + 1;
            }
            if (argval.a_value == 0 && argval2.a_value == 2)
            {
                printf("98\n");
                bytesSoFar = bytesSoFar + 1;
            }
            if (argval.a_value == 1 && argval2.a_value == 0)
            {
                printf("AA\n");
                bytesSoFar = bytesSoFar + 1;
            }
            if (argval.a_value == 2 && argval2.a_value == 0)
            {
                printf("A8\n");
                bytesSoFar = bytesSoFar + 1;
            }
        }

        if (argval.a_type == AT_PTR && argval2.a_type == AT_REG)
        {
            if (argval2.a_value == 0)
            {
                printf("8D %02x %02x\n", argval.a_value % 256, argval.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
            if (argval2.a_value == 1)
            {
                printf("8E %02x %02x\n", argval.a_value % 256, argval.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
            if (argval2.a_value == 2)
            {
                printf("8C %02x %02x\n", argval.a_value % 256, argval.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }

        if (argval.a_type == AT_REG && argval.a_value == 2) // want to load to Y
        {
            if (argval2.a_type == AT_NUM) // immediate load to Y
            {
                printf("A0 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute load to Y
            {
                printf("AC %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }

        if (argval.a_type == AT_REG && argval.a_value == 1) // want to load to X
        {
            if (argval2.a_type == AT_NUM) // immediate load to X
            {
                printf("A2 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute load to X
            {
                printf("AE %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }

        if (argval.a_type == AT_REG && argval.a_value == 0) // want to load to A
        {
            if (argval2.a_type == AT_NUM) // immediate load to A
            {
                printf("A9 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute load to A
            {
                printf("AD %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }
    }

    else if (opc == OP_ADDC)
    {
        if (argval.a_type == AT_REG && argval.a_value == 0) // want to add to A
        {
            if (argval2.a_type == AT_NUM) // immediate add to A
            {
                printf("69 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute add to A
            {
                printf("6D %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }
    }

    else if (opc == OP_SUBC)
    {
        if (argval.a_type == AT_REG && argval.a_value == 0) // want to sub from A
        {
            if (argval2.a_type == AT_NUM) // immediate sub from A
            {
                printf("E9 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar - 2;
            }
            if (argval2.a_type == AT_PTR) // absolute sub from A
            {
                printf("ED %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar - 3;
            }
        }
    }

    else if (opc == OP_AND)
    {
        if (argval.a_type == AT_REG && argval.a_value == 0) // want to AND with A
        {
            if (argval2.a_type == AT_NUM) // immediate AND with A
            {
                printf("29 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute AND with A
            {
                printf("2D %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }
    }

    else if (opc == OP_OR)
    {
        if (argval.a_type == AT_REG && argval.a_value == 0) // want to OR with A
        {
            if (argval2.a_type == AT_NUM) // immediate OR with A
            {
                printf("09 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute OR with A
            {
                printf("0D %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }
    }

    else if (opc == OP_XOR)
    {
        if (argval.a_type == AT_REG && argval.a_value == 0) // want to XOR with A
        {
            if (argval2.a_type == AT_NUM) // immediate XOR with A
            {
                printf("49 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute XOR with A
            {
                printf("4D %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }
    }

    else if (opc == OP_CMP)
    {
        if (argval.a_type == AT_REG && argval.a_value == 0) // want to compare A
        {
            if (argval2.a_type == AT_NUM) // immediate compare A
            {
                printf("C9 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute compare A
            {
                printf("CD %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }

        if (argval.a_type == AT_REG && argval.a_value == 1) // want to compare X
        {
            if (argval2.a_type == AT_NUM) // immediate compare X
            {
                printf("E0 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute compare X
            {
                printf("EC %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
            }
        }

        if (argval.a_type == AT_REG && argval.a_value == 2) // want to compare Y
        {
            if (argval2.a_type == AT_NUM) // immediate compare Y
            {
                printf("C0 %02x\n", argval2.a_value);
                bytesSoFar = bytesSoFar + 2;
            }
            if (argval2.a_type == AT_PTR) // absolute compare Y
            {
                printf("CC %02x %02x\n", argval2.a_value % 256, argval2.a_value / 256);
                bytesSoFar = bytesSoFar + 3;
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
