/**
 1. Используя typedef, определить новые имена для всехстандартных типов. Объявить несколько переменных новых типов данных, задать им значения, вывести на экран.
 */

#include <iostream>

using namespace std;

///Целочисленные типы

typedef char Ch;
typedef short Sint;
typedef int Mint;
typedef long Lint;
typedef long long LLint;

///Безнаковые типы

typedef unsigned char Un_Ch;
typedef unsigned short Un_Sint;
typedef unsigned int Un_Mint;
typedef unsigned long Un_Lint;
typedef unsigned long long Un_LLint;

///Вещественные типы

typedef float SwimPoint;
typedef double LSwimPoint;
typedef long double LLSwimPoint;

int main(){
	cout << endl;
	cout << "Integer types" << endl
		<< "type \"char\" now called \"Ch\", sizeof = " << sizeof(Ch) << endl
		<< "type \"short\" now called \"Sint\", sizeof = " << sizeof(Sint) << endl
		<< "type \"int\" now called \"Mint\", sizeof = " << sizeof(Mint) << endl
		<< "type \"long\" now called \"Lint\", sizeof = " << sizeof(Lint) << endl
		<< "type \"long long\" now called \"LLint\", sizeof = " << sizeof(LLint) << endl
		<< endl;

	cout << "Unsigned types" << endl
		<< "type \"unsigned char\" now called \"Un_Ch\", sizeof = " << sizeof(Un_Ch) << endl
		<< "type \"unsigned short\" now called \"Un_Sint\", sizeof = " << sizeof(Un_Sint) << endl
		<< "type \"unsigned int\" now called \"Un_Mint\", sizeof = " << sizeof(Un_Mint) << endl
		<< "type \"unsigned long\" now called \"Un_Lint\", sizeof = " << sizeof(Un_Lint) << endl
		<< "type \"unsigned long long\" now called \"Un_LLint\", sizeof = " << sizeof(Un_LLint) << endl
		<< endl;

	cout << "Float types" << endl
		<< "type \"float\" now called \"SwimPoint\", sizeof = " << sizeof(SwimPoint) << endl
		<< "type \"double\" now called \"LSwimPoint\", sizeof = " << sizeof(LSwimPoint) << endl
		<< "type \"long double\" now called \"LLSwimPoint\", sizeof = " << sizeof(LLSwimPoint) << endl
		<< endl;
	return 0;
}
