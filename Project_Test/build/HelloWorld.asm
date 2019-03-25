; Variables
; Temp variables
global main

extern printf

section .data

section .text

; String Literals


; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 0

push dword [strl0]
push strl1
call printf 
add esp, 4


push dword [strl2]
push strl1
call printf 
add esp, 4

__lbl_main_epilog:
add esp, 0
leave
ret

