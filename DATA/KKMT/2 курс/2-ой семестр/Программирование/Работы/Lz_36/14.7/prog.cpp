/**
7. Сформировать массив, содержащий сведения о наличии билетов, на рейсы Аэрофлота. Структурный тип содержит поля: номер рейса, пункт назначения, время вылета, время прибытия, количество свободных мест в салоне.
	Написать программу, выдающую следующую информацию:
	- Время вылета самолетов в город X
	- Наличие свободных мест на рейс в город X с временем отправления Y
*/
/// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
#include "function.h"

using namespace std;
typedef unsigned int Uint;

int main(){
	Uint num = 0;
	Flight *mas = nullptr;
	
	input(mas, num);
	int k = 1;
	while (k){
		menu();
		cout << "Enter: ";
		cin >> k;
		if (k == 1)
			departureTime(mas, num);
		else if (k == 2)
			freePlaces(mas, num);
		else if (k != 0)
			cout << "Error" << endl;
	}
	
	output(mas, num);	

	delete []mas;
	return 0;
}
