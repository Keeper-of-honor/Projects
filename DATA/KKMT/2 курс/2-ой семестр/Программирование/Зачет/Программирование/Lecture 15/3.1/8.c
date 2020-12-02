#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct ClockFace{
	char min;
	char h;
	int *day;
} Ctime;

int main(){
	Ctime timer_1, timer_2;
	int date =  8;

	timer_1.h = 11;
	timer_1.min = 23;
	timer_1.day = &date;

	timer_2.h = 22;
	timer_2.min = 34;
	timer_2.day = &date;

	printf("timer 1: %02d %02hhd:%02hhd\n", *(timer_1.day), timer_1.h, timer_1.min);
        printf("timer 2: %02d %02hhd:%02hhd\n\n", *(timer_2.day), timer_2.h, timer_2.min);

	date++;

	printf("timer 1: %02d %02hhd:%02hhd\n", *(timer_1.day), timer_1.h, timer_1.min);
	printf("timer 2: %02d %02hhd:%02hhd\n", *(timer_2.day), timer_2.h, timer_2.min);

	return 0;
}
