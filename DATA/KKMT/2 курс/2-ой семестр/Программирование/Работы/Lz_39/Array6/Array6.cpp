/**
Array6. Даны целые числа N (> 2), A и B. Сформировать и вывести целочисленный массив размера N, первый элемент которого равен A, второй равен B, а каждый последующий элемент равен сумме всех предыдущих.
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){

	cout << "Input n: ";
	size_t n;
	cin >> n;
	
	cout << "Input a and b: ";
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	vector <int> ivec = {a, b};
	for (size_t i = 2; i != n; ++i){
		sum *= 2;
		ivec.push_back(sum);
	}

	cout << "Sum: " << sum << endl;

	return 0;
}
