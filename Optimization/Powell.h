#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <sstream>

class Powell
{
public:
	std::vector<std::string> original;
	std::vector<std::vector<std::string>> posteq;
	std::vector<std::string> GEquation;
	int EquationIndex;
	double phi = (1 + sqrt(5)) / 2;
	double resphi = 2 - phi;
	double GoldenSearch(double a, double b, double c);
	double FunctionValue(double x, double y, int set);
	std::string ChangeEq(std::string, std::string);
};
