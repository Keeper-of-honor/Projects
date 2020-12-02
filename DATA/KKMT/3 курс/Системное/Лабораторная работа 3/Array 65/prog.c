/**
Array65. Дан массив A размера N и целое число K (1 ≤ K ≤ N). Преобразовать массив, увеличив каждый его элемент на исходное значение элемента AK.

Дата: 28.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>
#include <stdlib.h>

void scanfArray(int mas[], int n);

int main(){
	
	int n;
	printf("Input N (size array): ");
	scanf("%d", &n);
	int k;
	printf("Input K: ");
	scanf("%d", &k);
	int *mas = (int*) malloc(sizeof(int) * n);
	scanfArray(mas, n);
	
	if (k > n)
		printf("Error. K must be less than N");
	else
		for (int i = 0; i != n; ++i){
			mas[i] += mas[k];
			printf("%d ", mas[i]);
		}
	printf("\n");
	
	free(mas);
	
	return 0;
}

void scanfArray(int mas[], int n){
	printf("Input array: ");
	for (int i = 0; i != n; ++i)
		scanf("%d", &mas[i]);
}
