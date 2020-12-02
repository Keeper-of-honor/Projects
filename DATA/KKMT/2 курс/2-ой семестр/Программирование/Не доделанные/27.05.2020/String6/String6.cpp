/**
String6. Дан символ C, изображающий цифру или букву (латинскую или русскую). Если C изображает цифру, то вывести строку «digit», если латинскую букву — вывести строку «lat», если русскую — вывести строку «rus».
 */

#include <iostream>

using namespace std;

int main(){

	cout << "Input char C: ";
	char c;
	cin.get(c);
	
	if (c >= '0' && c <= '9')
		cout << "digit" << endl;
	else if (c >= 'a' && c <= 'z')
		cout << "lat" << endl;
	else
		cout << "Error" << endl;
		

	return 0;
}
