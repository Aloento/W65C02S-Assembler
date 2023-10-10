
;Sends a command to the LCD,
;the command byte is in A
;X register is modified
lcdcommand:
   mov x, 0x00
   mov [0x4001], x
   mov [0x4000], a ; PORTB set DB the input
   mov x, 0x80
   mov [0x4001], x ; PORTA: RS=0, E=1
   mov x, 0x00
   mov [0x4001], x ; PORTA: RS=0, E=0
   nop  ; it will be changed to ret (60)

;Sends a character to the LCD,
;the character byte is in A
;X register is modified
lcdprintchar:
   mov x, 0x00
   mov [0x4001], x
   mov [0x4000], a ; PORTB set DB the input
   mov x, 0xc0
   mov [0x4001], x ; PORTA: RS=1, E=1
   mov x, 0x40
   mov [0x4001], x ; PORTA: RS=1, E=0
   nop  ; it will be changed to ret (60)


start:
   mov a, 0x3b  ; 0011 1011 Function set
   jmp lcdcommand ; change to call (20)
   mov a, 0x0e  ; 0000 1110 Display on/off control
   jmp lcdcommand ; change to call (20)
   mov a, 0x06  ; 0000 0110 Entry mode set
   jmp lcdcommand ; change to call (20)

   mov a, 0x48  ; print H
   jmp lcdprintchar ; change to call (20)

happyend:
   jmp happyend

   jmp start


