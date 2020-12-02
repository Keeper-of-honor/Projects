/**Разработать АТД "Список". Список List1 содержит записи о студентах [Зачетка, Фамилия], сдающих тест. Сдача теста 
        каждым студентом означает удаление из списка List1 и включение в список List2 с оценкой, т.е. [Зачетка, Фамилия, 
        Оценка]. Отпечатать оба списка.
*/

#include <iostream>
#include "func.h"

using namespace std;

void menu(){
	cout << "0. Выход" << endl
		<< "1. Отправить студента на сдачу" << endl
		<< "2. Студент сдал" << endl
		<< "3. Список сдающих" << endl
		<< "4. Список сдавших" << endl;
}

int main(){

	vector <List1> vList1;
	vector <List2> vList2;

	while (n){
		menu();
		cout << "Пункт меню: ";
		cin >> n;
		if (n == 1)
			appList(vList1);
		else if (n == 2)
			passStudent(vList1, vList2)
		else if (n == 3)
		else if (n == 4)
		else if (n)
			cout << "Error. Диапазон 0..4" <<endl;
			
	}

	return 0;
}
