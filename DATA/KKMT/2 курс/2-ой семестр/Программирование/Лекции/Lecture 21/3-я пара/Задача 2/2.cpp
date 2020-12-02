/**
Вычислить значения функций и вывести их на экран (результаты расчетов должны совпадать). 
z =2*sin^2*(3pi-2*a)*cos^2(5*pi+2*a)
y =1\4 - 1\4 * sin((5\2) * pi - 8a)
Программа сначала вводит значение а, выводит z и на следующей строке y.
(Нужно подключить заголовочный файл <cmath>).

Выполнил: Герасимов Дмитрий Александрович П1-18
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a;
    cin >> a;
    cout << 2 * pow(sin(3*M_PI - 2*a),2)*pow(cos(5*M_PI + 2*a),2) << endl
        << 1./4 - 1./4 * sin(5. / 2 * M_PI - 8 * a) << endl;
    
    return 0;
}

/**
Sample Input:

6.7
Sample Output:

0.495362
0.495362

*/
