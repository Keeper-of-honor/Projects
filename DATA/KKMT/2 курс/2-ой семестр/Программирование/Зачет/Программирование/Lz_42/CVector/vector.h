#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class CVector{
private:
	int N;
	double *px;
public:
	CVector(int n = 1);
	~CVector();
	void prn();
	void gen();
	double max();
};
#endif
