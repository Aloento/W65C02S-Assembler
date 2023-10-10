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
ret  ; ret in reality  0x60

;moves the cursor to row x, and column y
;the a, x, and y registers are modified
lcdCursor:
mov a, x
subc a, 1
bzc 4
mov a, y
addc a, 16
mov y, a
mov a, 0b00000011 ; bring cursor home
call lcdCommand
mov a, y
loop:
bzs 12
mov y, a
mov a, 0b00010111 ; move cursor right
call lcdCommand
mov a, y
subc a, 1
jmp loop
ret

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
ret ; ret  0x60

start:
;We set all pins to output
mov a, 0xff
mov [0x4002], a ; DDRB
mov [0x4003], a ; DDRA

;PA7 is E, PA6 is RS

;then perform the example in Table 13, pp 43 of the datasheet
mov a, 0x3b  ; 0011 1011 Function set
call lcdCommand  ; call 0x20
mov a, 0x0e  ; 0000 1110 Display on/off control
call lcdCommand  ; call 0x20
mov a,  0x06  ; 0000 0110 Entry mode set
call lcdCommand  ;call 0x20


;Setup is complete, now we can print characters

mov x, 1;
mov y, 9;
call lcdCursor

mov a, 0x48  ; H
call lcdPrintchar  ; call 0x20
mov a, 0xc8  ; ??
call lcdPrintchar  ; call 0x20
mov a,  0xc9  ; ??
call lcdPrintchar  ;call 0x20

;infinite loop to stop the program
stop:
jmp stop

jmp start ; to know the reset vector
