#pragma once
#include <iostream>
#include <vector>
#include <string>

class Matrix
{
public:
	std::vector<std::vector<double>> data;
	int ExChangeTime;
	Matrix();
	Matrix(std::vector<std::vector<double>>);
	int row();
	int column();
	// OperatorOverloading
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	// Function
	const int rank();
	double determinant();
	Matrix Gaussian(double);
	Matrix trans();
	Matrix adj();
	Matrix inverse();
	Matrix identityM(int);
};

enum struct Matrix_Error
{
	Dimension_Error,
};