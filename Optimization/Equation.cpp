#include "Equation.h"
#define IsTri(s) (s == "sin" || s == "cos" || s == "tan" || s == "sec" || s == "csc" ||  s == "cot")
#define IsOp(p) (p == "+" || p == "-" || p == "*" || p == "/" || p == "^" || p == "@" || p == "$" || IsTri(p))

double Equation::FunctionValue(double x, double y, int set)
{
	double result = 0, current = 0;
	std::vector<std::string> Equation;
	if (set == 1)
	{
		Equation = this->changeEqu;
	}
	else
	{
		Equation = this->postEqu;
	}
	std::stack<double> op;
	for (unsigned int i = 0; i < Equation.size(); ++i)
	{
		if (Equation[i] == "+")
		{
			current = op.top();
			op.pop();
			op.top() += current;
		}
		else if (Equation[i] == "-")
		{
			current = op.top();
			op.pop();
			op.top() -= current;
		}
		else if (Equation[i] == "*")
		{
			current = op.top();
			op.pop();
			op.top() *= current;
		}
		else if (Equation[i] == "/")
		{
			current = op.top();
			op.pop();
			op.top() /= current;
		}
		else if (Equation[i] == "^")
		{
			current = op.top();
			op.pop();
			op.top() = powl(op.top(), current);
		}
		else if (Equation[i] == "@")
		{
			continue;
		}
		else if (Equation[i] == "$")
		{
			op.top() *= -1;
		}
		else if (IsTri(Equation[i]))
		{
			if (Equation[i] == "sin")
				op.top() = sin(op.top());
			else if (Equation[i] == "cos")
				op.top() = cos(op.top());
			else if (Equation[i] == "tan")
				op.top() = tan(op.top());
			else if (Equation[i] == "sec")
				op.top() = 1 / cos(op.top());
			else if (Equation[i] == "csc")
				op.top() = 1 / sin(op.top());
			else if (Equation[i] == "cot")
				op.top() = 1 / tan(op.top());
		}
		else
		{
			if (Equation[i] == "x")
				op.push(x);
			else if (Equation[i] == "y")
				op.push(y);
			else
				op.push(std::stod(Equation[i]));
		}
	}
	result = op.top();
	return result;
}

std::string Equation::ChangeEq(std::string x, std::string y)
{
	std::string ori = original[EquIndex];
	std::string result;
	x += ')';
	y += ')';
	for (unsigned int i = 0; i < x.length(); ++i)
	{
		if (x[i] == 'a')
			x[i] = 'x';
	}
	for (unsigned int i = 0; i < y.length(); ++i)
	{
		if (y[i] == 'a')
			y[i] = 'x';
	}
	for (unsigned int i = 0; i < ori.length(); ++i)
	{
		if (ori[i] == 'x')
		{
			result += "(";
			result += x;
		}
		else if (ori[i] == 'y')
		{
			result += "(";
			result += y;
		}
		else
			result += ori[i];
	}
	return result;
}

double Equation::GoldenSearch(double a, double b, double c)
{
	double x = 0;
	if (c - b > b - a)
	{
		x = b + resphi * (c - b);
	}
	else
	{
		x = b - resphi * (b - a);
	}
	if (abs(c - a) < 0.001 * (abs(b) + abs(x)))
	{
		return (c + a) / 2;
	}
	if (FunctionValue(x, 0, 1) < FunctionValue(b, 0, 1))
	{
		if (c - b > b - a)
		{
			return GoldenSearch(b, x, c);
		}
		else
		{
			return GoldenSearch(a, x, b);
		}
	}
	else
	{
		if (c - b > b - a)
		{
			return GoldenSearch(a, b, x);
		}
		else
		{
			return GoldenSearch(x, b, c);
		}
	}
}

Equation::Equation()
{
	HasSqrt = false;
}

double Equation::dif_x(double x, int set, double h)
{
	return (FunctionValue(x + h, 0, set) - FunctionValue(x, 0, set)) / h;
}

double Equation::dif_xx(double x, int set, double h)
{
	return (dif_x(x + h, set, h) - dif_x(x, set, h)) / h;
}

double Equation::dif_xxx(double x, int set, double h)
{
	return (dif_xx(x + h, set, h) - dif_xx(x, set, h)) / h;
}

double Equation::pdf_x(double x, double y, int set, double h)
{
	return (FunctionValue(x + h, y, set) - FunctionValue(x, y, set)) / h;
}

double Equation::pdf_y(double x, double y, int set, double h)
{

	return (FunctionValue(x, y + h, set) - FunctionValue(x, y, set)) / h;
}

double Equation::pdf_xx(double x, double y, int set, double h)
{
	return (FunctionValue(x + h, y, set) - 2 * FunctionValue(x, y, set) + FunctionValue(x - h, y, set)) / (h*h);
}

double Equation::pdf_yy(double x, double y, int set, double h)
{
	return (FunctionValue(x, y + h, set) - 2 * FunctionValue(x, y, set) + FunctionValue(x, y - h, set)) / (h*h);
}

double Equation::pdf_xy(double x, double y, int set, double h)
{
	return (FunctionValue(x + h, y + h, set) - FunctionValue(x - h, y + h, set) - FunctionValue(x + h, y - h, set) + FunctionValue(x - h, y - h, set)) / (4 * h*h);
}

void Equation::getHessian(double x, double y)
{
	Matrix result;
	std::vector<double>temp;
	double h1, h2, h3, h4;
	h1 = h2 = h3 = h4 = 0;
	h1 = pdf_xx(x, y, 0, 10E-5);
	h2 = h3 = pdf_xy(x, y, 0, 10E-5);
	h4 = pdf_yy(x, y, 0, 10E-5);
	temp.push_back(h1);
	temp.push_back(h2);
	result.data.push_back(temp);
	temp.clear();
	temp.push_back(h3);
	temp.push_back(h4);
	result.data.push_back(temp);
	hessian = result;
}

Vector Equation::gradient(double x, double y, int set, int var)
{
	Vector result;
	if (var == 1)
	{
		result.data.push_back(dif_x(x, set, 10E-5));
	}
	else
	{
		result.data.push_back(pdf_x(x, y, set, 10E-5));
		result.data.push_back(pdf_y(x, y, set, 10E-5));
	}
	return result;
}

void Equation::CheckSqrt()
{
	for (unsigned int i = 0; i < postEqu.size(); ++i)
	{
		if (postEqu[i] != "+" && postEqu[i] != "-" && postEqu[i] != "*" && postEqu[i] != "/" && postEqu[i] != "^" && postEqu[i] != "(" && postEqu[i] != ")" && postEqu[i] != "x" && postEqu[i] != "y" &&postEqu[i] != "@" && postEqu[i] != "$")
		{
			if (i != postEqu.size() - 1)
			{
				double temp = std::stod(postEqu[i]);
				if ((std::fmod(temp, 0.5)) == 0 && (std::fmod(temp, 1.0)) != 0 && postEqu[i + 1] == "^")
				{
					bool flag = false;
					int k = i - 1;
					while (k >= 0)
					{
						if(postEqu[k] == "x" || postEqu[k] == "y")
						{
							flag = true;
							break;
						}
						else if(IsOp(postEqu[k]))
						{
							--k;
						}
						else
						{
							break;
						}
					}
					if (flag)
					{
						HasSqrt = true;
						break;
					}
				}
			}
		}
	}
	return;
}
