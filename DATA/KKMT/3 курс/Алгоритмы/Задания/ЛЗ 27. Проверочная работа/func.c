#include "func.h"

#include <stdio.h>
#include "helpF.h"

#define LEN 50

//Проверка на системную данную (одну)
int checkST(const char var[], const char ST_func[]){
	//Длина функции пльзователя
	int len_var = lenStr(var);
	
	for (int i = 0; i < len_var; ++i)
		if (var[i] != ST_func[i])
			return 0;
	return 1;
}

//Проверка на системные данные
int checkSTs(const char var[], const char ST_func[], const int ST_num_func){
	//Длина функции пльзователя
	int len_var = lenStr(var);
	
	int is_func = 0;
	for (int i = 0; i != ST_num_func; ++i){
		for (int j = 0; j < len_var; ++j){
			if (var[j] == ST_func[i*LEN + j])
				is_func = 1;
			else
				is_func = 0;
		}
		if (is_func)
			return i;
	}
	
	return -1;
}

int checkVariable(const char var_user[], Variable *Vars, const int num_Vars){
	for (int i = 0; i != num_Vars; ++i)
		if( checkST(var_user, Vars[i].name) )
			return i;
	return -1;
	
}
