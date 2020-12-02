/* Управляющая конструкция switch */
/* Число дней по номеру месяца, невисокосный год. 13.04.2020, Гусятинер Л.Б., МГОТУ ККМТ */
/** Начало мантры */
#include <iostream>
using namespace std;
int main() {
    int month;
    int days = 0;
    cin >> month;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31; break;
    case 2:
        days = 28; break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30; break;
    default:
        days = -1; break;
    }
    if (days > 0)
        cout << days << endl;
    else
        cout << "wrong month number" << endl;
    return 0;
}
