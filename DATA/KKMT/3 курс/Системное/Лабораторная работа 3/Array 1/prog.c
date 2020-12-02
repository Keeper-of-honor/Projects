/**
Array1. Дано целое число N (> 0). Сформировать и вывести целочисленный массив размера N,
содержащий N первых положительных нечетных чисел: 1, 3, 5, … .

Дата: 28.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int *mas = (int*) malloc(sizeof(int) * n);
	
	//Формирование массива
	int num = -1;
	for (int i = 0; i != n; ++i)
		mas[i] = (num += 2);
		
	//Вывод массива
	printf("mas: ");
	for (int i = 0; i != n; ++i)
		printf("%d ", mas[i]);
	printf("\n");
	free(mas);

	return 0;
}
