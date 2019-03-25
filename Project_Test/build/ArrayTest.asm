; Variables
i dd 0
n dd 10
; Temp variables
global main

extern printf

section .data

section .text

; String Literals


; Array Declaration

arr times 10 dd 0


main:
push ebp
mov ebp, esp
sub esp, 0


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
mov dword [], eax
mov eax, dword []
cmp eax, 0
je lbl3

mov ecx, dword [i]

push dword [arr+ecx*4]
push strl0
call printf 
add esp, 4


push dword [strl1]
push strl2
call printf 
add esp, 4



jmp lbl2
lbl3:


push dword [strl3]
push strl2
call printf 
add esp, 4

__lbl_main_epilog:
add esp, 0
leave
ret

