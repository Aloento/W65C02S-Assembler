;fisrt comment
start:
    mov a, 0xff
    mov [0x002], a
label1: mov a, 0x55
    mov [0x0000], a
    mov a, 0xaa
    mov [0x0000], a
    jmp label1 ; second comment with label
