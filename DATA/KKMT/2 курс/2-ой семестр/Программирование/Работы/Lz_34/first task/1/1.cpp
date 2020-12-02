/** 1. Объявить указатели на типы int, double, char. Вывести на экран
размер памяти, занимаемый этими указателями. Объясните полученный
результат.*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
using namespace std;

int main(){
    int *pi;
    double *pd;
    char *pc;
    cout << "Size pointer to int: " << sizeof(pi) << " byte" << endl
		<< "Size pointer to double: " << sizeof(pd) << " byte" << endl
		<< "Size pointer to char: " << sizeof(pc) << " byte" << endl;

    return 0;
}
