/**Text2. Дано имя файла и целое число N (0 < N < 27). Создать текстовый файл с указанным именем и записать в него N строк: первая строка должна содержать строчную (т. е. маленькую) латинскую букву «a», вторая — буквы «ab», третья — буквы «abc» и т. д.; последняя строка должна содержать N начальных строчных латинских букв в алфавитном порядке.*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ofstream file("text.txt");

	string s;
	unsigned short n;

	cin >> n;
	
	if (n <= 26)
		for (unsigned short i = 0; i < n; ++i){
			s += 'a' + i;
			file << s << endl;
		}
	else
		cout << "Error: bruh\n";
	file.close();
	return 0;
}
