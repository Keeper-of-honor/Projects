#ifndef _STACK_
#define _STACK_

//Добавить элемент в стек
void push(int stack[], int *len_stack, int number);

//Удаление элемента из стека
int pop(int stack[], int *len_stack);

//Вывод стека
void printStack(int stack[], int len_stack);

#endif
