import { OpCode } from "./OpCode";
import { Register } from "./Register";

export interface Token {
  type: TokenType;
  value: string | Register | OpCode | number;
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
   * Kind of [0x1234]
   */
  Pointer,
  /**
   * any_string1: EOF
   */
  Label,
  /**
   * String
   */
  Arugment,
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

    // Skip whitespace and comma and new line
    if (char === " " || char === "\t" || char === "," || isNewLine(char)) {
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

    // Handle Register
    const upper = char.toUpperCase();
    if (Object.values(Register).indexOf(upper as Register) !== -1) {
      tokens.push({
        type: TokenType.Register,
        value: upper,
      });

      current++;
      continue;
    }

    // Handle OpCode
    const op = [
      input.slice(current, current + 2),
      input.slice(current, current + 3),
      input.slice(current, current + 4)
    ].map(x => x.toUpperCase()).find(op => op in OpCode);

    if (op) {
      tokens.push({
        type: TokenType.OpCode,
        value: OpCode[op as keyof typeof OpCode]
      });

      current += op.length;
      continue;
    }

    // Handle HexNumber 0xFF
    if (char + input[current + 1] === "0x") {
      let value = "";
      current += 2;

      while (current < input.length && /[0-9A-F]/.test(input[current])) {
        value += input[current];
        current++;
      }

      tokens.push({
        type: TokenType.Number,
        value: parseInt(value, 16),
      });

      continue;
    }

    // Handle Pointer [ 0x1234 ]
    if (char === "[") {
      let value = "";
      current++;

      while (current < input.length && input[current] !== "]") {
        value += input[current];
        current++;
      }

      tokens.push({
        type: TokenType.Pointer,
        value: parseInt(value, 16),
      });

      current++;
      continue;
    }

    // Handle Label and Argument
    if (/[a-zA-Z_]/.test(char)) {
      let value = "";
      while (current < input.length && /[a-zA-Z0-9_]/.test(input[current])) {
        value += input[current];
        current++;
      }

      if (input[current] === ":") {
        tokens.push({
          type: TokenType.Label,
          value,
        });
        current++;
      } else {
        tokens.push({
          type: TokenType.Arugment,
          value,
        });
      }

      continue;
    }

    throw new TypeError(`Syntax Error: ${char} at ${current}.\n
    Recent Tokens: ${tokens.slice(-5).map(x => x.value).join(" ")}\n
    Recent String: ${input.slice(current - 10, current + 10)}`);
  }

  return tokens;
}
