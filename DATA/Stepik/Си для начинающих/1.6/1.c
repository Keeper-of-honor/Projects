#include <stdio.h>

int main(){
	int N;
	int dedl, dedDays;
	int babl, babDays;
	int dedOne;
	int babOne;
	int result;

	scanf("%d%d",&dedl, &dedDays);
	scanf("%d%d",&babl, &babDays);
	scanf("%d", &N);

	dedOne = dedl / dedDays;
	printf("Дед за день:\t%d\n",dedOne);

	babOne = babl / babDays;
	printf("Бабка за день:\t%d\n",babOne);

	result = (dedOne + babOne) * N;
	printf("All:\t%d\n",result);

	return 0;
}
