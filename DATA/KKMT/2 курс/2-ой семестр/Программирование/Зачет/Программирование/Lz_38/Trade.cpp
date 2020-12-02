/** Лабораторное занятие 38. Создание многофайлового проекта.
Команда состоит из 4-х человек: Груздев Роман, Герасимов Дмитрий, Батраков Данила, Слепов Андрей.
П1-18, 26.05.2020 г.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "func.h"

using namespace std;

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

int main() {
    
    vOrders v;
    string fname, fname_o;
    int choice = -1;
    while (choice != 0) {
        menu();
	cout << endl << "Введите пункт меню: ";
        cin >> choice;
	cout << endl;
        switch (choice) {
        case 0:
            // 0. Выход
	    cout << "До скорых встреч!	:)" << endl;
            break;
        case 1:
            // 1. Загрузить из файла
	    cout << "Введите название файла(без .txt): ";
	    cin >> fname;
	    fname += ".txt";     	
            load(&v, fname);
            break;
        case 2:
            // 2. Выгрузить в файл
	    cout << "Введите название файла(без .txt) в которой будет выгружен вектор: ";
	    cin >> fname_o;
	    fname_o += ".txt";
            save(v, fname_o);
            break;
        case 3:
            // 3. Добавить новый заказ
	    cout << "Добавьте новый заказ(пример: Номер\\Продавец\\Покупатель\\Дата(дд.мм.гггг)\\сумма):" << endl;
            append(&v);
            break;
        case 4:
            // 4. Редактировать сумму заказа
	    cout << "В каком заказе хочется поменять сумму? - ";
	    size_t ix;
	    cin >> ix;
            edit(v, ix);
            break;
        case 5:
            // 5. Удалить заказ
	    cout << "Какой заказ хотелось бы удалить? - ";
	    size_t idx;
	    cin >> idx;
            del(&v, idx);
            break;
        case 6:
            // 6. Сортировать по дате
	    cout << "Сортировка была произведена!" << endl;
            sort(v);
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
