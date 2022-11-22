import { OpCode } from "../../../OpCode";
import { AST, ASTType } from "../../../Parser";
import { PointerLeft } from "./PointerLeft";
import { Reg2Reg } from "./Reg2Reg";
import { RegLeft } from "./RegLeft";

export function TransformMOV(arg1: AST, arg2: AST, call: AST) {
  switch (arg1.type) {
    case ASTType.RegisterLiteral:
      if (arg2.type === ASTType.RegisterLiteral) {
        Reg2Reg(arg1, arg2, call);
        break;
      }

      RegLeft(arg1, arg2, call);
      break;

    case ASTType.PointerLiteral:
      PointerLeft(arg1, arg2, call);
      break;

    default:
      throw new Error(`Unexpected Left param type: ${arg1.type} for ${OpCode.MOV}`);
  }
}
