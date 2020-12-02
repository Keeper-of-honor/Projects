/** Команда состоит из 3-х человек: Груздев Роман, Герасимов Дмитрий, Пётр Митюшин.
П1-18, 05.06.2020 г.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "func.h"

using namespace std;

// 1.Загрузить из файла
void load(vNom &v) {
    string fname;
    cout << "Введите название файла (с его расширением): ";
    cin >> fname; 
    cout << endl;
    Nomination nom;
    ifstream in(fname);

	if(!(in.is_open()))
		cout << "Файла с таким именем или расширением - нет :(" << endl << endl;
	else{	
    	char delim;
	short outb;
	cout << "0. Добавить файл с данными в вектор" << endl 
		<< "1. Опустошить вектор с данными " << endl;
	cin >> outb;

	if(outb)	
    		v.clear();
    	while (in >> nom.nom_id >> nom.name >> nom.pr >> nom.date.day >> delim >> nom.date.month
		 		>> delim >> nom.date.year >> nom.cost >> nom.t >> nom.number){
			v.push_back(nom);
    	}
		cout << "Файл успешно загружен!" << endl << endl;
	}

	in.close();
	
}

// 2.Выгрузить в файл
///Для определения табуляций (используется в 2,7,8)
void numCh(string s1, string &t1, string s2, string &t2){
	char num = s1.size();
	//t1
	if (num > 7)
		t1 = "\t";
	else
		t1 = "\t\t";
	//t2
	if ((s2.size() + num) > 9)
		t2 = "\t";
	else
		t2 = "\t\t";	
}
//input.txt
void save(vNom &v){
	string fname_o;
	cout << "Введите название файла(с его расширением) в которой будет выгружен вектор: ";
	cin >> fname_o;
	ofstream out(fname_o, ios::app);

	string t1, t2;
	for(size_t i = 0; i != v.size(); i++){
		numCh(v[i].name, t1, v[i].pr, t2);
		out << v[i].nom_id << "  \t"
			<< v[i].name << "  " << t1
			<< v[i].pr << "   " << t2
			<< v[i].date.day << "." << v[i].date.month << "." << v[i].date.year << "  \t"
			<< v[i].cost << "\t\t"
			<< v[i].t << "\t"
			<< v[i].number << endl;
	}
	out << endl;	
}

// 3.Добавить новую строку (наименование)
void append(vNom &v){
	cout << "Добавить новое изделие(пример: ID\\Наименование изделия\\Производитель\\Дата\\Стоимость\\Есть ли на складе\\Количество):" << endl;
	Nomination nom;
	char delim;
        while(cin >> nom.nom_id >> nom.name >> nom.pr >> nom.date.day >> delim >> nom.date.month >> 		delim >> nom.date.year >> nom.cost >> nom.t >> nom.number){

        v.push_back(nom);
	break;
	}
	cout << endl;
}

// 4.Редактировать строку (наименование)
void edit(vNom &v){
	cout << "Какую строку надо отредактировать? - ";
	size_t ix;
	cin >> ix;
	cout << endl;
	int i_x = -1;

    while(i_x){
	cout << "0. Выход" << endl
	<< "1. Редактировать номер наименования" << endl
	<< "2. Редактировать название наименования" << endl
	<< "3. Редактировать производителя" << endl
	<< "4. Редактировать дату производства" << endl
	<< "5. Редактировать стоимость наименования" << endl
	<< "6. Редактировать наличие наименования на складе" << endl 
	<< "7. Редактировать количество наименования" << endl;
	cout << "Введите нужный пункт подменю: ";
	cin >> i_x;
	cout << endl;
	if (i_x > 7 || i_x < 0)
			cout << "Error. Диапазон меню: 0..7" << endl;
	else if(i_x == 1){
		int ed_id;
		cin >> ed_id;
		v[ix - 1].nom_id = ed_id;
		cout << endl; }
	else if(i_x == 2){
		string ed_name;
		cin >> ed_name;
		v[ix - 1].name = ed_name;
		cout << endl; }
	else if(i_x == 3){
		string ed_pr;
		cin >> ed_pr;
		v[ix - 1].pr = ed_pr;
		cout << endl; }
	else if(i_x == 4){
		Date data;
		char sign;
		cin >> data.day >> sign >> data.month >> sign >> data.year;
			v[ix - 1].date = data;
		cout << endl; }
	else if(i_x == 5){
		double ed_cost;
		cin >> ed_cost;
		v[ix - 1].cost = ed_cost;
		cout << endl; }
	else if(i_x == 6){
		bool ed_t;
		cin >> ed_t;
		v[ix - 1].t = ed_t;
		cout << endl; }
	else if(i_x == 7){
		int ed_number;
		cin >> ed_number;
		v[ix - 1].number = ed_number;
		cout << endl; }
	
	}


	
}

// 5.Удалить строку (наименование)
void del(vNom &v){
	cout << "Какую строку хотелось бы удалить? - ";
	size_t idx;
	cin >> idx;
	v.erase(v.begin() + (--idx));
	cout << endl << "Строка удалена!" << endl;
}

// 6.Сортировать по дате производства
bool comp_year (const Nomination& a, const Nomination& b) { return (a.date.year < b.date.year); }

bool comp_month (const Nomination& a, const Nomination& b) { return (a.date.month < b.date.month); }

bool comp_day (const Nomination& a, const Nomination& b) { return (a.date.day < b.date.day); }

void sort(vNom &v){

	sort(v.begin(), v.end(), comp_day);
	sort(v.begin(), v.end(), comp_month);
	sort(v.begin(), v.end(), comp_year);
	cout << "Сортировка была произведена!" << endl << endl;
	
}

// 7.Выдать общий список
void print_all(vNom v){
	cout << "№ str\tID\tНаименование\tПроизводитель\tДата\t\tСтоимость\tЕсть ли на складе\tКоличество\n";
	string t1, t2;
	for(size_t i = 0; i != v.size(); i++){
		numCh(v[i].name, t1, v[i].pr, t2);
		cout << i + 1 << " \t" << v[i].nom_id << "  \t"
			<< v[i].name << "  " << t1
			<< v[i].pr << "   " << t2
			<< v[i].date.day << "." << v[i].date.month << "." << v[i].date.year << "  \t"
			<< v[i].cost << "\t\t\t"
			<< v[i].t << "	\t"
			<< v[i].number << endl;
	}
	cout << endl;		
}

// 8. Выдать максимум и минимум по количеству или стоимости

//Макс для количества
void maxx1(vNom v, size_t &index){
	size_t num_v = v.size();
	int elem_max = v[0].number;
	for (size_t i = 0; i < num_v; ++i){
    	if (v[i].number > elem_max){
            elem_max = v[i].number;
            index = i;
        }
    }
}
//Макс для стоимости
void maxx2(vNom v, size_t &index){
	size_t num_v = v.size();
	int elem_max = v[0].cost;
	for (size_t i = 0; i < num_v; ++i){
    	if (v[i].cost > elem_max){
            elem_max = v[i].cost;
            index = i;
        }
    }
}

//Мин для количества
void minn1(vNom v, size_t &index){
	size_t num_v = v.size();
	int elem_min = v[0].number;
	for (size_t i = 0; i < num_v; ++i){
    	if (v[i].number < elem_min){
            elem_min = v[i].number;
            index = i;
        }
    }
}
//Мин для стоимости
void minn2(vNom v, size_t &index){
	size_t num_v = v.size();
	int elem_min = v[0].cost;
	for (size_t i = 0; i < num_v; ++i){
    	if (v[i].cost < elem_min){
            elem_min = v[i].cost;
            index = i;
        }
    }
}

//Общая
void allMM(vNom v, int k){
    size_t index = 0;
	string t1, t2;
	
	if (k == 1)
		maxx1(v, index);
	else if (k == 2)
		maxx2(v, index);
	else if (k == 3)
		minn1(v, index);
	else
		minn2(v, index);		

	numCh(v[index].name, t1, v[index].pr, t2);
    cout << v[index].nom_id << "  \t"
			<< v[index].name << "  " << t1
			<< v[index].pr << "   " << t2
			<< v[index].date.day << "." << v[index].date.month << "." << v[index].date.year << "  \t"
			<< v[index].cost << "\t\t"
			<< v[index].t << "\t"
			<< v[index].number << endl
			<< endl;
}

//Главная
void maxxMinn(vNom v){
    int k = -1;
	while(k){
		cout << "0. Выход" << endl
				<< "1. Максимум по количеству" << endl
				<< "2. Максимум по стоимости" << endl
				<< "3. Минимум по количеству" << endl
				<< "4. Минимум по стоимости" << endl
				<< endl;
		cin >> k;
		if (k > 4 || k < 0)
			cout << "Error. Диапазон меню: 0..4" << endl;
		else if (k)
			allMM(v, k);
	}
}










