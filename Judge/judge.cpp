/*
例如：有5名选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分

1.创建5名选手类，放到vector中
2.遍历vector容器，取出每一个选手，执行for循环，可以把10个评委打分分别存到deque容器中
3.sort算法对deque容器中分数排序，pop_back\pop_front去除最高和最低分
4.deque容器遍历一遍，累加分数
5. person.average = 平均分
*/

//评委打分
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>	//算法头文件
#include <ctime>	//#include <time.h>
class PerSon
{
public:
	PerSon(string name)
	{
		_name = name;
		_average = 0;
	}
	string& RetName()
	{
		return _name;
	}
	int& RetAVRGe()
	{
		return _average;
	}
	void TAVRGe(int average)
	{
		_average = average;
	}
private:
	string _name;
	int _average;
};


void CreatePerson(vector<PerSon>& v)
{
	string names = string("ABCDE");
	for (int i = 0; i < 5; i++)
	{
		string name;
		name += names[i];
		PerSon p(name);
		v.push_back(p);
	}
}
void setScore(vector<PerSon>& v)
{
	for (vector<PerSon>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> dq;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; //60~100
			dq.push_back(score);
		}
		sort(dq.begin(), dq.end());	//从小到大排序
		//去除最低最高
		dq.pop_front();
		dq.pop_back();
		//获取总分
		int sum = 0;
		for (deque<int>::iterator itq = dq.begin(); itq != dq.end(); itq++)
		{
			sum += *itq;
		}
		it->TAVRGe(sum / dq.size());
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//1.创建5名选手类，放到vector中
	vector<PerSon> v;
	CreatePerson(v);
	for (vector<PerSon>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->RetName() << "  " << it->RetAVRGe() << endl;
	}
	//	2.遍历vector容器，取出每一个选手，执行for循环，可以把10个评委打分分别存到deque容器中
	//	3.sort算法对deque容器中分数排序，pop_back\pop_front去除最高和最低分
	//	4.deque容器遍历一遍，累加封分数
	//	5. person.average = 平均分
	setScore(v);
	//可以在创建一个vector，将每一个评委打分放入vector<deque<int>>中，与选手一一对应，或者可以直接将deque放入选手类中，更加方便计算
	for (vector<PerSon>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->RetName() << "  " << it->RetAVRGe() << endl;
	}
	return 0;
}
