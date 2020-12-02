/**Отрезок на плоскости задается координатами точек своих концов. Все координаты - целые числа, не превышающие 10^4.

Требуется вычислить длину этого отрезка с точностью до второго знака после запятой.*/

#include <stdio.h>
#include <math.h>

typedef struct Coords{
	short int x;
	short int y;
} Point;

typedef struct LineSegment{
	Point a;
	Point b;
	float distance;
} Line;

int main(){
	Line lin;
	
	printf("Input a.x: ");
	scanf("%hd", &lin.a.x);
	printf("Input a.y: ");
	scanf("%hd", &lin.a.y);
	
	printf("\n");
	
	printf("Input b.x: ");
	scanf("%hd", &lin.b.x);
	printf("Input b.y: ");
	scanf("%hd", &lin.b.y);
	
	lin.distance = sqrt(pow(lin.a.x - lin.b.x, 2) + pow(lin.a.y - lin.b.y, 2));
	
	printf("Output: distance = %0.2f\n", lin.distance);
	
	return 0;
}

void inputData(&lin){
	
}
