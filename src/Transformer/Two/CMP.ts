import { OpCode } from "../../OpCode";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";
import { ToHexAST } from "..";

export function TransformCMP(arg1: AST, arg2: AST, call: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.name) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "C9";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "CD";
              call.params = ToHexAST(arg2.value as number);
              break;

            default:
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.ADC}`);
          }
          break;

        case Register.IndexX:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "E0";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "EC";
              call.params = ToHexAST(arg2.value as number);
              break;

            default:
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.ADC}`);
          }
          break;

        case Register.IndexY:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "C0";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "CC";
              call.params = ToHexAST(arg2.value as number);
              break;

            default:
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.ADC}`);
          }
          break;

        default:
          throw new Error(`UnSupport Left Register: ${arg1.value} for ${call.name}`);
      }
      break;

    default:
      throw new Error(`Unexpected Left param type: ${arg1.type} for ${call.name}`);
  }
}
