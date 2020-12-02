#ifndef FUNC_H
#define FUNC_H

using namespace std;

struct List1{
	bool doc;
	std::string last_name;
};
struct List2{
	bool doc;
	std::string last_name;
	char assessment;
};

typedef std::vector <List1> vList1;
typedef std::vector <List2> vList2;

//1. Отправить студента на сдачу
void appList(vector <List1> &vList1);
//2. Студент сдал
void passStudent(vector <List1> &vList1, vector <List2> &vList2);
//3. Список сдающих
void
//4. Список сдавших
void

