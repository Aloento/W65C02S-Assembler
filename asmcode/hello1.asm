
;We set all pins to output
mov a, 0xff
mov [0x0002], a ; DDRB
mov [0x0003], a ; DDRA

;PA7 is E, PA6 is RS

;then perform the example in Table 13, pp 43 of the datasheet
mov a, 0x00
mov [0x0001], a ; PORTA: RS=0, E=0
mov a, 0x3b  ; 0011 1011 Function set
mov [0x0000], a ; PORTB set DB pins to 001110XX
mov a, 0x80
mov [0x0001], a ; PORTA: RS=0, E=1
mov a, 0x00
mov [0x0001], a ; PORTA: RS=0, E=0

mov a, 0x0e  ; 0000 1110 Display on/off control
mov [0x0000], a ; PORTB set DB pins to 00001110
mov a, 0x80
mov [0x0001], a ; PORTA: RS=0, E=1
mov a, 0x00
mov [0x0001], a ; PORTA: RS=0, E=0

mov a, 0x06  ; 0000 0110 Entry mode set
mov [0x0000], a ; PORTB set DB pins to 00000110
mov a, 0x80
mov [0x0001], a ; PORTA: RS=0, E=1
mov a, 0x00
mov [0x0001], a ; PORTA: RS=0, E=0

;Setup is complete, now we can print characters
mov a, 0x40
mov [0x0001], a ; PORTA: RS=1, E=0
mov a, 0x48  ; 0100 1000 = H
mov [0x0000], a ; PORTB set DB pins to 01001000
mov a, 0xc0
mov [0x0001], a ; PORTA: RS=1, E=1
mov a, 0x40
mov [0x0001], a ; PORTA: RS=1, E=0

mov a, 0xc8  ; 1100 1000 = something Japanese
mov [0x0000], a ; PORTB set DB pins to 01001000
mov a, 0xc0
mov [0x0001], a ; PORTA: RS=1, E=1
mov a, 0x40
mov [0x0001], a ; PORTA: RS=1, E=0

;infinite loop to stop the program
stop:
jmp stop
