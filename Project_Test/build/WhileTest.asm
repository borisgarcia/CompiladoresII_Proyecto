; Variables
number dd 0
total dd 0
count dd 0
; Temp variables
PLACE : 
PLACE : 
PLACE : 
PLACE : 
global main

extern printf

section .data

section .text

; String Literals


; Array Declaration

main:
push ebp
mov ebp, esp
sub esp, 0




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
mov dword [], eax
mov eax, dword []
cmp eax, 0
je lbl3


mov eax, dword [count]
add eax, 1
mov dword [], eax

mov eax, dword []
imul eax, 10
mov dword [], eax

mov eax, dword []
mov dword [number], eax

push dword [strl0]
push strl1
call printf 
add esp, 4


push dword [count]
push strl2
call printf 
add esp, 4


push dword [strl3]
push strl1
call printf 
add esp, 4


push dword [number]
push strl2
call printf 
add esp, 4



mov eax, dword [count]
add eax, 1
mov dword [], eax
mov eax, dword []
mov dword [count], eax


mov eax, dword [total]
add eax, dword [number]
mov dword [], eax
mov eax, dword []
mov dword [total], eax

jmp lbl2
lbl3:


push dword [strl4]
push strl1
call printf 
add esp, 4


push dword [total]
push strl2
call printf 
add esp, 4

__lbl_main_epilog:
add esp, 0
leave
ret

