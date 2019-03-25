; Variables
z dd 0
y dd 0
x dd 0
a dd 10
b dd 20
; Temp variables

; String Literals

strl0global main

extern printf

section .data

section .text

; Array Declaration



main:
push ebp
mov ebp, esp
sub esp, 0


mov eax, dword [a]
mov dword [x], eax

mov eax, dword [b]
mov dword [y], eax

mov eax, dword []
mov dword [z], eax

push dword [z]
push strl0
call printf 
add esp, 4

__lbl_main_epilog:
add esp, 0
leave
ret
gcd:
push ebp
mov ebp, esp
sub esp, 8


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

mov eax, dword []
jmp __lbl_gcd_epilog

lbl3:
__lbl_gcd_epilog:
add esp, 8
leave
ret

