#include "commnd.h"


//�ļ���������
//����csv�ļ��ĺ���
void FileManger::LoadCsvFile(string& file, map<string, map<string, string>>& mapFileData)
{
	//���ļ� ifstream
	ifstream ifs(file);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//�ȵ����ѵ�һ�е������ó���������������Ϣ
	string line;
	ifs >> line;
	//cout << line << endl;
	//��line�е����ݷֱ�ŵ�vector��ȥ
	vector<string> vFirst;
	//��������
	ParseStrToVec(line, vFirst);

	//ͨ������Ƕ��������������������
	// ���         ��Ϣ���� ��Ϣ����
	//�ڶ�ȡ��������
	string Data;
	while (ifs >> Data)	//ÿ�ζ�ȡ���Ὣstring��պ��ٷ����µ�����
	{
		//cout << Data << endl;
		//��Data�е����ݷֱ�ŵ�vector��ȥ
		vector<string> vData;
		//��������
		ParseStrToVec(Data, vData);
		//׼����һ��С����
		map<string, string> mData;
		for (int i = 0; i < (int)vFirst.size(); i++)
		{
			//Ҫ��vFirst�е���Ϣ��vData�е���Ϣһһ��Ӧ����
			mData.insert(pair<string, string>(vFirst[i], vData[i]));
		}
		//��������Ϣ���浽��������
		mapFileData.insert(make_pair(vData[0], mData));  //<��ţ���Ϣ>
	}
	//ֱ�Ӵ�ӡ������������
	//auto p = mapFileData["1"]["HeroName"];	//string��ʽ�ַ���

	//cout << p << endl;
}

//������������
void FileManger::ParseStrToVec(string& line, vector<string>& v)
{
	int pos = 0;
	int start = 0;

	while (1)
	{
		int pos = line.find(',', start);
		if (-1 == pos)
		{
			//���һ�����ʺ�����û�У��ģ�������Ҫ�����һ������ѹ��ȥ
			string tmp = line.substr(start, string::npos);//ʹ���ܳ���-startҲ���ԣ�npos��ʾ�ַ������������Ǵ�start��ȡ��npos
			
			v.push_back(tmp);
			break;//�Ҳ��������
		}
		string tmp = line.substr(start, pos - start);
		//�����ǲ��ǿ���֮�����atio�������ַ���ת��Ϊint
		v.push_back(tmp);
		start = pos + 1;
	}

	//��ӡ
	/*for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->c_str() << "  ";
	}
	cout << endl;*/
}


