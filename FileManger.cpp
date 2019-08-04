#include "commnd.h"


//文件解析函数
//加载csv文件的函数
void FileManger::LoadCsvFile(string& file, map<string, map<string, string>>& mapFileData)
{
	//读文件 ifstream
	ifstream ifs(file);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//先单独把第一行的数据拿出来，用来保存信息
	string line;
	ifs >> line;
	//cout << line << endl;
	//把line中的数据分别放到vector中去
	vector<string> vFirst;
	//解析数据
	ParseStrToVec(line, vFirst);

	//通过容器嵌套容器来保存所有数据
	// 编号         信息名称 信息内容
	//在读取其他数据
	string Data;
	while (ifs >> Data)	//每次读取都会将string清空后再放入新的数据
	{
		//cout << Data << endl;
		//把Data中的数据分别放到vector中去
		vector<string> vData;
		//解析数据
		ParseStrToVec(Data, vData);
		//准备出一个小容器
		map<string, string> mData;
		for (int i = 0; i < (int)vFirst.size(); i++)
		{
			//要把vFirst中的信息与vData中的信息一一对应起来
			mData.insert(pair<string, string>(vFirst[i], vData[i]));
		}
		//将所有信息保存到大容器中
		mapFileData.insert(make_pair(vData[0], mData));  //<编号，信息>
	}
	//直接打印不出来？？？
	//auto p = mapFileData["1"]["HeroName"];	//string中式字符串

	//cout << p << endl;
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
			//最后一个单词后面是没有，的，所以需要把最后一个单词压进去
			string tmp = line.substr(start, string::npos);//使用总长度-start也可以，npos表示字符串结束，就是从start截取到npos
			
			v.push_back(tmp);
			break;//找不到则结束
		}
		string tmp = line.substr(start, pos - start);
		//这里是不是可以之间调用atio函数将字符串转换为int
		v.push_back(tmp);
		start = pos + 1;
	}

	//打印
	/*for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->c_str() << "  ";
	}
	cout << endl;*/
}


