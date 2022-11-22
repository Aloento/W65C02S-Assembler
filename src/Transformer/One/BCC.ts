import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";

export function TransformBCC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.NumberLiteral:
      call.value = "90";
      call.params = [arg];
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BCC}`);
  }
}
