#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void uploadFile(vector <string> svec){
	cout << "Введите имя файла и его разрешение (Пример: text.txt): ";
	string name_f;
	cin >> name_f;
	ofstream file(name_f, ios::app);
	cout << "Вы записали в файл:" << endl; 
	size_t size_svec = svec.size();
	for (size_t i = 0; i != size_svec; ++i){
		cout << svec[i] << endl;
		file << svec[i] << endl;
	}
}
