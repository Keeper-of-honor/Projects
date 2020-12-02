/**
 Proc6. Описать процедуру DigitCountSum(K, C, S), находящую количество C цифр целого положительного числа K, а также их сумму S (K — входной, C и S — выходные параметры целого типа). С помощью этой процедуры найти количество и сумму цифр для каждого из пяти данных целых чисел.
 */
/// Выполнил: Герасимов Д.А., П1-18

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
