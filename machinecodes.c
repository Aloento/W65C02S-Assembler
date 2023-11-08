#include "machinecodes.h"
#include <stdio.h>

static int writebyte(int b, int err, unsigned char result[3])
{
	if (0 <= b && b <= 0xff)
	{
		result[1] = b;
		return 2;
	}
	return err;
}

static int writeword(int b, int err, unsigned char result[3])
{
	if (0 <= b && b <= 0xffff)
	{
		result[1] = b % 0x100;
		result[2] = b / 0x100;
		return 3;
	}
	return err;
}

static int writebranch(int bytepos, int num2, unsigned char result[3])
{
	if (0 <= bytepos && bytepos <= 0xffff && 0 <= num2 && num2 <= 0xffff)
	{
		int diff = bytepos - num2 - 2;
		if (diff < -128 || 127 < diff) { return -5; }
		result[1] = (diff + 0x100) % 0x100;
		return 2;
	}
	return -4; /*address wraparound not supported*/
}

static int writearith2(
	opcode_t opcode,
	argument_type_t arg1, int num1,
	argument_type_t arg2, int num2,
	unsigned char result[3])
{
	unsigned char offset;
	int err = -4;
	int err1 = -2;
	if (arg1 != AT_REG_A)
	{
		if (opcode == OP_MOV && arg2 == AT_REG_A)
		{
			offset = 0x80;
			arg2 = arg1;
			num2 = num1;
			err = -3;
			err1 = -1;
		}
		else
		{
			return -1; /*only the a register is good*/
		}
	}
	else
	{
		switch (opcode)
		{
		case OP_ADDC: offset = 0x60;
			break;
		case OP_SUBC: offset = 0xe0;
			break;
		case OP_AND: offset = 0x20;
			break;
		case OP_OR: offset = 0x00;
			break;
		case OP_XOR: offset = 0x40;
			break;
		case OP_CMP: offset = 0xc0;
			break;
		case OP_MOV: offset = 0xa0;
			break;
		default: return 0;
		}
	}
	switch (arg2)
	{
	case AT_IMMEDIATE:
		result[0] = offset + 0x09;
		return writebyte(num2, err, result);
	case AT_ABSOLUTE:
		result[0] = offset + 0x0d;
		return writeword(num2, err, result);
	case AT_ABSOLUTE_X:
		result[0] = offset + 0x1d;
		return writeword(num2, err, result);
	case AT_ABSOLUTE_Y:
		result[0] = offset + 0x19;
		return writeword(num2, err, result);
	case AT_ZEROPAGE:
		result[0] = offset + 0x05;
		return writebyte(num2, err, result);
	case AT_ZEROPAGE_X:
		result[0] = offset + 0x15;
		return writebyte(num2, err, result);
	case AT_INDIRECT_ZP:
		result[0] = offset + 0x12;
		return writebyte(num2, err, result);
	case AT_INDIRECT_ZP_X:
		result[0] = offset + 0x01;
		return writebyte(num2, err, result);
	case AT_INDIRECT_Y_ZP:
		result[0] = offset + 0x11;
		return writebyte(num2, err, result);
	default:
		return err1;
	}
}

static int writearith1(
	opcode_t opcode,
	argument_type_t arg1, int num1,
	argument_type_t arg2, int num2,
	unsigned char result[3])
{
	unsigned char offset;
	if (arg2 != AT_NONE)
	{
		return -2;
	}
	switch (opcode)
	{
	case OP_INC:
		if (arg1 == AT_REG_A)
		{
			result[0] = 0x1a;
			return 1;
		}
		if (arg1 == AT_REG_X)
		{
			result[0] = 0xe8;
			return 1;
		}
		if (arg1 == AT_REG_Y)
		{
			result[0] = 0xc8;
			return 1;
		}
		offset = 0xe0;
		break;
	case OP_DEC:
		if (arg1 == AT_REG_A)
		{
			result[0] = 0x3a;
			return 1;
		}
		if (arg1 == AT_REG_X)
		{
			result[0] = 0xca;
			return 1;
		}
		if (arg1 == AT_REG_Y)
		{
			result[0] = 0x88;
			return 1;
		}
		offset = 0xc0;
		break;
	case OP_ROR: offset = 0x60;
		break;
	case OP_ROL: offset = 0x20;
		break;
	case OP_ASL: offset = 0x00;
		break;
	case OP_LSR: offset = 0x40;
		break;
	default: return 0;
	}
	switch (arg1)
	{
	case AT_REG_A:
		result[0] = offset + 0x0a;
		return 1;
	case AT_ABSOLUTE:
		result[0] = offset + 0x0e;
		return writeword(num1, -3, result);
	case AT_ABSOLUTE_X:
		result[0] = offset + 0x1e;
		return writeword(num1, -3, result);
	case AT_ZEROPAGE:
		result[0] = offset + 0x06;
		return writebyte(num1, -3, result);
	case AT_ZEROPAGE_X:
		result[0] = offset + 0x16;
		return writebyte(num1, -3, result);
	default:
		return -1;
	}
}


