import { OpCode } from "../OpCode";
import { AST, ASTType } from "../Parser";
import { Register } from "../Register";
import { ToHexAST } from ".";

export function TransformOne(node: AST, call: AST) {
  const arg = node.params![0];

  switch (node.name) {
    case OpCode.JMP:
      TransformJMP(call, arg);
      break;

    case OpCode.INC:
      TransformINC(arg, call);
      break;

    case OpCode.DEC:
      TransformDEC(arg, call);
      break;

    case OpCode.BZS:
      TransformBZS(arg, call);
      break;

    case OpCode.BZC:
      TransformBZC(arg, call);
      break;

    case OpCode.BCS:
      TransformBCS(arg, call);
      break;

    case OpCode.BCC:
      TransformBCC(arg, call);
      break;

    case OpCode.PUSH:
      TransformPUSH(arg, call);
      break;

    case OpCode.POP:
      TransformPOP(arg, call);
      break;

    default:
      throw new Error(`UnSupport OpCode: ${node.name} with 1 param`);
  }
}

function TransformPOP(arg: AST, call: AST) {
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

function TransformPUSH(arg: AST, call: AST) {
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

function TransformBCC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.NumberLiteral:
      call.value = "90";
      call.params = [arg];
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BCC}`);
  }
}

function TransformBCS(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.NumberLiteral:
      call.value = "B0";
      call.params = [arg];
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BCS}`);
  }
}

function TransformBZC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.NumberLiteral:
      call.value = "D0";
      call.params = [arg];
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BZC}`);
  }
}

function TransformBZS(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.NumberLiteral:
      call.value = "F0";
      call.params = [arg];
      break;

    default:
      throw new Error(`Unexpected param type: ${arg.type} for ${OpCode.BZS}`);
  }
}

function TransformDEC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
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
}

function TransformINC(arg: AST, call: AST) {
  switch (arg.type) {
    case ASTType.RegisterLiteral:
      switch (arg.name) {
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
}

function TransformJMP(call: AST, arg: AST) {
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
}
