export enum Register {
    /**
     * X 索引寄存器 Index Register X
     */
    IndexX = "X",
    /**
     * Y 索引寄存器 Index Register Y
     */
    IndexY = "Y",
    /**
     * 累加寄存器 Accumulator
     */
    Accumulator = "A",
    /**
     * 栈指针 Stack Pointer
     */
    StackPointer = "S",
    /**
     * 指令计数器 Program Counter
     */
    ProgramCounter = "R",

    ////////// 以下为伪寄存器 //////////

    /**
     * 状态寄存器 Status Register
     */
    StatusRegister = "P",
    /**
     * 零页寻址 Zero Page
     */
    ZeroPage = "ZP",
}
