;consts
FIRSTCONST = 0x4000 
NEWCONST = 0x2332
ONEMORE = NEWCONST + 1
ANDONEMORE  = ONEMORE + 1 ; some comment
FINAL  = ANDONEMORE + 1

start:
  mov a, 0x2345
  mov [FINAL], a  ;  four pins are output, for pins are input
  mov a, 0x4001
  mov [NEWCONST], a  ;  all pins are output
loop:
  mov a, 0b11111111
  mov [ANDONEMORE], a  ;  set some otput values
  mov a, 0b00001111
  mov [FIRSTCONST], a  ;  set some otput values
  jmp loop  ; repeat forever
  ;loading something into a register:
mov a, 0x55
mov a, [ 0x1234 ]
mov x, 0x55
mov x, [ 0x1234 ]
mov y, 0x55
mov y, [ 0x1234 ]
; storing the value from a register into memory:
mov [ 0x1234 ], a
mov [ 0x1234 ], x
mov [ 0x1234 ], y
; moving between registers:
mov a, x
mov x, a
mov a, y
mov y, a
;arithmetic and logic operations, the result always goes to A
addc a, 0x55 ; adds two bytes
addc a, [ 0x1234 ]
subc a, 0x55 ; substract
subc a, [ 0x1234 ]
and a, 0x55 ; biwise and
and a, [ 0x1234 ]
or a, 0x55 ; bitwise or
or a, [ 0x1234 ]
xor a, 0x55 ; bitwise xor
xor a, [ 0x1234 ]
inc a ; increment (add one)
inc x
inc y
inc [ 0x1234 ]
dec a ; decrement (substract one)
dec x
dec y
dec [ 0x1234 ]
; comparison operations (more explanations in the next class)
cmp a, 0x55
cmp a, [ 0x1234 ]
cmp x, 0x55
cmp x, [ 0x1234 ]
cmp y, 0x55
cmp y, [ 0x9999 ]
; conditional jump. The meaning of the immediate value
; will be explaine in the next class, or you can read the datasheet
bzs 0x55
bzc 0x55
bcs 0x55
