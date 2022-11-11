import preactLogo from "./assets/preact.svg"
import "./app.css"
import { Tokenizer } from "./Tokenizer";
import { Parser } from "./Parser";
import { TestASM } from "./TestASM";

export function App() {
  // @ts-expect-error
  window.Tokenizer = Tokenizer;
  // @ts-expect-error
  window.Parser = Parser;

  const t = Tokenizer(TestASM);
  console.log(t);

  const ast = Parser(t);
  console.log(ast);

  return (
    <div>
      <img src={preactLogo} alt="Preact Logo" />
    </div>
  )
}
