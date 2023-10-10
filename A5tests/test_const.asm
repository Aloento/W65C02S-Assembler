;constants
VIABASE = 0x4000  ; start of memory address of the interface adapter
PORTB = VIABASE
PORTA = VIABASE + 1
DDRB  = VIABASE + 2 ; data direction registers
DDRA  = VIABASE + 3

start:
  mov a, 0b11110000
  mov [DDRA], a  ;  four pins are output, for pins are input
  mov a, 0b11111111
  mov [DDRB], a  ;  all pins are output
loop:
  mov a, 0x55
  mov [PORTB], a  ;  set some otput values
  mov a, 0xaa
  mov [PORTB], a  ;  set some otput values
  jmp loop  ; repeat forever
