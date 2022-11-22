import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";

export function TransformBZC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.NumberLiteral:
      call.value = "D0";
      call.params = [arg];
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BZC}`);
  }
}
