//Логарифм. Доработать, для отрицательного и если число не является чатью этого числа.
int logV(int n, int base){
	int count = 0;
	if (n != 1)
		for (int i = n; i != 1; i /= base)
			++count;
	return count;
}

//Возвращает тип double, чтобы не было переполнения
double factV(int n){
	double fn = 1;
	for (int i = 2; i <= n; ++i)
		fn *= i;
	return fn;
}
