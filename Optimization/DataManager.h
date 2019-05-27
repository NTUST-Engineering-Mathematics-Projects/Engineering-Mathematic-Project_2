#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include "Matrix.h"


//定義控管資料class
class DataManager
{
private:
	//儲存方程式資料
	std::vector<std::string> Equations;
	std::vector<std::vector<std::string>> Postfixs;
	std::vector<std::string> ChangePostEquation;
	//紀錄向量ID，用於控管
	int EquationIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadEquationData();
	//取得向量資料
	std::vector<std::string> GetEquations();
	std::vector<std::vector<std::string>> GetPostEqs();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
	std::vector<std::string>InfixToPost(std::string);
};