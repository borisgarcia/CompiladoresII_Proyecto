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
sub esp, 16


mov eax, 5
mov dword [x], eax

mov eax, 7
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

push dword [strl4]
push strl1
call printf 
add esp, 4


jmp lbl3
lbl2:

push dword [strl5]
push strl1
call printf 
add esp, 4


lbl3:

mov eax, 456
mov dword [x], eax

mov eax, 456
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

push dword [strl4]
push strl1
call printf 
add esp, 4


jmp lbl7
lbl6:

push dword [strl5]
push strl1
call printf 
add esp, 4


lbl7:
__lbl_main_epilog:
add esp, 16
leave
ret

