#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include "Matrix.h"


//�w�q���޸��class
class DataManager
{
private:
	//�x�s��{�����
	std::vector<std::string> Equations;
	std::vector<std::vector<std::string>> Postfixs;
	std::vector<std::string> ChangePostEquation;
	//�����V�qID�A�Ω󱱺�
	int EquationIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadEquationData();
	//���o�V�q���
	std::vector<std::string> GetEquations();
	std::vector<std::vector<std::string>> GetPostEqs();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
	std::vector<std::string>InfixToPost(std::string);
};