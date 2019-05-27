#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "Matrix.h"
#include "Vector.h"

class Equation
{
public:
	int EquIndex;
	bool HasSqrt;
	std::vector<std::string> original;
	std::vector<std::string> postEqu;
	std::vector<std::string> changeEqu;
	double phi = (1 + sqrt(5)) / 2;
	double resphi = 2 - phi;
	double FunctionValue(double, double, int);
	double GoldenSearch(double, double, double);
	Equation();
	void CheckSqrt();
	std::string ChangeEq(std::string, std::string);
	// differential
	double dif_x(double, int, double);
	double dif_xx(double, int, double);
	double dif_xxx(double, int, double);
	// Partial differential
	double pdf_x(double, double, int, double);
	double pdf_y(double, double, int, double);
	double pdf_xx(double, double, int, double);
	double pdf_yy(double, double, int, double);
	double pdf_xy(double, double, int, double);
	// Hessian
	Matrix hessian;
	void getHessian(double, double);
	// Gradiant
	Vector gradient(double, double, int, int);
};