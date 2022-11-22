import { OpCode } from "../../OpCode";
import { AST } from "../../Parser";
import { TransformMOV } from "./MOV";
import { TransformCMP } from "./CMP";
import { TransformEOR } from "./EOR";
import { TransformORA } from "./ORA";
import { TransformAND } from "./AND";
import { TransformSBC } from "./SBC";
import { TransformADC } from "./ADC";

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
