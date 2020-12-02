name "print_a"

org 100h

mov ah, 2   
mov dl, 'A'
int 21h    

mov ah, 0
int 16h

ret