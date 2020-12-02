/**
 5. Написать программу, демонстрирующую утечку памяти.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
using namespace std;

int main(){
    int *pi = new int;
	*pi = 4387 + 742;
	pi = new int;
	*pi = 32 - 13142;
	cout << "digit: " << *pi << endl;

	// Кажется появилась протечка памяти

   return 0;
}
