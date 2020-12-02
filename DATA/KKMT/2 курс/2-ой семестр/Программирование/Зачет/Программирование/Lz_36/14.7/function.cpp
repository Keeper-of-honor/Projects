/**
7. Сформировать массив, содержащий сведения о наличии билетов, на рейсы Аэрофлота. Структурный тип содержит поля: номер рейса, пункт назначения, время вылета, время прибытия, количество свободных мест в салоне.
	Написать программу, выдающую следующую информацию:
	- Время вылета самолетов в город X
	- Наличие свободных мест на рейс в город X с временем отправления Y
*/
/// Выполнил: Герасимов Д.А., П1-18

#include "function.h"

///Меню
void menu(){
	cout << endl
		<< "Menu" << endl
		<< "0. Выход" << endl
		<< "1. Время вылета самолетов в город X" << endl
		<< "2. Наличие свободных мест на рейс в город X с временем отправления Y" << endl
		<< endl;
}

///Ввод нескольких рейсов
void input(Flight *&mas, Uint &num){
	cout << endl
		<< "Enter the number of flights: ";
	cin >> num;
	mas = new Flight[num];
	for (size_t i = 0; i != num; ++i){
		cout << endl
			<< "Input number " << i + 1 << endl;
		inSpisok(mas[i]);
	}
}
///Конкретный ввод данных 
void inSpisok(Flight &elem){
	cout << "Enter flight number: ";
	cin >> elem.Number;

	cout << "Enter destination: ";
	cin >> elem.City;

	cout << "Enter departure time (dd mm yy hh mm): ";
	cin >> elem.Dbegin.Day >> elem.Dbegin.Mouth >> elem.Dbegin.Year >> elem.Dbegin.Hour >> elem.Dbegin.Minute;

	cout << "Enter arrival time (dd mm yy hh mm): ";
	cin >> elem.Dend.Day >> elem.Dend.Mouth >> elem.Dend.Year >> elem.Dend.Hour >> elem.Dend.Minute;

	cout << "Number of free places: ";
	cin >> elem.Num_place;
}

///Время вылета самолетов в город X
void departureTime(Flight mas[], Uint num){
	cout << endl;
	string loc_city;
	cout << "Enter destination: ";
	cin >> loc_city;

	cout << "Departure times:" << endl;
	for (size_t i = 0; i != num; ++i)
		if (mas[i].City == loc_city)
			cout << i+1 << ". " << mas[i].Dbegin.Day << '.' << mas[i].Dbegin.Mouth << '.'<< mas[i].Dbegin.Year << '\t' << mas[i].Dbegin.Hour << ':' << mas[i].Dbegin.Minute << endl;
	cout << endl;
}

///Наличие свободных мест на рейс в город X с временем отправления Y
void freePlaces(Flight mas[], Uint num){
	cout << endl;

	string loc_city;
	cout << "Enter destination: ";
	cin >> loc_city;
	Data loc_times;
	cout << "Enter departure time (dd mm yy hh mm): ";
	cin >> loc_times.Day >> loc_times.Mouth >> loc_times.Year >> loc_times.Hour >> loc_times.Minute;

	cout << "Number of free places:" << endl;
	for (size_t i = 0; i != num; ++i){
		if ((mas[i].City == loc_city) && ((mas[i].Dbegin.Day == loc_times.Day) && (mas[i].Dbegin.Mouth == loc_times.Mouth) && (mas[i].Dbegin.Year == loc_times.Year) && (mas[i].Dbegin.Hour == loc_times.Hour) && (mas[i].Dbegin.Minute == loc_times.Minute)))
		cout << i+1 << ". " << mas[i].Num_place << endl;
			
	}
	cout << endl;
}

///Вывод рейсов
void output(Flight mas[], Uint num){
	for (size_t i = 0; i != num; ++i)
		cout << endl
			<< i+1 << ". " << mas[i].Number << ' ' << mas[i].City << endl 
			<< mas[i].Dbegin.Day << ' ' << mas[i].Dbegin.Hour << ' ' << mas[i].Dbegin.Minute << endl
			<< mas[i].Dend.Day << '.' << mas[i].Dend.Mouth << '.'<< mas[i].Dend.Year << '.' << '\t' << mas[i].Dend.Hour << ':' << mas[i].Dend.Minute << endl
			<< mas[i].Num_place << endl;
}




