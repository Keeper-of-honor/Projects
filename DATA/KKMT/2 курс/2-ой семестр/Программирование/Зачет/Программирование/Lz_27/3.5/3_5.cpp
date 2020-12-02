/**
Напишите программу, читающий со стандратного устройства ввода целые строки. Измените программу так, чтобы она читала отдельные слова.
Выполнил: Герасимов Дмитрий Александрович П1-18
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	string s;
	string word;
	char c;

	while (cin >> word)
		cout << word << endl;

	cout << endl;
	/*while (cin >> word){
		s += word + ' ';
		while ((c = getchar()) == ' ' || c == '\t' );
		if (c == '\n')
			break;
		else
			s += c;
	}

	cout << s << endl;*/
	
	return 0;
}

/**
Input:
Привет, Андрей!

Output:
Привет,
Андрей!

*/
