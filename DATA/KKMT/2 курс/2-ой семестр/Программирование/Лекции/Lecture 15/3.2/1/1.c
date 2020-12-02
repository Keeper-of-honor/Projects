#include <stdio.h>

typedef struct Termin{
	unsigned char day;
	unsigned char month;
	unsigned int year;
} Date;

void printDate(Date a){
	printf("%04u-%02hhu-%02hhu\n", a.year, a.month, a.day);
};

int main(){
	Date dt;
	scanf("%u%hhu%hhu", &(dt.year), &(dt.month), &(dt.day));
	printDate(dt);

	return 0;
}


