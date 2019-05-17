#include "DataManager.h"
#define IsTri(s) (s == "sin" || s == "cos" || s == "tan" || s == "sec" || s == "csc" ||  s == "cot")

DataManager::DataManager()
{
	EquationIndex = 0;
}

bool DataManager::LoadEquationData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempSring;
			// std::cout << tempSring << std::endl;
			//�ѪR��V�q�аO"V"
			Equations.push_back(tempSring);
			Postfixs.push_back(InfixToPost(tempSring));
			//���WEquationIndex�A�аO���eŪ���V�qID
			EquationIndex++;
		}
		return true;
	}
}

std::vector<std::string> DataManager::GetEquations()
{
	return Equations;
}

std::vector<std::vector<std::string>> DataManager::GetPostEqs()
{
	return Postfixs;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

std::vector<std::string> DataManager::InfixToPost(std::string str)
{
	std::stack<std::string> op;
	std::vector<std::string> result;
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '^')
		{
			if (op.empty())
			{
				std::string s(1, str[i]);
				op.push(s);
			}
			else
			{
				if (str[i] == '+' || str[i] == '-')
				{
					while (op.size() > 0)
					{
						result.push_back(op.top());
						op.pop();
					}
				}
				else if (str[i] == '*')
				{
					while (op.top() == "*")
					{
						result.push_back(op.top());
						op.pop();
					}
				}
				else if (str[i] == '^')
				{
					while (op.top() == "^" || IsTri(op.top()))
					{
						result.push_back(op.top());
						op.pop();
					}
				}
				std::string s(1, str[i]);
				op.push(s);
			}
		}
		else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n')
		{
			if (op.empty())
			{
				op.push("sin");
			}
			else
			{
				while (op.top() == "^" || IsTri(op.top()))
				{
					result.push_back(op.top());
					op.pop();
				}
				op.push("sin");
			}
			i += 2;
		}
		else if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's')
		{
			if (op.empty())
			{
				op.push("cos");
			}
			else
			{
				while (op.top() == "^" || IsTri(op.top()))
				{
					result.push_back(op.top());
					op.pop();
				}
				op.push("cos");
			}
			i += 2;
		}
		else if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n')
		{
			if (op.empty())
			{
				op.push("tan");
			}
			else
			{
				while (op.top() == "^" || IsTri(op.top()))
				{
					result.push_back(op.top());
					op.pop();
				}
				op.push("tan");
			}
			i += 2;
		}
		else if (str[i] == 's' && str[i + 1] == 'e' && str[i + 2] == 'c')
		{
			if (op.empty())
			{
				op.push("sec");
			}
			else
			{
				while (op.top() == "^" || IsTri(op.top()))
				{
					result.push_back(op.top());
					op.pop();
				}
				op.push("sec");
			}
			i += 2;
		}
		else if (str[i] == 'c' && str[i + 1] == 's' && str[i + 2] == 'c')
		{
			if (op.empty())
			{
				op.push("csc");
			}
			else
			{
				while (op.top() == "^" || IsTri(op.top()))
				{
					result.push_back(op.top());
					op.pop();
				}
				op.push("csc");
			}
			i += 2;
		}
		else if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 't')
		{
			if (op.empty())
			{
				op.push("cot");
			}
			else
			{
				while (op.top() == "^" || IsTri(op.top()))
				{
					result.push_back(op.top());
					op.pop();
				}
				op.push("cot");
			}
			i += 2;
		}
		else if (str[i] == '(')
		{
			op.push("(");
		}
		else if (str[i] == ')')
		{
			while (op.top() != "(")
			{
				result.push_back(op.top());
				op.pop();
			}
			op.pop();
		}
		else
		{
			std::string temp = std::string();
			while (!(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '^'))
			{
				if (str[i] == ')' || str[i] == '(')
				{
					break;
				}
				temp += str[i];
				++i;
				if (i >= str.length())
					break;
			}
			--i;
			result.push_back(temp);
		}
	}
	while (op.size() > 0)
	{
		result.push_back(op.top());
		op.pop();
	}
	return result;
}
