//Создал: Герасимов Дмитрий 
//Дата: 02.12.2020
//Программа: ЧИСЛО ФИБОНАЧИ

//Для запуска введите в терминал:
//	make
//	make run

#include <iostream>
#include <cassert>

unsigned long fib(long n){
	assert(n > -1);
	
	if (n < 2)
		return n;
	unsigned long prev = 0;
	unsigned long cur = 1;
	for (long i = 2; i <= n; ++i){
		unsigned  long new_cur = prev + cur;
		prev = cur;
		cur = new_cur;
	}
	
	return cur;
}

int main(){
	long n;
	std::cin >> n;
	std::cout << fib(n) << std::endl;

	return 0;
}
