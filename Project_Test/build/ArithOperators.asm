; Variables
y dd 0
x dd 0
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
sub esp, 20


mov eax, 9800
mov dword [x], eax

mov eax, 324234
mov dword [y], eax

push dword [strl0]
push strl1
call printf 
add esp, 4


push dword [x]
push strl2
call printf 
add esp, 4


push dword [strl3]
push strl1
call printf 
add esp, 4


push dword [y]
push strl2
call printf 
add esp, 4


push dword [strl4]
push strl1
call printf 
add esp, 4



mov eax, dword [x]
add eax, dword [y]
mov dword [ebp - 4], eax
push dword [ebp - 4]
push strl2
call printf 
add esp, 4


push dword [strl5]
push strl1
call printf 
add esp, 4



mov eax, dword [x]
sub eax, dword [y]
mov dword [ebp - 8], eax
push dword [ebp - 8]
push strl2
call printf 
add esp, 4


push dword [strl6]
push strl1
call printf 
add esp, 4



mov eax, dword [x]
imul eax, dword [y]
mov dword [ebp - 12], eax

push dword [ebp - 12]
push strl2
call printf 
add esp, 4


push dword [strl7]
push strl1
call printf 
add esp, 4



mov eax, dword [x]
mov ebx, dword [y]
cdq
idiv ebx
mov dword [ebp - 16], eax
push dword [ebp - 16]
push strl2
call printf 
add esp, 4


push dword [strl8]
push strl1
call printf 
add esp, 4



mov eax, dword [x]
mov ebx, dword [y]
cdq
idiv ebx
mov dword [ebp - 20], edx
push dword [ebp - 20]
push strl2
call printf 
add esp, 4

__lbl_main_epilog:
add esp, 20
leave
ret

