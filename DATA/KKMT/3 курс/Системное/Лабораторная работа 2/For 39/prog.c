/**
For39. Даны целые положительные числа A и B (A < B). Вывести все целые числа от A до B включительно; при этом каждое число должно выводиться столько раз, каково его значение (например, число 3 выводится 3 раза).

Дата: 29.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>

int main(){
	int a, b;
	printf("Input A, B: ");
	scanf("%d%d", &a, &b);

	printf("\n");
	for (int i = a; i <= b; ++i){
		for (int j = 0; j < i; ++j)
			printf("%d ", i);
		printf("\n");
	}
	printf("\n");

	return 0;
}
