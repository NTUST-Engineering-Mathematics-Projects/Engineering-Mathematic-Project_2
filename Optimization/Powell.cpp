#include "Powell.h"
#define IsTri(s) (s == "sin" || s == "cos" || s == "tan" || s == "sec" || s == "csc" ||  s == "cot")
#define IsVar(v) ("A" <= v && v <= "Z" || "a" <= v && v <= "z")
#define IsX(x) (x == "X" || x == "x")
#define IsY(y) (y == "Y" || y == "y")

double Powell::FunctionValue(double x, double y, int set)
{
	double result = 0, current = 0;
	std::vector<std::string> Equation;
	if (set == 1)
	{
		Equation = GEquation;
	}
	else
	{
		Equation = posteq[EquationIndex];
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

std::string Powell::ChangeEq(std::string x, std::string y)
{
	std::string ori = original[EquationIndex];
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

double Powell::GoldenSearch(double a, double b, double c)
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