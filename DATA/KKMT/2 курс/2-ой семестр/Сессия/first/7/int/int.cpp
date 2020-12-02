#include <iostream>

using namespace std;

int summ(int a, int b);

int main (){
	int a = 5;
	int b = 2;
	int sum;

	sum = summ(a, b);

	cout << sum << endl;

	return 0;
}

int summ(int a, int b){
	return a + b;
}
