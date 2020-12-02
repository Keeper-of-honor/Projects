/**В механическом календаре всего 360 дней в году. Все дни поделены на месяцы (с 1 по 12), в каждом месяце - 30 дней (с 1 по 30).

Сначала на календаре была дата: year - год (0 ≤ y0 ≤ 9999), month - месяц (1 ≤ m0 ≤ 12), day - день (1 ≤ m0 ≤ 30). Если меняется последний день последнего месяца последнего года, то новый год становится нулевым.

Прошло days дней (0 ≤ y0 ≤ 10^6). */

#include <stdio.h>

struct Date{
	int year;
	char month;
	char day;
};

int main(){
	struct Date oneDay;
	struct Date *ptrDate;
	int days = 0;
	scanf("%d%hhd%hhd",&(oneDay.year), &(oneDay.month), &(oneDay.day));

	ptrDate = &oneDay;
	days += ptrDate->year * 12 * 30;
	days += ptrDate->month * 30;
	days += ptrDate->day;

	printf("oneDay: %04d.%02hhd.%02hhd\n",ptrDate->year,ptrDate->month, ptrDate->day);
	printf("дней с начала отсчета: %d\n", days);

	return 0;
}
