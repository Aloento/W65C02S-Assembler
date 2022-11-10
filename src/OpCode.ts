export enum OpCode {
    /**
     * MOV X, Y
     */
    MOV = "MOV",
    /**
     * Same as ADC
     */
    ADDC = "ADDC",
    /**
     * Same as SBC
     */
    SUBC = "SUBC",
    /**
     * Same as ORA
     */
    OR = "OR",
    /**
     * Same as EOR
     */
    XOR = "XOR",
    /**
     * Same as BEQ
     */
    BZS = "BZS",
    /**
     * Same as BNE
     */
    BZC = "BZC",

    ////////////////////////////////

    /**
     * ADd memory to accumulator with Carry
     */
    ADC = "ADC",
    /**
     * "AND" memory with accumulator
     */
    AND = "AND",
    /**
     * Arithmetic Shift one bit Left, memory or accumulator
     */
    ASL = "ASL",
    /**
     * Branch on Bit Reset
     */
    BBR = "BBR",
    /**
     * Branch of Bit Set
     */
    BBS = "BBS",
    /**
     * Branch on Carry Clear (Pc=0)
     */
    BCC = "BCC",
    /**
     * Branch on Carry Set (Pc=1)
     */
    BCS = "BCS",
    /**
     * Branch if EQual (Pz=1)
     */
    BEQ = "BEQ",
    /**
     * BIt Test
     */
    BIT = "BIT",
    /**
     * Branch if result MInus (Pn=1)
     */
    BMI = "BMI",
    /**
     * Branch if Not Equal (Pz=0)
     */
    BNE = "BNE",
    /**
     * Branch if result PLus (Pn=0)
     */
    BPL = "BPL",
    /**
     * BRanch Always
     */
    BRA = "BRA",
    /**
     * BReaK instruction
     */
    BRK = "BRK",
    /**
     * Branch on oVerflow Clear (Pv=0)
     */
    BVC = "BVC",
    /**
     * Branch on oVerflow Set (Pv=1)
     */
    BVS = "BVS",
    /**
     * CLear Cary flag
     */
    CLC = "CLC",
    /**
     * CLear Decimal mode
     */
    CLD = "CLD",
    /**
     * CLear Interrupt disable bit
     */
    CLI = "CLI",
    /**
     * CLear oVerflow flag
     */
    CLV = "CLV",
    /**
     * CoMPare memory and accumulator
     */
    CMP = "CMP",
    /**
     * ComPare memory and X register
     */
    CPX = "CPX",
    /**
     * ComPare memory and Y register
     */
    CPY = "CPY",
    /**
     * DECrement memory or accumulate by one
     */
    DEC = "DEC",
    /**
     * DEcrement X by one
     */
    DEX = "DEX",
    /**
     * DEcrement Y by one
     */
    DEY = "DEY",
    /**
     * "Exclusive OR" memory with accumulate
     */
    EOR = "EOR",
    /**
     * INCrement memory or accumulate by one
     */
    INC = "INC",
    /**
     * INcrement X register by one
     */
    INX = "INX",
    /**
     * INcrement Y register by one
     */
    INY = "INY",
    /**
     * JuMP to new location
     */
    JMP = "JMP",
    /**
     * Jump to new location Saving Return (Jump to SubRoutine)
     */
    JSR = "JSR",
    /**
     * LoaD Accumulator with memory
     */
    LDA = "LDA",
    /**
     * LoaD the X register with memory
     */
    LDX = "LDX",
    /**
     * LoaD the Y register with memory
     */
    LDY = "LDY",
    /**
     * Logical Shift one bit Right memory or accumulator
     */
    LSR = "LSR",
    /**
     * No OPeration
     */
    NOP = "NOP",
    /**
     * "OR" memory with Accumulator
     */
    ORA = "ORA",
    /**
     * PusH Accumulator on stack
     */
    PHA = "PHA",
    /**
     * PusH Processor status on stack
     */
    PHP = "PHP",
    /**
     * PusH X register on stack
     */
    PHX = "PHX",
    /**
     * PusH Y register on stack
     */
    PHY = "PHY",
    /**
     * PuLl Accumulator from stack
     */
    PLA = "PLA",
    /**
     * PuLl Processor status from stack
     */
    PLP = "PLP",
    /**
     * PuLl X register from stack
     */
    PLX = "PLX",
    /**
     * PuLl Y register from stack
     */
    PLY = "PLY",
    /**
     * Reset Memory Bit
     */
    RMB = "RMB",
    /**
     * ROtate one bit Left memory or accumulator
     */
    ROL = "ROL",
    /**
     * ROtate one bit Right memory or accumulator
     */
    ROR = "ROR",
    /**
     * ReTurn from Interrupt
     */
    RTI = "RTI",
    /**
     * ReTurn from Subroutine
     */
    RTS = "RTS",
    /**
     * SuBtract memory from accumulator with borrow (Carry bit)
     */
    SBC = "SBC",
    /**
     * SEt Carry
     */
    SEC = "SEC",
    /**
     * SEt Decimal mode
     */
    SED = "SED",
    /**
     * SEt Interrupt disable status
     */
    SEI = "SEI",
    /**
     * Set Memory Bit
     */
    SMB = "SMB",
    /**
     * STore Accumulator in memory
     */
    STA = "STA",
    /**
     * SToP mod e
     */
    STP = "STP",
    /**
     * STore the X register in memory
     */
    STX = "STX",
    /**
     * STore the Y register in memory
     */
    STY = "STY",
    /**
     * STore Zero in memory
     */
    STZ = "STZ",
    /**
     * Transfer the Accumulator to the X register
     */
    TAX = "TAX",
    /**
     * Transfer the Accumulator to the Y register
     */
    TAY = "TAY",
    /**
     * Test and R eset memory Bit
     */
    TRB = "TRB",
    /**
     * Test and S et memory Bit
     */
    TSB = "TSB",
    /**
     * Transfer the Stack pointer to the X register
     */
    TSX = "TSX",
    /**
     * Transfer the X register to the Accumulator
     */
    TXA = "TXA",
    /**
     * Transfer the X register to the Stack pointer register
     */
    TXS = "TXS",
    /**
     * Transfer Y register to the Accumulator
     */
    TYA = "TYA",
    /**
     * WAit for In terrupt
     */
    WAI = "WAI",
}
