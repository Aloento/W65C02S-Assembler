;expressions with labels
start:
  jmp start + 2
  jmp start % 32
label1
  mov a, label1 - start
