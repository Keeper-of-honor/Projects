//2. Разработать АТД "Дек"
//Выполнил: Герасимов Д.А. П1-18. 23.06.2020

#include <iostream>

using namespace std;

const int N = 5; //размер дека

struct Deque{
    int data[N]; //массив данных
    int last; //указатель на конец
};

void Creation(Deque &D){ //создание дека
    D.last = 0;
}
bool Full(Deque &D){ //проверка дека на пустоту
	if (D.last)
		return false;
	else
		return true;
}
void AddL(Deque &D){ //добавление элемента в начало
	if (D.last == N){ 
		cout << endl
			<< "Дек заполнен" << endl
			<< endl;
		return;
	}
	int value;
	cout << endl
		<< "Значение > ";
	cin >> value;
	for (int i = D.last; i > 0; --i)
		D.data[i] = D.data[i-1];
	D.data[0] = value;
	++D.last;

	cout << endl
			<<"Элемент добавлен" << endl
			<< endl;
}
void AddR(Deque &D){ //добавление элемента в конец
	if (D.last == N){
		cout << endl
				<< "Дек заполнен" << endl
				<< endl;
		return;
	}
	int value;
	cout << endl
		<< "Значение > ";
	cin >> value;
	D.data[D.last++] = value;

	cout << endl
			<< "Элемент добавлен" << endl
			<< endl;
}
void DeleteL(Deque &D){ //удаление первого элемента
	for (int i = 1; i != D.last; ++i) //смещение элементов
		D.data[i - 1] = D.data[i];
	D.last--;
}
void DeleteR(Deque &D){ //удаление последнего элемента
	D.last--;
}
int OutputL(Deque &D){ //вывод первого элемента
	return D.data[0];
}
int OutputR(Deque &D){ //вывод последнего элемента
	return D.data[D.last-1];
}
int Size(Deque &D){ //размер дека
	return D.last;
}
