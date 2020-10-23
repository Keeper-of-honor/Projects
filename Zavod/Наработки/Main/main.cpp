#include <ncurses.h>
#include <iostream>

#include "mainFunc.h"	//Главные функции
#include "helpFunc.h"	//Вспомогательные функции

/*
	Задачи:
	1. while(true){} перевести в функцию
*/

int main()
{
	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}

	//Объявление переменных

	const int WIDTH_WIN = 50;	// Ширина окна меню
	const int HEIGHT_WIN = 20;	// Длина окна меню
	
	const int NUM_BLOCK_MENU = 4;	//Колличество блоков в меню
	const int LEN = 20;	//Длина

	//Меню
	char text_menu[NUM_BLOCK_MENU][LEN]= {
		"Game selection",
		"Setting",
		"Help",
		"Exit"
	};

	// Menu/Game section
	const int NUM_BLOCK_GAMES = 4;	//Колличество блоков в меню
	char game_section[NUM_BLOCK_GAMES][LEN]= {
		"Snake",
		"Pacman",
		"War of Countries",
		"Exit"
	};

	initscr();
	
	refresh();

	//Анимация в начале и черчение границ
	borderMenu(WIDTH_WIN, HEIGHT_WIN, LEN);
	
	curs_set(0);
	noecho();	//Чтобы при записи буквы, буква не повторялась
	keypad(stdscr, TRUE);	//Включает возможности клавиатуры

	//Вывод имени платформы
	char name_app[] = "Zavod";
	nameGame(HEIGHT_WIN, name_app);
	
	//Выписывает все меню
	for (size_t i = 0; i != NUM_BLOCK_MENU; ++i)
		printBlock(i, WIDTH_WIN, NUM_BLOCK_MENU, text_menu[i]);	//Печать блока
		
	int pos_cursor = 0;	//Позиция курсора
	int ch = 0;	//Символ навигации
	int is_exit = 0;	//Выход из цикла

	selectBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Выделение блока
	while(true){
		ch = getch();

		printBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Печать блока
		navigation(ch, pos_cursor, NUM_BLOCK_MENU);	//Навигация
		selectBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Выделение блока
		
		
		if (ch == KEY_RIGHT || ch == '\n')
		{

			//1. Выбор игры
			if (pos_cursor == 0)
			{
				is_exit = 0;
				//Выписывает выбор игры (Без какого-либо выделения)
				for (size_t i = 0; i != NUM_BLOCK_GAMES; ++i)
					printBlock(i, WIDTH_WIN, NUM_BLOCK_GAMES, game_section[i]);	//Печать блока
				pos_cursor = 0;
				selectBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_GAMES, game_section[pos_cursor]);	//Выделение блока
				while(is_exit != 1)
				{
					ch = getch();

					printBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_GAMES, game_section[pos_cursor]);	//Печать блока
					navigation(ch, pos_cursor, NUM_BLOCK_GAMES);	//Навигация
					selectBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_GAMES, game_section[pos_cursor]);	//Выделение блока
					
					if (ch == KEY_RIGHT || ch == '\n')
					{
						//Snake
						if (pos_cursor == 1){
							
						}
						//Pacman
						else if (pos_cursor == 1){}
						//War of Countries
						else if (pos_cursor == 2){}
						//Exit
						else if (pos_cursor == NUM_BLOCK_GAMES - 1)
						{
							pos_cursor = 0;
							is_exit = 1;
						}
					}
				}	//while

			}

			else if (pos_cursor == 1){}

			else if (pos_cursor == 2){}

			else if (pos_cursor == NUM_BLOCK_MENU - 1)
				break;
			for (size_t i = 0; i != NUM_BLOCK_MENU; ++i)
				printBlock(i, WIDTH_WIN, NUM_BLOCK_MENU, text_menu[i]);	//Печать блока
			selectBlock(pos_cursor, WIDTH_WIN, NUM_BLOCK_MENU, text_menu[pos_cursor]);	//Выделение блока

		}
	}
	
	endwin();
}
