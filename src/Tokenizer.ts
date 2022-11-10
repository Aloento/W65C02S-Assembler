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
}

function isNewLine(token: string): boolean {
  return token === "\n" || token === "\r";
}

/**
 * 词法分析器
 * 我们接受 ASM 字符串，然后把它们分割成 Token 数组
 */
export function Tokenizer(input: string) {
  // Index of current character in input string
  let current = 0;

  // Array of tokens
  const tokens: Token[] = [];

  // Loop through input string
  while (current < input.length) {
    const char = input[current];

    // Skip whitespace
    if (char === " " || char === "\t") {
      current++;
      continue;
    }

    // Skip comments
    if (char === ";") {
      while (current < input.length && !isNewLine(input[current])) {
        current++;
      }
      continue;
    }

    // Skip new lines
    if (isNewLine(char)) {
      current++;
      continue;
    }

    const norm = char.toLocaleUpperCase();

    // Handle OpCode
    if (norm in OpCode) {
      tokens.push({
        type: TokenType.OpCode,
        value: OpCode[norm as keyof typeof OpCode],
      });
      current++;
      continue;
    }


  }
}
