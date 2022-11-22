import { ToHexAST } from "..";
import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";

export function TransformJSR(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.PointerLiteral:
      call.value = "20";
      call.params = ToHexAST(arg.value as number);
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.JSR}`);
  }
}
