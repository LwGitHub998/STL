#pragma once
#include <iostream>
using namespace std;
#include <fstream>	//��д�ļ�ͷ�ļ�
#include <string>
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>
//��Ź����������

//�ļ�������
class FileManger
{
public:
	void FileManger::LoadCsvFile(string& file, map<string, map<string, string>>& mapFileData);//����csv�ļ��ĺ���

	void ParseStrToVec(string& line, vector<string>& v);//������������
};




