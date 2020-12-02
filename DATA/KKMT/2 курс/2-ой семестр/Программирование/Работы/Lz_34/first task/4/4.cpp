/**
 4. С клавиатуры ввести значения двух вещественных переменных. Посчитать их сумму и разность, вывести результат на экран. Решить задачу, используя динамическую память.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream> 
using namespace std;

int main(){
	double a, b;
    	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;

	double *psum = new double, *pdiff = new double;
	double  *pa = &a, *pb = &b;
	*psum = *pa + *pb;
	*pdiff = *pa - *pb;

	cout << "Sum: " << *psum << endl;
	cout << "Diff: " << *pdiff << endl;

	delete psum;
	delete pdiff;

    return 0;
}
