#include <ncurses.h>
#include <iostream>
#include <string.h>

#include "helpFunc.h"

//------------------------------------------------
//Глобальные константы
extern const int WIDTH_WIN;	// Ширина окна меню
extern const int HEIGHT_WIN;	// Длина окна меню

extern const int LEN;	//Длина

//Первоначальная анимация и создание границ
void borderMenu(){

	int offsetx = (COLS - WIDTH_WIN) / 2;
	int offsety = (LINES - HEIGHT_WIN) / 2;

	WINDOW *win = newwin(HEIGHT_WIN, WIDTH_WIN, offsety, offsetx);

	//Ввод никнейма
	//char username[LEN];
	//mvprintw(LINES / 2 - 2, COLS / 2 - LEN + 10, "Enter name :  ");
	//scanw("%s", &username);
	//mvprintw(1, 0, "%s", username);	

	//Чертим границы
	box(win, 0, 0);

	wrefresh(win);
	delwin(win);
}

//Вывод имени игры
void nameGame(char name_app[]){
	size_t len_str = strlen(name_app);
	size_t y = (LINES - HEIGHT_WIN) / 2 + 3;
	size_t x = (COLS - len_str) / 2;
	for (size_t i = 0; i != len_str; ++i)
		mvaddch(y, x + i, name_app[i] | A_BOLD);
}
