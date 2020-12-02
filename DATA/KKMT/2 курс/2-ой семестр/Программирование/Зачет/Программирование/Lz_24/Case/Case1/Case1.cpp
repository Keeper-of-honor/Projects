/**
©  М. Э. Абрамян (Южный федеральный университет), 1998–2020
Case1. Дано целое число в диапазоне 1–7. Вывести строку — название дня недели, соответствующее данному числу (1 — «понедельник», 2 — «вторник» и т. д.).
Автор решения: Герасимов Дмитрий Александрович
*/
#include <iostream>
using namespace std;

int main(){
	int day;
	cin >> day;
	switch (day){
	case 1:
		cout << "понедельник" << endl; break;
	case 2:
		cout << "вторник" << endl; break;
	case 3:
		cout << "среда" << endl; break;
	case 4:
		cout << "четверг" << endl; break;
	case 5:
		cout << "пятница" << endl; break;
	case 6:
		cout << "суббота" << endl; break;
	case 7:
		cout << "воскресение" << endl; break;
	default:
		cout << "Error" << endl; break;
	}

	return 0;
}

/**
Input:
1

Output:
понедельник
------------
Input:
9

Output:
Error
*/
