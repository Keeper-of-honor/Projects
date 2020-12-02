/**
Minmax6°. Дано целое число N и набор из N целых чисел. Найти номера первого минимального и последнего максимального элемента из данного набора и вывести их в указанном порядке.
 */

#include <iostream>

using namespace std;

int main(){

	cout << "Input n: ";
	size_t n;
	cin >> n;
	
	int k;
	cin >> k;
	int imin = 0, imax = 0;
	int min = k, max = k;
	for (size_t i = 1; i != n; ++i){
		cin >> k;
		if (k > -1){
			if (k < min){
				min = k;
				imin = i;
			}
			if (k >= max){
				max = k;
				imax = i;
			}
		}
		else{
			cout << "Error. Digit k < 0" << endl;
			--i;
		}
	}

	cout << "Pos min: " << imin << endl
		<< "Pos last max: " << imax << endl;

	return 0;
}
