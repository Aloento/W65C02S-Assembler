import { render } from "preact";
import "./index.css";
import preactLogo from "./assets/preact.svg";
import "./app.css";
import { Tokenizer } from "./Tokenizer";
import { Parser } from "./Parser";
import { TestASM } from "./TestASM";
import { Transformer } from "./Transformer";
import { Generator } from "./Generator";

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

  const t = Tokenizer(TestASM);
  console.log(t);

  const ast = Parser(t);
  console.log(ast);

  const newer = Transformer(ast);
  console.log(newer);

  const code = Generator(newer);
  console.log(code);

  return (
    <div>
      <img src={preactLogo} />
    </div>
  );
}

render(<App />, document.getElementById("app") as HTMLElement);
