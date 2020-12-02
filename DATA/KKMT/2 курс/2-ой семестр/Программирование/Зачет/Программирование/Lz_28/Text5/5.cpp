/**Text5. Дана строка S и текстовый файл. Добавить строку S в конец файла.*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ofstream file("text.txt", ios::app);

	string s;

	/*while (getline(file, s))
		file << s << endl;*/
	getline(cin, s);
	file << s << endl;

	file.close();
	return 0;
}
