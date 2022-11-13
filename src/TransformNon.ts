import { OpCode } from "./OpCode";
import { AST } from "./Parser";

export function TransformNon(node: AST, call: AST) {
  switch (node.name) {
    case OpCode.NOP:
      call.value = "EA";
      break;

    default:
      throw new Error(`Not Supported opcode: ${node.name} with no params`);
  }
}
