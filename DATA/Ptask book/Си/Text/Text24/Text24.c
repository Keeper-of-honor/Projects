/**Text24°. Дан текстовый файл. Найти количество абзацев в тексте, если абзацы отделяются друг от друга одной или несколькими пустыми строками.*/
#include <stdio.h>
#include <string.h>
#define MAXN 1000

int main(){
	FILE *fin = fopen("text.txt", "r");

	char c;
	char s[MAXN][MAXN];
	int count;
	int len_i,len_j;
	int i, j;

	count = 0;
	for (i = 0, j = 0; (c = fgetc(fin)) != EOF; j++){
		if (c == '\n'){
			s[i][j] = '\0';
			s[i][++j] = '\n';
			++i;
			j = 0;
			continue;
		}
		s[i][j] = c;
	}
	len_i = i;
	for (i = 0; i < len_i; ++i){
		len_j = strlen(s[i]);
		for (j = 0; j < len_j; ++j)
			putchar(s[i][j]);
		putchar('\n');
	}

	printf("%d\n", count);

	fclose(fin);

	return 0;
}
