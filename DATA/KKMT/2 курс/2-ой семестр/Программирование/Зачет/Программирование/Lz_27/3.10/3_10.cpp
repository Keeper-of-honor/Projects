/**
Напишите программу, поиска в строке занков пунктуации. Программа должна позволить ввести символьную строку, содержащую знаки пунктуации, и вывести ту же строку, но уже без знаков пунктуации.
Выполнил: Герасимов Дмитрий Александрович П1-18
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
	string s;
	unsigned int len_s;
	
	getline(cin, s);
	len_s = s.size();
	for (unsigned int i = 0; i < len_s; ++i)
		if (ispunct(s[i]))
			s[i] = ' ';

	cout << s << endl;

	return 0;
}

/**
Input:
Привет, Андрей!

Output:
Привет  Андрей

*/
