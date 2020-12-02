/* Управляющая конструкция if */
/* Максимальное из 3х целых чисел. 13.04.2020, Гусятинер Л.Б., МГОТУ ККМТ */
/** Начало мантры */
#include <iostream>
using namespace std;
/** Конец мантры */
int main() {
    int a, b, c; /* Определение и одновременно бъявление переменных, не инициализированы, "мусор" */
    cin >> a >> b >> c;
    int max;
    if (a >= b && a >= c)
        max = a;
    else if (b >= a && b >= c)
        max = b;
    else
        max = c;
    cout << "max = " << max << endl;
    return 0;
}
