#include <stdio.h>
#include <stdlib.h>

typedef struct Time{
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
} Timer;

void printTime(Timer a){	//Вывод
    printf("%02hhu:%02hhu:%02hhu\n", a.hour, a.min, a.sec);
};

int time2usec(Timer t) {	//Перевод в секунды
    int res = t.hour * 60 + t.min;
    res = (res * 60 + t.sec) % (24 * 60 * 60);
    return res;
}
Timer usec2time(int sec) {	//Перевод из секунд в структуру (часы/минуты/секунды)
    Timer t;
    t.sec = sec % 60;
    sec = sec / 60;     
    t.min = sec % 60;
    sec = sec / 60;     
    t.hour = sec % 60;
    return t;
}

int main(){
    Timer t1, t2;
    int res;
    scanf("%hhu:%hhu:%hhu", &(t1.hour), &(t1.min), &(t1.sec));
    scanf("%hhu:%hhu:%hhu", &(t2.hour), &(t2.min), &(t2.sec));

    res = time2usec(t2) - time2usec(t1);
    if (res < 0)
	    res += (24 * 60 * 60);

    printTime(usec2time(res));
    return 0;
}
