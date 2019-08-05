#pragma once
#include "common.h"
#include "Monsters.h"
#include "Weapon.h"

class Monster; //怪物类
//英雄类
class Hero
{
public:
	Hero(int heroId);
	void Attack(Monster* monster);
	void EquipWeapon(Weapon* weapon);	
public:
	//HeroId, HeroName, HeapHp, HeroAtk, HeroDef, HeroInfo
	int HeroHp;	//生命值
	int HeroAtk;	//攻击力
	int HeroDef;	//防御力
	string HeroName;	//姓名
	string HeroInfo;	//特点
	Weapon* pWeapon;	//武器类指针
};
