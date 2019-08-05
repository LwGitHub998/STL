#include "Monsters.h"


//怪物类
Monster::Monster(int monsterId)
{
	FileManger fm;
	string Monstersfile = string("./Monsters.csv");	
	map<string, map<string, string>> mapMonstersData;	
	fm.LoadCsvFile(Monstersfile, mapMonstersData);
	string tmpId = std::to_string(monsterId);
	string id = mapMonstersData[tmpId]["MonsterId"];
	MonsterName = mapMonstersData[id]["MonsterName"];;
	MonsterHp = atoi(mapMonstersData[id]["MonsterHp"].c_str());//血量
	MonsterAtk = atoi(mapMonstersData[id]["MonsterAtk"].c_str());	//攻击力
	MonsterDef = atoi(mapMonstersData[id]["MonsterDef"].c_str());	//防御力
	isFrizen = false;	//默认没有被冰冻 
}
void Monster::Attack(Hero* hero)
{
	if (isFrizen)
	{
		cout << "怪物" << MonsterName << "被冰冻，停止攻击一回合" << endl;
		isFrizen = false;
		return;
		
	}
	int damage = ((MonsterAtk - hero->HeroDef) > 0) ? (MonsterAtk - hero->HeroDef) : 1;
	hero->HeroHp -= damage;
	cout << "怪物" << MonsterName << "对英雄" << hero->HeroName << "造成了" << damage << "点伤害" << endl;
}
