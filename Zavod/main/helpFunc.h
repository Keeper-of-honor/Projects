#ifndef HELPFUNC_H
#define HELPFUNC_H

void animation(int s_win, int sleep_step);	//Анимация

//Блок = строка. Например, если pos_cursor = 0, то блок = "Run"
void printBlock(int pos_cursor, const int NUM_BLOCK, char text[]);	//Печать блока
void printAllBlocks(const int NUM_BLOCK, char text[]);	//Печать всех блоков
void selectBlock(int pos_cursor, const int NUM_BLOCK, char text[]);	//Выделение блока

//Навигация
void navigation(int &ch, int &pos_cursor, const int NUM_BLOCK, char text[]);

void clearWindow(size_t height, size_t width);	//Очистка экрана

//void dataUpdate(int &depth_menu, int &pos_cursor, const int NUM_BLOCK, char text[]);

#endif
