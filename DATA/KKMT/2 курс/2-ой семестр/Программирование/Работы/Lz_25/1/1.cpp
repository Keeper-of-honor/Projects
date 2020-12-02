/**
Задание 1. Гусятинер Л.Б., (c) 17.04.2020
Палиндромом называется число, которое читается одинаково как слева направо, так и справа налево.
Например, 121, 5, 4774 - палиндромы, 122 - не является палиндромом.
Требуется вывести через запятую по 10 числе в строке все палиндромы в интервале от 1 до N, где 1 <= N < 1000.
Решение - 1 балл
За эффективность - бонус 1 балл.
Примечание. Решение считается эффективным, если экономит или память или процессорное время, или то и другое вместе.
В данной задаче решение может быть эффективным по времени

Выполнил: Герасимов Дмитрий Александрович
*/

#include <iostream>
using namespace std;

#define MAXN 400

int first(int n);
char is_palindrom(int n, int f);


int main(){
	int n;
	int mas[MAXN];
	int index;
	cin >> n;

	index = 0;
	for(int i = 1; i <= n; ++i){
		if(is_palindrom(i, first(i)) == '1'){
			mas[index] = i;
			++index;
		}
	}
	for (int i = 1; i < index; ++i){
		if (i % 10 == 0)
			cout << mas[i-1];
		else
			cout << mas[i-1] << ',';
		if (i % 10 == 0)
                        cout << endl;

	}
	cout << mas[index - 1] << endl;
	
	return 0;
}

int first(int n){
	while(n / 10)
		n /= 10;
	return n;

}

char is_palindrom(int n, int f){
	if(n % 10 == f)
		return '1';
	else
		return '0';
}

/**
Пример
Input
30
Output
1,2,3,4,5,6,7,8,9,11,
22
*/
