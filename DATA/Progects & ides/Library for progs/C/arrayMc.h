// Для ввода массива
void scanfA(int mas[], int n){
	printf("Введите массив: ");
	for (int i = 0; i != n; ++i)
		scanf("%d", &mas[i]);
}

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

// Для вывода массива
void printA(int mas[], int n){
	for(int i = 0; i != n; ++i)
		printf("%d ", mas[i]);
	printf("\n");
}
