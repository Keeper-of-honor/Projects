#include <ncurses.h>
#include <iostream>
#include <string.h>
#include <string>

#include <unistd.h>
#include <fstream>
#include <experimental/filesystem>

#include <vector>
#include <fstream>

#include "helpFunc.h"
#define MAXX 10000
#define LEN 35


using namespace std;
namespace fs = std::experimental::filesystem;

//------------------------------------------------
//Глобальные константы
extern const int WIDTH_WIN;	// Ширина окна меню
extern const int HEIGHT_WIN;	// Длина окна меню

//extern const int LEN;	//Длина
//extern const int MAXX = 10000;	//Максимальная длина

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

//{-------------- Archive maps --------------}

//Создание архива + вернет количество файлов в нем
size_t creatArchive(char archive_map[]){
	std::string str;
	size_t len_archive = 0;
	chdir("./archive/maps");
	std::string path = ".";
	//std::string path = "./archive/maps";
	for (const auto & entry : fs::directory_iterator(path)){
		str = entry.path();	// "./name_file"
		
		//Передаем в наш массив name_file и удаляем из начала "./"
		size_t i;
		for (i = 2; str[i] != '\0'; ++i)
			archive_map[LEN * len_archive + i - 2] = str[i];
		archive_map[LEN * len_archive + i] = '\0';
		
		++len_archive;
	}
	return len_archive;
}

//{-------------- Creat map --------------}

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
	//Очистка экрана
	clearWindow(LINES, COLS);

	curs_set(0);
	noecho();	//Чтобы при записи символа, символ не повторялся
	keypad(stdscr, TRUE);	//Включает возможности клавиатуры

	//system("clear");	//Очистка экрана

	//char road_map [100];
	//sprintf(road_map, ".//%s//%s", MAPS_PATH, filename);
	//ofstream fout = fopen("", "w");
	chdir("./archive/maps");
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
	mvprintw(height + 2, 3, "Press \"C\" to clear map");
	mvprintw(height + 3, 3, "Press \"ENTER\" to set the start of the snake");
    	
    	
//Чертеж карты
	//Символы печати
    	int ch = 0;	//Символ для навигации
    	char w_ch = '#';	//Символ для печати

	move(y, x);
	addch(w_ch | A_STANDOUT);
   	while (true){
		ch = getch();	//ввод символа (для навигации и печати).
		
		//Навигация
		if (ch == KEY_DOWN || ch == 's'){
			mvprintw(y, x, "%c", w_ch);
			y++;
		}
		else if (ch == KEY_UP || ch == 'w'){
			mvprintw(y, x, "%c", w_ch);
			y--;
		}
		else if (ch == KEY_LEFT || ch == 'a'){
			mvprintw(y, x, "%c", w_ch);
			x--;
		}
		else if (ch == KEY_RIGHT || ch == 'd'){
			mvprintw(y, x, "%c", w_ch);			
			x++;
		}
		
		//Home
		else if (ch == KEY_HOME){
			mvprintw(y, x, "%c", w_ch);
			x = 1;
			mvprintw(y, x, "%c", w_ch);			
		}
		//End
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
		
		else if (ch == '\n'){
			mvprintw(y, x, "%c", w_ch);
			break;
		}
		
		
		//Запись после передвижения
		else if (ch == '\t'){
			if (w_ch == ' ')
				w_ch = '#';
			else
				w_ch = ' ';
		}
		
		//Clear window
		else if (ch == 'c' || ch == 'C')
			 clearStrs(1, 1, height - 1, width - 1);
		
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

	clearStrs(height, 0, height + 5, COLS);
	mvprintw(height + 1, 3, "Press \"ENTER\" to exit and save");

//Точка старта змейки
	x = width / 2 - 1;
	y = height / 2 - 1;
	char last = canvas[y][x];	//Последний символ
	size_t x1;
	size_t y1;
	w_ch = 'O';
	
	move(y, x);
	addch(w_ch | A_STANDOUT);
	
	while (true){
		ch = getch();	//ввод символа (для навигации и печати).
		
		last = canvas[y][x];
		y1 = y;
		x1 = x;
		
		//Навигация
		if (ch == KEY_DOWN || ch == 's')	//Down
			y++;
		else if (ch == KEY_UP || ch == 'w')	//Up
			y--;
		else if (ch == KEY_LEFT || ch == 'a')	//Left
			x--;
		else if (ch == KEY_RIGHT || ch == 'd')//Right	
			x++;
		
		else if (ch == KEY_HOME)	//Home
			x = 1;
		else if (ch == KEY_END)	//End
			x = width - 2;
		else if (ch == KEY_NPAGE)	//Page Up
			y = height - 2;
		else if (ch == KEY_PPAGE)	//Page Down
			y = 1;		
		
		else if (ch == '\n'){
			mvprintw(y, x, "%c", w_ch);
			break;
		}
		
		//Чтоб кусор не вышел за предел границы
		if (x == width-1 ){
			--x;
			--x1;
		}
		else if (x == 0){
			++x;
			++x1;
		}
		else if (y == height-1){
			--y;
			--y1;
		}
		else if (y == 0){
			++y;
			++y1;
		}
		
		//Печать активного символа (место где находится курсор)
		move(y, x);
		addch(w_ch | A_STANDOUT);
		
		mvprintw(y1, x1, "%c", last);

		//canvas[y][x] = last;
	}

	
	canvas[y][x] = w_ch;
	
	for (size_t i = 0; i != height; ++i){
		for (size_t j = 0; j != width; ++j){
			fout << canvas[i][j];
		}
		fout << endl;
	}
	fout << endl
		<< '\t' << "Name user: " << username << endl
		<< '\t' << "Name map: " << mapname << endl
		<< '\t' << "Width map: " << width << endl
		<< '\t' << "Height map: " << height << endl;
	
	chdir("..//..//");
	
	clearWindow(LINES, COLS);
	//system("clear");
}




