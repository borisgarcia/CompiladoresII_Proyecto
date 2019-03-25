; Variables
; Temp variables
global main

extern printf

section .data

; String Literals

strl3 db 'Hola Mundo', 0
strl2 db '%c', 0
strl0 db 'Hello World!\n', 0
strl1 db '%s', 0

section .text
section .data

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 0

push strl0
push strl1
call printf
add esp, 4


push strl3
push strl1
call printf
add esp, 4
push 10
push strl2
call printf
add esp, 8

__lbl_main_epilog:
add esp, 0
leave
ret

