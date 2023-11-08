typedef enum
{
	/*data movement instructions*/
	OP_MOV,
	OP_PULL,
	OP_PUSH,
	OP_SET,
	OP_CLR,
	/*Arithmetic logic instructions*/
	OP_ADDC,
	OP_SUBC,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_INC,
	OP_DEC,
	OP_ROR,
	OP_ROL,
	OP_ASL,
	OP_LSR,
	/*condition instructions*/
	OP_BIT,
	OP_CMP,
	OP_TRB,
	OP_TSB,
	/*control flow instructions*/
	OP_NOP,
	OP_JMP,
	OP_BR,
	OP_CALL,
	OP_RET,
	OP_RETI,
	OP_BRK,
	OP_STOP,
	OP_WAIT
} opcode_t;

typedef enum
{
	/*registers*/
	AT_REG_A,
	AT_REG_X,
	AT_REG_Y,
	AT_REG_P,
	AT_REG_S,
	/*flags*/
	AT_CFLAG,
	AT_ZFLAG,
	AT_IFLAG,
	AT_DFLAG,
	AT_VFLAG,
	AT_NFLAG,
	AT_ALWAYS,
	/*only for br true, label instruction*/
	/*memory*/
	AT_IMMEDIATE,
	AT_ABSOLUTE,
	AT_ABSOLUTE_X,
	AT_ABSOLUTE_Y,
	AT_ZEROPAGE,
	AT_ZEROPAGE_X,
	AT_ZEROPAGE_Y,
	AT_INDIRECT_ZP,
	AT_INDIRECT_ZP_X,
	AT_INDIRECT_Y_ZP,
	/*bits in memory (zero page)*/
	AT_BIT0,
	AT_BIT1,
	AT_BIT2,
	AT_BIT3,
	AT_BIT4,
	AT_BIT5,
	AT_BIT6,
	AT_BIT7,
	/**/
	AT_NONE /* If there is no second argument, or there is no argument at all. */
} argument_type_t;


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
                    unsigned char result[3]);
