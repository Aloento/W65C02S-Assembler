import { OpCode } from "./OpCode";

export interface Token {
  type: TokenType;
  value: string | Register | OpCode;
}

export enum TokenType {
  /**
   * X, Y, A (Accumulator)
   */
  Register,
  /**
   * Kind of 0xFF
   */
  Number,
  /**
   * any_string: \n
   */
  Label,
  /**
   * Some ASCII string
   */
  String,
  /**
   * ,
   */
  Comma,
  /**
   * \n or \r\n or \r or ;
   */
  EOF,
}

export enum Register {
  X,
  Y,
  A,
}

/**
 * 词法分析器
 * 我们接受 ASM 字符串，然后把它们分割成 Token 数组
 */
export function Tokenizer(input: string) {
  // Index of current character in input string
  let current = 0;

  // Array of tokens
  let tokens: Token[] = [];
}
