#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void addEntryToVector(vector <string> *svec, vector <string> *data_file){
	setlocale(LC_ALL, "Russian");
	if (data_file->empty())
		cout << "Error. Вы не выполнили запись в файл. Чтобы выполнить запись в файл нажмите 1" << endl;
	else{
		vector <string> text = *data_file;
		int size_text = text.size();

		int n = 1;
		vector <string> loc_svec;

		while (n != 0){
			///Меню
			cout << endl 
				<< "1. Ввести все данные" << endl
				<< "2. Ввести номер строки." << endl
				<< "3. Ввести диапазон строк." << endl
				<< "4. Записанные данные." << endl
				<< "5. Удалить записанные данные." << endl
				<< "0. Выход." << endl
				<< endl;
			cin >> n;
			///1. Ввести все данные
			if (n == 1){
				for (int i = 0; i != size_text; ++i){
					cout << text[i] << endl;
					loc_svec.push_back(text[i]);
				}
			}
			///2. Ввести номер строки.
			else if (n == 2){
				cout << "Введите номер строки: ";
				int number_str = 0;
				cin >> number_str;
				cout << "Вы записали:" << endl;
				if (number_str >= size_text)
					cout << "Error. Количество строк в файле: " << size_text << endl;
				else{
					loc_svec.push_back(text[number_str-1]);
					cout << text[number_str-1] << endl;
				}
			}

			///3. Ввести диапазон строк.
			else if (n == 3){
				cout << "Введите диапазон строк (Пример: 2 6): ";
				int start_str = 0;
				int end_str = 0;
				cin >> start_str;
				cin >> end_str;
				cout << "Вы записали:" << endl;
				if (end_str >= size_text)
					cout << "Error. Количество строк в файле: " << size_text << endl;
				else
					for (int i = start_str - 1; i != end_str; ++i){
						cout << text[i] << endl;
						loc_svec.push_back(text[i]);
					}
			}

			///4. Записанные данные.
			else if (n == 4){
				if (!loc_svec.empty()){
					size_t size_loc_svec = loc_svec.size();
					cout << "Записанные данные:" << endl;
					for (size_t i = 0; i != size_loc_svec; ++i)
						cout << loc_svec[i] << endl;
				}
				else
					cout << "Error. Вы ещё ничего не записали" << endl;
			}

			///5. Удалить записанные данные.
			else if (n == 5){
				if (!loc_svec.empty())
					loc_svec.clear();
				else
					cout << "Error. Вы ещё ничего не записали" << endl;
			}

			///Проверка
			else if (n != 0)
				cout << "Error. Диапазон чисел в меню [0,5]";
		}

		if (!loc_svec.empty()){
			svec->reserve(svec->size() + loc_svec.size());
			svec->insert(svec->end(), loc_svec.begin(), loc_svec.end());
		}
	}
}
