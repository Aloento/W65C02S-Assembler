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

;jumping to a subroutine
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

