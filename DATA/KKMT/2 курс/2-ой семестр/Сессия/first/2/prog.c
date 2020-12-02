#include <stdio.h>

void menu(){
	printf("\n");
	printf("1. If\n");
	printf("2. Switch case\n");
	printf("\n");
}

int main(){
	char n = -1;
	menu();
	scanf("%c", &n);
	getchar();

	printf("1+1 = ?\n");
	printf("1. = 2\n");
	printf("2. = 4\n");
	printf("3. = 8\n");
	printf("4. = bruh\n\n");
	char answer;
	scanf("%c", &answer);	

	if (n == '1'){
		if (answer == '1')
			printf("True\n");
		else
			printf("bruh\n");
	}

	else if (n == '2'){
		switch(answer){
		case '1':
			printf("True\n"); break;
		default:
			printf("bruh\n");
		}
	}
	else
		printf("bruh\n");
		

	return 0;
}

