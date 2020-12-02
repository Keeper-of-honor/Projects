#include <stdio.h>
#include <stdlib.h>
#define NDAYS 30
#define NYEARS 12

struct Date{
    long year;
    char month;
    char day;
};

int main(){ 
    struct Date startDay;
    struct Date newDay;
    int days;
    long y;
    char m,d;
    scanf("%ld%hhd%hhd", &y, &m, &d);

    startDay.year = y;
    startDay.month = m;
    startDay.day = d;
    newDay = startDay;

    printf("newDay: %04ld : %02hhd : %02hhd\n", newDay.year, newDay.month, newDay.day);

    scanf("%d", &days);
    newDay.day += days;
    newDay.day %= NDAYS;
    m = startDay.month + (newDay.day + days) / NDAYS;
    newDay.month += m - 1;
    newDay.month %= NYEARS;
    ++newDay.month;
    newDay.year += m / NYARS ;

    printf("newDay: %04ld : %02hhd : %02hhd\n",newDay.year, newDay.month, newDay.day);

    return 0;
}
