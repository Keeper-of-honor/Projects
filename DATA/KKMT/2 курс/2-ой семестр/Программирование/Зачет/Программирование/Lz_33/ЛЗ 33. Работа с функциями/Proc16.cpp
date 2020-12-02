/* Programming Taskbook. Электронный задачник по программированию
(c)  М. Э. Абрамян (Южный федеральный университет), 1998–2020 */
// Процедуры и функции
// http://ptaskbook.com/ru/tasks/proc.php
/* Функции с числовыми параметрами
Proc16. Описать функцию Sign(X) целого типа, возвращающую для вещественного числа X следующие значения:
-1, если X < 0;
 0, если X = 0;
 1, если X > 0.
С помощью этой функции найти значение выражения Sign(A) + Sign(B) для данных вещественных чисел A и B. */
/* Решение. Гусятинер Л.Б., МГОТУ ККМТ, 06.05.2020 */
#include <iostream>
using namespace std;
int sign(int x);
int main() {
    int a, b;
    cin >> a >> b;
    int c = sign(a) + sign(b);
    cout << c << endl;
	return 0;
}

int sign(int x) {
    if (x < 0)
        return -1;
    else if (x == 0)
        return 0;
    else
        return 1;
}
