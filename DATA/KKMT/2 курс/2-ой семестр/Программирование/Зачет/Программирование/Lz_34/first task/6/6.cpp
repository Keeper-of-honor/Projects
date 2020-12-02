/**
 6. С клавиатуры ввести значение вещественной переменной. Объявить ссылку на эту переменную. Вывести на экран объем памяти, занимаемый переменной и ссылкой. Объяснить полученные результаты.
*/
// Выполнил: Герасимов Д.А., П1-18
 
#include <iostream>
using namespace std;

int main(){
	double n;
	cout << "Enter n: ";
	cin >> a;

	cout << "Variable: " << sizeof(n) << " byte" << endl
		<< "Link: " << sizeof(&n) << " byte" << endl;

    return 0;
}
