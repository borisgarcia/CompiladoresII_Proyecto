global main

extern printf

section .data

; String Literals

strl3 db '%s', 10, '', 0
strl2 db 'Hola Mundo', 0
strl0 db 'Hello World!', 10, '', 0
strl1 db '%s', 0

section .text
section .data
; Variables
; Temp variables

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 0

push strl0
push strl1
call printf 
add esp, 8


push strl2
push strl3
call printf 
add esp, 8

__lbl_main_epilog:
add esp, 0
leave
ret

