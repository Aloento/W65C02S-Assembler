import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";

export function TransformPUSH(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
        case Register.Accumulator:
          call.value = "48";
          break;

        case Register.IndexX:
          call.value = "DA";
          break;

        case Register.IndexY:
          call.value = "5A";
          break;

        case Register.StatusRegister:
          call.value = "08";
          break;

        default:
          throw new Error(`UnSupport Register: ${arg.value} for ${OpCode.PUSH}`);
      }
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.PUSH}`);
  }
}
