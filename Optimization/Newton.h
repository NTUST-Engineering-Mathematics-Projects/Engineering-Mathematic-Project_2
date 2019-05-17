#pragma once
#include <iostream>
#include <vector>
#include <string>
#define THRESOLD 10E-8

class Newton
{
public:
	struct Hessian
	{
		std::vector<std::vector<double>> Matrix;
	};
	std::vector<std::string> original;
	std::vector<std::vector<std::string>> PostEq;

};