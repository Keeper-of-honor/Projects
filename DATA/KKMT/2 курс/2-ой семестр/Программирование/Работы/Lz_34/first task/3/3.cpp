/**
 3. С клавиатуры ввести значение целочисленной переменной. Записать адрес этой переменной в указатель и вывести его значение на экран. Увеличить значение указателя на 5. Вывести новое значение на экран. Сравнить его с предыдущим значением.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
using namespace std;

int main(){
	int a;
    	cout << "Enter a: ";
	cin >> a;
	
	int *pa = &a;

	cout << "Pointer to a (*pa): " << *pa << endl 
		<< "Pointer to a + 5 (*pa + 5): " << *pa + 5 << endl
		<< "Adress of pointer to a (pa): " << pa << endl
		<< "Adress of pointer to a + 5 (pa + 5): " << pa + 5 << endl;

    return 0;
}
