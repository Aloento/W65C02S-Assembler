import { OpCode } from "../OpCode";
import { AST, ASTType } from "../Parser";
import { Register } from "../Register";
import { ToHexAST } from ".";

export function TransformMOV(arg1: AST, arg2: AST, call: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      if (arg2.type === ASTType.RegisterLiteral) {
        if (arg1.value === Register.Accumulator && arg2.value === Register.IndexX) {
          call.name = OpCode.TXA;
          call.value = "8A";
        }

        if (arg1.value === Register.Accumulator && arg2.value === Register.IndexY) {
          call.name = OpCode.TYA;
          call.value = "98";
        }

        if (arg1.value === Register.IndexX && arg2.value === Register.Accumulator) {
          call.name = OpCode.TAX;
          call.value = "AA";
        }

        if (arg1.value === Register.IndexY && arg2.value === Register.Accumulator) {
          call.name = OpCode.TAY;
          call.value = "A8";
        }

        break;
      }

      switch (arg1.value) {
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
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.LDA}`);
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
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.LDX}`);
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
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.LDY}`);
          }
          break;

        default:
          throw new Error(`UnSupport Left Register: ${arg1.value} for ${OpCode.MOV}`);
      }
      break;

    case ASTType.PointerLiteral:
      switch (arg2.type) {
        case ASTType.RegisterLiteral:
          call.params = ToHexAST(arg1.value as number);

          switch (arg2.value) {
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
              throw new Error(`UnSupport Right Register: ${arg2.value} for ${OpCode.MOV}`);
          }
          break;

        default:
          throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.MOV}`);
      }
      break;

    default:
      throw new Error(`Unexpected Left param type: ${arg1.type} for ${OpCode.MOV}`);
  }
}
