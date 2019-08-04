#include "common.h"

//加载csv文件的函数
void FileManger::LoadCsvFile(string& file, map<string, map<string, string>>& mapFileData)
{
	ifstream ifs(file);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	string line;
	ifs >> line;
	//cout << line << endl;
	vector<string> vFirst;
	ParseStrToVec(line, vFirst);
	string Data;
	while (ifs >> Data)	
	{
		vector<string> vData;
		ParseStrToVec(Data, vData);
		map<string, string> mData;
		for (int i = 0; i < (int)vFirst.size(); i++)
		{
			mData.insert(pair<string, string>(vFirst[i], vData[i]));
		}
		mapFileData.insert(make_pair(vData[0], mData)); 
	}
}

//解析单行数据
void FileManger::ParseStrToVec(string& line, vector<string>& v)
{
	int pos = 0;
	int start = 0;
	while (1)
	{
		int pos = line.find(',', start);
		if (-1 == pos)
		{
			string tmp = line.substr(start, string::npos);
			v.push_back(tmp);
			break;
		}
		string tmp = line.substr(start, pos - start);
		v.push_back(tmp);
		start = pos + 1;
	}
}


