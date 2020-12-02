#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

void delStr(std::vector <std::string> *svec){
	setlocale(LC_ALL, "Russian");
	int a = 1;		///Число для меню
	int pos = 0;		///Позиция строки которую хочет изменить пользователь
	vector <string> loc_svec;		///Вектор для временного хранения данных svec
	size_t size_svec = svec->size();	///Размер вектора svec
	while (a != 0){
		cout << endl
			<< "1. Удалить строку в векторе" << endl
			<< "2. Удалить строку в файле" << endl
			<< "0. Выход" << endl
			<< endl;
		cin >> a;
		int n1 = 1;	///Число 1-ое для подменю
		int n2 = 1;	///Число 2-ое для подменю
		if (a == 1)
			if (svec->empty())
				cout << "Error. Ваш вектор пустой. Чтобы добавить данные в вектор зайдите в главное меню (нажмите 0, затем 1)" << endl;
			else{
				while (n1 != 0){
					///Меню
					cout << endl
						<< "1. Удалить строку" << endl
						<< "2. Сохранить" << endl
						<< "0. Выход" << endl
						<< endl;
						cin >> n1;
					if (n1 == 1){
						///Добавим в loc_svec, svec
						loc_svec.reserve(svec->size() + loc_svec.size());
						loc_svec.insert(loc_svec.end(), svec->begin(), svec->end());

						cout << "Введите номер строки которую хотели бы удалить: ";
						cin >> pos;
						loc_svec.erase(loc_svec.begin() + (pos-1));

						cout << "Данные в вектре (не сохранены):" << endl;
						for (size_t i = 0; i != size_svec; ++i)
							cout << loc_svec[i] << endl;	
					}
					else if (n1 == 2){
						cout << "Успешно сохраннено. Теперь данные в векторе:" << endl;
						svec->clear();
						svec->reserve(svec->size() + loc_svec.size());
						svec->insert(svec->end(), loc_svec.begin(), loc_svec.end());
						for (size_t i = 0; i != size_svec; ++i)
							cout << loc_svec[i] << endl;
					}
					else if (n1 != 0)
						cout << "Error диапазон чисел в меню [0,2]";
				}
			}
		else if (a == 2){
			cout << "Введите имя файла и его разрешение (Пример: text.txt), в котором собираетесь удалять данные: ";
			string name_f;
			cin >> name_f;
			ifstream file (name_f);
			vector <string> text;
			string str;
			cout << "Данные файла:" << endl; 
			while (!file.eof()){
				getline(file, str);
				cout << str << endl;
				text.push_back(str);
			}
			size_t size_text = text.size();
			file.close();

			if (size_text == 0)
				cout << "Error. Файл не содержит данных." << endl;

			while (n2 != 0){
				///Меню
				cout << endl
					<< "1. Удалить строку из файла" << endl
					<< "2. Сохранить" << endl
					<< "0. Выход" << endl
					<< endl;
					cin >> n2;
					if (n2 == 1){
						cout << "Введите номер строки которую хотели бы удалить: ";
						cin >> pos;
						text.erase(text.begin() + (pos-1));

						cout << "Данные в файле (не сохранены):" << endl;
						for (size_t i = 0; i != size_text; ++i)
							cout << text[i] << endl;
							
					}
					else if (n2 == 2){
						remove(name_f.c_str());
						ofstream file (name_f);
						cout << "Теперь данные файла:" << endl;
						for (size_t i = 0; i != size_text; ++i){
							file << text[i] << endl;
							cout << text[i] << endl;
						}
						file.close();
					}
					else if (n2 != 0)
						cout << "Error. Диапазон чисел в меню [0,2]";
		
			}
		}
		else if (a != 0)
			cout << "Error. Диапазон чисел меню [0,2]" << endl;
	}
}
