#include <stdio.h>

void menu(){
	printf("\n");
	printf("0. Выход\n");
	printf("1. Цикл for\n");
	printf("2. Цикл while\n");
	printf("3. Цикл do...while\n");
	printf("\n");
}

int main(){
	char start = 0;
	char finish = 10;

	char i;

	int n = -1;
	while (n != 0){
		menu();
		scanf("%d", &n);

		if (n == 1)
			for (i = start; i < finish; ++i)
				printf("%d ", i);

		else if (n == 2){
			i = start;
			while (i != finish){
				++i;
				printf("%d ", i);
			}
		}

		else if (n == 3){
			i = start;
			do{
				++i;
				printf("%d ", i);
			} while (i != finish);
		}

		else if (n != 0)
			printf("Диапазон 0..3");
		printf("\n");
	}

	return 0;
}
