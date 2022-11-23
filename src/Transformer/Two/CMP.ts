import { ToHexAST } from "..";
import { AST, ASTType } from "../../Parser";
import { Register } from "../../Register";

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

            case ASTType.RegisterLiteral:
              switch (arg2.name) {
                case Register.ZeroPage:
                  if (arg2.value === Register.IndexY)
                    call.value = "D1";
                  else
                    call.value = "D2";

                  call.params = arg2.params;
                  break;

                default:
                  throw new Error(`Unsupport Right Register: ${arg2.name} for ${call.name}`);
              }
              break;

            default:
              throw new Error(`Unsupport Right param type: ${arg2.type} for ${call.name}`);
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
              throw new Error(`Unsupport Right param type: ${arg2.type} for ${call.name}`);
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
              throw new Error(`Unsupport Right param type: ${arg2.type} for ${call.name}`);
          }
          break;

        default:
          throw new Error(`Unsupport Left Register: ${arg1.name} for ${call.name}`);
      }
      break;

    default:
      throw new Error(`Unexpected Left param type: ${arg1.type} for ${call.name}`);
  }
}
