#include <iostream>

using namespace std;

int main (){
	int x, y, i, pen; //описаваем нужные переменные
	x=0; //стартовое значение переменной
	y=64; //определяем пенсионный возраст

	do{
		cout<<"How old are you? \n";
		cin>>i;
		pen=y-i;
		cout<<"Remained until retirement (years) = "<<pen<<endl;
		x++; //изменение параметра цикла (аналогично x=x+1)
	}while (x<=-1); //условие ложно, но цикл выполняется 1 раз

	return 0;
}
