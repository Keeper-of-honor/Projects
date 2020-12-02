/**Задание 2. Гусятинер Л.Б., (c) 17.04.2020
Вводятся границы интервала целых чисел, -100 <= a <= b <= 100.
Вводится вид операции: 1 - сложение, 2 - умножение.
Требуется найти сумму или произведение чисел на интервале.
Вывод должен выглядеть как в примере
Использовать switch-case.

Выполнил: Герасимов Дмитрий П1-18
*/

#include <iostream>
using namespace std;

void sum(int a, int b);
void multip(int a, int b);

int main(){
	int a,b;
	cin >> a >> b;
	char sign;
	cin >> sign;
	
	switch (sign){
		case '1':
			sum(a,b);break;
		case '2':
			multip(a,b);break;

	}
	cout << endl;

	return 0;
}

void sum(int a, int b){
	int all;
	all = 0;
	for (int i = a; i < b; ++i){
		if (i < 0)
			cout << '(' << i << ')' << '+';
		else
			cout << i << '+';
		all += i;
	}
	all += b;
	if (b < 0)
		cout << '(' << b << ')' << '=' << all;
	else
		cout << b << '=' << all << 'x';
}

void multip(int a, int b){
	int all;
	all = 1;
	if (a < 0){
		for (int i = a; i < b; ++i){
			if (i < 0)
        	                cout << '(' << i << ')' << '*';
                	else
                        	cout << i << '*';
		}
		all = 0;
	}
	else{
	        for (int i = a; i < b; ++i){
        	        if (i < 0)
                	        cout << '(' << i << ')' << '*';
	                else
        	                cout << i << '*';
	                all *= i;
		}
		all *= b;
        }
	if (b < 0)
		cout << '(' << b << ')' << '=' << all;
	else
		cout << b << '=' << all <<;
}


/*
Пример 1
Input
-5 2
1
Output
(-5)+(-4)+(-3)+(-2)+(-1)+0+1+2=-12

Пример 2
Input
-5 2
2
Output
(-5)*(-4)*(-3)*(-2)*(-1)*0*1*2=0 
 */
