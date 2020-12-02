/**String13. Дана строка. Подсчитать количество содержащихся в ней цифр.*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	unsigned short count;
	unsigned short len_s;
	string s;

	cout << "Enter string: ";
	getline(cin, s);

	count = 0;
	len_s = s.size();
	for (int i = 0; i != len_s; ++i)
		if (s[i] >= '0' && s[i] <= '9')
			++count;
	cout << "Number of digits in string: " << count << endl;

	return 0;
}
