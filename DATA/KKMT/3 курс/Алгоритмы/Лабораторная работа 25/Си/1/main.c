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

	//Создаем стек-архив, из которого мы будем брать данные
	int len__stack_archive = 0;
	int *stack_archive = (int *) malloc(len__stack_archive + 1);
	
	int number = 0;
	printf("To stop input data, press <Ctrl + D>\n");
	//Ввод данных
	for (int i = 0; scanf("%d", &number) != EOF; ++i)
		//Заполнение стека
		push(stack_archive, &len__stack_archive, number);
	
	//Создаем стек, в который будет хранить перевернутые данные
	int len__stack = 0;
	int *stack = (int *) malloc(len__stack + 1);
	while (len__stack_archive)
		push( stack, &len__stack, pop(stack_archive, &len__stack_archive) );

	printStack(stack, len__stack);

	return 0;
}
