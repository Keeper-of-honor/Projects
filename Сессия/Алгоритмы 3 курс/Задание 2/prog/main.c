//Выполнил: Герасимов Дмитрий
//Группа: П1-18

/*
Л1. Вычислить s=1^2+3^2+5^2+...+n^2, n - нечетное 
число
*/

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	double s = 1;
	
	if (n < 1)
		s = 0;
		
	for (int i = 3; i <= n; i += 2)
		s += i*i;
	
	printf("s=%lf\n", s);
	
	return 0;
}

