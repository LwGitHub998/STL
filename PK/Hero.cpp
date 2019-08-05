#include "Hero.h"


//英雄类
Hero::Hero(int heroId)
{
	FileManger fh;
	string Herofile = string("./Hero.csv");
	map<string, map<string, string>> mapHeroData;	
	fh.LoadCsvFile(Herofile, mapHeroData);
	string tmpId = std::to_string(heroId);
	string id = mapHeroData[tmpId]["HeroId"];
	HeroName = mapHeroData[id]["HeroName"];
	HeroInfo = mapHeroData[id]["HeroInfo"];
	HeroDef = atoi(mapHeroData[id]["HeroDef"].c_str());
	HeroAtk = atoi(mapHeroData[id]["HeroAtk"].c_str());
	HeroHp = atoi(mapHeroData[id]["HeroHp"].c_str());
	pWeapon = nullptr;
}
void Hero::Attack(Monster* monster)
{
	int crit = 0;	//暴击
	int suck = 0;	//吸血
	int frozen = 0;		//冰冻
	int damage = 0;	//对怪物造成伤害

	if (nullptr == pWeapon)
	{
		damage = HeroAtk;
		//cout << "英雄" << HeroName << "对怪物" << monster->MonsterName << "造成了" << damage << "点伤害" << endl;
	}
	else
	{
		damage = HeroAtk + pWeapon->getBaseDamage();
		crit = pWeapon->getCrit();
		suck = pWeapon->getSuckBlood();
		frozen = pWeapon->getFrozen();
	}
	if (crit)
	{
		damage += crit;
		cout << "英雄" << HeroName << "使用武器" << pWeapon->weapoName << "触发暴击效果,怪物" << monster->MonsterName << "受到暴击伤害" << endl;
	}
	if (suck)
	{
		cout << "英雄" << HeroName << "使用武器" << pWeapon->weapoName << "触发吸血效果，英雄增加了" << suck << "点生命值" << endl;
	}
	if (frozen)
	{
		cout << "英雄" << HeroName << "使用武器" << pWeapon->weapoName << "触发冰冻效果，怪物" << monster->MonsterName << "停止攻击一回合" << endl;
		monster->isFrizen = true;
	}
	int trueDamage = ((damage - monster->MonsterDef) > 0) ? damage - monster->MonsterDef : 1;
	HeroHp += suck;
	monster->MonsterHp -= trueDamage;
	cout << "英雄" << HeroName << "对怪物" << monster->MonsterName << "造成了" << trueDamage << "点伤害" << endl;
}
void Hero::EquipWeapon(Weapon* weapon)
{
	if (nullptr == weapon)
	{
		return;
	}
	pWeapon = weapon;	
	cout << "英雄" << HeroName << "装备" << pWeapon->weapoName << endl;
}
