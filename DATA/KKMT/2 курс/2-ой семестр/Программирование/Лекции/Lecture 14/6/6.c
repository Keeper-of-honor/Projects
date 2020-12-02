#include <stdio.h>

typedef struct Coord{
	int x;
	int y;
}Point;

int main(){
	Point coord = {7,5};
	Point *directPoint;
	int *px, *py;

	directPoint = &coord;
	px = &(coord.x);
	py = &(coord.y);
	printf("Адрес px: %p | значение: %d\n", px, coord.x);
	printf("Адрес py: %p | значение: %d\n", py, coord.y);
	
	px = &(directPoint->x);
	py = &(directPoint->y);
	printf("Адрес px: %p | значение: %d\n", px, coord.x);
	printf("Адрес py: %p | значение: %d\n", px, coord.y);

	scanf("%d%d", &(coord.x), &(coord.y));

	printf("scanf coord.x: %d\n", coord.x);
	printf("scanf coord.y: %d\n", coord.y);

	return 0;
}
