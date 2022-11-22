import { ToHexAST } from "../..";
import { OpCode } from "../../../OpCode";
import { AST, ASTType } from "../../../Parser";
import { Register } from "../../../Register";

export function RegLeft(arg1: AST, arg2: AST, call: AST) {
  switch (arg1.name) {
    case Register.Accumulator:
      call.name = OpCode.LDA;

      switch (arg2.type) {
        case ASTType.NumberLiteral:
          call.value = "A9";
          call.params = [arg2];
          break;

        case ASTType.PointerLiteral:
          call.value = "AD";
          call.params = ToHexAST(arg2.value as number);
          break;

        default:
          throw new Error(`Unsupport Right param type: ${arg2.type} for ${OpCode.LDA}`);
      }
      break;

    case Register.IndexX:
      call.name = OpCode.LDX;

      switch (arg2.type) {
        case ASTType.NumberLiteral:
          call.value = "A2";
          call.params = [arg2];
          break;

        case ASTType.PointerLiteral:
          call.value = "AE";
          call.params = ToHexAST(arg2.value as number);
          break;

        default:
          throw new Error(`Unsupport Right param type: ${arg2.type} for ${OpCode.LDX}`);
      }
      break;

    case Register.IndexY:
      call.name = OpCode.LDY;

      switch (arg2.type) {
        case ASTType.NumberLiteral:
          call.value = "A0";
          call.params = [arg2];
          break;

        case ASTType.PointerLiteral:
          call.value = "AC";
          call.params = ToHexAST(arg2.value as number);
          break;

        default:
          throw new Error(`Unsupport Right param type: ${arg2.type} for ${OpCode.LDY}`);
      }
      break;

    default:
      throw new Error(`Unsupport Left Register: ${arg1.value} for ${OpCode.MOV}`);
  }
}
