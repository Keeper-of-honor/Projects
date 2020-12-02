#ifndef FUNC_H
#define FUNC_H

struct Date{
	unsigned int day;	//День 
	unsigned int month;	//Месяц
	unsigned int year;	//Год
};

struct Plist{
	Date date;		//Дата
	std::string name;	//Марка
	unsigned int price;	//Цена
};

typedef std::vector <Plist> vPlist;

void load(vPlist &vec);		// 1. Загрузка файла в вектор

void save(vPlist vec);		// 2. Загрузить вектор в файл

void swapStr(vPlist &vec);	// 3. Заменить строку N

void delStr(vPlist &vec);	// 4. Удалить строку с номером N

void printVec(vPlist vec);	// 5. Выгрузить даные вектора

void report(vPlist vec); 	// 6. Отпечатать суммарные ежемесячные и годовую продажи

#endif
