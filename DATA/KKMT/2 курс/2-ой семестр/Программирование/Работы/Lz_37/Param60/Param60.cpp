/*
 * Param60°. Используя тип TDate и функцию LeapYear (см. задание Param59), описать функцию DaysInMonth(D) целого типа с параметром типа TDate, которая возвращает количество дней для месяца, указанного в дате D. Вывести значение функции DaysInMonth для пяти данных дат (предполагается, что все даты являются правильными)
 */

#include <iostream>
#include "tdate.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");

	const size_t N = 5;

	for (size_t i = 0; i != N; ++i){
		tdate date;
		cout << i+1 << ". " << "Введите день, месяц, год: ";
		cin >> date.day >> date.month >> date.year;
		cout << "В этом месяце: "<< date.days_in_month() << " дней." << endl
			<< endl;
	}

	return 0;
}
