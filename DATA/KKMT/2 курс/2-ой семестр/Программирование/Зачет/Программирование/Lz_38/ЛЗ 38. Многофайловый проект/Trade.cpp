// Гусятинер Л.Б., МГОТУ ККМТ, 09.05.2020
// Заготовка ("рыба") для развёртывания многофайлового проекта в грурппе

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

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
    string name;
    double sum;
};

typedef std::vector <Order> vOrders;

// Меню
void menu() {
    cout << "0. Выход\n";
    cout << "1. Загрузить из файла\n";
    cout << "2. Выгрузить в файл\n";
    cout << "3. Добавить новый заказ\n";
    cout << "4. Редактировать сумму заказа\n";
    cout << "5. Удалить заказ\n";
    cout << "6. Сортировать по дате\n";
    cout << "7. Выдать свод по каждому Продавцу (по убыванию общей суммы)\n";
    cout << "8. Выдать общий список\n";
}

// Редактировать сумму заказа
void edit(vOrders &v, int orderid, Date new_date) {
}

// Загрузить из файла
void load(std::vector<Order> & v, string fname) {
    Order order;
    ifstream in("orders.txt");

    char delim;
    v.clear();
    while (in >> order.order_id >> order.saler >> order.customer >>
        order.date.year >> delim >> order.date.month >> delim >> order.date.day >> delim >> order.cost)
    {
        v.push_back(order);
    }
}

// Выгрузить в файл
void save(vOrders v, std::ofstream out) {
}

// Добавить новый заказ
void append() {
}

// Удалить заказ
void del() {
}

// Компаратор для сортировки по убыванию суммы
bool comp_sum (const Saler& a, const Saler& b) { return (a.sum > b.sum); }

// Сортировать по дате
void vsort() {
}

// Выдать свод по каждому Продавцу (по убыванию общей суммы)
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
}

// Выдать общий список
void print_all(vOrders v) {
    cout << "Номер\tПродавец\tПокупатель\tДата\tСумма\n";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i].order_id << "\t" << v[i].saler << "\t" << v[i].customer << endl;
}

int main() {
    system("chcp 1251>nul");
    vOrders v;
    string fname = "orders.txt";
    int choice = -1;
    while (choice != 0) {
        menu();
        cin >> choice;
        switch (choice) {
        case 0:
            // 0. Выход
            break;
        case 1:
            // 1. Загрузить из файла
            load(v, fname);
            break;
        case 2:
            // 2. Выгрузить в файл
            // save();
            break;
        case 3:
            // 3. Добавить новый заказ
            append();
            break;
        case 4:
            // 4. Редактировать сумму заказа
            // edit();
            break;
        case 5:
            // 5. Удалить заказ
            del();
            break;
        case 6:
            // 6. Сортировать по дате
            vsort();
            break;
        case 7:
            // 7. Выдать свод по каждому Продавцу (по убыванию общей суммы)
            print_salers(v);
            break;
        case 8:
            // 8. Выдать общий список
            print_all(v);
            break;
        default:
            cout << "Неверный ввод. От 0 до 8" << endl;
            break;
        }
    }

    return 0;
}
