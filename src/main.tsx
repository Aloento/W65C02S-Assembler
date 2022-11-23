import { render } from "preact";
import "./app.css";
import { Assembler } from "./Assembler";
import preactLogo from "./assets/preact.svg";
import { Generator } from "./Generator";
import "./index.css";
import { Parser } from "./Parser";
import { TestASM } from "./TestASM";
import { Tokenizer } from "./Tokenizer";
import { Transformer } from "./Transformer";

function App() {
  // @ts-expect-error
  window.TestASM = TestASM;
  // @ts-expect-error
  window.Tokenizer = Tokenizer;
  // @ts-expect-error
  window.Parser = Parser;
  // @ts-expect-error
  window.Transformer = Transformer;
  // @ts-expect-error
  window.Generator = Generator;
  // @ts-expect-error
  window.Assembler = Assembler;

  const t = Tokenizer("hellostring:   db 72, 101, 108, 108, 111, 0");
  console.log(t);

  const ast = Parser(t[0]);
  console.log(ast);

  const newer = Transformer(ast);

  const code = Generator(newer);
  console.log(code);

  return (
    <div>
      <img src={preactLogo} />
    </div>
  );
}

render(<App />, document.getElementById("app") as HTMLElement);
