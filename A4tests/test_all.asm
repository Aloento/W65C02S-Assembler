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
bcc 0x55
;subroutine calls
call 0x1234
ret
reti
;stack operations
push a
push x
push y
push p
pop a
pop x
pop y
pop p
;movement between x and s
mov s, x
mov x, s
;manipulating bits in p
sec
clc
sei
cli
clv
;rotating bits left or right
rotl a
rotr a
;zero page operations
mov a, [ zp[42] ]
mov a, [ zp[42] + y ]
mov [ zp[42] ], a
mov [ zp[42] + y ], a

addc a, [ zp[42] ]
addc a, [ zp[42] + y ]
subc a, [ zp[42] ]
subc a, [ zp[42] + y ]
cmp a, [ zp[42] ]
cmp a, [ zp[42] + y ]
and a, [ zp[42] ]
and a, [ zp[42] + y ]
or a, [ zp[42] ]
or a, [ zp[42] + y ]
xor a, [ zp[42] ]
xor a, [ zp[42] + y ]

