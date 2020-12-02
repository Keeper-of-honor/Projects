/** Param60*/

#include "tdate.h"

///Високосный / не високосный год
bool leap_year(unsigned int year){
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

///Сколько дней в месяце
unsigned int tdate::days_in_month(){
	bool l_year = leap_year(year);
	if ((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0))
		return 31;
	else if (l_year == 1 && month == 2)
		return 29;
	else if (l_year == 0 && month == 2)
		return 28;
	else
		return 30;
}
