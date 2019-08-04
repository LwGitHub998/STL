#pragma once
#include <iostream>
using namespace std;
#include <fstream>	
#include <string>
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>

//文件管理类
class FileManger
{
public:
	void FileManger::LoadCsvFile(string& file, map<string, map<string, string>>& mapFileData);

	void ParseStrToVec(string& line, vector<string>& v);
};
