; Variables
i dd 0
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


lbl2:


mov eax, dword [i]
cmp eax, 10
jle lbl0
mov eax, 0
jmp lbl1
lbl0:
mov eax, 1
lbl1:
mov dword [], eax
mov eax, dword []
cmp eax, 0
je lbl3

push dword [strl0]
push strl1
call printf 
add esp, 4


push dword [i]
push strl2
call printf 
add esp, 4



jmp lbl2
lbl3:


push dword [strl3]
push strl1
call printf 
add esp, 4

__lbl_main_epilog:
add esp, 0
leave
ret

