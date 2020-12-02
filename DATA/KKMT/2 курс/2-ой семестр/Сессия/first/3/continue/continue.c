#include <stdio.h>

int main(){
int i = 0;
while(i < 100){
	if(i%2){
		i += 3;
		printf("%d ", i);
		continue;
	}
	++i;
}
printf("\n");

return 0;
} 
