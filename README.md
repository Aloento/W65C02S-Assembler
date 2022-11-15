# W65C02S-Assembler

This is a simple W65C02S assembler, it doesn't support all OpCode, you are welcome to complement it.

The code to call it is available in `src/main.tsx` for your reference.

## Quick Start

Go to https://w6502.aloen.to and open `DevTools` (usually F12) and switch to `Console` tab  
then you'll see some sample output.

And you can also try to assemble your own ASM.  
For example:

```js
console.log(Assembler(`
start:
jmp start
mov a, 0x11
mov [0x3000], x
mov y, 0x21
inc x
addc a, 0x02
`));
```
