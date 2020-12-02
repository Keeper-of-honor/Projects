/**
Русская змейка.
*/
#include <iostream>
//#include "conio.h"

//#include <ncurses.h>
#include <curses.h>
//#define _CRT_SECURE_NO_WARNINGS


using namespace std;

//keypad(stdscr, TRUE);

bool gameOver;

const unsigned short width = 40;	///Ширина
const unsigned short height = 20;	///Длина
unsigned short x, y;			///Координаты
unsigned short fruitX, fruitY;		///Координаты фрукта
unsigned short score;			///Счётчик баллов
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN, EMPTY};
eDirection dir;

///Настриваем переменные
void Setup(){
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	///Рандомное значение для фруктов
	fruitX = rand() % width;	
	fruitY = rand() % height;
	score = 0;
}

///Рисуем поле
void Draw(){
	system("clear");

	for (size_t i = 0; i != width + 1; ++i)	///Верхняя граница
		cout << '#';
	cout << endl;
	for (size_t i = 0; i != height; ++i){		
		for (size_t j = 0; j != width; ++j){		/// i = высота; j = ширина
			if (j == 0 || j == width - 1)		///Боковые границы
				cout << '#';
			if (i == y && j == x)			///Голова змеи
				cout << '0';
			else if (i == fruitY && j == fruitX)	///Фрукты
				cout << 'F';
			else
				cout << ' ';
		}
		cout << endl;
	}

	for (size_t i = 0; i != width + 1; ++i)	///Нижняя граница
		cout << '#';
	cout << endl;
}

int _kbhit() {
    static bool inited = false;
    int left;

    if (!inited) {
        termios t;
        tcgetattr(0, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(0, TCSANOW, &t);
        setbuf(stdin, NULL);
        inited = true;
    }

    ioctl(0, FIONREAD, &left);

    return left;
}

///Перемещение змейки на поле
void Input(){
	//if (_kbhit()){	///Был ли веден символ
		switch (getch()){	///Что это за символ
		case 'a':
			dir = LEFT; break;
		case 'd':
			dir = RIGHT; break;
		case 'w':
			dir = UP; break;
		case 's':
			dir = DOWN; break;
		case 'x':			///Закрыть окно
			gameOver = true; break;
		}
}

void Logic(){
	switch (dir){
		case LEFT:
			--x; break;
		case RIGHT:
			++x; break;
		case UP:
			--y; break;
		case DOWN:
			++y; break;
		case EMPTY:
			break;
	}
}


int main(){
	//initscr();
	Setup();
	while (!gameOver){
		Draw();
		Input();
		Logic();
	}

	return 0;
}
