/** Лабораторное занятие 38. Создание многофайлового проекта.
Команда состоит из 4-х человек: Груздев Роман, Герасимов Дмитрий, Батраков Данила, Слепов Андрей.
П1-18, 26.05.2020 г.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "func.h"

using namespace std;

// Загрузить из файла
void load(vector<Order> *v, string fname) {
    Order order;
    ifstream in(fname);

    char delim;
    v->clear();
    while (in >> order.order_id >> order.saler >> order.customer >> order.date.year >> delim >> order.date.month >> delim >> order.date.day >> delim >> order.cost)
    {
        v->push_back(order);
    }

   cout << endl;
}

// Выгрузить в файл
void save(vOrders &v, string fname_o){

	ofstream out(fname_o);

	for(size_t i = 0; i != v.size(); i++)
		out << v[i].order_id << "  \t" << v[i].saler << "  \t" << v[i].customer << "   \t" << v[i].date.year << "." << v[i].date.month << "." << v[i].date.day << "  \t" << v[i].cost << endl;

}

// Добавить новый заказ
void append(vOrders *v){
	Order order;
	char delim;
        while(cin >> order.order_id >> order.saler >> order.customer >> order.date.year >> delim >> order.date.month >> delim >> order.date.day >> order.cost){

        v->push_back(order);
	break;
	}
	cout << endl;
}

// Редактировать сумму заказа
void edit(vOrders &v, size_t idx){
	std::cout << "Введите новую сумму: ";
	double ed_cost;
	std::cin >> ed_cost;
	v[--idx].cost = ed_cost;
	cout << endl;
}

// Удалить заказ
void del(vOrders *v, size_t idx){
	v->erase(v->begin() + (--idx));
	cout << endl << "Заказ удалён!" << endl;
}

// Сортировать по дате 
bool comp_year (const Order& a, const Order& b) {
	return (a.date.year < b.date.year);
}

bool comp_month (const Order& a, const Order& b) {
	return (a.date.month < b.date.month);
}

bool comp_day (const Order& a, const Order& b) {
	return (a.date.day < b.date.day);
}

void sort(vOrders &v){

	sort(v.begin(), v.end(), comp_year);
	sort(v.begin(), v.end(), comp_month);
	sort(v.begin(), v.end(), comp_day);
	cout << endl;
}

// Выдать свод по каждому Продавцу (по убыванию общей суммы)
bool comp_sum (const Saler& a, const Saler& b) { return (a.sum > b.sum); }

void print_salers(vOrders v) {
    vector <Saler> salers;
    for (size_t i = 0; i < v.size(); i++) {
        size_t j;
        for (j = 0; j < salers.size() && salers[j].name != v[i].saler; j++)
            ;
        if (j < salers.size())
            salers[j].sum += v[i].cost;
        else {
            Saler s;
            s.name = v[i].saler;
            s.sum = v[i].cost;
            salers.push_back(s);
        }
    }
    sort(salers.begin(), salers.end(), comp_sum);
    for (size_t i = 0; i < salers.size(); i++)
        cout << salers[i].name << "\t" << salers[i].sum << endl;
    cin.get();
	cout << endl;
}

// Выдать общий список
void print_all(vOrders v){
    cout << "Номер\tПродавец\tПокупатель\tДата\t\tСумма\n";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i].order_id << "  \t" << v[i].saler << "  \t" << v[i].customer << "   \t" << v[i].date.year << "." << v[i].date.month << "." << v[i].date.day << "  \t" << v[i].cost << endl;

    cout << endl;
}
