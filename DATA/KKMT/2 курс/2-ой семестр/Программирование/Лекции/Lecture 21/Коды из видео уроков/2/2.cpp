/**
Вывод:
    Время
    Сколько времени осталось до конца дня
*/

#include <iostream>
#include <cstdio>

int main(){
    int h = 20, m = 14;
    printf("Time: %d:%d\n", h, m);
    printf("It's %.2f hours to midnight\n", ((24 - h) * 60. - m)/60 );
    
    return 0;
}

