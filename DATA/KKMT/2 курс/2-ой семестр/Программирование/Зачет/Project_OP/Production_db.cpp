/** Команда состоит из 3-х человек: Груздев Роман, Герасимов Дмитрий, Пётр Митюшин.
П1-18, 05.06.2020 г.
*/
#include <iostream>
#include <vector>
#include "func.h"

using namespace std;

// Меню
void menu() {
	cout << "0. Выход" << endl
		<< "1. Загрузить из файла" << endl
		<< "2. Выгрузить в файл" << endl
    		<< "3. Добавить новое наименование" << endl
    		<< "4. Редактировать наименование" << endl
    		<< "5. Удалить наименование" << endl
    		<< "6. Сортировать по дате прозводства" << endl
		<< "7. Выдать общий список наименований" << endl
		<< "8. Выдать максимум или минимум(по количеству или стоимости)" << endl;
}

int main() {
    
    vNom v;
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
            	load(v); 
            break;
        case 2:
            // 2. Выгрузить в файл
            save(v);
            break;
        case 3:
            // 3. Добавить новую строку (наименование)
            append(v);
            break;
        case 4:
            // 4. Редактировать строку (наименование)
	  
            edit(v);
            break;
        case 5:
            // 5. Удалить строку (наименование)
            del(v);
            break;
        case 6:
            // 6. Сортировать по дате производства
            sort(v);
            break;
        case 7:
            // 7. Выдать общий список
            print_all(v);
            break;
	case 8:
	    // 8. Выдать максимум и минимум по количеству или стоимости
            maxxMinn(v);
            break;
        default:
            cout << "Неверный ввод. От 0 до 8" << endl;
            break;
        }
    }

    return 0;
}
