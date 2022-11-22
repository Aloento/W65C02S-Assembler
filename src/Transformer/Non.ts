import { OpCode } from "../OpCode";
import { AST } from "../Parser";

export function TransformNon(node: AST, call: AST) {
  switch (node.name) {
    case OpCode.NOP:
      call.value = "EA";
      break;

    case OpCode.RET:
    case OpCode.RTS:
      call.value = "60";
      break;

    case OpCode.RETI:
    case OpCode.RTI:
      call.value = "40";
      break;

    case OpCode.SEC:
      call.value = "38";
      break;

    case OpCode.CLC:
      call.value = "18";
      break;

    case OpCode.SEI:
      call.value = "78";
      break;

    case OpCode.CLI:
      call.value = "58";
      break;

    case OpCode.CLV:
      call.value = "B8";

    default:
      throw new Error(`Not Supported opcode: ${node.name} with no params`);
  }
}
