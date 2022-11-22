import { ToHexAST } from "../..";
import { OpCode } from "../../../OpCode";
import { AST, ASTType } from "../../../Parser";
import { Register } from "../../../Register";

export function PointerLeft(arg1: AST, arg2: AST, call: AST) {
  switch (arg2.type) {
    case ASTType.RegisterLiteral:
      call.params = ToHexAST(arg1.value as number);

      switch (arg2.name) {
        case Register.Accumulator:
          call.name = OpCode.STA;
          call.value = "8D";
          break;

        case Register.IndexX:
          call.name = OpCode.STX;
          call.value = "8E";
          break;

        case Register.IndexY:
          call.name = OpCode.STY;
          call.value = "8C";
          break;

        default:
          throw new Error(`Unsupport Right Register: ${arg2.value} for ${OpCode.MOV}`);
      }
      break;

    default:
      throw new Error(`Unsupport Right param type: ${arg2.type} for ${OpCode.MOV}`);
  }
}
