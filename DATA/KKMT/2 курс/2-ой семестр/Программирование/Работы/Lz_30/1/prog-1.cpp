/**Задание 1.
Реализовать на языке C++ программу для демонстрации работы функции бинарного поиска binSearch [1]*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned int Type;

int main(){
	vector <Type> mas;
	Type n;
	Type digit;
	Type left, right, middle;
	Type unknown;

	cout << "Введите кол-во элементов в массиве: ";
	cin >> n;
	cout << "Введите целочисленный массив: ";
	for (Type i = 0; i < n; ++i){
		cin >>  digit;
		mas.push_back(digit);
	}
	
	cout << "Введите искомое число: ";
	cin >> unknown;
	left = -1;
	right = n - 1;
	
	while (right - left > 1){
	///for (unsigned short i = 0; i < log2(n) + 1; ++i){
		middle = (right + left) / 2;
		if (mas[middle] >= unknown)
			right = middle;
		else
			left = middle;
	}
	if (mas[right] == unknown)
		cout << "Ваше число попавсь. Его позиция в списке: " << right + 1 << endl;
	else
		cout << "Ваше число не попавсь. Т.к его нет в данном списке" << endl;

	return 0;
}
