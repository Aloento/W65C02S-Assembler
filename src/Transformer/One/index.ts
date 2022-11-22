import { OpCode } from "../../OpCode";
import { AST } from "../../Parser";
import { TransformBCC } from "./BCC";
import { TransformBCS } from "./BCS";
import { TransformBZC } from "./BZC";
import { TransformBZS } from "./BZS";
import { TransformDEC } from "./DEC";
import { TransformINC } from "./INC";
import { TransformJMP } from "./JMP";
import { TransformJSR } from "./JSR";
import { TransformPOP } from "./POP";
import { TransformPUSH } from "./PUSH";
import { TransformROL } from "./ROL";
import { TransformROR } from "./ROR";

export function TransformOne(node: AST, call: AST) {
  const arg = node.params![0];

  switch (node.name) {
    case OpCode.JMP:
      TransformJMP(arg, call);
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

    case OpCode.CALL:
    case OpCode.JSR:
      TransformJSR(arg, call);
      break;

    case OpCode.ROTL:
    case OpCode.ROL:
      TransformROL(arg, call);
      break;

    case OpCode.ROTR:
    case OpCode.ROR:
      TransformROR(arg, call);
      break;

    default:
      throw new Error(`UnSupport OpCode: ${node.name} with 1 param`);
  }
}
