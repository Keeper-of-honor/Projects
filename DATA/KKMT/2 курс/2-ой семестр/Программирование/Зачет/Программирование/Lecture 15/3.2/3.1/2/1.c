#include <stdio.h>
#include <stdlib.h>

struct Date{
    int year;
    char month;
    char day;
};

int main(){ 
    struct Date startDay;
    int a;
    char b,c;
    scanf("%d%hhd%hhd",&a,&b,&c);

    startDay.year = a;
    startDay.month = b;
    startDay.day = c;
    printf("%04d.%02hhd.%02hhd\n",startDay.year, startDay.month, startDay.day);

    return 0;
}
