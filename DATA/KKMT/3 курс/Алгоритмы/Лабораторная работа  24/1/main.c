/**
Условие:
	Дан список чисел. Определите, сколько в нем встречается различных чисел.

Выполнил: Герасимов Дмитрий П1-18 18.11.2020

*/

#include <stdio.h>
#define LEN 10000

#include "lot.h"

int main(){
	int mas[LEN];
	int len_mas = 0;
	int n = -1;

	for (int i = 0; scanf("%d", &n) != EOF; ++i)
		//Добавить элемент в множество
		lotAddI(mas, &len_mas, n);
	
	//Вывод множества
	printLotI(mas, len_mas);

	return 0;
}
