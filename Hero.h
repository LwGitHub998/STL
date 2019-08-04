#pragma once
#include "commnd.h"
#include "Monsters.h"
#include "Weapon.h"

//必须提前声明
class Monster; //怪物类
//英雄类
class Hero
{
public:
	Hero(int heroId);
	void Attack(Monster* monster);	//打怪物
	void EquipWeapon(Weapon* weapon);	//拿武器
public:
	//HeroId, HeroName, HeapHp, HeroAtk, HeroDef, HeroInfo
	int HeroHp;	//生命值
	int HeroAtk;	//攻击力
	int HeroDef;	//防御力
	string HeroName;	//姓名
	string HeroInfo;	//特点
	Weapon* pWeapon;	//武器类指针
};