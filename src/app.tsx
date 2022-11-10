import preactLogo from "./assets/preact.svg"
import "./app.css"
import { Tokenizer } from "./Tokenizer";

export function App() {
  // @ts-expect-error
  window.Tokenizer = Tokenizer;

  return (
    <div>
      <img src={preactLogo} alt="Preact Logo" />
    </div>
  )
}
