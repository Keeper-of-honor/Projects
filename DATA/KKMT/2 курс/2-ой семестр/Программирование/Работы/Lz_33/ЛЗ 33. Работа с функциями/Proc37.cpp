/* Programming Taskbook. Электронный задачник по программированию
(c)  М. Э. Абрамян (Южный федеральный университет), 1998–2020 */
// Процедуры и функции
// http://ptaskbook.com/ru/tasks/proc.php
/* Дополнительные задания на процедуры и функции
Proc37. Описать функцию Power1(A, B) вещественного типа, находящую величину A^B
по формуле A^B = exp(B*ln(A)) (параметры A и B — вещественные).
В случае нулевого или отрицательного параметра A функция возвращает 0.
С помощью этой функции найти степени A^P, B^P, C^P, если даны числа P, A, B, C. */
/* Решение. Гусятинер Л.Б., МГОТУ ККМТ, 06.05.2020 */
#include <iostream>
#include <cmath>
using namespace std;
double power1(double a, double b);
int main() {
    double p, a, b, c;
    cin >> p >> a >> b >> c;
    cout << a << "^" << p << "=" << power1(a, p) << endl;
    cout << b << "^" << p << "=" << power1(b, p) << endl;
    cout << c << "^" << p << "=" << power1(c, p) << endl;
	return 0;
}

double power1(double a, double b) {
    if (a <= 0)
        return 0;
    else
        return exp(b * log(a));
}
