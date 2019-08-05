#pragma once
#include "common.h"
#include "Hero.h"

class Hero;
//怪物类
class Monster
{
public:
	Monster(int monsterId);
	void Attack(Hero* hero);
public:
	//MonsterId,MonsterName,MonsterHp,MonsterAtk,MonsterDef
	string MonsterName;	//怪物名字
	int MonsterHp;//生命值
	int MonsterAtk;	//攻击力
	int MonsterDef;	//防御力
	bool isFrizen;	//怪物是否冰冻
};
