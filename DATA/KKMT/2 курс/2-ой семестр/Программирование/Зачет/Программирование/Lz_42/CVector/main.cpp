#include <iostream>
#include "vector.h"

int main(){
	srand(time(nullptr));
	CVector massiv(3);
	massiv.gen();
	massiv.prn();

	cout << "max = " << massiv.max();

	return 0;
}

