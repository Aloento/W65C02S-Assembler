C = 2
D = 5
E = 3

mov a, 0x90
mov [42], a
mov a, 0x11
mov [43], a

hello:
mov a, C + D + E
mov y, 2
mov [zp[42] + y], a

xor a, [0x9013]

bzc hello
