#include "Monsters.h"


//怪物类
Monster::Monster(int monsterId) //指定怪物号
{
	//Monsters信息
	FileManger fm;
	string Monstersfile = string("./Monsters.csv");	//文件路径
	map<string, map<string, string>> mapMonstersData;	//保存信息map
	fm.LoadCsvFile(Monstersfile, mapMonstersData);
	string tmpId = std::to_string(monsterId);
	//获取id，方便后面的修改
	//MonsterId,MonsterName,MonsterHp,MonsterAtk,MonsterDef
	string id = mapMonstersData[tmpId]["MonsterId"];
	MonsterName = mapMonstersData[id]["MonsterName"];;
	MonsterHp = atoi(mapMonstersData[id]["MonsterHp"].c_str());//血量
	MonsterAtk = atoi(mapMonstersData[id]["MonsterAtk"].c_str());	//攻击力
	MonsterDef = atoi(mapMonstersData[id]["MonsterDef"].c_str());	//防御力
	isFrizen = false;	//默认没有被冰冻 
}
void Monster::Attack(Hero* hero)	//打英雄
{
	//判断怪物是否本冰冻，如果怪物被冰冻，则停止攻击一回合
	if (isFrizen)
	{
		//冰冻
		//谁优先攻击说不来
		cout << "怪物" << MonsterName << "被冰冻，停止攻击一回合" << endl;
		isFrizen = false;
		return;
		
	}
	//计算对英雄的伤害 
	//怪物伤害-英雄防御力
	int damage = ((MonsterAtk - hero->HeroDef) > 0) ? (MonsterAtk - hero->HeroDef) : 1;
	//英雄掉生命值
	hero->HeroHp -= damage;
	cout << "怪物" << MonsterName << "对英雄" << hero->HeroName << "造成了" << damage << "点伤害" << endl;
}