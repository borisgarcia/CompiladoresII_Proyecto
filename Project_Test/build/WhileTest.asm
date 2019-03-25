; Variables
number dd 0
total dd 0
count dd 0
; Temp variables
global main

extern printf

section .data

; String Literals

strl4 db '] = ', 0
strl3 db '%d', 0
strl2 db '%c', 0
strl5 db 'The total is ', 0
strl0 db 'Number [', 0
strl1 db '%s', 0

section .text
section .data

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 24




mov eax, 0
mov dword [total], eax

mov eax, 0
mov dword [count], eax
lbl2:


mov eax, dword [count]
cmp eax, 3
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


mov eax, dword [count]
add eax, 1
mov dword [ebp - 12], eax

mov eax, dword [ebp - 12]
imul eax, 10
mov dword [ebp - 16], eax

mov eax, dword [ebp - 16]
mov dword [number], eax

push strl0
push strl1
call printf
add esp, 4


push strl3
call printf
add esp, 4


push strl4
push strl1
call printf
add esp, 4


push strl3
call printf
add esp, 4
push 10
push strl2
call printf
add esp, 4



mov eax, dword [count]
add eax, 1
mov dword [ebp - 20], eax
mov eax, dword [ebp - 20]
mov dword [count], eax


mov eax, dword [total]
add eax, dword [number]
mov dword [ebp - 24], eax
mov eax, dword [ebp - 24]
mov dword [total], eax

jmp lbl2
lbl3:


push strl5
push strl1
call printf
add esp, 4


push strl3
call printf
add esp, 4
push 10
push strl2
call printf
add esp, 4

__lbl_main_epilog:
add esp, 24
leave
ret

