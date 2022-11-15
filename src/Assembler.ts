export function Assembler(asm: string): string {
  return Generator(Transformer(Parser(Tokenizer(asm))));
}
