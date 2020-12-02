#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

typedef unsigned int Uint;
using namespace std;
using std::string;

struct Data{
	Uint Day;	///День
	Uint Mouth;	///Месяц
	Uint Year;	///Год
	Uint Hour;	///Час
	Uint Minute;	///Минуты
};

struct Flight{
	std::string Number;	///Номер рейса
	std::string City;	///Пункт назначения
	Data Dbegin;	///Время вылета
	Data Dend;	///Время прибытия
	Uint Num_place;	///Количество свободных мест
};

void menu();
void input(Flight *&mas, Uint &num);
void inSpisok(Flight &mas);
void departureTime(Flight mas[], Uint num);
void freePlaces(Flight mas[], Uint num);
void output(Flight mas[], Uint num);

#endif
