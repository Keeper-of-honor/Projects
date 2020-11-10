#ifndef MAINFUNC_H
#define MAINFUNC_H

void borderMenu();	//Первоначальная анимация и создание границ
void nameGame(char name_app[]);	//Запись имени игры

void inputdata(char filename[], char mapname[]); //Ввод имени файла и имени карты

//Главный функционал

void creatMap(char username[], char filename[], char mapname[]);

void drawField();	//2. Нарисовать поле для змейки

#endif
