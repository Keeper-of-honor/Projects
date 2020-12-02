#include <stdio.h>

void hello_message(const char *name){
	printf("Hello %s!\n", name);
}

void bye_message(const char *name, const size_t num){
	for (size_t i = 0; i != num; ++i)
		printf("Bye %s!\n", name);
}
