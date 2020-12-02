/**
Дата 20.11.2020
Выполнил: Герасимов Дмитрий П1-18

Задача 1.
    Вводится некоторое количество целых чисел. 
    Нужно распечатать их в обратном порядке. Используем стек.
    Пример
    Ввод 1 2 3 4 5
    Вывод 5 4 3 2 1
*/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
// Чтобы воспользоваться библиотекой "stack.h", надо использовать 
//динамический массив

int main(){
	//Создаем стек
	int len__stack = 0;
	int *stack = (int *) malloc(len__stack + 1);

	//Ввод данных в стек
	int number = 0;
	printf("To stop input data in stack, press <Ctrl + D>\n");
	for (int i = 0; scanf("%d", &number) != EOF; ++i)
		push(stack, &len__stack, number);	//Заполнение стека
	
	reversStack(stack, len__stack); //Разворот стека

	printStack(stack, len__stack); //Вывод стека

	return 0;
}
