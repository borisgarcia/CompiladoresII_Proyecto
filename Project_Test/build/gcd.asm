; Variables
z dd 0
y dd 0
x dd 0
a dd 10
b dd 20
; Temp variables
global main

extern printf

section .data

; String Literals

strl1 db '%c', 0
strl0 db '%d', 0

section .text
section .data

; Array Declaration



main:
push ebp
mov ebp, esp
sub esp, 4


mov eax, dword [a]
mov dword [x], eax

mov eax, dword [b]
mov dword [y], eax


push dword [y]
push dword [x]
call gcd
add esp, 8
mov dword [ebp - 4], eax
mov eax, 
mov dword [z], eax

push strl0
call printf
add esp, 4
push 10
push strl1
call printf
add esp, 8

__lbl_main_epilog:
add esp, 4
leave
ret
gcd:
push ebp
mov ebp, esp
sub esp, 16


mov eax, dword [ebp + 12]
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

mov eax, dword [ebp + 8]
jmp __lbl_gcd_epilog

jmp lbl3
lbl2:



mov eax, dword [ebp + 8]
mov ebx, dword [ebp + 12]
cdq
idiv ebx
mov dword [ebp - 12], edx
push dword [ebp - 12]
push dword [ebp + 12]
call gcd
add esp, 8
mov dword [ebp - 16], eax
mov eax, 
jmp __lbl_gcd_epilog

lbl3:
__lbl_gcd_epilog:
add esp, 16
leave
ret

