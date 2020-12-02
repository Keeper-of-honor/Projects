#include <stdio.h>

typedef struct Time{
	unsigned char hour;
	unsigned char min;
	unsigned char sec;
} Timer;

void printTime(Timer a){
	printf("%02hhu:%02hhu:%02hhu\n", a.hour, a.min, a.sec);
};

Timer timeMinus(Timer a, Timer b){
	Timer tmp;
	unsigned char sec, min, h;

	h = a.hour - b.hour - 1;
	min = 60 + a.min - b.min - 1;
	sec = 60 + a.min - b.sec;

	tmp.sec = sec % 60;
	tmp.min = (min + sec / 60) % 60;
	tmp.hour = (h + min / 60) % 24;

	return tmp;
}

int main(){
	Timer t1, t2;
	Timer res;

	scanf("%hhu:%hhu:%hhu", &(t1.hour), &(t1.min), &(t1.sec));
	scanf("%hhu:%hhu:%hhu", &(t2.hour), &(t2.min), &(t2.sec));

	res = timeMinus(t1, t2);

	printTime(res);
	return 0;
}
