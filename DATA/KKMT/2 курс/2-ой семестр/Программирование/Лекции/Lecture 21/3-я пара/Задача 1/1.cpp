/**
Напишите программу, которая выводит размеры типов int, float, char, bool и size_t в битах . Каждое значение должно быть в отдельной строке в указанном порядке. Для вывода используйте cout, заголовок уже подключен.
*/
#include <iostream>
int main(){
    std::cout << sizeof(int)*8 << std::endl
        << sizeof(float)*8 << std::endl
        << sizeof(char)*8 << std::endl
        << sizeof(bool)*8 << std::endl
        << sizeof(size_t)*8 << std::endl;

    return 0;
}
