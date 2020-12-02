/*указатель на переменную можно назвать другим именем (явно указав в имени, что это указатель: intPtr - указатель на int):*/

#include <stdio.h>
#include <stdlib.h>

typedef int* intPtr;

int main(){
	int a;
	intPtr pa;
	pa = &a;
	scanf("%d",pa);

	printf("a = %d\n", a);

	return 0;
}
