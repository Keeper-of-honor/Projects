/** Proc50. Описать процедуру TimeToHMS(T, H, M, S), определяющую по времени T (в секундах) содержащееся в нем количество часов H, минут M и секунд S (T — входной, H, M и S — выходные параметры целого типа). Используя эту процедуру, найти количество часов, минут и секунд для пяти данных отрезков времени T1, T2, …, T5.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>

using namespace std;

void TimeToHMS(unsigned long time);

int main(){
	const int N = 5;

	unsigned long time;
	for (size_t i = 0; i != N; ++i){
		cout << i+1 << ". "<<"Input number of sec: ";
		cin >> time;
	
		TimeToHMS(time);
		cout << endl;
	}

	return 0;
}

void TimeToHMS(unsigned long time){
	unsigned long h, min, sec;
	h = time / 3600;
	min = time % 3600 / 60;
	sec = time % 60;

	cout << "Hours: " << h << endl
		<< "Minutes: " << min << endl
		<< "Seconds: " << sec << endl;
}
