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
	Snake
		Start
		Archive fields
		Creat field
		Import field
		Exit
	Pacman
		Start
		Archive fields
		Creat field
		Import field
		Exit
	War of Countries
		Start
		Archive fields
		Creat field
		Import field
		Exit
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

	//Главное меню
	const int NUM_BLOCK_MENU = 4;	//Колличество блоков в меню
	char text_menu[NUM_BLOCK_MENU][LEN]= {
		"Game selection",
		"Setting",
		"Help",
		"Exit"
	};

	//Данные пользователя
	struct DataUser{
		char username[LEN];	//Имя
		char filename[LEN];	//Имя файла
		char mapname[LEN];	//Имя карты
	} user;	//!!!!!!!!!!!!!!!!!!


	initscr();
	refresh();

	//Ввод имени
	mvprintw(LINES / 2 - 2, COLS / 2 - LEN + 10, "Enter name :  ");
	scanw("%s", &user.username);
	
	//Анимация
	int s_win = COLS  * LINES;	// Площадь консоли
	//animation(s_win);
	
	//Черчение границ
	borderMenu();
	
	curs_set(0);
	noecho();	//Чтобы при записи символа, символ не повторялся
	keypad(stdscr, TRUE);	//Включает возможности клавиатуры

	//Вывод имени платформы
	char name_app[] = "Zavod";
	nameGame(name_app);
	char empty_str[LEN] = "                  ";	//Пустая строка, рабтает как стёрка
	
	printAllBlocks(NUM_BLOCK_MENU, &text_menu[0][0]);	//Выписывает все главное меню
		
	int pos_cursor = 0;	//Позиция курсора
	int ch = 0;	//Символ навигации
	int depth_menu = 1;	//Выход из цикла
	int token = 0;	// токен игры. Если 1, то Snake. Если 2, то Pacman. Если 3, то War of Countries. Если 0, то не активен

	selectBlock(pos_cursor, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Выделение блока
	
	/*{---- 1. Главное меню ----}*/
	
	while(depth_menu == 1){
		navigation(ch, pos_cursor, NUM_BLOCK_MENU, &text_menu[0][0]);	//Навигация + Печать блока + Выделение блока
		
		if (ch == KEY_RIGHT || ch == '\n' || ch == 'd'){
			++depth_menu;
			
			/*{---- 2. Выбор игры ----}*/

			const int NUM_BLOCK_GAMES = 4;	//Список игр + exit
			char game_section[NUM_BLOCK_GAMES][LEN]= {
				"Snake",
				"Pacman",
				"War of Countries",
				"Exit"
			};
			
			if (pos_cursor == 0){
			
				pos_cursor = 0;
				printAllBlocks(NUM_BLOCK_GAMES, &game_section[0][0]);	//Выписывает весь список игр
				selectBlock(pos_cursor, NUM_BLOCK_GAMES, game_section[pos_cursor]);	//Выделение блока
				
				while(depth_menu == 2){
					navigation(ch, pos_cursor, NUM_BLOCK_GAMES, &game_section[0][0]);	//Навигация + Печать блока + Выделение блока
					
					/*{---- 3. Меню игры ----}*/
					
					const int NUM_BLOCK_MENU_GAME = 5;	//Список игр + exit
					char game_menu[NUM_BLOCK_MENU_GAME][LEN]= {
						"Start",
						"Archive maps",
						"Creat map",
						"Import map",
						"Exit"
					};
					
					if (ch == KEY_RIGHT || ch == '\n' || ch == 'd'){
						//Exit
						if (pos_cursor == NUM_BLOCK_GAMES - 1){
							pos_cursor = 0;
							--depth_menu;
							continue;
						}
						token = pos_cursor + 1;	//Токен игры
						nameGame(&game_section[pos_cursor][0]);	//Печатаем имя игры
						++depth_menu;	//Опускаемся вниз
						pos_cursor = 0;
						printAllBlocks(NUM_BLOCK_MENU_GAME, &game_menu[0][0]);	//Выписывает весь список игр
						selectBlock(pos_cursor, NUM_BLOCK_MENU_GAME, game_menu[pos_cursor]);	//Выделение блока
						
						while(depth_menu == 3){
							navigation(ch, pos_cursor, NUM_BLOCK_MENU_GAME, &game_menu[0][0]);	//Навигация + Печать блока + Выделение блока
							
							if (ch == KEY_RIGHT || ch == '\n' || ch == 'd'){
								if (pos_cursor == NUM_BLOCK_MENU_GAME - 1){
									pos_cursor = 0;
									--depth_menu;
									
									printAllBlocks(NUM_BLOCK_GAMES + 1, &game_section[0][0]);	//Выписывает весь список игр
									printBlock(4, NUM_BLOCK_GAMES, &empty_str[0]);	//Стираем 5-ую лишнюю строку, т.к мы поднялись на верх, где их 4
									selectBlock(pos_cursor, NUM_BLOCK_GAMES, game_section[pos_cursor]);	//Выделение блока
									
									nameGame(&empty_str[0]);	//Стираем прошлую строку
									nameGame(name_app);	//Стираем прошлую строку
									
									continue;
								}
								//Start game
								if (pos_cursor == 0){}
								//Archive fields
								else if (pos_cursor == 1){}
								//Creat field
								else if (pos_cursor == 2){
								
								
									/*
									const int NUM_BLOCK_CREAT_MAP = 3;	//Список игр + exit
									char creat_map[NUM_BLOCK_CREAT_MAP][LEN]= {
										"Next",
										"Rewrite",
										"Exit"
									};
									
									//Exit
									if (pos_cursor == NUM_BLOCK_CREAT_MAP - 1){
										pos_cursor = 0;
										--depth_menu;
										continue;
									}
									*/
									
									echo();	//Чтобы при записи символа, символ не повторялся
									curs_set(1);
									
									system("clear");	//Очистка экрана
									inputNamefileNamemap(user.filename, user.mapname);
									
									++depth_menu;	//Опускаемся вниз
									pos_cursor = 0;
									printAllBlocks(NUM_BLOCK_CREAT_MAP, &creat_map[0][0]);	//Выписывает весь список игр
									selectBlock(pos_cursor, NUM_BLOCK_CREAT_MAP, creat_map[pos_cursor]);	//Выделение блока
										
									while(depth_menu == 4){	
										navigation(ch, pos_cursor, NUM_BLOCK_CREAT_MAP, &creat_map[0][0]);	//Навигация
								
										ch = getch();
										if (ch == KEY_RIGHT || ch == '\n')
											is_exit = 1;
										else if (ch == KEY_LEFT){
											for (int i = width; i != COLS; ++i){
												mvprintw(height - 2, width - 8 + i, "%c", ' ');
												mvprintw(height - 1, width - 4 + i, "%c", ' ');
											}
										}
										
									}
									system("clear");	//Очистка экрана
									mvprintw(LINES / 2 - 1, COLS / 2 - LEN + 10, "Bruh");
								}
								//Import field
								else if (pos_cursor == 3){}
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
}

void inputNamefileNamemap(char &filename, char mapname){
	// Ввод имени файла
	mvprintw(0, 0, "Input Filename :  ");
	scanw("%s", &filename);
									
	// Добавляем в конец строки ".txt"
	//int len_filename = strlen(user.filename);
	mvprintw(1, 0, "Input Filename :  %s.txt", filename);
	mvprintw(0, 0, "Input name map :  ");
	scanw("%s", &mapname);
}
