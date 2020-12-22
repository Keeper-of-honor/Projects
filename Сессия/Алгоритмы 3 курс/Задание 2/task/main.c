//Выполнил: Герасимов Дмитрий
//Группа: П1-18

/*
Л1. Вычислить s=1^2+3^2+5^2+...+n^2, n - нечетное 
число
*/

#include <stdio.h>

int main(){
	int i, n;
	double s;
	
	scanf("%d", &n);
	s = 0;
	for (i = 1; i <= n; ++i)
		if (i % 2 != 0)
			s = s + i * i;
	printf("s=%lf\n", s);

	return 0;
}

