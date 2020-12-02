/**
While5. Дано целое число N (> 0), являющееся некоторой степенью числа 2: N = 2^K. Найти целое число K — показатель этой степени.

Дата: 29.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>

int logMc(int n, int base);

int main(){
	int n;
	printf("Input N: ");
	scanf("%d", &n);
	
	int k = logMc(n, 2);
	printf("k = %d\n", k);

	return 0;
}

int logMc(int n, int base){
	int count = 0;
	if (n != 1)
		for (int i = n; i != 1; i /= base)
			++count;
	return count;
}
