/**Text53. Дан текстовый файл. Создать символьный файл, содержащий все знаки препинания, встретившиеся в текстовом файле (в том же порядке).*/

#include <stdio.h>

struct znaks{
	int z1;
        int z2;
        int z3;
        int z4;
        int z5;
	int z6;
};


int main(){
	FILE *fin = fopen("in.txt","r");
	FILE *fout = fopen("out.txt","w");
	
	int c;
	struct znaks text = {0};
	while((c = fgetc(fin)) != EOF){
		if (c == '.' && text.z1 == 0){
			fprintf(fout, "%c", c);
			++text.z1;
		}
		else if (c == ',' && text.z2 == 0){
                        fprintf(fout, "%c", c);
                        ++text.z2;
                }
		else if (c == ':' && text.z3 == 0){
                        fprintf(fout, "%c", c);
                        ++text.z3;
                }
		else if (c == ';' && text.z4 == 0){
                        fprintf(fout, "%c", c);
                        ++text.z4;
                }
		else if (c == '!' && text.z5 == 0){
                        fprintf(fout, "%c", c);
                        ++text.z5;
                }
		else if (c == '?' && text.z6 == 0){
                        fprintf(fout, "%c", c);
                        ++text.z6;
                }
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
/**	10.04.20. 4-ая пара (Программирование)	*/
/**		Герасимов Дмитрий П1-18		*/

