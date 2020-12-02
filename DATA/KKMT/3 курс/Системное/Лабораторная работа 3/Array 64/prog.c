/**
Array64. Даны три целочисленных массива A, B и C размера NA, NB, NC соответственно, элементы которых упорядочены по убыванию. Объединить эти массивы так, чтобы результирующий целочисленный массив D (размера NA + NB + NC) остался упорядоченным по убыванию.

Дата: 28.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>
#include <stdlib.h>

void scanfArray(int mas[], int n);
void sort(int mas[], int n);
void swap(int *a, int *b);
void printArray(int mas[], int n);

int main(){
	
	int n1, n2, n3;
	printf("Введите колличество элементов массивов: ");
	scanf("%d%d%d", &n1, &n2, &n3);
	int *mas1 = (int*) malloc(sizeof(int) * n1);
	int *mas2 = (int*) malloc(sizeof(int) * n2);
	int *mas3 = (int*) malloc(sizeof(int) * n3);
	printf("1)");
	scanfArray(mas1, n1);
	printf("2)");
	scanfArray(mas2, n2);
	printf("3)");
	scanfArray(mas3, n3);
	
	int n4 = n1 + n2 + n3;
	int *mas4 = (int*) malloc(sizeof(int) * n4);
	for (int i = 0; i != n1; ++i)
		mas4[i] = mas1[i];
	int n1_n2 = n1 + n2;
	for (int i = n1; i != n1_n2; ++i)
		mas4[i] = mas2[i - n1];
	for (int i = n1_n2; i != n4; ++i)
		mas4[i] = mas3[i - n1_n2];
	printArray(mas4, n4);
	sort(mas4, n4);
	printArray(mas4, n4);
	
	free(mas1);
	free(mas2);
	free(mas3);
	
	return 0;
}

void scanfArray(int mas[], int n){
	printf("Введите массив: ");
	for (int i = 0; i != n; ++i)
		scanf("%d", &mas[i]);
}

void sort(int mas[], int n){
    int loc_n = n - 1;
    for (int i = 0; i != loc_n; ++i)
        for (int j = 0; j != loc_n - i; ++j)
            if (mas[j] > mas[j + 1])
                swap(&mas[j], &mas[j+1]);
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int mas[], int n){
    for(int i = 0; i != n; ++i)
        printf("%d ", mas[i]);
    printf("\n");
}
