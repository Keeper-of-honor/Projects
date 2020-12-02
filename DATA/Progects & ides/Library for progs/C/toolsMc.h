//Сортировка пузырьком массива 
void sortA(int mas[], int n){
	int loc_n = n - 1;
	for (int i = 0; i != loc_n; ++i)
		for (int j = 0; j != loc_n - i; ++j)
			if (mas[j] > mas[j + 1]){
				int t = *a;
				*a = *b;
				*b = t;
			}
}

//Поменять местами значения переменных
void swapV(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
