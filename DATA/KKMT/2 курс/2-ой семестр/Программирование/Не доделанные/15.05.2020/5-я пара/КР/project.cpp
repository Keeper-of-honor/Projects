#include <iostream>
#include <vector>
#include <string>

#include "upload_memory.h"
#include "add_entry_to_vector.h"
#include "swap_str.h"
#include "del_str.h"
#include "upload_file.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 1;
	vector <string> svec;
	vector <string> data_file;
	
	///Функции
	while (n != 0){
		cout << endl 
			<<"----------------------------------------------------------" << endl
			<< "\tMenu" << endl
			<< "1. Загрузить файл в память" << endl
			<< "2. Добавить запись из файла в массив (вектор)" << endl
			<< "3. Заменить строку с номером N" << endl
			<< "4. Удалить строку с номером N" << endl
			<< "5. Выгрузить строки из памяти в файл" << endl
			<< "6. Отпечатать суммарные ежемесячные и годовую продажи" << endl
			<< "0. Выйти" << endl
			<< "-------------------------------------------------------" << endl
			<< endl;
		cin >> n;

		if (n == 1)
			data_file = uploadMemory();
		else if (n == 2)
			addEntryToVector(&svec, &data_file);
		else if (n == 3)
			swapStr(&svec);
		else if (n == 4)
			delStr(&svec);
		else if (n == 5)
			uploadFile(svec);
		else if (n == 6){}
		else if (n != 0)
			cout << "Error. Диапазон чисел [0,6]";
		
	}

	cout << "В векторе:" << endl;
	size_t bruh = svec.size();
	for (size_t i = 0; i != bruh; ++i)
		cout << svec[i] << endl;

	return 0;
}
