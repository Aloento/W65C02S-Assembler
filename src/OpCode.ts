export enum OpCode {
    /**
     * ADd memory to accumulator with Carry
     */
    ADC,
    /**
     * "AND" memory with accumulator
     */
    AND,
    /**
     * Arithmetic Shift one bit Left, memory or accumulator
     */
    ASL,
    /**
     * Branch on Bit Reset
     */
    BBR,
    /**
     * Branch of Bit Set
     */
    BBS,
    /**
     * Branch on Carry Clear (Pc=0)
     */
    BCC,
    /**
     * Branch on Carry Set (Pc=1)
     */
    BCS,
    /**
     * Branch if EQual (Pz=1)
     */
    BEQ,
    /**
     * BIt Test
     */
    BIT,
    /**
     * Branch if result MInus (Pn=1)
     */
    BMI,
    /**
     * Branch if Not Equal (Pz=0)
     */
    BNE,
    /**
     * Branch if result PLus (Pn=0)
     */
    BPL,
    /**
     * BRanch Always
     */
    BRA,
    /**
     * BReaK instruction
     */
    BRK,
    /**
     * Branch on oVerflow Clear (Pv=0)
     */
    BVC,
    /**
     * Branch on oVerflow Set (Pv=1)
     */
    BVS,
    /**
     * CLear Cary flag
     */
    CLC,
    /**
     * CLear Decimal mode
     */
    CLD,
    /**
     * CLear Interrupt disable bit
     */
    CLI,
    /**
     * CLear oVerflow flag
     */
    CLV,
    /**
     * CoMPare memory and accumulator
     */
    CMP,
    /**
     * ComPare memory and X register
     */
    CPX,
    /**
     * ComPare memory and Y register
     */
    CPY,
    /**
     * DECrement memory or accumulate by one
     */
    DEC,
    /**
     * DEcrement X by one
     */
    DEX,
    /**
     * DEcrement Y by one
     */
    DEY,
    /**
     * "Exclusive OR" memory with accumulate
     */
    EOR,
    /**
     * INCrement memory or accumulate by one
     */
    INC,
    /**
     * INcrement X register by one
     */
    INX,
    /**
     * INcrement Y register by one
     */
    INY,
    /**
     * JuMP to new location
     */
    JMP,
    /**
     * Jump to new location Saving Return (Jump to SubRoutine)
     */
    JSR,
    /**
     * LoaD Accumulator with memory
     */
    LDA,
    /**
     * LoaD the X register with memory
     */
    LDX,
    /**
     * LoaD the Y register with memory
     */
    LDY,
    /**
     * Logical Shift one bit Right memory or accumulator
     */
    LSR,
    /**
     * No OPeration
     */
    NOP,
    /**
     * "OR" mem ory with Accumulator
     */
    ORA,
    /**
     * PusH Acc umulator on stack
     */
    PHA,
    /**
     * PusH Proc essor status on stack
     */
    PHP,
    /**
     * PusH X re gister on stack
     */
    PHX,
    /**
     * PusH Y re gister on stack
     */
    PHY,
    /**
     * PuLl Accu mulator from stack
     */
    PLA,
    /**
     * PuLl Proce ssor status from stack
     */
    PLP,
    /**
     * PuLl X reg ister from stack
     */
    PLX,
    /**
     * PuLl Y reg ister from stack
     */
    PLY,
    /**
     * Reset Mem ory Bit
     */
    RMB,
    /**
     * ROtate on e bit Left memory or accumulator
     */
    ROL,
    /**
     * ROtate on e bit Right memory or accumulator
     */
    ROR,
    /**
     * ReTurn fro m Interrupt
     */
    RTI,
    /**
     * ReTurn fro m Subroutine
     */
    RTS,
    /**
     * SuBtract memory from accumulator with borrow (Carry bit)
     */
    SBC,
    /**
     * SEt Carry
     */
    SEC,
    /**
     * SEt Decim al mode
     */
    SED,
    /**
     * SEt Interru pt disable status
     */
    SEI,
    /**
     * Set Memo ry Bit
     */
    SMB,
    /**
     * STore Acc umulator in memory
     */
    STA,
    /**
     * SToP mod e
     */
    STP,
    /**
     * STore the X register in memory
     */
    STX,
    /**
     * STore the Y register in memory
     */
    STY,
    /**
     * STore Zer o in memory
     */
    STZ,
    /**
     * Transfer th e Accumulator to the X register
     */
    TAX,
    /**
     * Transfer th e Accumulator to the Y register
     */
    TAY,
    /**
     * Test and R eset memory Bit
     */
    TRB,
    /**
     * Test and S et memory Bit
     */
    TSB,
    /**
     * Transfer th e Stack pointer to the X register
     */
    TSX,
    /**
     * Transfer th e X register to the Accumulator
     */
    TXA,
    /**
     * Transfer the X register to the Stack pointer register
     */
    TXS,
    /**
     * Transfer Y register to the Accumulator
     */
    TYA,
    /**
     * WAit for In terrupt
     */
    WAI
}
