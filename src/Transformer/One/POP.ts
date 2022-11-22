import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";

export function TransformPOP(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
        case Register.Accumulator:
          call.value = "68";
          break;

        case Register.IndexX:
          call.value = "FA";
          break;

        case Register.IndexY:
          call.value = "7A";
          break;

        case Register.StatusRegister:
          call.value = "28";
          break;

        default:
          throw new Error(`UnSupport Register: ${arg.value} for ${OpCode.POP}`);
      }
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.POP}`);
  }
}
