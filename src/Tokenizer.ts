import { OpCode } from "./OpCode";
import { Register } from "./Register";

export interface Token {
  type: TokenType;
  value: string | Register | OpCode;
}

export const enum TokenType {
  /**
   * X, Y, A ...
   */
  Register,
  /**
   * MOV, ADD ...
   */
  OpCode,
  /**
   * Kind of 0xFF
   */
  Number,
  /**
   * any_string: EOF
   */
  Label,
  /**
   * Some ASCII string
   */
  Argument,
  /**
   * \n or \r\n or \r or ;
   */
  EOF,
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
