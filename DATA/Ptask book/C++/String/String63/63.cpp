/**String63°. Дана строка-предложение на русском языке и число K (0 < K < 10). Зашифровать строку, выполнив циклическую замену каждой буквы на букву того же регистра, расположенную в алфавите на K-й позиции после шифруемой буквы (например, для K = 2 «А» перейдет в «В», «а» — в «в», «Б» — в «Г», «я» — в «б» и т. д.). Букву «ё» в алфавите не учитывать, знаки препинания и пробелы не изменять.*/

#include <iostream>
#include <string>
/*#include <clocale>
#include <windows.h>

#undef min
#undef max*/

using namespace std;

int main(){
/*	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned short lang;
*/
	string s, s_new;
	int k;
	unsigned short len_s;

/*	cout << "rus - 0" << endl
	      << "eng - 1" << endl
	      << "Enter lang: ";
	cin >> lang;
	getchar();
*/
	cout << "Enter string: ";
	getline(cin, s);
	cout << "Enter digital: ";
	cin >> k;


	len_s = s.size();
/*	if (lang == '0'){
		for (int i = 0; i < len_s; ++i){
			if (s[i] >= '0' && s[i] <= '9');
			else if (s[i] >= 'а' && s[i] <= 'я')
				s_new += ((s[i] - 'а' + k) % 32 + 'a');
			else if (s[i] >= 'А' && s[i] <= 'Я')
				s_new += ((s[i] - 'А' + k) % 32 + 'А'); 
		}
	}
*/
//	else{
		for (int i = 0; i < len_s; ++i){
                        if (s[i] >= '0' && s[i] <= '9');
                        else if (s[i] >= 'a' && s[i] <= 'z')
                                s_new += ((s[i] - 'a' + k) % 26 + 'a'); 
                        else if (s[i] >= 'A' && s[i] <= 'Z')
                                s_new += ((s[i] - 'A' + k) % 32 + 'A');
                }

//	}

	cout << "String incognito: " << s_new << endl;

	return 0;
}
