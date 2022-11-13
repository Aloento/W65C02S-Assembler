import { OpCode } from "../OpCode";
import { AST, ASTType } from "../Parser";
import { Register } from "../Register";
import { To2LE } from ".";
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
      TransformADC(call, arg1, arg2, node);
      break;

    default:
      throw new Error(`UnSupport OpCode: ${node.name} with 2 params`);
  }
}

function TransformADC(call: AST, arg1: AST, arg2: AST, node: AST) {
  call.name = OpCode.ADC;

  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      switch (arg1.value) {
        case Register.Accumulator:
          switch (arg2.type) {
            case ASTType.NumberLiteral:
              call.params = [arg2];
              break;

            case ASTType.PointerLiteral:
              call.params = To2LE(arg2.value as number);
              break;

            default:
              throw new Error(`UnSupport Right param type: ${arg2.type} for ${OpCode.ADC}`);
          }
          break;

        default:
          throw new Error(`UnSupport Left Register: ${arg1.value} for ${node.name}`);
      }
      break;

    default:
      throw new Error(`Unexpected Left param type: ${arg1.type} for ${node.name}`);
  }
}
