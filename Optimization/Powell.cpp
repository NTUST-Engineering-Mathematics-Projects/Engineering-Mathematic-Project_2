#include "Powell.h"
#define IsTri(s) (s == "sin" || s == "cos" || s == "tan" || s == "sec" || s == "csc" ||  s == "cot")
#define IsVar(v) ("A" <= v && v <= "Z" || "a" <= v && v <= "z")
#define IsX(x) (x == "X" || x == "x")
#define IsY(y) (y == "Y" || y == "y")

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
	if (abs(c - a) < 0.0001 * (abs(b) + abs(x)))
	{
		return (c - a) / 2;
	}
	if (FunctionValue(x, 0) < FunctionValue(b, 0))
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

double Powell::FunctionValue(double x, double y)
{
	double result, current;
	std::stack<std::string> op;
	for (unsigned int i = 0; i < posteq[EquationIndex].size(); ++i)
	{
		int operation = 0;
		if (posteq[EquationIndex][i] == "+")
			operation = 1;
		else if (posteq[EquationIndex][i] == "-")
			operation = 2;
		else if (posteq[EquationIndex][i] == "*")
			operation = 3;
		else if (posteq[EquationIndex][i] == "^")
			operation = 4;
		// àㄧ计
		else if(IsTri(posteq[EquationIndex][i]))
		{
			operation = 5;
		}
		else
		{
			op.push(posteq[EquationIndex][i]);
			continue;
		}
		if (operation != 5)
		{
			// 计
			if (IsVar(op.top()))
			{
				// 跑计
				if (IsX(op.top()))
				{
					result = x;
				}
				else if (IsY(op.top()))
				{
					result = y;
				}
			}
			else
			{
				result = std::stof(op.top());
			}
			op.pop();
		}
		// 计
		if (IsVar(op.top()))
		{
			// 跑计
			if (IsX(op.top()))
			{
				current = x;
			}
			else if (IsY(op.top()))
			{
				current = y;
			}
		}
		else
		{
			current = std::stof(op.top());
		}
		op.pop();
		switch (operation)
		{
		case 1:
			current += result;
			break;
		case 2:
			current -= result;
			break;
		case 3:
			current *= result;
			break;
		case 4:
			current = pow(current, result);
			break;
		case 5:
			if (posteq[EquationIndex][i] == "sin")
				current = sin(current);
			else if (posteq[EquationIndex][i] == "cos")
				current = cos(current);
			else if (posteq[EquationIndex][i] == "tan")
				current = tan(current);
			else if (posteq[EquationIndex][i] == "sec")
				current = 1 / cos(current);
			else if (posteq[EquationIndex][i] == "csc")
				current = 1 / sin(current);
			else if (posteq[EquationIndex][i] == "cot")
				current = 1 / tan(current);
			break;
		default:
			break;
		}
		std::ostringstream ss;
		ss << current;
		op.push(ss.str());
	}
	result = current;
	return result;
}
