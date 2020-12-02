/**
Array49. Дан целочисленный массив размера N. Если он является перестановкой, т. е. содержит все числа от 1 до N, то вывести 0; в противном случае вывести номер первого недопустимого элемента.

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
	
	//Input mas
	for (int i = 0; i != n; ++i)
		scanf("%d", &mas[i]);
	
	int num = 0;	//число для вывода
	for (int i = 0; i != n; ++i)
		if (mas[i] != i+1){
			num = i;
			break;
		}
	
	printf("%d\n", num);
	
	free(mas);

	return 0;
}
