#ifndef LOT_H
#define LOT_H

//{--------STRING--------}
//void lotAddS(int lot[], int *len_lot, int n);	//Добавить элемент в множество (STRING)
void printLotS(char *lot, int len_lot);	//Вывод множества (STRING)

//{--------INT--------}
void lotAddI(int lot[], int *len_lot, int n);	//Добавить элемент в множество (INT)
void printLotI(int *lot, int len_lot);	//Вывод множества (INT)

#endif
