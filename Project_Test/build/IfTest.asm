; Variables
y dd 0
x dd 0
; Temp variables
global main

extern printf

section .data

; String Literals

strl6 db 'X is not equal to Y\n', 0
strl1 db '%s', 0
strl0 db 'X = ', 0
strl4 db ' Y = ', 0
strl5 db 'X is equal to Y\n', 0
strl2 db '%c', 0
strl3 db '%d', 0

section .text
section .data

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 16


mov eax, 5
mov dword [x], eax

mov eax, 7
mov dword [y], eax

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



mov eax, dword [x]
cmp eax, dword [y]
je lbl0
mov eax, 0
jmp lbl1
lbl0:
mov eax, 1
lbl1:
mov dword [ebp - 8], eax
cmp dword [ebp - 8], 0
je lbl2

push strl5
push strl1
call printf
add esp, 4


jmp lbl3
lbl2:

push strl6
push strl1
call printf
add esp, 4


lbl3:

mov eax, 456
mov dword [x], eax

mov eax, 456
mov dword [y], eax

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



mov eax, dword [x]
cmp eax, dword [y]
je lbl4
mov eax, 0
jmp lbl5
lbl4:
mov eax, 1
lbl5:
mov dword [ebp - 16], eax
cmp dword [ebp - 16], 0
je lbl6

push strl5
push strl1
call printf
add esp, 4


jmp lbl7
lbl6:

push strl6
push strl1
call printf
add esp, 4


lbl7:
__lbl_main_epilog:
add esp, 16
leave
ret

