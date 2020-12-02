#include "vector.h"

CVector::CVector(int n){
	N = n;
	px = new double (n);
}
CVector::~CVector(){
	delete []px;
}

void CVector::gen(){
	for (size_t i = 0; i != N; ++i)
		px[i] = double(rand()) / RAND_MAX * 5;
}

void CVector::prn(){
	for (size_t i = 0; i != N; ++i)
		cout << px[i] << ' ';
	cout << endl;
}

double CVector::max(){
	double M;
	M = *px;
	for (size_t i = 1; i != N; ++i)
		if (px[i] > M)
			M = px[i];
	return M;
}
