#include <iostream>

using namespace std;

int main(){
	int i; //определяем переменную
	int sum = 0;
	for (i=1; i<=500; i=i+1) // задаем начальное значение, конечное 500, шаг цикла
		sum = sum + i;

	cout << "The sum of the numbers from 1 to 500 = " <<sum<<endl;

	return 0;
}
