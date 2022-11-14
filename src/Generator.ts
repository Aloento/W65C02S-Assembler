import { AST, ASTType } from "./Parser";
import { To16LE } from "./Transformer";

let current = 0;
const labels = new Map<string, number>();

/**
 * HEX Code Generator
 */
export function Generator(node: AST): string {
  switch (node.type) {
    case ASTType.Program:
      return node.body!.map(Generator).join("\n");

    case ASTType.LabelLiteral:
      if (node.name) {
        labels.set(node.name, current);
        return "";
      } else
        return To16LE(labels.get(node.value as string) as number).join(" ");

    case ASTType.CallExpression:
      current++;
      return `${node.value} ${node.params!.map(Generator).join(" ")}`;

    case ASTType.NumberLiteral:
      current++;
      return node.value!.toString(16);

    default:
      throw new Error(`Unknown AST type: ${node.type}`);
  }
}
