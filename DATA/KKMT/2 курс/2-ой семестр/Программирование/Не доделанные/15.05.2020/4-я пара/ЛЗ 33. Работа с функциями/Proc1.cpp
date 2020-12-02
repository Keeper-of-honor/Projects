/* Programming Taskbook. Электронный задачник по программированию
(c)  М. Э. Абрамян (Южный федеральный университет), 1998–2020 */
// Процедуры и функции
// http://ptaskbook.com/ru/tasks/proc.php
/* Процедуры с числовыми параметрами
Proc1. Описать процедуру PowerA3(A, B), вычисляющую третью степень числа A и возвращающую ее
в переменной B (A — входной, B — выходной параметр; оба параметра являются вещественными).
С помощью этой процедуры найти третьи степени пяти данных чисел. */
/* Решение. Гусятинер Л.Б., МГОТУ ККМТ, 06.05.2020 */
#include <iostream>
using namespace std;
void powerA3(double a, double& b);
// С использованием ссылки
int main() {
    const int n = 5;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a;
        powerA3(a, b);
        cout << "a^3=" << b << endl;
    }
	return 0;
}

void powerA3(double a, double& b) {
    b = a * a * a;
}
