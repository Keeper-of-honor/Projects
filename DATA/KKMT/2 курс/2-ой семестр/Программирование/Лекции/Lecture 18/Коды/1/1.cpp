#include <iostream>
#define G 9.81

int main() {
	/*const double G = 9.81;*/
	double mass;
	std::cin >> mass; 

	double weight = mass * G;
	/*cout << "mass = " << mass;
	cout <<" weight = " << weight << endl;*/

	std::cout << "mass = " << mass << std::endl
         <<"weight = " << weight << std::endl;

	
	return 0;
}
