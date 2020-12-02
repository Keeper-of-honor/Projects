/**
Вывод:
    Длина строки s1
    Конкантенация s1 и s2
    Сравнение чтрок s1 и s3
*/

#include <iostream>
#include <cstring>

int main()
{
    char s1[100] = "Hello";
    std::cout << strlen(s1) << std::endl;
    
    char s2[] = ", world!";
    std::cout << strcat(s1, s2) << std::endl;

    char s3[6] = {72, 101, 108, 108, 111};
    if (strcmp(s1, s3) == 0)
        std::cout << "s1 == s3" << std::endl;
    else
        std::cout << "s1 != s3" << std::endl;
    
    return 0;
}

