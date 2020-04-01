#include "jacobi.h"

Jacobi::Jacobi(uint dim) : Matrix(dim) {}

void Jacobi::solveJacobi()
{
	vector<double> TempX(n);
	double norm; 
	vector<double> X(initStartAppr());
	do {
		for (int i = 0; i < n; i++) {
			TempX[i] = barr[i];
			for (int g = 0; g < n; g++) {
				if (i != g)
					TempX[i] -= matrix[i][g] * X[g];
			}
			TempX[i] /= matrix[i][i];
		}
		norm = fabs(X[0] - TempX[0]);
		for (int h = 0; h < n; h++) {
			if (fabs(X[h] - TempX[h]) > norm)
				norm = fabs(X[h] - TempX[h]);
			X[h] = TempX[h];
		}
	} while (norm > eps);
	xsol.clear();
	xsol = X;
}

void Jacobi::displaySol()
{
	for (uint i = 0; i < n; i++) 
		cout << "x" << i + 1 << " = " << setw(7) << xsol[i] << "\n";
}

vector<double> Jacobi::initStartAppr()
{
	vector<double> temp;
	for (uint i = 0; i < n; i++) {
		if (matrix[i][i] == 0)
			temp.push_back(0);
		else
			temp.push_back(barr[i] / matrix[i][i]);
	}
	return temp;
}
