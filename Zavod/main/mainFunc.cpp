#include <ncurses.h>
#include <iostream>
#include <string.h>

#include <unistd.h>
#include <fstream>

#include <vector>
#include <fstream>

#include "helpFunc.h"

using namespace std;

//------------------------------------------------
//Глобальные константы
extern const int WIDTH_WIN;	// Ширина окна меню
extern const int HEIGHT_WIN;	// Длина окна меню

extern const int LEN;	//Длина

//Создание границ
void borderMenu(int offsetx, int offsety){
	//Чертим карту
	WINDOW *win = newwin(HEIGHT_WIN, WIDTH_WIN, offsety, offsetx);
	wrefresh(win);

	box(win, 0, 0);
	wrefresh(win);
	delwin(win);
}


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

//{---- Creat map ----}

//Ввод имени файла и имени карты 
void inputdata(char filename[], char mapname[]){
	//Очистка экрана
	clearWindow(LINES, COLS);

	curs_set(1);	// + курсок
	echo();	//+ печать
	char ch = 0;
	
	// Ввод имени файла
	mvprintw(LINES - 1, 0, "Input Filename :  ");
	//scanw("%s", &filename);
	
	int len_filename = 0;
	while ( (ch = getch()) != '\n' )
		filename[len_filename++] = ch;
	filename[len_filename++] = '\0';
	
	// Добавляем в конец строки ".txt"
	mvprintw(LINES - 2, 0, "Input Filename :  %s", filename);
	for (int i = 0; i != COLS; ++i)
		mvaddch(LINES - 1, i, ' ');	
	// Ввод имени карты
	mvprintw(LINES - 1, 0, "Input name map :  ");
	//scanw("%s", &mapname);
	
	int len_mapname = 0;
	while ( (ch = getch()) != '\n' )
		mapname[len_mapname++] = ch;
	mapname[len_mapname++] = '\0';
	
	curs_set(0);
	noecho();
	
	//system("clear");
	for (int i = 0; i != COLS; ++i)
		mvaddch(LINES - 1, i, ' ');
	for (int i = 0; i != COLS; ++i)
		mvaddch(LINES - 2, i, ' ');
}

//char MAPS_PATH[] = "archivе";

//Создание карты
void creatMap(char username[], char filename[], char mapname[]){

	curs_set(0);
	noecho();	//Чтобы при записи символа, символ не повторялся
	keypad(stdscr, TRUE);	//Включает возможности клавиатуры

	//system("clear");	//Очистка экрана

	//char road_map [100];
	//sprintf(road_map, ".//%s//%s", MAPS_PATH, filename);
	//ofstream fout = fopen("", "w");
	chdir(".//archive");
	ofstream fout = ofstream(filename);
	//FILE *fout = fopen(road_map,"w"); 
	size_t height;	//высота окна
	size_t width;	//ширина окна

	getmaxyx(stdscr, height, width); //определяем размер экрана

	height -= 5;

	//Для записи с центра карты
	size_t x = width / 2 - 1;		//координата строчки
	size_t y = height / 2 - 1;	//координата столбца
	
	//Инициализация 2мерного массива
	vector <vector<char>> canvas;	//Лист для 
	canvas = vector <vector<char>>(height, vector<char> (width, ' ') );

	//Очистка экрана
	clearWindow(LINES, COLS);
	
	//Чертим карту
   	for (size_t i = 0; i != height; ++i){
		for (size_t j = 0; j != width; ++j){		/// i = высота; j = ширина
			mvaddch(0, j, '#');			///Верхняя граница
			mvaddch(height - 1, j, '#');		///Нижняя граница
			if (j == 0 || j == width - 1){		///Боковые границы
				mvaddch(i, j, '#');
				canvas[i][j] = '#';
			}
			canvas[0][j] = '#';
			canvas[height - 1][j] = '#';
		}
	}
	mvprintw(height + 1, 3, "Press \"TAB\" to change mode (wall/empty)");
	mvprintw(height + 2, 3, "Press \"ENTER\" to set the start of the snake");
    	
	//Символы печати
    	int ch = 0;	//Символ для навигации
    	char w_ch = '#';	//Символ для печати

	move(y, x);
	addch(w_ch | A_STANDOUT);
   	while (true){
		ch = getch();	//ввод символа (для навигации и печати).
		
		//Навигация
		if (ch == KEY_DOWN){
			mvprintw(y, x, "%c", w_ch);
			y++;
		}
		else if (ch == KEY_UP){
			mvprintw(y, x, "%c", w_ch);
			y--;
		}
		else if (ch == KEY_LEFT){
			mvprintw(y, x, "%c", w_ch);
			x--;
		}
		else if (ch == KEY_RIGHT){
			mvprintw(y, x, "%c", w_ch);			
			x++;
		}
		
		else if (ch == KEY_HOME){
			mvprintw(y, x, "%c", w_ch);
			x = 1;
			mvprintw(y, x, "%c", w_ch);			
		}
		else if (ch == KEY_END){
			mvprintw(y, x, "%c", w_ch);
			x = width - 2;
			mvprintw(y, x, "%c", w_ch);
		}
		
		//Page Up
		else if (ch == KEY_NPAGE){
			mvprintw(y, x, "%c", w_ch);
			y = height - 2;
			mvprintw(y, x, "%c", w_ch);			
		}
		//Page Down
		else if (ch == KEY_PPAGE){
			mvprintw(y, x, "%c", w_ch);
			y = 1;
			mvprintw(y, x, "%c", w_ch);			
		}
		
		else if (ch == '\n')
			break;
		
		//Запись после передвижения
		else if (ch == '\t'){
			if (w_ch == ' ')
				w_ch = '#';
			else
				w_ch = ' ';
		}
		
		//Чтоб кусор не вышел за предел границы
		if (x == width-1)
			--x;
		else if (x == 0)
			++x;
		else if (y == height-1)
			--y;
		else if (y == 0)
			++y;
			
			
		//Печать активного символа (место где находится курсор)
		move(y, x);
		addch(w_ch | A_STANDOUT);

		canvas[y][x] = w_ch;
	}
	
	for (size_t i = 0; i != height; ++i){
		for (size_t j = 0; j != width; ++j){
			fout << canvas[i][j];
		}
		fout << endl;
	}
	fout << '\t' << "Name: " << username << endl;
	fout << '\t' << "Name map: " << mapname << endl;

	system("clear");	//Очистка экрана
}
