import { OpCode } from "../OpCode";
import { AST, ASTType } from "../Parser";
import { Traverser } from "../Traverser";
import { TransformNon } from "./Non";
import { TransformOne } from "./One";
import { TransformTwo } from "./Two";

export function To16LE(num: number): string[] {
  const hex = num.toString(16).padStart(4, "0");
  return [hex.slice(2, 4), hex.slice(0, 2)];
}

/**
 * Number to LittleEndian HexString
 */
export function ToHexAST(num: number): AST[] {
  return To16LE(num).map((x) => ({
    type: ASTType.NumberLiteral,
    value: x,
  }));
}

/**
 * 转换器
 */
export function Transformer(ast: AST) {
  const newAst: AST = {
    type: ASTType.Program,
    body: [],
  };
  ast.context = newAst.body;

  Traverser(ast, {
    [ASTType.LabelLiteral](node, parent) {
      if (parent?.type === ASTType.Program)
        newAst.body!.push(node);
    },

    [ASTType.CallExpression](node, parent) {
      const call: AST = {
        type: ASTType.CallExpression,
        name: node.name,
        params: [],
      };

      if (call.name === OpCode.DB)
        call.params = node.params;
      else
        switch (node.params?.length) {
          case 1:
            TransformOne(node, call);
            break;

          case 2:
            TransformTwo(node, call);
            break;

          case 0:
          case undefined:
            TransformNon(node, call);
            break;

          default:
            throw new Error(
              `Params length out of range: ${node.params?.length} for opcode: ${node.name}`
            );
        }

      parent!.context!.push(call);
    },
  });

  return newAst;
}
