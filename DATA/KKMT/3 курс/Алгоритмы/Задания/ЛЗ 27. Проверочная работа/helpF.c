#include "helpF.h"

int lenStr(const char var[]){
	int len_var;
	for (len_var = 0; var[len_var] != '\0'; ++len_var)
		;
	return len_var;
}
