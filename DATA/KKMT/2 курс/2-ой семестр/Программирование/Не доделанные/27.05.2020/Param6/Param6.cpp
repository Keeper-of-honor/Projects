/**
Param6. Описать процедуру Smooth2(A, N), выполняющую сглаживание вещественного массива A размера N следующим образом: элемент A1 не изменяется, элемент AK (K = 2, …, N) заменяется на полусумму исходных элементов AK−1 и AK. Массив A является входным и выходным параметром. С помощью этой процедуры выполнить пятикратное сглаживание данного массива A размера N, выводя результаты каждого сглаживания.
 */

#include <iostream>

using namespace std;

void DigitCountSum(int k, int *count, int *summ);

int main(){
	int k, count, summ;	
	int all_count = 0, all_summ = 0;

	cout << "Input 5 time k:" << endl;
	for (size_t i = 0; i != 5; ++i){
		cin >> k;
		if (k >= 0){
			DigitCountSum(k, &count, &summ);
			cout << "Sum = " << summ << endl
				<< "Count = " << count << endl;
			all_count += count;
			all_summ += summ;
		}
		else{
			cout << "Error. Digit k < 0" << endl;
			--i;
		}
	}
	cout << endl
		<< "All count = " << all_count << endl
		<< "All sum = " << all_summ << endl;

	return 0;
}

void DigitCountSum(int k, int *count, int *summ){
	*count = 0;
	*summ = 0;
	while(k){
		*count = *count + 1;
		*summ += (k % 10);
		k /= 10;
	}
}
