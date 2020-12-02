/**
Text6. Даны два текстовых файла. Добавить в конец первого файла содержимое второго файла.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string in_file;	//bruh.txt
	string out_file; //text.txt

	cout << "Input name file for input: ";
	cin >> in_file;
	cout << "Output name file for output: ";
	cin >> out_file;
	ifstream input(in_file);
	ofstream output(out_file, ios::app);

	string text;
	while (getline(input,text))
		output << text << endl;
		
	input.close();
	output.close();

	return 0;	
}
