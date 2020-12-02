/**Text1°. Дано имя файла и целые положительные числа N и K. Создать текстовый файл с указанным именем и записать в него N строк, каждая из которых состоит из K символов «*» (звездочка).*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ofstream output("output.txt");

	unsigned short n,k;

	cin >> n >> k;
	
	string s(k, '*');
	for (unsigned short i = 0; i < n; ++i)
		output << s << endl;

	output.close();

	return 0;
}
