import { OpCode } from "../OpCode";
import { AST, ASTType } from "../Parser";
import { Register } from "../Register";
import { ToHexAST } from ".";
import { TransformMOV } from "./MOV";

export function TransformTwo(node: AST, call: AST) {
  const arg1 = node.params![0];
  const arg2 = node.params![1];

  switch (node.name) {
    case OpCode.MOV:
      TransformMOV(arg1, arg2, call);
      break;

    case OpCode.ADDC:
    case OpCode.ADC:
      TransformADC(call, arg1, arg2);
      break;

    case OpCode.SUBC:
    case OpCode.SBC:
      TransformSBC(call, arg1, arg2);
      break;

    case OpCode.AND:
      TransformAND(call, arg1, arg2);
      break;

    case OpCode.OR:
    case OpCode.ORA:
      TransformORA(call, arg1, arg2);
      break;

    case OpCode.XOR:
    case OpCode.EOR:
      TransformEOR(call, arg1, arg2);
      break;

    case OpCode.CMP:
      TransformCMP(arg1, arg2, call);
      break;

    default:
      throw new Error(`UnSupport OpCode: ${node.name} with 2 params`);
  }
}

function TransformCMP(arg1: AST, arg2: AST, call: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
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

function TransformEOR(call: AST, arg1: AST, arg2: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "49";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "4D";
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

function TransformORA(call: AST, arg1: AST, arg2: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "09";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "0D";
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

function TransformAND(call: AST, arg1: AST, arg2: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "29";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "2D";
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

function TransformSBC(call: AST, arg1: AST, arg2: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "E9";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "ED";
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

function TransformADC(call: AST, arg1: AST, arg2: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.value = "69";
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.value = "6D";
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
