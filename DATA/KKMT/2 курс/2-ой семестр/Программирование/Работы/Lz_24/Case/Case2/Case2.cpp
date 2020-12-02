/**
©  М. Э. Абрамян (Южный федеральный университет), 1998–2020
Case2°. Дано целое число K. Вывести строку-описание оценки, соответствующей числу K (1 — «плохо», 2 — «неудовлетворительно», 3 — «удовлетворительно», 4 — «хорошо», 5 — «отлично»). Если K не лежит в диапазоне 1–5, то вывести строку «ошибка».
Автор решения: Герасимов Дмитрий Александрович
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	switch (day){
	case 1:
		cout << "плохо" << endl; break;
	case 2:
		cout << "неудовлетворительно" << endl; break;
	case 3:
		cout << "удовлетворительно" << endl; break;
	case 4:
		cout << "хорошо" << endl; break;
	case 5:
		cout << "отлично" << endl; break;
	default:
		cout << "Error" << endl; break;
	}
return 0;
}

/**
Input:
5
 
Output: 
отлично
------------
Input:
9

Output:
Error
 
*/
