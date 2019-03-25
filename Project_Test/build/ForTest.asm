; Variables
i dd 0
; Temp variables
global main

extern printf

section .data

; String Literals

strl3 db '%d', 0
strl2 db '%c', 0
strl4 db 'End of loop', 0
strl0 db 'i = ', 0
strl1 db '%s', 0

section .text
section .data

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 8


lbl2:


mov eax, dword [i]
cmp eax, 10
jle lbl0
mov eax, 0
jmp lbl1
lbl0:
mov eax, 1
lbl1:
mov dword [ebp - 8], eax
mov eax, dword [ebp - 8]
cmp eax, 0
je lbl3

push strl0
push strl1
call printf
add esp, 4


push strl3
call printf
add esp, 4
push 10
push strl2
call printf
add esp, 8



jmp lbl2
lbl3:


push strl4
push strl1
call printf
add esp, 4
push 10
push strl2
call printf
add esp, 8

__lbl_main_epilog:
add esp, 8
leave
ret

