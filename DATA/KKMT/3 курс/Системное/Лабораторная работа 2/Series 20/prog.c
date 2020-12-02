/**
Series20. Дано целое число N (> 1) и набор из N целых чисел. Вывести те элементы в наборе, которые меньше своего правого соседа, и количество K таких элементов.

Дата: 29.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>

int main(){
	int n;
	printf("Input N: ");
	scanf("%d", &n);

	printf("Input a set of N numbers: ");
	int num1, num2;
	scanf("%d", &num1);
	for (int i = 1; i != n; ++i){
		scanf("%d", &num2);
		if (num1 < num2)
			printf("%d ", num1);
		num1 = num2;
	}
	printf("\n");

	return 0;
}
