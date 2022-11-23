import { OpCode } from "../../../OpCode";
import { AST } from "../../../Parser";
import { Register } from "../../../Register";

export function Reg2Reg(arg1: AST, arg2: AST, call: AST) {
  switch (arg1.name) {
    case Register.Accumulator:
      switch (arg2.name) {
        case Register.IndexX:
          call.name = OpCode.TXA;
          call.value = "8A";
          break;

        case Register.IndexY:
          call.name = OpCode.TYA;
          call.value = "98";
          break;

        case Register.ZeroPage:
          call.name = OpCode.LDA;
          if (arg2.value === Register.IndexY)
            call.value = "B1";

          else
            call.value = "B2";

          call.params = arg2.params;
          break;

        default:
          throw new Error(`Unsupport Register Pair: ${arg1.name} : ${arg2.name} for ${call.name}`);
      }
      break;

    case Register.IndexX:
      switch (arg2.name) {
        case Register.Accumulator:
          call.name = OpCode.TAX;
          call.value = "AA";
          break;

        case Register.StackPointer:
          call.name = OpCode.TSX;
          call.value = "BA";
          break;

        default:
          throw new Error(`Unsupport Register Pair: ${arg1.name} : ${arg2.name} for ${call.name}`);
      }
      break;

    case Register.IndexY:
      switch (arg2.name) {
        case Register.Accumulator:
          call.name = OpCode.TAY;
          call.value = "A8";
          break;

        default:
          throw new Error(`Unsupport Register Pair: ${arg1.name} : ${arg2.name} for ${call.name}`);
      }
      break;

    case Register.StackPointer:
      switch (arg2.name) {
        case Register.IndexX:
          call.name = OpCode.TXS;
          call.value = "9A";
          break;

        default:
          throw new Error(`Unsupport Register Pair: ${arg1.name} : ${arg2.name} for ${call.name}`);
      }
      break;

    case Register.ZeroPage:
      switch (arg2.name) {
        case Register.Accumulator:
          call.name = OpCode.STA;
          if (arg1.value === Register.IndexY)
            call.value = "91";
          else
            call.value = "92";

          call.params = arg1.params;
          break;

        default:
          throw new Error(`Unsupport Register Pair: ${arg1.name} : ${arg2.name} for ${call.name}`);
      }
      break;

    default:
      throw new Error(`Unsupport Left Register: ${arg1.name} for ${call.name}`);
  }
}
