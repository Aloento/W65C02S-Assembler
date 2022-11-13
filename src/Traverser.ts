import { AST, ASTType } from "./Parser";

export type Visitor = Partial<Record<ASTType, (node: AST, parent?: AST) => void>>;

/**
 * 遍历器
 */
export function Traverser(ast: AST, visitor: Visitor) {
  function traverseArray(array: AST[], parent: AST) {
    array.forEach(child => traverseNode(child, parent));
  }

  function traverseNode(node: AST, parent?: AST) {
    const method = visitor[node.type];

    if (method)
      method(node, parent);

    switch (node.type) {
      case ASTType.Program:
        traverseArray(node.body!, node);
        break;

      case ASTType.CallExpression:
        traverseArray(node.params!, node);
        break;

      case ASTType.RegisterLiteral:
      case ASTType.NumberLiteral:
      case ASTType.PointerLiteral:
      case ASTType.LabelLiteral:
        break;

      default:
        throw new TypeError(`Unexpected node type ${node.type}`);
    }
  }

  traverseNode(ast);
}