static int writemov(
	argument_type_t arg1, int num1,
	argument_type_t arg2, int num2,
	unsigned char result[3])
{
	if (arg1 == AT_REG_A)
	{
		if (arg2 == AT_REG_X)
		{
			result[0] = 0x8a;
			return 1;
		}
		if (arg2 == AT_REG_Y)
		{
			result[0] = 0x98;
			return 1;
		}
		return writearith2(OP_MOV, arg1, num1, arg2, num2, result);
	}
	if (arg2 == AT_REG_A)
	{
		if (arg1 == AT_REG_X)
		{
			result[0] = 0xaa;
			return 1;
		}
		if (arg1 == AT_REG_Y)
		{
			result[0] = 0xa8;
			return 1;
		}
		return writearith2(OP_MOV, arg1, num1, arg2, num2, result);
	}
	if (arg1 == AT_REG_X)
	{
		switch (arg2)
		{
		case AT_REG_S:
			result[0] = 0xba;
			return 1;
		case AT_IMMEDIATE:
			result[0] = 0xa2;
			return writebyte(num2, -4, result);
		case AT_ABSOLUTE:
			result[0] = 0xae;
			return writeword(num2, -4, result);
		case AT_ABSOLUTE_Y:
			result[0] = 0xbe;
			return writeword(num2, -4, result);
		case AT_ZEROPAGE:
			result[0] = 0xa6;
			return writebyte(num2, -4, result);
		case AT_ZEROPAGE_Y:
			result[0] = 0xb6;
			return writebyte(num2, -4, result);
		default:
			return -2;
		}
	}
	if (arg1 == AT_REG_Y)
	{
		switch (arg2)
		{
		case AT_IMMEDIATE:
			result[0] = 0xa0;
			return writebyte(num2, -4, result);
		case AT_ABSOLUTE:
			result[0] = 0xac;
			return writeword(num2, -4, result);
		case AT_ABSOLUTE_X:
			result[0] = 0xbc;
			return writeword(num2, -4, result);
		case AT_ZEROPAGE:
			result[0] = 0xa4;
			return writebyte(num2, -4, result);
		case AT_ZEROPAGE_X:
			result[0] = 0xb4;
			return writebyte(num2, -4, result);
		default:
			return -2;
		}
	}
	if (arg2 == AT_REG_X)
	{
		switch (arg1)
		{
		case AT_REG_S:
			result[0] = 0x9a;
			return 1;
		case AT_ABSOLUTE:
			result[0] = 0x8e;
			return writeword(num1, -3, result);
		case AT_ZEROPAGE:
			result[0] = 0x86;
			return writebyte(num1, -3, result);
		case AT_ZEROPAGE_Y:
			result[0] = 0x96;
			return writebyte(num1, -3, result);
		default:
			return -2;
		}
	}
	if (arg2 == AT_REG_Y)
	{
		switch (arg1)
		{
		case AT_ABSOLUTE:
			result[0] = 0x8c;
			return writeword(num1, -3, result);
		case AT_ZEROPAGE:
			result[0] = 0x84;
			return writebyte(num1, -3, result);
		case AT_ZEROPAGE_X:
			result[0] = 0x94;
			return writebyte(num1, -3, result);
		default:
			return -2;
		}
	}
	if (arg2 == AT_IMMEDIATE)
	{
		if (num2 != 0) { return -4; } /*only zero can be stored to memory*/
		switch (arg1)
		{
		case AT_ABSOLUTE:
			result[0] = 0x9c;
			return writeword(num1, -3, result);
		case AT_ABSOLUTE_X:
			result[0] = 0x9e;
			return writeword(num1, -3, result);
		case AT_ZEROPAGE:
			result[0] = 0x64;
			return writebyte(num1, -3, result);
		case AT_ZEROPAGE_X:
			result[0] = 0x74;
			return writebyte(num1, -3, result);
		default:
			return -2;
		}
	}
	return -1;
}


