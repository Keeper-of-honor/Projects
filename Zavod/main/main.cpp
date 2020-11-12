#include <ncurses.h>
#include <iostream>
#include <string.h>

#include "mainFunc.h"	//Главные функции
#include "helpFunc.h"	//Вспомогательные функции

/*
	1. В Creat map, оформить как блоки до этого
*/

/**
-------------MENU------------------------------
Game selection

	Start
	Archive fields
	Creat field
	Import field
	Exit

Setting
Help
Exit
----------------------------------------------
*/

//Глобальные константы
extern const int WIDTH_WIN = 50;	// Ширина окна меню
extern const int HEIGHT_WIN = 20;	// Длина окна меню

extern const int LEN = 35;	//Длина

int main()
{
	if (!initscr()){
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}
	
//########################################################################

	//Главное меню
	const int NUM_BLOCK_MENU = 4;	//Колличество блоков в меню
	char text_menu[NUM_BLOCK_MENU][LEN]= {
		"Next",
		"Setting",
		"Help",
		"Exit"
	};
	
	// Menu /Game section /Any games
	const int NUM_BLOCK_MENU_GAME = 5;	//Список игр + exit
	char game_menu[NUM_BLOCK_MENU_GAME][LEN]= {
		"Start",
		"Archive maps",
		"Create map",
		"Import map",
		"Exit"
	};

	// Menu /Game section /Any games / Creat map
	const int NUM_BLOCK_CREAT_MAP = 3;	//Список игр + exit
	char menu_creat_map[NUM_BLOCK_CREAT_MAP][LEN]= {
		"Start draw",
		"Rewrite map",
		"Exit"
	};

	//Данные пользователя
	struct DataUser{
		char username[LEN];	//Имя
		char filename[LEN];	//Имя файла
		char mapname[LEN];	//Имя карты
	} user;	//!!!!!!!!!!!!!!!!!!

//########################################################################

	initscr();
	refresh();

	//Ввод имени
	mvprintw(LINES / 2 - 2, COLS / 2 - LEN + 10, "Enter name :  ");
	scanw("%s", &user.username);
	
	//Анимация
	int s_win = COLS  * LINES;	// Площадь консоли
	//----animation(s_win, 1000);
	
	//Создаем окно
	int offsetx = (COLS - WIDTH_WIN) / 2;
	int offsety = (LINES - HEIGHT_WIN) / 2;
	//WINDOW *win = newwin(HEIGHT_WIN, WIDTH_WIN, offsety, offsetx);

	//Чертим границы
	borderMenu(offsetx, offsety);
	
	curs_set(0);
	noecho();	//Чтобы при записи символа, символ не повторялся
	keypad(stdscr, TRUE);	//Включает возможности клавиатуры

	//Вывод имени платформы
	char name_app[] = "Snake";
	nameGame(name_app);
	char empty_str[LEN] = "                  \0";	//Пустая строка, рабтает как стёрка
	
	printAllBlocks(NUM_BLOCK_MENU, &text_menu[0][0]);	//Выписывает все главное меню
		
	int pos_cursor = 0;	//Позиция курсора
	int ch = 0;	//Символ навигации
	int depth_menu = 1;	//Выход из цикла

	selectBlock(pos_cursor, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Выделение блока
	
	//1. Главное меню
	while(depth_menu == 1){
		navigation(ch, pos_cursor, NUM_BLOCK_MENU, &text_menu[0][0]);	//Навигация + Печать блока + Выделение блока
		
		if (ch == KEY_RIGHT || ch == '\n'){
			++depth_menu;
			
			//2. Меню игры
			if (pos_cursor == 0){
			
				//pos_cursor = 0;
				printAllBlocks(NUM_BLOCK_MENU_GAME, &game_menu[0][0]);	//Выписывает весь список игр
				selectBlock(pos_cursor, NUM_BLOCK_MENU_GAME, game_menu[pos_cursor]);	//Выделение блока
				
				while(depth_menu == 2){
				
					navigation(ch, pos_cursor, NUM_BLOCK_MENU_GAME, &game_menu[0][0]);	//Навигация + Печать блока + Выделение блока
					
					if (ch == KEY_RIGHT || ch == '\n' || ch == 'd'){
						//Exit
						if (pos_cursor == NUM_BLOCK_MENU_GAME - 1){
							pos_cursor = 0;
							--depth_menu;
							
							printBlock(4, NUM_BLOCK_MENU_GAME, &empty_str[0]);	//Стираем 5-ую лишнюю строку, т.к мы поднялись на верх, где их 4
							
							continue;
						}
						
						//Creat map
						if (pos_cursor == 2){
						//````````````````````````````````````````````````
							bool is_exit = 0;
							while (!is_exit){
								++depth_menu;
								
								inputdata(&user.filename[0], &user.mapname[0]);	//Ввод имени файла и имени карты
								//-----animation(s_win, 100);
								borderMenu(offsetx, offsety);
								nameGame(name_app);	//имя игры
								
								pos_cursor = 0;
								printAllBlocks(NUM_BLOCK_CREAT_MAP, &menu_creat_map[0][0]);	//Выписывает весь список игр
								selectBlock(pos_cursor, NUM_BLOCK_CREAT_MAP, menu_creat_map[pos_cursor]);	//Выделение блока
								
								while(depth_menu == 3){
									navigation(ch, pos_cursor, NUM_BLOCK_CREAT_MAP, &menu_creat_map[0][0]);	//Навигация + Печать блока + Выделение блока
						
									if (ch == KEY_RIGHT || ch == '\n' || ch == 'd'){
										//Exit
										if (pos_cursor == NUM_BLOCK_CREAT_MAP - 1){
											pos_cursor = 0;
											is_exit = 1;
											
											printAllBlocks(NUM_BLOCK_MENU_GAME, &game_menu[0][0]);	//Выписывает весь список игр
											selectBlock(pos_cursor, NUM_BLOCK_MENU_GAME, game_menu[pos_cursor]);	//Выделение блока
										}
										
										else if (pos_cursor == 0){
											creatMap(&user.username[0], &user.filename[0], &user.mapname[0]);
											
											//---animation(s_win, 100);
											borderMenu(offsetx, offsety);
											
											printAllBlocks(NUM_BLOCK_MENU_GAME, &game_menu[0][0]);	//Выписывает весь список игр
											selectBlock(pos_cursor, NUM_BLOCK_MENU_GAME, game_menu[pos_cursor]);	//Выделение блока
											nameGame(name_app);	//имя игры
											
											is_exit = 1;
										}
										
										//else if(pos_cursor == 1);
										
										--depth_menu;
										
									}
									
								}//while 3
							}
							
						}
						
						
					}
					
				}	//while

			}

			else if (pos_cursor == 1){}

			else if (pos_cursor == 2){}

			else if (pos_cursor == NUM_BLOCK_MENU - 1)
				depth_menu -= 2;	//Выход
			printAllBlocks(NUM_BLOCK_MENU, &text_menu[0][0]);
			selectBlock(pos_cursor, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Выделение блока

		}
	}
	
	endwin();
	
	return 0;
}


