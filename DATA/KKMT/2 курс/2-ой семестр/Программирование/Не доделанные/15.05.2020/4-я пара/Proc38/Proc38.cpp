/**
Proc38. Описать функцию Power2(A, N) вещественного типа, находящую величину AN (A — вещественный, N — целый параметр) по следующим формулам:

A0 = 1;
AN = A·A·…·A    (N сомножителей),    если N > 0;
AN = 1/(A·A·…·A)    (|N| сомножителей),    если N < 0.

С помощью этой функции найти AK, AL, AM, если даны числа A, K, L, M.
*/
/// Выполнил: Герасимов Д.А., П1-18

#include <iostream>

using namespace std;

double Power2(double a, int k);

int main(){
	unsigned int num;
	double a;

	cout << "Input number powers: ";
	cin >> num;
	cout << "Input A: ";
	cin >> a;
	
	int k;
	for (size_t i = 0; i != num; ++i){
		cout << endl
			<< i+1 << ". "<<"Input power: ";
		cin >> k;
		cout << "Digit " << a << " with power " << k << " equals: " << Power2(a, k) << endl;
	}

	return 0;
}

double Power2(double a, int k){
	if (k > 0){
		double xz = a;
		for (int i = 1; i != k; ++i)
			xz *= a;
		return xz;
	}
	else if (k == 0)
		return 1;
	else{
		double xz = a;
		int loc_k = -1 * k;
		for (int i = 1; i != loc_k; ++i)
			xz *= a;
		return 1 / xz;
	}
}
