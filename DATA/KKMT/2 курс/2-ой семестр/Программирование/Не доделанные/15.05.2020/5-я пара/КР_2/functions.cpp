#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "func.h"

using namespace std;

// 1. Загрузка файла в вектор
void load(vPlist &vec){
	string ifname;
	cout << "Введите имя файла: ";
	cin >> ifname;
	ifstream in(ifname);
	Plist plist;

	char dot;
	vec.clear();
	while (in >> plist.date.day >> dot >> plist.date.month >> dot  >> plist.date.year >> plist.name >> plist.price){
		vec.push_back(plist);
	}

	in.close();
}

// 2. Загрузить вектор в файл
void save(vPlist vec){
	cout << "Введите имя файла выгрузки: ";
	string ofname;
	cin >> ofname;
	ofstream out(ofname, ios::app);

	unsigned int size_vec = vec.size();
	for (size_t i = 0; i != size_vec; ++i){
		out << setw(2) << setfill('0') << vec[i].date.day << "."
			<< setw(2) << vec[i].date.month << "."
			<< setw(4) << vec[i].date.year << "\t"
			<< vec[i].name << "\t"
			<< vec[i].price << endl;
	}
}

//3. Заменить строку с номером N
void swapStr(vPlist &vec){
	unsigned int size_vec = vec.size();

	unsigned int n;
	cout << "Введите номер строки которую хотите заменить: ";
	cin >> n;
	
	if (n > size_vec || n <= 0)
		cout << "Error. Диапазон строк 1.." << size_vec;
	else{
		Plist new_str;
		char dot;

		cin >> new_str.date.day >> dot >> new_str.date.month >> dot  >> new_str.date.year >> new_str.name >> new_str.price;
		vec[n-1] = new_str;
		cout << "Строка заменена";
	}
}

//4. Удалить строку с номером N
void delStr(vPlist &vec){
	unsigned int size_vec = vec.size();

	unsigned int n;
	cout << "Введите номер строки которую хотите удалить: ";
	cin >> n;
	
	if (n > size_vec || n <= 0)
		cout << "Error. Диапазон строк 1.." << size_vec;
	else{
		vec.erase(vec.begin() + n-1);
		cout << "Строка удаленна";
	}
}

//5. Содержимое вектора
void printVec(vPlist vec){
	unsigned int size_vec = vec.size();

	for (size_t i = 0; i != size_vec; ++i){
		printf("%02d.%02d.%04d\t", vec[i].date.day, vec[i].date.month, vec[i].date.year);
		cout << vec[i].name << "\t"
			<< vec[i].price << endl;
	}
}

/*
Формат выходной ведомости к п.6
Апрель 2010 500
Май 2010 100
Июнь 2010 200
Итого за 2010 год 800
*/

//6. Отпечатать суммарные ежемесячные и годовую продажи
void report(vPlist vec){
	size_t size_vec = vec.size();
	
	// Сортировка по году
	Date temp;
	for (size_t i = 0; i != size_vec; ++i)
		for (size_t j = 1; j != size_vec; ++j)
			if (vec[j-1].date.year > vec[j].date.year){
				temp = vec[j-1].date;
				vec[j-1].date = vec[j].date;
				vec[j].date = temp;
			}

	size_t compare_year = 0;
	for (size_t i = 0; i != size_vec; ++i){
		vector <unsigned int> loc_month(12);
		if (compare_year != vec[i].date.year || i == ){
			compare_year = vec[i].date.year;
			for (size_t i = 0; i != size_vec)
		}
	}

	/*
	//vector <unsigned int> vloc_years;	//Тип хранящий год
	//size_t size_vly = 0;			//Размер vloc_years
	// Все виды годов
	for (size_t i = 0; i != size_vec; ++i){	
		size_vly = vloc_years.size();
		bool present = 0;
		for (size_t j = 0; j != size_vly; ++j)	
			if (vec[i].date.year == vloc_years[j]){	//Присутствует ли год в цикле
				present = 1;
				break;
			}
		if (!present)
			vloc_years.push_back(vec[i].date.year);
	}

	// Вывод
	size_vly = vloc_years.size();
	for (size_t i = 0; i != size_vec; ++i){	
		vector <char> vloc_month(12);
		for (size_t j = 0; j != size_vly; ++j){
			for (size_t k = 0; k != 12; ++k){
				if
			}
		}
	}
	*/
}





















