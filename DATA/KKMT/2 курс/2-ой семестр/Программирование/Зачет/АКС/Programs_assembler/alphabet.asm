org 100h  

mov ah, 02
mov dl, 'a'
mov cx, 26
print:  int 21h
        inc dl
loop print

mov ah, 0
int 16h
ret