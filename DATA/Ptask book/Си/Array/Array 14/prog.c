/**
Array14. Дан массив A размера N. Вывести вначале его элементы с четными номерами (в порядке возрастания номеров), а затем — элементы с нечетными номерами (также в порядке возрастания номеров):

A2,    A4,    A6,    …,    A1,    A3,    A5,    … .

Условный оператор не использовать.

Дата: 28.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int *a = (int*) malloc(sizeof(int) * n);
	
	//Input mas
	for (int i = 0; i != n; ++i)
		scanf("%d", &a[i]);
		
	//Output even elements mas 
	//printf("Output even elements mas: ");
	for (int i = 0; i < n; i+=2)
		printf("%d, ", a[i]);
	//printf("\n");
	
	//Output odd elements mas 
	//printf("Output odd elements mas: ");
	for (int i = 1; i < n; i+=2)
		printf("%d, ", a[i]);
	printf("\n");

	free(a);

	return 0;
}
