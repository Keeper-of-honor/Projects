/**
Proc24. Описать функцию Even(K) логического типа, возвращающую True, если целый параметр K является четным, и False в противном случае. С ее помощью найти количество четных чисел в наборе из 10 целых чисел.
 */
/// Выполнил: Герасимов Д.А., П1-18

#include <iostream>

using namespace std;

bool Even(int k);

int main(){
	const int N = 10;
	
	int count = 0;
	int k;
	
	for (size_t i = 0; i != N; ++i){
		cout << i+1 << ". "<<"Input K: ";
		cin >> k;
		if (Even(k)){
			cout << "True" << endl;
			++count;
		}
		else
			cout << "False" << endl;
	}

	cout << "Number of even digitals: " << count << endl;

	return 0;
}

bool Even(int k){
	return (k % 2 == 0 ? 1 : 0);
}
