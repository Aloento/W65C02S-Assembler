start:
jmp start
mov a , 0x11
mov [0x3000] , X
mov y , 0x21
xirui:
jmp xirui
inc X
addc a , 2
