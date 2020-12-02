/**String29°. Дан символ C и строки S, S0. Перед каждым вхождением символа C в строку S вставить строку S0.*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	char c;
	string s;
	string s0;
	string s2;
	unsigned short len_s;

	cout << "Enter s: ";
	getline(cin, s);
	cout << "Enter s0 ";
	getline(cin, s0);
	cout << "Enter c: ";
        c = getchar();


	len_s = s.size();
	for (int i = 0; i < len_s; ++i){
		if (s[i] == c)
			s2 += s0;
		s2 += s[i];
	}
	
	cout << s2 << endl;

	return 0;
}
