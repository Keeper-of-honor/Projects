/**
2. Ввести с клавиатуры значения переменных a и b. Поменять значения переменных местами, используя указатели.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
using namespace std;

int main(){
    int a, b;
        cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;

	///Variable for swap
    int *pa = &a, 
	*pb = &b,
	temp;
	///Swap
	temp = *pa;
	*pa = *pb;
	*pb = temp;

	cout << "a = " << a << endl
		<< "b = " << b << endl;
    return 0;
}