/**
Computes the machine code bytes for an instruction
bytepos: the memory address of the instruction (only needed
   for the branch instructions for calculating the distance
   to the jump target)
opcode: opcode of instruction
arg1: type of the first argument
num1: value of the first argument, if applicable
arg2: type of the second argument
num2: value of the second argument, if applicable
result: the machie code bytes will be written into this array

Return value: 1-3: number of bytes written  (success)
              0: bad opcode
             -1: first argument type is not appropriate
             -2: second argument type is not appropriate
             -3: first argument value is out of range
             -4: second argument value is out of range
             -5: branch too far
*/
int getmachinebytes(int bytepos,
                    opcode_t opcode,
                    argument_type_t arg1, int num1,
                    argument_type_t arg2, int num2,
                    unsigned char result[3])
{
	switch (opcode)
	{
	case OP_MOV:
		return writemov(arg1, num1, arg2, num2, result);
	case OP_PULL:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_REG_A:
			result[0] = 0x68;
			return 1;
		case AT_REG_X:
			result[0] = 0xfa;
			return 1;
		case AT_REG_Y:
			result[0] = 0x7a;
			return 1;
		case AT_REG_P:
			result[0] = 0x28;
			return 1;
		default:
			return -1;
		}
	case OP_PUSH:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_REG_A:
			result[0] = 0x48;
			return 1;
		case AT_REG_X:
			result[0] = 0xda;
			return 1;
		case AT_REG_Y:
			result[0] = 0x5a;
			return 1;
		case AT_REG_P:
			result[0] = 0x08;
			return 1;
		default:
			return -1;
		}
	case OP_SET:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_CFLAG:
			result[0] = 0x38;
			return 1;
		case AT_IFLAG:
			result[0] = 0x78;
			return 1;
		case AT_DFLAG:
			result[0] = 0xf8;
			return 1;
		default:
			return -1;
		}
	case OP_CLR:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_CFLAG:
			result[0] = 0x18;
			return 1;
		case AT_IFLAG:
			result[0] = 0x58;
			return 1;
		case AT_VFLAG:
			result[0] = 0xB8;
			return 1;
		case AT_DFLAG:
			result[0] = 0xd8;
			return 1;
		default:
			return -1;
		}

	case OP_ADDC:
	case OP_SUBC:
	case OP_AND:
	case OP_OR:
	case OP_XOR:
		return writearith2(opcode, arg1, num1, arg2, num2, result);
	case OP_INC:
	case OP_DEC:
	case OP_ROR:
	case OP_ROL:
	case OP_ASL:
	case OP_LSR:
		return writearith1(opcode, arg1, num1, arg2, num2, result);


	case OP_CMP:
		switch (arg1)
		{
		case AT_REG_X:
			switch (arg2)
			{
			case AT_IMMEDIATE:
				result[0] = 0xe0;
				return writebyte(num2, -4, result);
			case AT_ABSOLUTE:
				result[0] = 0xec;
				return writeword(num2, -4, result);
			case AT_ZEROPAGE:
				result[0] = 0xe4;
				return writebyte(num2, -4, result);
			default:
				return -2;
			}
		case AT_REG_Y:
			switch (arg2)
			{
			case AT_IMMEDIATE:
				result[0] = 0xc0;
				return writebyte(num2, -4, result);
			case AT_ABSOLUTE:
				result[0] = 0xcc;
				return writeword(num2, -4, result);
			case AT_ZEROPAGE:
				result[0] = 0xc4;
				return writebyte(num2, -4, result);
			default:
				return -2;
			}
		default:
			return writearith2(opcode, arg1, num1, arg2, num2, result);
		}

	case OP_BIT:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_ABSOLUTE:
			result[0] = 0x2c;
			return writeword(num1, -3, result);
		case AT_ABSOLUTE_X:
			result[0] = 0x3c;
			return writeword(num1, -3, result);
		case AT_IMMEDIATE:
			result[0] = 0x89;
			return writebyte(num1, -3, result);
		case AT_ZEROPAGE:
			result[0] = 0x24;
			return writebyte(num1, -3, result);
		case AT_ZEROPAGE_X:
			result[0] = 0x34;
			return writebyte(num1, -3, result);
		default:
			return -1;
		}

	case OP_TRB:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_ABSOLUTE:
			result[0] = 0x1c;
			return writeword(num1, -3, result);
		case AT_ZEROPAGE:
			result[0] = 0x14;
			return writebyte(num1, -3, result);
		default:
			return -1;
		}

	case OP_TSB:
		if (arg2 != AT_NONE) return -2; /*one argument instruction*/
		switch (arg1)
		{
		case AT_ABSOLUTE:
			result[0] = 0x0c;
			return writeword(num1, -3, result);
		case AT_ZEROPAGE:
			result[0] = 0x04;
			return writebyte(num1, -3, result);
		default:
			return -1;
		}


	case OP_NOP:
		if (arg1 != AT_NONE) { return -1; }
		if (arg2 != AT_NONE) { return -2; }
		result[0] = 0xea;
		return 1;

	case OP_JMP:
		if (arg2 != AT_NONE) { return -2; }
		switch (arg1)
		{
		case AT_IMMEDIATE:
			result[0] = 0x4c;
			return writeword(num1, -3, result);
		case AT_ABSOLUTE:
			result[0] = 0x6c;
			return writeword(num1, -3, result);
		case AT_ABSOLUTE_X:
			result[0] = 0x7c;
			return writeword(num1, -3, result);
		default:
			return -1;
		}

	case OP_BR:
		if (arg2 != AT_IMMEDIATE) { return -2; }
		switch (arg1)
		{
		case AT_NFLAG:
			{
				if (num1 == 0)
				{
					result[0] = 0x10;
					return writebranch(bytepos, num2, result);
				}
				result[0] = 0x30;
				return writebranch(bytepos, num2, result);
			}
		case AT_VFLAG:
			{
				if (num1 == 0)
				{
					result[0] = 0x50;
					return writebranch(bytepos, num2, result);
				}
				result[0] = 0x70;
				return writebranch(bytepos, num2, result);
			}
		case AT_CFLAG:
			{
				if (num1 == 0)
				{
					result[0] = 0x90;
					return writebranch(bytepos, num2, result);
				}
				result[0] = 0xb0;
				return writebranch(bytepos, num2, result);
			}
		case AT_ZFLAG:
			{
				if (num1 == 0)
				{
					result[0] = 0xd0;
					return writebranch(bytepos, num2, result);
				}
				result[0] = 0xf0;
				return writebranch(bytepos, num2, result);
			}
		case AT_ALWAYS:
			result[0] = 0x80;
			return writebranch(bytepos, num2, result);
		default:
			return -1;
		}
	case OP_CALL:
		if (arg1 != AT_IMMEDIATE) { return -1; }
		if (arg2 != AT_NONE) { return -2; }
		result[0] = 0x20;
		return writeword(num1, -3, result);
	case OP_RET:
		if (arg1 != AT_NONE || arg2 != AT_NONE) { return -1; }
		result[0] = 0x60;
		return 1;
	case OP_RETI:
		if (arg1 != AT_NONE || arg2 != AT_NONE) { return -1; }
		result[0] = 0x40;
		return 1;
	case OP_BRK:
		if (arg1 != AT_NONE || arg2 != AT_NONE) { return -1; }
		result[0] = 0x00;
		result[1] = 0xea;
		return 2;
	case OP_STOP:
		if (arg1 != AT_NONE || arg2 != AT_NONE) { return -1; }
		result[0] = 0xdb;
		return 1;
	case OP_WAIT:
		if (arg1 != AT_NONE || arg2 != AT_NONE) { return -1; }
		result[0] = 0xcb;
		return 1;
	}
	return 0;
}
