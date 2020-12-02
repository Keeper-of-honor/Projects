/** Команда состоит из 3-х человек: Груздев Роман, Герасимов Дмитрий, Пётр Митюшин.
П1-18, 05.06.2020 г.
*/
#ifndef FUNC_H
#define FUNC_H

struct Date { // дата
    int day; // день
    int month; // месяц
    int year; // год
};

struct Nomination { // Заказ
    int nom_id; // Номер изделия
    std::string name; // название изделия
    std::string pr; // производитель 
    Date date; // Дата производства
    double cost; // Стоимость изделия
    bool t; // Присутствует ли изделие на складе
	int number;	//Колличество
};

typedef std::vector <Nomination> vNom;

void load(vNom &v); // 1.Загрузка файла из фнейм

void save(vNom &v); // 2.Выгрузка файла в фнейм_о

void append(vNom &v); // 3.Добавление нового изделия в вектор

void edit(vNom &v); // 4.Редактирование стоимости изделия

void del(vNom &v); // 5.Удаление заказа

void sort(vNom &v); // 6.Сортировка изделий по дате

void print_all(vNom v); // 7.Общ. список изделий

void maxxMinn(vNom v); // 8. Выдать максимум и минимум по количеству или по сумме
#endif
