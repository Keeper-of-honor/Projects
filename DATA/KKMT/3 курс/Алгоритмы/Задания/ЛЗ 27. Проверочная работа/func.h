#ifndef __FUNC__
#define __FUNC__

#define LEN 50

	#ifdef __cplusplus
	extern "C"
	#endif
struct Variable{
	char name[LEN];
	int value;
	char is_init;
};

typedef struct Variable Variable;

int checkST(const char var[], const char ST_func[]);
int checkSTs(const char var[], const char ST_func[], const int ST_num_func);	//Проверка на СИСТЕМНУЮ Функцию/Переменную

int checkVariable(const char var_user[], Variable *Vars, const int num_Vars);	//Проверка на объявление переменной

#endif 
