#include <stdio.h>


int stringStat(const char *string, size_t multiplier, int *count){
	++(*count);
	size_t len_str = 0;
	while (string[len_str] != '\0')
		++len_str;

	return len_str * multiplier;
}

void bye(const char *name){
	printf("Bye %s\n", name);
}
