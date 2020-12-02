#include <stdio.h>
#include <stdlib.h>
// Конец мантры

struct Date
{
    int year;
    char month;
    char day;
};

int main(){
    //объявляем переменную типа struct Date
    struct Date oneDay;
    struct Date *ptrDate;
    int days = 0;

    scanf("%d%hhd%hhd",&(oneDay.year), &(oneDay.month), &(oneDay.day));
    ptrDate = &oneDay;
    days += ptrDate->year * 12 * 30;
    days += ptrDate->month * 30;
    days += ptrDate->day;
    printf("oneDay: %04d.%02hhd.%02hhd\n",ptrDate->year, ptrDate->month, ptrDate->day);

    printf("дней с начала отсчета: %d\n",days);
    return 0;
}
