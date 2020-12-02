#ifndef _STACK_
#define _STACK_

//Развернуть стек
void reversStack(int stack[], int len__stack);

//Добавить элемент в стек
void push(int stack[], int *len__stack, int number);

//Удаление элемента из стека
int pop(int stack[], int *len__stack);

//Вывод стека
void printStack(int stack[], int len__stack);

#endif
