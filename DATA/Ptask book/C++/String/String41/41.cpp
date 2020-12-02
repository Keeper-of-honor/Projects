/**String41°. Дана строка, состоящая из русских слов, разделенных пробелами (одним или несколькими). Найти количество слов в строке.*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	unsigned short count;
	unsigned short len_s;
	
	cout << "Enter string s: ";
	getline(cin, s);

	count = 0;
	s += ' ';
	len_s = s.size();
	for (int i = 1; i < len_s; ++i)
		if (s[i] == ' ' && s[i-1] != ' ')
			++count;

	cout << "Number of word: "  << count << endl;

	return 0;
}
