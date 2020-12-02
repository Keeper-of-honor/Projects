/*
Series6. Дано целое число N и набор из N положительных вещественных чисел. Вывести в том же порядке дробные части всех чисел из данного набора (как вещественные числа с нулевой целой частью), а также произведение всех дробных частей.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	cout << "Input N: ";
	unsigned int n;
	cin >> n;

	if (n > 0){
		cout << "Input set N:" << endl;
		vector <double> vdob;
		double v = 0.0; //  Переменная для ввода элементов
		double remainder = 0.0; // Дробная часть
		double times = 1.0; // Перемножение дробных частей
		for (size_t i = 0; i != n; ++i){
			cin >> v;
			remainder = v - (int)v;
			vdob.push_back(remainder);
			times *= remainder;
		}

		cout << endl;
		cout << "Fractional parts:" << endl;
		for (size_t i = 0; i != n; ++i)
			cout << vdob[i] << ' ';
		cout << endl
			<< "Times fractional parts: " << times << endl;
	}
	else
		cout << "Error" << endl;

	return 0;
}
