/**
 3. Ввести с клавиатуры  номер дня недели. Вывести на экран его название. Использовать перечисления (enum)
 */

#include <iostream>

using namespace std;

enum Days{mon = 1, td, wd, thd, fd, st, sd = 0} day;

void dayWeek(Days day);

int main(){

	cout << "Enter the day number of the week " << endl;
	int n_day;
	cin >> n_day;
	
	Days day (n_day);
	dayWeek(day);

	return 0;
}

void dayWeek(Days day){
	switch (day % 7){
	case mon:
		cout << "Monday" << endl; break;
	case td:
		cout << "Tuesday" << endl; break;
	case wd:
		cout << "Wednasday" << endl; break;
	case thd:
		cout << "Thurday" << endl; break;
	case fd:
		cout << "Friday" << endl; break;
	case st:
		cout << "Saturday" << endl; break;
	case sd:
		cout << "Sunday" << endl; break;
	}
}
