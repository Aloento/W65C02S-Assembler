import { OpCode } from "./OpCode";
import { Register } from "./Register";
import { Token, TokenType } from "./Tokenizer";

export interface AST {
  type: ASTType;
  body?: AST[];
  name?: string | OpCode;
  value?: string | number | Register;
  params?: AST[];
}

export enum ASTType {
  Program,
  CallExpression,
  RegisterLiteral,
  NumberLiteral,
  PointerLiteral,
  LabelLiteral,
}

/**
 * 语法分析器
 * 接受 token 数组，然后把它转化为 AST
 */
export function Parser(tokens: Token[]) {
  let current = 0;

  // Recursive
  function walk(): AST {
    let token = tokens[current];

    // Handle NumberLiteral
    if (token.type === TokenType.Number) {
      current++;

      return {
        type: ASTType.NumberLiteral,
        value: token.value as number,
      };
    }

    // Handle RegisterLiteral
    if (token.type === TokenType.Register) {
      current++;

      return {
        type: ASTType.RegisterLiteral,
        value: token.value as Register,
      };
    }

    // Handle PointerLiteral
    if (token.type === TokenType.Pointer) {
      current++;

      return {
        type: ASTType.PointerLiteral,
        value: token.value as number,
      };
    }

    // Handle Label
    if (token.type === TokenType.Label) {
      current++;

      return {
        type: ASTType.LabelLiteral,
        name: token.value as string,
      };
    }

    // Handle CallExpression
    if (token.type === TokenType.OpCode) {
      // Root node
      const node: AST = {
        type: ASTType.CallExpression,
        name: token.value as OpCode,
        params: [],
      }

      token = tokens[++current];

      // Handle params stop until next OpCode
      while (current < tokens.length && token.type !== TokenType.OpCode) {
        node.params!.push(walk());
        token = tokens[current];
      }

      return node;
    }

    throw new TypeError(`Unexpected token ${TokenType[token.type]} : ${token.value} at ${current}`);
  }

  // Root node
  const ast: AST = {
    type: ASTType.Program,
    body: [],
  }

  // Loop through tokens
  while (current < tokens.length) {
    ast.body!.push(walk());
  }

  return ast;
}
