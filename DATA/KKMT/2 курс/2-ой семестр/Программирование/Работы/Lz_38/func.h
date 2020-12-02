/** Лабораторное занятие 38. Создание многофайлового проекта.
Команда состоит из 4-х человек: Груздев Роман, Герасимов Дмитрий, Батраков Данила, Слепов Андрей.
П1-18, 26.05.2020 г.
*/
#ifndef FUNC_H
#define FUNC_H

struct Date { // дата
    int year; // год
    int month; // месяц
    int day; // день
};

struct Order { // Заказ
    int order_id; // Номер заказа
    std::string saler; // Продавец
    std::string customer; // Заказчик
    Date date; // Дата заказа
    double cost; // Сумма заказа
};

struct Saler {
    std::string name;
    double sum;
};

typedef std::vector <Order> vOrders;


void load(vOrders *v, std::string fname); // Загрузка файла из фнейм

void save(vOrders &v, std::string fname_o); // Выгрузка файла в фнейм_о

void append(vOrders *v); // Добавление нового заказа в вектор

void edit(vOrders &v, size_t idx); // Редактирование суммы заказа

void del(vOrders *v, size_t idx); // Удаление заказа

void sort(vOrders &v); // Сортировка заказов по дате

void print_salers(vOrders v); // Свод по каждом продавцу(по убыв. общ. суммы)

void print_all(vOrders v); // Общ. список продавцов

#endif
