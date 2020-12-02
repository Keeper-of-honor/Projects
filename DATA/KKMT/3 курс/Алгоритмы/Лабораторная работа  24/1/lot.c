#include <stdio.h>

//Добавляет элемент в множество
void lotAddI(int lot[], int *len_lot, int n){
	char is_here = 0;
	
	for (int j = 0; j != *len_lot; ++j){
		//Проверка на наличие в массиве
		if (lot[j] == n){
			is_here = 1;
			break;
		}
	}
			
	//Добавляет в массив если этого числа не было в списке
	if (is_here == 0){
		lot[*len_lot] = n;
		 *len_lot += 1;
	}
	is_here = 0;
}

//Выводит множество
void printLotI(int *lot, int len_lot){
	for (int i = 0; i != len_lot; ++i)
			printf("%d ", lot[i]);
		printf("\n");
}
