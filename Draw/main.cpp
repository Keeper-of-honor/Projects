/**
Енто рисовалка
Создатель: Герасимов Дмитрий
Дата: 11.10.2020

*/
#include <ncurses.h>
#include <iostream>
using namespace std;

//Границы (строим карту)
void Map(size_t width, size_t height){
	for (size_t i = 0; i != height; ++i){
		for (size_t j = 0; j != width; ++j){		/// i = высота; j = ширина
			mvprintw(0, j, "#");				///Верхняя граница
			mvprintw(height - 1, j, "#");		///Нижняя граница
			if (j == 0 || j == width - 1)		///Боковые границы
				mvprintw(i, j, "#");
		}
	}
}

//Запись управления/меню (снизу)
void Menu(size_t height){

	mvprintw(height + 1, 3, "Navigation");
	mvprintw(height + 2, 3, "Exit: enter ('\\n')");
	mvprintw(height + 3, 3, "By clicking on a char, you start printing with that char");
}

int main(){
	cout << "Добро пожаловать в рисовалку! Хотите начать творить?" << endl
		<< "1. Да" << endl
		<< "0. Нет" << endl;
	bool start;
	cout << "Ваш выбор: ";
	cin >> start;
	
	if (start){
		size_t height;	//высота окна
		size_t width;	//ширина окна
		
		initscr();	//Открываем экран
		
		getmaxyx(stdscr, height, width); //определяем размер экрана
		height -= 10;	//оставляем место для нижней меню
		curs_set(0);	//Убиваем курсор
		noecho();	//Чтобы при записи буквы, буква не повторялась
		keypad(stdscr, TRUE);	//

		//Для записи с центра карты
		size_t x = width / 2 - 1;		//координата строчки
		size_t y = height / 2 - 1;	//координата столбца

	    	Map(width, height);	//Границы (строим карту) 
	    	Menu(height);	//Запись управления (снизу)
	    	
	    	int ch = 0;
	    	char w_ch = 'X';
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
			else if (ch == '\n')
				break;
			
			//Запись после передвижения
			else if (ch != '\t'){
				w_ch = ch;
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
		}
		
		clear();	//очищаем окно
		endwin();	//закрываем окно
	}
	cout << endl << "Покеч" << endl;
	

	return 0;
}


