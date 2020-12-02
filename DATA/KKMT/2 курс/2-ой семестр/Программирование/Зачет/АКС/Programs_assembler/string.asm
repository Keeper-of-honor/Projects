org 100h

jmp start
str_bruh db 'bruh$'
start:  lea dx, str_bruh
        mov ah, 09h
        int 21h
mov ah, 0
int 16h

ret