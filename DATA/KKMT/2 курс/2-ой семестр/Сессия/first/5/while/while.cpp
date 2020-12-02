#include <iostream>

using namespace std;

int main (){
	int x, y, i, pen; //описаваем нужные переменные
	x=0; //стартовое значение переменной
	y=64; //определяем пенсионный возраст

	while (x<=3){ //пока параметр цикла не превышает конечное значение.
		cout<<"How old are you? \n";
		cin>>i;
		pen=y-i;
		cout<<"Remained until retirement (years) = "<<pen<<endl;
		x++; //изменение параметра цикла (аналогично x=x+1 (расмотрим в последующих уроках))
	}

	return 0;
}
