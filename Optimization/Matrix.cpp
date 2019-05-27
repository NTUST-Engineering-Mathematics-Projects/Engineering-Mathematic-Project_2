#include "Matrix.h"

Matrix::Matrix()
{
	data.clear();
}

Matrix::Matrix(std::vector<std::vector<double>> d)
{
	data = d;
}

int Matrix::row()
{
	return data.size();
}

int Matrix::column()
{
	return data[0].size();
}

Matrix Matrix::operator+(Matrix &m)
{
	Matrix result;
	std::vector<double>temp;
	if (this->row() == m.row() && this->column() == m.column())
	{
		for (unsigned int i = 0; i < this->row(); ++i)
		{
			for (unsigned j = 0; j < this->column(); ++j)
			{
				temp.push_back(this->data[i][j] + m.data[i][j]);
			}
			result.data.push_back(temp);
			temp.clear();
		}
		return result;
	}
	else
		throw Matrix_Error::Dimension_Error;
}

Matrix Matrix::operator-(Matrix &m)
{
	Matrix result;
	std::vector<double>temp;
	if (this->row() == m.row() && this->column() == m.column())
	{
		for (unsigned int i = 0; i < this->row(); ++i)
		{
			for (unsigned j = 0; j < this->column(); ++j)
			{
				temp.push_back(this->data[i][j] - m.data[i][j]);
			}
			result.data.push_back(temp);
			temp.clear();
		}
		return result;
	}
	else
		throw Matrix_Error::Dimension_Error;
}

Matrix Matrix::operator*(Matrix &m)
{
	Matrix result;
	if (this->column() == m.row())
	{
		for (unsigned int i = 0; i < this->row(); ++i)
		{
			std::vector<double>temp;
			for (unsigned int j = 0; j < m.column(); ++j)
			{
				double sum = 0;
				for (unsigned int k = 0; k < this->column(); ++k)
				{
					sum += this->data[i][k] * m.data[k][j];
				}
				temp.push_back(sum);
			}
			result.data.push_back(temp);
		}
		return result;
	}
	else
		throw Matrix_Error::Dimension_Error;
}

Matrix Matrix::Gaussian(double tolerance)
{
	ExChangeTime = 0;
	Matrix GaussTemp = *this;
	for (unsigned int cur_row = 0, cur_col = 0; cur_row < GaussTemp.row() && cur_col < GaussTemp.column(); cur_row++, cur_col++)
	{
		// Find currentMax
		double CMax = abs(GaussTemp.data[cur_row][cur_col]);
		int MRow = cur_row;
		for (int i = cur_row + 1; i < GaussTemp.data.size(); i++)
		{
			if (abs(GaussTemp.data[i][cur_col]) > CMax)
			{
				CMax = abs(GaussTemp.data[i][cur_col]);
				MRow = i;
			}
		}
		// Column of MRow are all zero
		if (!CMax)
		{
			cur_row--;
			continue;
		}
		if (MRow != cur_row)
		{
			// ExChange Row
			ExChangeTime++;
			std::vector<double> buf = GaussTemp.data[MRow];
			GaussTemp.data[MRow] = GaussTemp.data[cur_row];
			GaussTemp.data[cur_row] = buf;
		}
		// Clear all nonzero columns
		for (int i = cur_row + 1; i < GaussTemp.data.size(); i++)
		{
			if (GaussTemp.data[i][cur_col] == 0)
			{
				continue;
			}
			double sub = GaussTemp.data[i][cur_col] / GaussTemp.data[cur_row][cur_col];
			for (int j = cur_col + 1; j < GaussTemp.data[0].size(); j++)
			{
				GaussTemp.data[i][j] -= (sub * GaussTemp.data[cur_row][j]);
			}
			GaussTemp.data[i][cur_col] = 0;
		}
	}
	// Compare with tolerant
	for (unsigned int i = 0; i < GaussTemp.row(); i++)
	{
		for (unsigned int j = 0; j < GaussTemp.column(); j++)
		{
			if (abs(GaussTemp.data[i][j]) < tolerance)
				GaussTemp.data[i][j] = 0;
		}
	}
	return GaussTemp;
}

const int Matrix::rank()
{
	Matrix RankTemp = this->Gaussian(1E-6);
	int result = 0;
	// Calculate rank
	for (int i = 0; i < RankTemp.data.size(); i++)
	{
		bool Rflag = true;
		// If all are zero => zero row
		for (int j = 0; j < RankTemp.data[0].size(); j++)
		{
			if (RankTemp.data[i][j])
			{
				Rflag = false;
				break;
			}
		}
		// Is zero row ?
		if (Rflag)
			result++;
		else
			continue;
	}
	result = RankTemp.column() - result;
	return result;
}

double Matrix::determinant()
{
	double result = 1.0;
	Matrix DetTemp = this->Gaussian(1E-6);
	for (int i = 0; i < DetTemp.data.size(); i++)
	{
		result *= DetTemp.data[i][i];
	}
	result *= pow(-1, ExChangeTime);
	return result;
}

Matrix Matrix::trans()
{
	Matrix trans;
	trans.data.clear();
	for (int i = 0; i < this->column(); i++)
	{
		std::vector<double>TrTemp;
		for (unsigned int j = 0; j < this->row(); j++)
		{
			TrTemp.push_back(this->data[j][i]);
		}
		trans.data.push_back(TrTemp);
		TrTemp.clear();
	}
	return trans;
}

Matrix Matrix::adj()
{
	if (this->row() != this->column())
		throw Matrix_Error::Dimension_Error;
	else
	{
		Matrix AdjMatrix = *this;
		Matrix adjTemp;
		// Get Every Cofactor
		for (unsigned int i = 0; i < this->row(); i++)
		{
			for (unsigned int j = 0; j < this->column(); j++)
			{
				adjTemp = *this;
				// 去除目前位置的Row, Column
				for (unsigned int k = 0; k < this->column(); k++)
				{
					if (k != i)
						adjTemp.data[k].erase(adjTemp.data[k].begin() + j);
				}
				adjTemp.data.erase(adjTemp.data.begin() + i);
				AdjMatrix.data[i][j] = pow(-1, i + j) * adjTemp.determinant();
			}
		}
		AdjMatrix = AdjMatrix.trans();
		return AdjMatrix;
	}
}

Matrix Matrix::inverse()
{
	if (this->row() != this->column())
	{
		throw Matrix_Error::Dimension_Error;
	}
	else
	{
		Matrix result = this->adj();
		long double det = 1.0 / this->determinant();
		for (int i = 0; i < this->row(); ++i)
		{
			for (int j = 0; j < this->column(); ++j)
			{
				result.data[i][j] = det * result.data[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::identityM(int I)
{
	Matrix result;
	for (unsigned int i = 0; i < I; ++i)
	{
		std::vector<double>temp(I, 0);
		temp[i] = 1;
		result.data.push_back(temp);
	}
	return result;
}
