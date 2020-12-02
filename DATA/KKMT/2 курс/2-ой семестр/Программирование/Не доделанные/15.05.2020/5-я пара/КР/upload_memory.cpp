#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> uploadMemory(){
	cout << "Введите имя файла и его разрешение (Пример: text.txt) откуда собираетесь взять информацию: ";
	string name_f;
	cin >> name_f;
	ifstream file(name_f);
	vector <string> text;
	string str;
	cout << "Вы записали:" << endl; 
	while (!file.eof()){
		getline(file, str);
		cout << str << endl;
		text.push_back(str);
	}
	return text;
}
