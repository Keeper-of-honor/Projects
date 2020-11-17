#ifndef MAINFUNC_H
#define MAINFUNC_H

void borderMenu(int offsetx, int offsety);	//Первоначальная анимация и создание границ
void nameGame(char name_app[]);	//Запись имени игры

//Главный функционал

//Создание архива
size_t creatArchive(char archive_map[]);

//Создание карты
void inputdata(char filename[], char mapname[]); //Ввод имени файла и имени карты
void creatMap(char username[], char filename[], char mapname[]);	//Чертеж карты

#endif
