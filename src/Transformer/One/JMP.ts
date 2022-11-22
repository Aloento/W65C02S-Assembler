import { ToHexAST } from "..";
import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";

export function TransformJMP(arg: AST, call: AST) {
  call.value = "4C";

  switch (arg.type) {
    case ASTType.LabelLiteral:
      call.params = [arg];
      break;

    case ASTType.PointerLiteral:
      call.params = ToHexAST(arg.value as number);
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.JMP}`);
  }
}
