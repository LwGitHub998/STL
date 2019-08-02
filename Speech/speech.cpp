/*
例：学校演讲比赛

1）某市举行一场演讲比赛，共有 24 个人参加，按参加顺序设置参赛号。比赛共三轮，前两 轮为淘汰赛，第三轮为决赛。 
2）比赛方式：分组比赛
        第一轮分为 4 个小组，根据参赛号顺序依次划分，比如 100-105 为一组，106-111 为第 二组，依次类推，每组 6 个人，每人分别按参赛号顺序演讲。当小组演讲完后，淘汰组内排 名最后的三个选手，然后继续下一个小组的比赛。 
        第二轮分为 2 个小组，每组 6 人，每个人分别按参赛号顺序演讲。当小组完后，淘汰组 内排名最后的三个选手，然后继续下一个小组的比赛。 
        第三轮只剩下 6 个人，本轮为决赛，选出前三名。
        选手每次要随机分组，进行比赛。
4）比赛评分：10 个评委打分，去除最低、最高分，求平均分
每个选手演讲完由 10 个评委分别打分。该选手的最终得分是去掉一个最高分和一个最 低分，求得剩下的 8 个成绩的平均分。选手的名次按得分降序排列，若得分一样，按参赛号 升序排名。 

1） 请打印出所有选手的名字与参赛号，并以参赛号的升序排列。
2） 打印每一轮比赛前，分组情况
3） 打印每一轮比赛后，小组晋级名单
4） 打印决赛前三名，选手名称、成绩。
*/

//演讲比赛
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>	//算法头文件
#include<numeric>

//选手类
class Speaker
{
public:
	string _name;
	int _score[3];		//存放三轮比赛的结果
};

void GetSpeaker(map<int, Speaker>& mapSpaker, vector<int>& v)
{
	string str = string("ABCDEFGHIGKLMNOPQRSTUVWXYZ");
	random_shuffle(str.begin(), str.end());	//打乱选手顺序
	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp._name += str[i];
		mapSpaker.insert(pair<int, Speaker>(100+i, tmp));	//把选手保存下来
		v.push_back(100 + i);	//确定参赛选手
	}
}
void speech_Count(vector<int>& v)	//抽签
{
	random_shuffle(v.begin(), v.end());	//打乱选手顺序
}
void speech_Match(int num, vector<int>&  v1, map<int, Speaker>& mapSpaker, vector<int>& v2)	//比赛
{
	//根据v1的顺序使选手们进行比赛,//求出前3名 后三名
	multimap<int, int> mul;	//报错
	//默认是按照multimap键值的升序排列，
	//如果按降序排列则multimap<string,int,greater<string>>
	int tmpCount = 0;	//记录比赛人数
	for (auto it = v1.begin(); it < v1.end(); it++)
	{
		tmpCount++;
		//打分
		deque<int> dq;
		for (int i = 0; i < 10; i++)
		{
			int socre = rand() % 51 + 50;
			dq.push_back(socre);
		}
		//去除最高分和最低分
		sort(dq.begin(), dq.end());
		dq.pop_front();
		dq.pop_back();
		//求平均分
		int Sum = accumulate(dq.begin(), dq.end(), 0);
		int average = Sum / dq.size();
		//存入选手类中
		mapSpaker[*it]._score[num] = average;
		mul.insert(pair<int, int>(average, *it));

		if (0 == tmpCount % 6)
		{
			cout << "小组成绩" << endl;
			for (auto mit = mul.begin(); mit != mul.end(); mit++)
			{
				cout << mit->second << mapSpaker[mit->second]._name << mit->first << endl;
			}
			//前三名晋级
			//因为前面创建multimap时是升序的，所以需要从后向前遍历
			while (mul.size() > 3)
			{
				auto mit = mul.end();	//end是最后一个元素的下一个位置，所以需要--
				mit--;
				v2.push_back(mit->second);
				mul.erase(mit);
			}
			//清空本小组比赛成绩，进入下一组
			mul.clear();
		}
	}
}
void speech_Print(int num, vector<int>&  v, map<int, Speaker>& mapSpaker) //打印结果
{
	cout << "第" << num << "轮晋级名单" << endl;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << "编号" << *it << mapSpaker[*it]._name << mapSpaker[*it]._score[num] << endl;
	}
}
int main()
{
	//把选手放入map中
	map<int, Speaker> mapSpaker;
	vector<int> v1;	//第一轮的参赛名单
	vector<int> v2;	//第二轮的参赛名单--第一轮的淘汰后的结果名单
	vector<int> v3;	//第三轮的参赛名单
	vector<int> v4;	//第三轮的结果参赛名单
	//产生选手，得到第一轮的选手的参赛名单
	GetSpeaker(mapSpaker, v1);
	//第一轮抽签，比赛，查看结果
	speech_Count(v1);	//抽签
	speech_Match(1, v1, mapSpaker, v2);	//比赛 v1 -> v2
	speech_Print(1,v2, mapSpaker);	//查看结果
	//第二轮抽签，比赛，查看结果
	speech_Count(v2);	//抽签
	speech_Match(2, v2, mapSpaker, v3);	//比赛 v1 -> v2
	speech_Print(2, v3, mapSpaker);	//查看结果
	//第三轮抽签，比赛，查看结果
	speech_Count(v3);	//抽签
	speech_Match(3, v3, mapSpaker, v4);	//比赛 v1 -> v2
	speech_Print(3, v4, mapSpaker);	//查看结果
	cout << "end" << endl;
	return 0;
}
