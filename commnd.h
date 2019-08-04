#pragma once
#include <iostream>
using namespace std;
#include <fstream>	//读写文件头文件
#include <string>
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>
//存放公共类的声明

//文件管理类
class FileManger
{
public:
	void FileManger::LoadCsvFile(string& file, map<string, map<string, string>>& mapFileData);//加载csv文件的函数

	void ParseStrToVec(string& line, vector<string>& v);//解析单行数据
};




