//2. Разработать АТД "Дек"
//Выполнил: Герасимов Д.А. П1-18. 23.06.2020

#ifndef FUNC_H
#define FUNC_H

#include <iostream>

using namespace std;

/*
struct Deque{
    int data[N]; //массив данных
    int last; //указатель на конец
};
*/

//создание дека
void Creation(Deque &D);

//проверка дека на пустоту
bool Full(Deque &D);

//добавление элемента в начало
void AddL(Deque &D);

//добавление элемента в конец
void AddR(Deque &D);

//удаление первого элемента
void DeleteL(Deque &D);

//удаление последнего элемента
void DeleteR(Deque &D);

//вывод первого элемента
int OutputL(Deque &D);

//вывод последнего элемента
int OutputR(Deque &D);

//размер дека
int Size(Deque &D);

#endif
