import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";

export function TransformROR(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
        case Register.Accumulator:
          call.value = "6A";
          break;

        default:
          throw new Error(`UnSupport Register: ${arg.value} for ${OpCode.ROR}`);
      }
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.ROR}`);
  }
}
