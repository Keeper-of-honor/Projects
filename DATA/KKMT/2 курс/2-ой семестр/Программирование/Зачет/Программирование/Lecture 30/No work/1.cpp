#include <iostream>
#include <cmath>

using namespace std;

class Diff{
public:
	unsigned int difference(Date first, Date second){
		int all_year = 0;
		if (first.year - second.year)
			all_year = first.year - second.year;
		int all_month = 0;
		if (first.month - second.month)
			all_month = first.month - second.month;
		int all_day = 0;
		if (first.day - second.day)
			all_day = first.day - second.day;

		return fabs(all_day) + fabs(30 * all_month) + fabs(30 * 12 * all_year);
	}
};

int main(){
	Date today;
	inSet(today);

	Date other_day;
	inSet(other_day);

	Diff gdiff;
	gdiff.difference(today, other_day);
	
	cout << "Difference between dates: " << gdiff << " day(-s)" << endl;

	return 0;
}

struct Date{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

void inSet(Date data){
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter month: ";
	cin >> Date.month;
	cout << "Enter year: ";
	cin >> Date.year;
}
