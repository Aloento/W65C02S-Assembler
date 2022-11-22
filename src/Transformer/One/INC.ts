import { ToHexAST } from "..";
import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";

export function TransformINC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
        case Register.Accumulator:
          call.value = "1A";
          break;

        case Register.IndexX:
          call.value = "E8";
          break;

        case Register.IndexY:
          call.value = "C8";
          break;

        default:
          throw new Error(`UnSupport Register: ${arg.value} for ${OpCode.INC}`);
      }
      break;

    case ASTType.PointerLiteral:
      call.value = "EE";
      call.params = ToHexAST(arg.value as number);
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.INC}`);
  }
}
