/**
Text44°. Дан текстовый файл, каждая строка которого изображает целое число, дополненное слева и справа несколькими пробелами. Вывести количество этих чисел и их сумму.
Выполнил: Герасимов Дмитрий П1-18
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream file("text.txt");
	
	int c;
	long n;
	char znak;
	char quantity;
	long sum;
	
	n = 0; znak = 0;
	quantity = 0; sum = 0;

	while((c = file.get()) != EOF){
		if (c >= '0' && c <= '9')	//Проверка на число
			n = n * 10 + c - '0';
		else if (c == '-')		//Отрицательное число
			znak = 1;

		else if (c == '\n' && n == 0)	//Стоит минус, а числа нет
			znak = 0;
		else if (c == '\n' && n != 0){	//Производим операции
			++quantity;
			if (znak == 1)
				n *= -1;
			sum += n;
			n = 0;
			znak = 0;
		}
	}

	cout << "Колличество чисел: \n" << quantity 
		<< "Сумма этих чисел: \n" << sum;
	
	file.close();

	return 0;
}
