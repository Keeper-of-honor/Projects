//Выполнил: Герасимов Дмитрий
//Группа: П1-18


/**
Задача 2. (Составитель: Л.Гусятинер.  09.05.2006, Ковров, КГТА, ПМ и САПР)
Рассмотрим язык СтекЛО. ( STACK Language Ordinary ). Язык имеет 5 команд:
- var ( Объявление переменной ) - унарная
- let ( Присваивание значения ) - бинарная
- push( Втолкнуть ) - унарная
- pop( Вытолкнуть ) - унарная
- print( Печаать ) - унарная
В строке размещается только одна команда (с любой позиции). Могут быть пустые
  строки.
Возможны 4 вида ошибок
- переменная не объявлена;
- переменная не инициализирована;
- переполнение стека( при попытке выполнить команду push );
- стек пуст( при попытке выполнить команду pop ).

Имеется файл in.txt, хранящий строки
программы работы со стеком. stack - системная переменная, значение определяет
размер стека.
  Программа создает файлы Out.txt с результатами выполнения программы, trace.txt
( протокол работы )



	var <-- объявление переменной
	let <-- присваивание объявленной переменной
*/

#include <stdio.h>
#include <stddef.h>
#include "func.h"

#define LEN 50
#define MAXX 100000

int main(){
	//	{---- SYSTEM DATA ----}
	//Системные функции
	const char ST_func[LEN][LEN] = {"var", "let", "push", "pop", "print"};	//Системные функций
	const int ST_num_func = 5;	//Кол-во системных функций
	
	//Системные переменные
	const char ST_var[LEN][LEN] = {"stack"};	//Системные переменные
	const int ST_num_var = 1;	//Кол-во системных переменных
	
	int size_stack = 0;	//размер стека
	int stack[MAXX];	//стек
	int size_data_stack = 0; //сколько данных в стека
	
	//.............................


	//	{---- WORKING WHITH FILES ----}
	//Файл входа
	char namefile_i[LEN];
	printf("Enter name file input: ");
	scanf("%s", namefile_i);
	FILE *fin = fopen(namefile_i, "r");
	
	//Файл выхода
	char namefile_o[LEN];
	printf("Enter name file output: ");
	scanf("%s", namefile_o);
	FILE *fout = fopen(namefile_o, "w");
	
	//Файл перевода
	char namefile_t[LEN];
	printf("Enter name file translate: ");
	scanf("%s", namefile_t);
	FILE *ftrans = fopen(namefile_t, "w");
	
	//.............................
	
	//Создаем массив структур, для ханения в ней данных
	int num_Vars = 0;	//Кол-во переменных
	Variable Vars[MAXX];	//Переменные
	
	//Данные пользователя
	char func_user[LEN];	//Функция пользователя
	char var_user[LEN];
	
	//Считываем файл в структуру
	int pos;
	while (fscanf(fin, "%s", func_user) != EOF){
		pos = 0;
		
		//Существует ли такая функция?
		pos = checkSTs(func_user, &ST_func[0][0], ST_num_func);
		
		//	{-- Error
		if (pos == -1){
			printf("Ошибка. Нет такой функции (%s)\n", func_user);
			fprintf(fout, "Ошибка. Нет такой функции (%s)\n", func_user);
			fprintf(ftrans, "Ошибка. Нет такой функции (%s)\n", func_user);
			break;
		}//	Error --}
		
		//	{-- var 
		else if (pos == 0){
			fscanf(fin, "%s", Vars[num_Vars].name);
			Vars[num_Vars].is_init = 0;
			
			++num_Vars;
		}//	var --}
		
		//	{-- let
		else if (pos == 1){
			fscanf(fin, "%s", var_user);
			
			int i_Var = checkVariable(var_user, Vars, num_Vars);
			if (i_Var != -1){	//Если переменная объявлена
				fscanf(fin, "%d", &Vars[i_Var].value);
				Vars[i_Var].is_init = 1;
				
				fprintf(ftrans, "%s = %d\n", Vars[i_Var].name, Vars[i_Var].value);
			}
				
			//Проверка на системную переменную
			else if (checkSTs(var_user, &ST_var[0][0], ST_num_var) != -1 ){	//Если это системная переменная
				int new_size_stack;
				fscanf(fin, "%d", &new_size_stack);	//Ввод размера стека
				
				//Если новый размер меньше, то элементы удаляются 
				if (new_size_stack < size_stack){
					int difference_size = size_stack - new_size_stack;
					for (int i = 0; i != difference_size; ++i)
						stack[i] = stack[i+1];
				}
				
				size_stack = new_size_stack;	//Заменяем размеры
				
				fprintf(ftrans, "stack = []\n");
			}
			
			//Переменная не объявленна
			else{
				printf("Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(fout, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(ftrans, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				break;
			}
		}//	let --}
		
		//	{-- push
		else if (pos == 2){
			//Переполнение стека
			if (size_stack == size_data_stack){
				printf("Ошибка. Stack переполнен\n");
				fprintf(fout, "Ошибка. Stack переполнен\n");
				fprintf(ftrans, "Ошибка. Stack переполнен\n");
				break;
			}
			
			fscanf(fin, "%s", var_user);	//Ввод переменной пользователя
			int i_Var = checkVariable(var_user, Vars, num_Vars);	//Существует ли такая переменная
			//Переменная не объявленна
			if (i_Var == -1){
				printf("Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(fout, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(ftrans, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				break;
			}
			//Добавляем элемент в стек
			for (int i = size_data_stack; i > 0 ; --i){
				stack[i] = stack[i - 1];
			}
			stack[0] = Vars[i_Var].value;
			++size_data_stack;	//Увеличиваем кол-во чисел в стеке на 1
			
			//Вывод в файл trace.txt
			fprintf(ftrans, "stack = [");
			for (int i = 0; i != size_data_stack - 1; ++i)
				fprintf(ftrans, "%d, ", stack[i]);
			fprintf(ftrans, "%d]\n", stack[size_data_stack - 1]);
			
		}//	push --}
		
		//	{-- pop
		else if (pos == 3){
		
			//Стек пуст
			if (size_data_stack == 0){
				printf("Ошибка. Stack пуст\n");
				fprintf(fout, "Ошибка. Stack пуст\n");
				fprintf(ftrans, "Ошибка. Stack пуст\n");
				break;
			}
			
			fscanf(fin, "%s", var_user);	//Ввод переменной пользователя
			int i_Var = checkVariable(var_user, Vars, num_Vars);	//Существует ли такая переменная
			//Переменная не объявленна
			if (i_Var == -1){
				printf("Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(fout, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(ftrans, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				break;
			}
			
			//Удаляем элемент из стека
			--size_data_stack;	//Уменьшаем кол-во чисел в стеке на 1
			Vars[i_Var].value = stack[0];
			Vars[i_Var].is_init = 1;
			for (int i = 0; i != size_data_stack; ++i)
				stack[i] = stack[i+1];
				
			//Вывод в файл trace.txt
			fprintf(ftrans, "stack = [");
			for (int i = 0; i != size_data_stack - 1; ++i)
				fprintf(ftrans, "%d, ", stack[i]);
			fprintf(ftrans, "%d]\n", stack[size_data_stack - 1]);
			fprintf(ftrans, "%s = %d\n", Vars[i_Var].name, Vars[i_Var].value);
	
		}//	pop --}
		
		//	{-- print
		else if (pos == 4){
			
			fscanf(fin, "%s", var_user);	//Ввод переменной пользователя
			int i_Var = checkVariable(var_user, Vars, num_Vars);	//Существует ли такая переменная
			
			//Есть ли такая НЕ СИСТЕМНАЯ переменная
			if (i_Var != -1 && Vars[i_Var].is_init == 1){
				printf("%s = %d\n", Vars[i_Var].name, Vars[i_Var].value);	//Вывод элемента
				fprintf(fout, "%s = %d\n", Vars[i_Var].name, Vars[i_Var].value);	//Вывод элемента
				fprintf(ftrans, "%s = %d\n", Vars[i_Var].name, Vars[i_Var].value);	//Вывод элемента
			}
			//Есть ли такая СИСТЕМНАЯ ПЕРЕМЕННАЯ
			else if ( checkSTs(var_user, &ST_var[0][0], ST_num_var) != -1 ){	//Если это системная переменная
				printf("stack = ");
				fprintf(fout, "stack = ");
				for (int i = 0; i != size_data_stack; ++i){
					printf("%d ", stack[i]);
					fprintf(fout, "%d ", stack[i]);
					fprintf(ftrans, "%d ", stack[i]);
				}
				printf("\n");
				fprintf(fout, "\n");
				fprintf(ftrans, "\n");
			}
			//Переменная не объявленна
			else{
				printf("Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(fout, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				fprintf(ftrans, "Ошибка. Переменная (%s) не объявлена\n", var_user);
				break;
			}
		}//	print --}
	}
	
	
	return 0;
}
