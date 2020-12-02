org 100h
   
mov cx, 10
bruh:   mov ah, 02
        mov dl, '0'
        int 21h
        mov dl, '1'
        int 21h
loop bruh
   
ret