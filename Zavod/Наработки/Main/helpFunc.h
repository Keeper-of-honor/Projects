#ifndef HELPFUNC_H
#define HELPFUNC_H

void animation(int s_win);	//Анимация

//Блок = строка. Например, если pos_cursor = 0, то блок = "Run"
void printBlock(int pos_cursor, const int WIDTH_WIN, const int NUM_BLOCK, char text[]);	//Печать блока
void selectBlock(int pos_cursor, const int WIDTH_WIN, const int NUM_BLOCK, char text[]);	//Выделение блока

//Навигация
void navigation(int ch, int &pos_cursor, const int NUM_BLOCK);

#endif
