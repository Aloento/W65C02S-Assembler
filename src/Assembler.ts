import { Generator } from "./Generator";
import { Parser } from "./Parser";
import { Tokenizer } from "./Tokenizer";
import { Transformer } from "./Transformer";

export function Assembler(asm: string): string {
  return Generator(Transformer(Parser(Tokenizer(asm)[0])));
}
