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
export function Tokenizer(input: string): [Token[], number] {
  // Index of current character in input string
  let current = 0;

  // Array of tokens
  const tokens: Token[] = [];

  const labels = new Set<string>();

  // Loop through input string
  while (current < input.length) {
    const char = input[current];

    // Skip
    switch (char) {
      case " ":
      case ",":
      case "+":
      case "\t":
      case "\r":
      case "\n":
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

    // Handle DecNumber
    if (/[0-9]/.test(char)) {
      putNum(/[0-9]/, 10);
      continue;
    }

    const pref = char + input[current + 1].toLowerCase();
    switch (pref) {
      // Handle BinaryNumber 0b1010
      case "0b":
        let test = /[01]/;
        let base = 2;
      // Handle HexNumber 0xFf or 0xFFff
      case "0x":
        test ??= /[0-9A-Fa-f]/;
        base ??= 16;
        current += 2;

        putNum(test, base);
        continue;
    }

    // Handle []
    if (char === "[") {
      const [nested, passed] = Tokenizer(input.slice(++current));
      tokens.push(...nested);
      current += passed;
      continue;
    }

    if (char === "]") {
      current++;
      break;
    }

    throw new TypeError(`Syntax Error: ${char} at ${current}.\n
    Recent Tokens: ${tokens.slice(-5).map(x => x.value).join(" ")}\n
    Recent String: ${input.slice(current - 10, current + 10)}`);
  }

  return [tokens, current];

  function putNum(test: RegExp, base: number) {
    let value = "";
    while (current < input.length && test.test(input[current])) {
      value += input[current];
      current++;
    }

    const num = parseInt(value, base);

    if (num <= 255)
      tokens.push({
        type: TokenType.Number,
        value: num,
      });
    else if (num <= 65535)
      tokens.push({
        type: TokenType.Pointer,
        value: num,
      });

    else
      throw new Error(`Number Too Large ${num} raw ${value} at ${current}`);
  }
}
