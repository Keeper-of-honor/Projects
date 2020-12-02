#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//Добавление элемента в стек
void push(int stack[], int *len_stack, int number){
	stack[(*len_stack)++] = number;
}

//Удаление элемента из стека
int pop(int stack[], int *len_stack){
	if (*len_stack == 0)
		return(stderr);
	
	return stack[--(*len_stack)];
}

//Вывод стека
void printStack(int stack[], int len_stack){
	int i = 0;
	while (i != len_stack)
		printf("%d ", stack[i++]);
	printf("\n");
}
