/**
Case5. Арифметические действия над числами пронумерованы следующим образом: 1 — сложение, 2 — вычитание, 3 — умножение, 4 — деление. Дан номер действия N (целое число в диапазоне 1–4) и вещественные числа A и B (B не равно 0). Выполнить над числами указанное действие и вывести результат.

Дата: 29.09.2020
Источник: http://ptaskbook.com/ru/tasks/array.php
Выполнили: Герасимов Дмитрий, Груздев Роман П1-18
*/

#include <stdio.h>

int main(){
	int n;
	printf("Input N: ");
	scanf("%d", &n);
	int a,b;
	printf("Input A, B: ");
	scanf("%d%d", &a, &b);
	
	switch (n){
	case 1:
		printf("%d\n", a + b);
		break;
	case 2:
		printf("%d\n", a - b);
		break;
	case 3:
		printf("%d\n", a * b);
		break;
	case 4:
		printf("%d\n", a / b);
		break;
	default:
		printf("Error\n");
	}

	return 0;
}
