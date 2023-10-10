PORTA = 0x4001
PORTB = 0x4000
DDRB = 0x4002
DDRA = 0x4003

FUNCSET = 0x3b
DISPCTRL = 0x0e

LINELEN = 16
CURSHOME = 0b00000011
MVRIGHT = 0b00010111

ROW = 1 ; range 0-1
COL = 7 ; range 0-15

;sends the command which is in the a register to the LCD
;the x register is modified
lcdCommand:
mov x, 0x00
mov [PORTA], x ; RS=0, E=0
mov [PORTB], a ; Set DB pins to input data
mov x, 0x80
mov [PORTA], x ; RS=0, E=1
mov x, 0x00
mov [PORTA], x ; RS=0, E=0
ret

;moves the cursor to row x, and column y
;the a, x, and y registers are modified
lcdCursor:
mov a, x
subc a, 1
bzc 4
mov a, y
addc a, LINELEN
mov y, a
mov a, CURSHOME
call lcdCommand
mov a, y
loop:
bzs 12
mov y, a
mov a, MVRIGHT
call lcdCommand
mov a, y
subc a, 1
jmp loop
ret

start:
;We set all pins to output
mov a, 0xff
mov [DDRB], a
mov [DDRA], a

;PA7 is E, PA6 is RS

;then perform the example in Table 13, pp 43 of the datasheet
mov a, FUNCSET
call lcdCommand
mov a, DISPCTRL
call lcdCommand
mov x, ROW
mov y, COL
call lcdCursor

;infinite loop to stop the program
stop:
jmp stop
