//2. Разработать АТД "Дек"
//Выполнил: Герасимов Д.А. П1-18. 23.06.2020
#include <iostream>
#include "func.h"

using namespace std;

const int N = 5; //размер дека

struct Deque{
    int data[N]; //массив данных
    int last; //указатель на конец
};

int main(){
	setlocale(LC_ALL,"Rus");
	Deque D;
	Creation(D);
	char number;
	do{
		cout << "1. Добавить элемент в начало" << endl
				<< "2. Добавить элемент в конец" << endl
				<< "3. Удалить первый элемент" << endl
				<< "4. Удалить последний элемент" << endl
				<< "5. Вывести первый элемент" << endl
				<< "6. Вывести последний элемент" << endl
				<< "7. Узнать размер дека" << endl
				<< "0. Выйти" << endl
				<< endl;

		cout << "Номер команды > ";
		cin >> number;
		switch (number){
			case '1':
				AddL(D);
				break;
			case '2':
				AddR(D);
				break;
			case '3':
				if (Full(D))
					cout << endl 
						<< "Дек пуст" << endl
						<< endl;
				else{
					DeleteL(D);
					cout << endl << "Элемент удален из дека" << endl 
							<< endl;
				}
				break;
			case '4':
				if (Full(D))
					cout << endl
							<< "Дек пуст" << endl 
							<< endl;
				else{
					DeleteR(D);
					cout << endl 
						<< "Элемент удален" << endl
						<< endl;
				}
				break;
			case '5':
				if (Full(D))
					cout << endl
						<< "Дек пуст" << endl
						<< endl;
				else
					cout << endl 
						<< "Первый элемент: "<< OutputL(D) << endl
						<< endl;
				break;
			case '6':
				if (Full(D))
					cout << endl
							<< "Дек пуст" << endl
							<< endl;
				else
					cout << endl 
						<< "Последний элемент: " << OutputR(D) << endl 
						<< endl;
				break;
			case '7':
				if (Full(D))
					cout << endl
						<< "Дек пуст" << endl
						<< endl;
				else
					cout << endl 
						<< "Размер дека: "<< Size(D) << endl
						<< endl;
				break;
			case '0':
				break;
			default:
				cout << endl
						<< "Команда не определена" << endl
						<< endl;
			break;
		}
	} while(number!='0');

	return 0;
}

