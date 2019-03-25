global main

extern printf

section .data

; String Literals

strl4 db '%s', 10, '', 0
strl2 db '%d', 10, '', 0
strl3 db 'End of loop', 0
strl0 db 'i = ', 0
strl1 db '%s', 0

section .text
section .data
; Variables
i dd 0
; Temp variables

; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 12


mov eax, 0
mov dword [i], eax

lbl2:


mov eax, dword [i]
cmp eax, 10
jle lbl0
mov eax, 0
jmp lbl1
lbl0:
mov eax, 1
lbl1:
mov dword [ebp - 8], eax
mov eax, dword [ebp - 8]
cmp eax, 0
je lbl3

push strl0
push strl1
call printf 
add esp, 8


push dword [i]
push strl2
call printf 
add esp, 8




mov eax, dword [i]
add eax, 1
mov dword [ebp - 12], eax
mov eax, dword [ebp - 12]
mov dword [i], eax

jmp lbl2
lbl3:


push strl3
push strl4
call printf 
add esp, 8

__lbl_main_epilog:
add esp, 12
leave
ret

