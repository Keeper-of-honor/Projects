#include <stdio.h>
#include "solution.h"

int main(){
	char *str = "bruh";
	size_t multiplier = 2;
	int count = 1;
	
	printf("%d\n", stringStat(str, multiplier, &count) );
	printf("%d\n", stringStat(str, multiplier, &count) );
	bye(str);

	return 0;
}
