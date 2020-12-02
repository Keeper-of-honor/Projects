#include <stdio.h>

typedef struct Termin{
	unsigned char day;
	unsigned char month;
	unsigned int year;
} Date;

void printDate(Date a){
	printf("%04u-%02hhu-%02hhu\n", a.year, a.month, a.day);
}

void getDate(Date* b){
        scanf("%04u-%02hhu-%02hhu\n", &(b->year), &(b->month), &(b->day));
}

int main(){
	Date dt;
	getDate(&dt);

	printDate(dt);

	return 0;
}
