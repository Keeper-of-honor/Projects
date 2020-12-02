#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*
//Создаем стек
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
*/

//Развернуть стек
void reversStack(int stack[], int len__stack){

	int len__stack_archive = 0;
	int *stack_archive = (int *) malloc(len__stack_archive + 1);
	//Заполнение stack_archive
	while (len__stack)
		push( stack_archive, &len__stack_archive, pop(stack, &len__stack) );
		
	int len__stack_archive2 = 0;
	int *stack_archive2 = (int *) malloc(len__stack_archive2 + 1);
	//Заполнение stack_archive
	while (len__stack_archive)
		push( stack_archive2, &len__stack_archive2, pop(stack_archive, &len__stack_archive) );
		
	while (len__stack_archive2)
		push( stack, &len__stack, pop(stack_archive2, &len__stack_archive2) );
	
}

//Добавление элемента в стек
void push(int stack[], int *len__stack, int number){
	stack[(*len__stack)++] = number;
}

//Удаление элемента из стека
int pop(int stack[], int *len__stack){
	if (*len__stack == 0)
		return(stderr);
	
	return stack[--(*len__stack)];
}

//Вывод стека
void printStack(int stack[], int len_stack){
	int i = 0;
	while (i != len_stack)
		printf("%d ", stack[i++]);
	printf("\n");
}
