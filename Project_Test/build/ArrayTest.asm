; Variables
i dd 0
n dd 10
; Temp variables
global main

extern printf

section .data

; String Literals

strl4 db '', 0
strl3 db '%s', 0
strl2 db ' ', 0
strl0 db '%d', 0
strl1 db '%c', 0

section .text
section .data

; Array Declaration

arr times 10 dd 0


main:
push ebp
mov ebp, esp
sub esp, 8


mov edx, 24

mov ecx, 0

mov dword [arr+ecx*4], edx


mov edx, 71

mov ecx, 1

mov dword [arr+ecx*4], edx


mov edx, 94

mov ecx, 2

mov dword [arr+ecx*4], edx


mov edx, 3

mov ecx, 3

mov dword [arr+ecx*4], edx


mov edx, 46

mov ecx, 4

mov dword [arr+ecx*4], edx


mov edx, 54

mov ecx, 5

mov dword [arr+ecx*4], edx


mov edx, 96

mov ecx, 6

mov dword [arr+ecx*4], edx


mov edx, 14

mov ecx, 7

mov dword [arr+ecx*4], edx


mov edx, 7

mov ecx, 8

mov dword [arr+ecx*4], edx


mov edx, 42

mov ecx, 9

mov dword [arr+ecx*4], edx


lbl2:


mov eax, dword [i]
cmp eax, dword [n]
jl lbl0
mov eax, 0
jmp lbl1
lbl0:
mov eax, 1
lbl1:
mov dword [ebp - 8], eax
mov eax, dword [ebp - 8]
cmp eax, 0
je lbl3

mov ecx, dword [i]

push strl0
call printf
add esp, 4


push strl2
push strl3
call printf
add esp, 4



jmp lbl2
lbl3:


push strl4
push strl3
call printf
add esp, 4
push 10
push strl1
call printf
add esp, 4

__lbl_main_epilog:
add esp, 8
leave
ret

