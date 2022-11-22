import { ToHexAST } from "..";
import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";

export function TransformDEC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
        case Register.Accumulator:
          call.value = "3A";
          break;

        case Register.IndexX:
          call.value = "CA";
          break;

        case Register.IndexY:
          call.value = "88";
          break;

        default:
          throw new Error(`UnSupport Register: ${arg.value} for ${OpCode.DEC}`);
      }

      break;

    case ASTType.PointerLiteral:
      call.value = "CE";
      call.params = ToHexAST(arg.value as number);
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.DEC}`);
  }
}
