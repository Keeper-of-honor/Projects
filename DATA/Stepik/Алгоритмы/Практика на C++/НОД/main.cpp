//Создал: Герасимов Дмитрий 
//Дата: 02.12.2020
//Программа: НАИБОЛЬШИЙ ОБЩИЙ ДЕЛИТЕЛЬ (НОД)

//Для запуска введите в терминал:
//	make
//	make run

#include <iostream>
#include <cassert>

int64_t nod(int64_t a, int64_t b){
	assert(a > 0);
	
	if (b > 0)
		return nod(b, a % b);
	
	return a;
}

int main(){
	int64_t a, b;
	std::cin >> a >> b;
	std::cout << nod(a, b) << std::endl;

	return 0;
}
