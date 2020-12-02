/**
Ввод:
    a и b
Вывод:
    Сумма a и b
*/

#include <iostream>
#include <cstdio>

int main(){
    int a = 0, b = 0;
    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);
    printf("a + b = %d\n", (a + b));
    
    return 0;
}

