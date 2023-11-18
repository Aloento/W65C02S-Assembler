#include "machinecodes.h"
#include <stdio.h>


void printresult1(int err, unsigned char res[3])
{
	switch (err)
	{
	case 3:
		printf("%02x %02x %02x\n", res[0], res[1], res[2]);
		break;
	case 2:
		printf("%02x %02x\n", res[0], res[1]);
		break;
	case 1:
		printf("%02x\n", res[0]);
		break;
	default:
		printf("error: %d\n", err);
		break;
	}
}

void printresult(int err, unsigned char res[3])
{
	switch (err)
	{
	case 3:
		printf("%02x ", res[0]);
		break;
	case 2:
		printf("%02x ", res[0]);
		break;
	case 1:
		printf("%02x ", res[0]);
		break;
	default:
		printf("XX ");
		break;
	}
}


int main3(int argc, char** argv)
{
	unsigned char result[3];
	/* 0 */
	printresult(getmachinebytes(0, OP_BRK, AT_NONE, 0, AT_NONE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_TSB, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0x42, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ASL, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_PUSH, AT_REG_P, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0x42, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ASL, AT_REG_A, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_TSB, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0x42, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ASL, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 1 ***/
	printresult(getmachinebytes(0, OP_BR, AT_NFLAG, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_TRB, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0x42, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ASL, AT_ZEROPAGE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_CLR, AT_CFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0x42, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_INC, AT_REG_A, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_TRB, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_OR, AT_REG_A, 0x42, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ASL, AT_ABSOLUTE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 2 ***/
	printresult(getmachinebytes(0, OP_CALL, AT_IMMEDIATE, 0xabcd, AT_NONE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_BIT, AT_ZEROPAGE, 0, AT_NONE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0x42, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROL, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_PULL, AT_REG_P, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0x42, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROL, AT_REG_A, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_BIT, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0x42, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROL, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 3 ***/
	printresult(getmachinebytes(0, OP_BR, AT_NFLAG, 1, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_BIT, AT_ZEROPAGE_X, 0, AT_NONE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0x42, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROL, AT_ZEROPAGE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_SET, AT_CFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0x42, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_DEC, AT_REG_A, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_BIT, AT_ABSOLUTE_X, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_AND, AT_REG_A, 0x42, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROL, AT_ABSOLUTE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 4 ***/
	printresult(getmachinebytes(0, OP_RETI, AT_NONE, 0, AT_NONE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0x42, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_LSR, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_PUSH, AT_REG_A, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0x42, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_LSR, AT_REG_A, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_JMP, AT_IMMEDIATE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0x42, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_LSR, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 5 ***/
	printresult(getmachinebytes(0, OP_BR, AT_VFLAG, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0x42, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_LSR, AT_ZEROPAGE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_CLR, AT_IFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0x42, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_PUSH, AT_REG_Y, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_XOR, AT_REG_A, 0x42, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_LSR, AT_ABSOLUTE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 6 ***/
	printresult(getmachinebytes(0, OP_RET, AT_NONE, 0, AT_NONE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE, 0x42, AT_IMMEDIATE, 0, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0x42, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROR, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_PULL, AT_REG_A, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0x42, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROR, AT_REG_A, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_JMP, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0x42, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROR, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 7 ***/
	printresult(getmachinebytes(0, OP_BR, AT_VFLAG, 1, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE_X, 0x42, AT_IMMEDIATE, 0, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0x42, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROR, AT_ZEROPAGE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_SET, AT_IFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0x42, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_PULL, AT_REG_Y, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_JMP, AT_ABSOLUTE_X, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_ADDC, AT_REG_A, 0x42, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_ROR, AT_ABSOLUTE_X, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 8 ***/
	printresult(getmachinebytes(0, OP_BR, AT_ALWAYS, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_INDIRECT_ZP_X, 0x42, AT_REG_A, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE, 0x42, AT_REG_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE, 0x42, AT_REG_A, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE, 0x42, AT_REG_X, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_DEC, AT_REG_Y, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_BIT, AT_IMMEDIATE, 0x42, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0x42, AT_REG_X, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE, 0x42, AT_REG_Y, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE, 0x42, AT_REG_A, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE, 0x42, AT_REG_X, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** 9 ***/
	printresult(getmachinebytes(0, OP_BR, AT_CFLAG, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_INDIRECT_Y_ZP, 0x42, AT_REG_A, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_INDIRECT_ZP, 0x42, AT_REG_A, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE_X, 0x42, AT_REG_Y, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE_X, 0x42, AT_REG_A, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ZEROPAGE_Y, 0x42, AT_REG_X, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_REG_Y, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE_Y, 0x42, AT_REG_A, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_S, 0x42, AT_REG_X, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE, 0x42, AT_IMMEDIATE, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE_X, 0x42, AT_REG_A, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_ABSOLUTE_X, 0x42, AT_IMMEDIATE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** a ***/
	printresult(getmachinebytes(0, OP_MOV, AT_REG_Y, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0, AT_IMMEDIATE, 0x42, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_REG_Y, 0, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0, AT_ZEROPAGE, 0x42, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_MOV, AT_REG_Y, 0, AT_REG_A, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0x42, AT_REG_A, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_REG_Y, 0, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0, AT_ABSOLUTE, 0x42, result), result);
	printf(".. ");
	printf("\n");


	/*** b ***/
	printresult(getmachinebytes(0, OP_BR, AT_CFLAG, 1, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_REG_Y, 0, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0, AT_ZEROPAGE_Y, 0x42, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_CLR, AT_VFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0x42, AT_REG_S, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_MOV, AT_REG_Y, 0, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_A, 0, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_MOV, AT_REG_X, 0, AT_ABSOLUTE_Y, 0x42, result), result);
	printf(".. ");
	printf("\n");

	/*** c ***/
	printresult(getmachinebytes(0, OP_CMP, AT_REG_Y, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_CMP, AT_REG_Y, 0, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_DEC, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_INC, AT_REG_Y, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_DEC, AT_REG_X, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_WAIT, AT_NONE, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_Y, 0, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_DEC, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** d ***/
	printresult(getmachinebytes(0, OP_BR, AT_ZFLAG, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_DEC, AT_ZEROPAGE_X, 0, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_CLR, AT_DFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_PUSH, AT_REG_X, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_STOP, AT_NONE, 0, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_CMP, AT_REG_A, 0, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_DEC, AT_ABSOLUTE_X, 0, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** e ***/
	printresult(getmachinebytes(0, OP_CMP, AT_REG_X, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_INDIRECT_ZP_X, 0x42, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_CMP, AT_REG_X, 0, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_ZEROPAGE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_INC, AT_ZEROPAGE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_INC, AT_REG_X, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_NOP, AT_NONE, 0, AT_NONE, 0, result), result);
	printf(".. ");
	printresult(getmachinebytes(0, OP_CMP, AT_REG_X, 0, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_ABSOLUTE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_INC, AT_ABSOLUTE, 0x42, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");

	/*** f ***/
	printresult(getmachinebytes(0, OP_BR, AT_ZFLAG, 1, AT_IMMEDIATE, 0x42, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_INDIRECT_Y_ZP, 0x42, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_INDIRECT_ZP, 0x42, result), result);
	printf(".. ");
	printf(".. ");

	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_ZEROPAGE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_INC, AT_ZEROPAGE_X, 0, AT_NONE, 0, result), result);
	printf(".. ");

	printresult(getmachinebytes(0, OP_SET, AT_DFLAG, 0, AT_NONE, 0, result), result);
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_ABSOLUTE_Y, 0x42, result), result);
	printresult(getmachinebytes(0, OP_PULL, AT_REG_X, 0, AT_NONE, 0, result), result);
	printf(".. ");
	printf(".. ");
	printresult(getmachinebytes(0, OP_SUBC, AT_REG_A, 0, AT_ABSOLUTE_X, 0x42, result), result);
	printresult(getmachinebytes(0, OP_INC, AT_ABSOLUTE_X, 0, AT_NONE, 0, result), result);
	printf(".. ");
	printf("\n");


	return 0;
}
