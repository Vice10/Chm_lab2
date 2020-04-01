#pragma once
#include "matrix.h"
#include <math.h>
#include <iomanip>
const double eps = 0.01;
class Jacobi :
	public Matrix
{
public:
	Jacobi(uint dim);
	void solveJacobi();
	void displaySol();
private:
	vector<double> xsol;
	vector<double> initStartAppr();
};

