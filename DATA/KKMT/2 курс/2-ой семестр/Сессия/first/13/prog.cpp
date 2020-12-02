#include <iostream>
#include <cstring>

using namespace std;

int main(){
char s1[100] = "Hello";
	cout << strlen(s1)<<endl; //длина
char s2[] = ", world!";
char s3[6] = {72,101,108,108,111};
	if(strcmp(s1,s3)==0)
		cout<<"s1 = s3" << endl;
cout << s1 << endl
	<< s2 << endl
	<< s3 << endl;

return 0;
}
