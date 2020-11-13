#include <ncurses.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

//------------------------------------------------
//Глобальные константы
extern const int WIDTH_WIN;	// Ширина окна меню
extern const int HEIGHT_WIN;	// Длина окна меню

extern const int LEN;	//Длина

//Анимация
//	Передаём площадь экрана
void animation(int s_win, int sleep_step){
	//Адаптация скорости для экранов
	if (s_win / 1680){
		int step = s_win / 1680;
		for (int i = 0; i != step; ++i)
			sleep_step -= 150;
		if (sleep_step < 100)
			sleep_step = 100;
	}
	char zero_or_one = 0;
	while (s_win--){
		zero_or_one = s_win % 2 + '0';
		mvaddch(rand() % LINES, rand() % COLS, zero_or_one);
		//mvaddch(rand() % LINES, rand() % COLS, 'o');
		refresh();
		usleep(sleep_step);	//1 second = 1.000.000
	}
}

//Блок = строка. Например, если pos_cursor = 0, то блок = "Run"
//Печать блока
void printBlock(int pos_cursor, const int NUM_BLOCK, char text[]){
	size_t len_str = strlen(text);	//Длина блока

	size_t y = LINES/2 - (NUM_BLOCK / 2) + pos_cursor;	//Номер строки блока
	size_t x = (COLS - len_str)/2;	//Номер столбца начала блока
	
	size_t win_start = (COLS - WIDTH_WIN) / 2;	//Позиция начала win
	size_t win_end = win_start + WIDTH_WIN;	//Позиция конца win
	
	//Печать пробелов до блока
	for (size_t i = win_start + 1; i != x; ++i)
		mvaddch(y, i, ' ');
		
	//Печать блока
	mvaddstr(y, x, text);
	
	//Печать пробелов после блока
	for (size_t i = x + len_str; i != win_end - 1; ++i)
		mvaddch(y, i, ' ');
}

//Печать всех блоков
void printAllBlocks(const int NUM_BLOCK, char text[]){
	for (int i = 0; i != NUM_BLOCK; ++i)
		printBlock(i, NUM_BLOCK, &text[i * LEN]);	//Печать блока
}

//Выделение блока (строки)
void selectBlock(int pos_cursor, const int NUM_BLOCK, char text[]){
	size_t len_str = strlen(text);	//Длина блока

	size_t y = LINES/2 - (NUM_BLOCK / 2) + pos_cursor;	//Номер строки блока
	size_t x = (COLS - len_str)/2;	//Номер столбца начала блока
	
	size_t win_start = (COLS - WIDTH_WIN) / 2;	//Позиция начала win
	size_t win_end = win_start + WIDTH_WIN;	//Позиция конца win
	
	//Печать пробелов до блока
	for (size_t i = win_start + 1; i != x; ++i)
		mvaddch(y, i, ' '| A_STANDOUT);
	
	//Печать блока	
	size_t index = 0;
	for (size_t i = x; i != x + len_str; ++i){
		mvaddch(y, i, text[index]| A_STANDOUT);
		++index;
	}
	
	//Печать пробелов после блока
	for (size_t i = x + len_str; i != win_end - 1; ++i)
		mvaddch(y, i, ' ' | A_STANDOUT);
}

//Навигация
void navigation(int &ch, int &pos_cursor, const int NUM_BLOCK, char text[]){
	ch = getch();

	printBlock(pos_cursor, NUM_BLOCK, &text[pos_cursor * LEN]);	//Печать блока
	
	if (ch == KEY_DOWN || ch == 's'){
		++pos_cursor;
		if (pos_cursor == NUM_BLOCK)
			pos_cursor = 0;
	}
	else if (ch == KEY_UP || ch == 'w'){
		--pos_cursor;
		if (pos_cursor == -1)
			pos_cursor = NUM_BLOCK - 1;
	}
	if ( ch > '0' && ch <= NUM_BLOCK + '0' )
		pos_cursor = ch - '0' - 1;
	
	selectBlock(pos_cursor, NUM_BLOCK, &text[pos_cursor * LEN]);	//Выделение блока
}

//Очистка экрана
void clearWindow(size_t height, size_t width){
	for (size_t i = 0; i != height; ++i)
		for (size_t j = 0; j != width; ++j)
			mvaddch(i, j, ' ');
}

//Очистка строки
void clearStrs(int y_start, int x_start, int y_end, int x_end){
	for (int i = y_start; i != y_end; ++i)
		for (int j = x_start; j != x_end; ++j)
			mvaddch(i, j, ' ');
}
/*

//Обновление переменных и вывод всех блоков и выделение первого
void dataUpdate(int &depth_menu, int &pos_cursor, const int NUM_BLOCK, char text[]){
	//Обновление переменных
	--depth_menu;
	pos_cursor = 0;

	printAllBlocks(NUM_BLOCK, &text[0]);	//Выписывает весь список игр
	selectBlock(pos_cursor, NUM_BLOCK, &text[0]);	//Выделение блока
}

*/
