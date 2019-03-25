global main

extern printf

section .data

; String Literals

strl4 db 'Factorial de 7 = ', 0
strl3 db 'Factorial de 6 = ', 0
strl2 db '%d', 10, '', 0
strl0 db 'Factorial de 5 = ', 0
strl1 db '%s', 0

section .text
section .data
; Variables
x dd 0
; Temp variables

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 0


mov eax, dword []
mov dword [x], eax

push strl0
push strl1
call printf 
add esp, 8


mov eax, dword []
mov dword [x], eax

push dword [x]
push strl2
call printf 
add esp, 8


push strl3
push strl1
call printf 
add esp, 8


mov eax, dword []
mov dword [x], eax

push dword [x]
push strl2
call printf 
add esp, 8


push strl4
push strl1
call printf 
add esp, 8


mov eax, dword []
mov dword [x], eax

push dword [x]
push strl2
call printf 
add esp, 8

__lbl_main_epilog:
add esp, 0
leave
ret
factorial:
push ebp
mov ebp, esp
sub esp, 12


mov eax, dword [ebp + 8]
cmp eax, 0
je lbl0
mov eax, 0
jmp lbl1
lbl0:
mov eax, 1
lbl1:
mov dword [ebp - 8], eax
cmp dword [ebp - 8], 0
je lbl2

mov eax, 1
jmp __lbl_factorial_epilog

jmp lbl3
lbl2:


mov eax, dword [ebp + 8]
imul eax, dword []
mov dword [ebp - 12], eax

mov eax, dword [ebp - 12]
jmp __lbl_factorial_epilog

lbl3:
__lbl_factorial_epilog:
add esp, 12
leave
ret

