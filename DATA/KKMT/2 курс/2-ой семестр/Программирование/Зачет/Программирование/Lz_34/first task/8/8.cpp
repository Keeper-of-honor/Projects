/**
 8. Ввести с клавиатуры значения переменных a и b. Поменять значения переменных местами, используя ссылки.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
using namespace std;

int main(){
	int a, b;
	cout << "a and b: "	
	cin >> a >> b;
	
	int &ra = a, &rb = b;
	int temp;
	temp = ra;
	ra = rb;
	rb = temp;
	
	cout << endl
		<< "Has become" << endl
		<< "a = " << a << endl
		<< "b = " << b << endl;

	return 0;
}
