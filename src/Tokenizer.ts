import { OpCode } from "./OpCode";
import { Register } from "./Register";

export interface Token {
  type: TokenType;
  value: string | Register | OpCode | number;
}

export enum TokenType {
  /**
   * X, Y, A ...
   */
  Register = "Register",
  /**
   * MOV, ADD ...
   */
  OpCode = "OpCode",
  /**
   * Kind of 0xFF
   */
  Number = "Number",
  /**
   * Kind of [0x1234]
   */
  Pointer = "Pointer",
  /**
   * any_string1: EOF
   */
  Label = "Label",
  /**
   * Define new label
   */
  LabelDef = "LabelDef",
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

  const labels = new Set<string>();

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

    // Handle Label
    if (/[a-zA-Z_]/.test(char)) {
      let value = "";
      let i = current;

      while (i < input.length && /[a-zA-Z0-9_]/.test(input[i])) {
        value += input[i];
        i++;
      }

      if (input[i] === ":") {
        tokens.push({
          type: TokenType.LabelDef,
          value,
        });

        labels.add(value);
        current = i + 1;
        continue;
      }

      // Handle Arugment
      if (labels.has(value)) {
        tokens.push({
          type: TokenType.Label,
          value,
        });

        current = i;
        continue;
      }
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

    const pref = char + input[current + 1].toLowerCase();
    // Handle HexNumber 0xFf
    if (pref === "0x") {
      let value = "";
      current += 2;

      while (current < input.length && /[0-9A-Fa-f]/.test(input[current])) {
        value += input[current];
        current++;
      }

      const num = parseInt(value, 16);
      if (num > 255)
        throw new TypeError(`Number value ${num} is too large for 8-bit at ${current}`);

      tokens.push({
        type: TokenType.Number,
        value: num,
      });

      continue;
    }

    // Handle BinaryNumber 0b1010
    if (pref === "0b") {
      let value = "";
      current += 2;

      while (current < input.length && /[01]/.test(input[current])) {
        value += input[current];
        current++;
      }

      const num = parseInt(value, 2);
      if (num > 255)
        throw new TypeError(`Number value ${num} is too large for 8-bit at ${current}`);

      tokens.push({
        type: TokenType.Number,
        value: num,
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

      const num = parseInt(value, 16);
      if (num > 65535)
        throw new TypeError(`Pointer value ${num} is too large for 16-bit at ${current}`);

      tokens.push({
        type: TokenType.Pointer,
        value: num,
      });

      current++;
      continue;
    }

    throw new TypeError(`Syntax Error: ${char} at ${current}.\n
    Recent Tokens: ${tokens.slice(-5).map(x => x.value).join(" ")}\n
    Recent String: ${input.slice(current - 10, current + 10)}`);
  }

  return tokens;
}
