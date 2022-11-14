import { OpCode } from "../OpCode";
import { AST, ASTType } from "../Parser";
import { Register } from "../Register";
import { ToHexAST } from ".";

export function TransformOne(node: AST, call: AST) {
  const arg = node.params![0];

  switch (node.name) {
    case OpCode.JMP:
      call.value = "4C";

      switch (arg.type) {
        case ASTType.LabelLiteral:
          call.params = [arg];
          break;

        case ASTType.PointerLiteral:
          call.params = ToHexAST(arg.value as number);
          break;

        default:
          throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.JMP}`);
      }
      break;

    case OpCode.INC:
      switch (arg.type) {
        case ASTType.RegisterLiteral:
          switch (arg.value) {
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
      break;

    case OpCode.DEC:
      switch (arg.type) {
        case ASTType.RegisterLiteral:
          switch (arg.value) {
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
      break;

    case OpCode.BZS:
      switch (arg.type) {
        case ASTType.NumberLiteral:
          call.value = "F0";
          call.params = [arg];
          break;

        default:
          throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BZS}`);
      }
      break;

    case OpCode.BZC:
      switch (arg.type) {
        case ASTType.NumberLiteral:
          call.value = "D0";
          call.params = [arg];
          break;

        default:
          throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BZC}`);
      }
      break;

    case OpCode.BCS:
      switch (arg.type) {
        case ASTType.NumberLiteral:
          call.value = "B0";
          call.params = [arg];
          break;

        default:
          throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BCS}`);
      }
      break;

    case OpCode.BCC:
      switch (arg.type) {
        case ASTType.NumberLiteral:
          call.value = "90";
          call.params = [arg];
          break;

        default:
          throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BCC}`);
      }

    default:
      throw new Error(`UnSupport OpCode: ${node.name} with 1 param`);
  }
}
