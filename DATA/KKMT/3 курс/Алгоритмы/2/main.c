/**
Условие:
	Дан текст: в первой строке записано число строк, далее идут сами строки. Определите, сколько различных слов содержится в этом тексте.
	Словом считается последовательность непробельных символов идущих подряд, слова разделены одним или большим числом пробелов или символами конца строки.

Выполнил: Герасимов Дмитрий П1-18 18.11.2020

*/

#include <stdio.h>
#define MAXX 10000
#define LEN 50

//#include "lot.h"

int main(){
	size_t num_str = 0;	//Количество строк
	scanf("%d", &num_str);
	
	char lot[MAXX][LEN];	//Множество слов
	int len_lot = 0;
	char str[LEN];
	
	for (size_t i = 0; i != num_str; ++i){
	}
	
	//Вывод множества
	for (size_t i = 0; i != num_str; ++i)
		printf("%s ", lot[i]);
	/*
	int len_lot = 0;
	int n = -1;

	for (int i = 0; scanf("%d", &n) != EOF; ++i)
		//Добавить элемент в множество
		lotAddI(mas, &len_mas, n);
	
	//Вывод множества
	printLotI(mas, len_mas);
	*/

	return 0;
}
