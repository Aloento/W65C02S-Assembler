

;sends the command which is in the a register to the LCD
;the x register is modified
lcdCommand:
mov x, 0x00
mov [0x4001], x ; PORTA: RS=0, E=0
mov [0x4000], a ; PORTB set DB pins to input data
mov x, 0x80
mov [0x4001], x ; PORTA: RS=0, E=1
mov x, 0x00
mov [0x4001], x ; PORTA: RS=0, E=0
nop  ; ret in reality  0x60

;sends the character which is in the a register to the LCD
;the x register is modified
lcdPrintchar:
mov x, 0x40
mov [0x4001], x ; PORTA: RS=1, E=0
mov [0x4000], a ; PORTB set DB pins to input data
mov x, 0xc0
mov [0x4001], x ; PORTA: RS=1, E=1
mov x, 0x40
mov [0x4001], x ; PORTA: RS=1, E=0
nop ; ret  0x60

start:
;We set all pins to output
mov a, 0xff
mov [0x4002], a ; DDRB
mov [0x4003], a ; DDRA

;PA7 is E, PA6 is RS

;then perform the example in Table 13, pp 43 of the datasheet
mov a, 0x3b  ; 0011 1011 Function set
jmp lcdCommand  ; call 0x20
mov a, 0x0e  ; 0000 1110 Display on/off control
jmp lcdCommand  ; call 0x20
mov a,  0x06  ; 0000 0110 Entry mode set
jmp lcdCommand  ;call 0x20


;Setup is complete, now we can print characters

mov a, 0x48  ; H
jmp lcdPrintchar  ; call 0x20
mov a, 0xc8  ; ??
jmp lcdPrintchar  ; call 0x20
mov a,  0xc9  ; ??
jmp lcdPrintchar  ;call 0x20

;infinite loop to stop the program
stop:
jmp stop


jmp start ; to know the reset vector
