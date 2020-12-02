/**Отрезок в пространстве задается координатами точек своих концов. Все координаты - целые числа, не превышающие 10^4.

Требуется вычислить длину этого отрезка с точностью до второго знака после запятой.*/

#include <stdio.h>
#include <math.h>

typedef struct Coord{
	short int x;
	short int y;
	short int z;
} Point;

typedef struct LineSegment{
	Point a;
	Point b;
	float distance;
} Line;

int main(){
	Line lin;

	printf("Вводим a:\na.x = ");
	scanf("%hd",&lin.a.x);
	printf("a.y = ");
	scanf("%hd",&lin.a.y);
	printf("a.z = ");
	scanf("%hd",&lin.a.z);

	printf("\nВводим b:\nb.x = ");
	scanf("%hd",&lin.b.x);
	printf("b.y = ");
	scanf("%hd",&lin.b.y);
	printf("b.z = ");
	scanf("%hd",&lin.b.z);

	lin.distance = sqrtf(powf(lin.a.x - lin.b.x, 2) + powf(lin.a.y - lin.b.y, 2) + powf(lin.a.z - lin.b.z, 2));

	printf("\nlin: a(%d, %d), b(%d, %d), z(%d, %d) => %0.2f\n", lin.a.x, lin.a.y, lin.b.x, lin.b.y, lin.a.z, lin.b.z, lin.distance);

	return 0;
}
