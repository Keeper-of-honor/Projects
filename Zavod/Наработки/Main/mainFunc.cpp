#include <ncurses.h>
#include <iostream>
#include <string.h>

#include "helpFunc.h"

//Первоначальная анимация и создание границ
void borderMenu(const int WIDTH_WIN, const int HEIGHT_WIN, const int LEN){
	
	int offsetx = (COLS - WIDTH_WIN) / 2;
	int offsety = (LINES - HEIGHT_WIN) / 2;

	WINDOW *win = newwin(HEIGHT_WIN, WIDTH_WIN, offsety, offsetx);

	//Ввод никнейма
	char* username;
	mvprintw(LINES / 2 - 2, COLS / 2 - LEN + 2, "Enter name :  ");
	scanw("%s", &username);

	//Анимация перед чертением
	int s_win = COLS  * LINES;	// Площадь консоли
	animation(s_win);

	//Чертим границы
	box(win, 0, 0);

	wrefresh(win);
	delwin(win);
}

//Вывод имени игры
void nameGame(const int HEIGHT_WIN, char name_app[]){
	size_t len_str = strlen(name_app);
	size_t y = (LINES - HEIGHT_WIN) / 2 + 3;
	size_t x = (COLS - len_str) / 2;
	for (size_t i = 0; i != len_str; ++i)
		mvaddch(y, x + i, name_app[i] | A_BOLD);
}
