#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "func.h"

using namespace std;

void menu(){
	cout << endl 
			<<"----------------------------------------------------------" << endl
			<< "\tMenu" << endl
			<< "0. Выйти" << endl
			<< "1. Загрузить файл в вектор" << endl
			<< "2. Загрузить вектор в файл" << endl
			<< "3. Заменить строку с номером N" << endl
			<< "4. Удалить строку с номером N" << endl
			<< "5. Содержимое вектора" << endl
			<< "6. Отпечатать суммарные ежемесячные и годовую продажи" << endl
			<< "-------------------------------------------------------" << endl
			<< endl;
}

int main(){
	vPlist vec;
	setlocale(LC_ALL, "Russian");

	int n = -1;
	
	///Функции
	while (n != 0){
		menu();
		cout << "Вы выбрали: ";
		cin >> n;

		if (n == 1)
			load(vec);
		else if (n == 2)
			save(vec);
		else if (n == 3)
			swapStr(vec);
		else if (n == 4)
			delStr(vec);
		else if (n == 5)
			printVec(vec);
		else if (n == 6)
			report(vec);
		else if (n != 0)
			cout << "Error. Диапазон чисел [0,6]";
		
	}

	cout << "Да прибудет с тобой сила!" << endl;
	/*
	cout << "В векторе:" << endl;
	size_t bruh = svec.size();
	for (size_t i = 0; i != bruh; ++i)
		cout << svec[i] << endl;
	*/

	return 0;
}
