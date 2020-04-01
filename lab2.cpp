#include <iostream>
#include "matrix.h"
#include "gauss.h"
#include "jacobi.h"
using namespace std;

int main()
{
	uint n;
	cout << "Enter matrix dimension: \n";
	if (!(cin >> n)) exit(900);
	n = 3;

	Gauss matr3{n};
	cin >> matr3;
	matr3.direct();
	cout << matr3;
	matr3.reverse();
	matr3.dispSol();

	/*Jacobi matr{ n };
	cin >> matr;
	matr.solveJacobi();
	matr.displaySol();*/

	Gauss matr{ n };
	cin >> matr;
	double norm = matr.getNorm();
	double det = matr.getDet();
	
	cout << "The determinant is: \n" << det << "\n";

	cout << "The inverse matrix is: \n";
	Gauss matr2{ matr.getInv(det) };
	cout << matr2;

	cout << "The condition number is: " << norm * matr2.getNorm();
	return 0;
}
