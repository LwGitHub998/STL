#include "Hero.h"


//英雄类
Hero::Hero(int heroId)
{
	//Hero信息
	FileManger fh;	//只需创建一个就可以
	string Herofile = string("./Hero.csv");	//文件路径
	map<string, map<string, string>> mapHeroData;	//保存信息map
	fh.LoadCsvFile(Herofile, mapHeroData);

	//id转string
	string tmpId = std::to_string(heroId);
	//HeroId, HeroName, HeapHp, HeroAtk, HeroDef, HeroInfo
	//获取id，方便后面的修改
	string id = mapHeroData[tmpId]["HeroId"];
	//int HeroHp;	//生命值
	//int HeroAtk;	//攻击力
	//int HeroDef;	//防御力
	//string HeroName;	//姓名
	//string HeroInfo;	//特点
	//Weapon* pWeapon;	//武器类指针
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
		//没有武器，则没有额外的伤害加成
		damage = HeroAtk;
		//不是真实伤害
		//cout << "英雄" << HeroName << "对怪物" << monster->MonsterName << "造成了" << damage << "点伤害" << endl;
	}
	else
	{
		//基础伤害+武器基础伤害
		damage = HeroAtk + pWeapon->getBaseDamage();
		//是否暴击 武器伤害*暴击系数  在这里添加英雄攻击*武器暴击系数
		crit = pWeapon->getCrit();
		//吸血
		suck = pWeapon->getSuckBlood();
		//冰冻
		frozen = pWeapon->getFrozen();
	}
	if (crit)	//造成暴击
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
		//怪物冰冻
		monster->isFrizen = true;
	}


	//更新怪物、英雄信息
	//计算对怪物的伤害
	int trueDamage = ((damage - monster->MonsterDef) > 0) ? damage - monster->MonsterDef : 1;
	//英雄吸血
	HeroHp += suck;
	//更新怪物血量
	monster->MonsterHp -= trueDamage;
	cout << "英雄" << HeroName << "对怪物" << monster->MonsterName << "造成了" << trueDamage << "点伤害" << endl;
}
void Hero::EquipWeapon(Weapon* weapon)
{
	if (nullptr == weapon)	//用户没装备武器
	{
		return;
	}
	pWeapon = weapon;	//英雄装备武器
	cout << "英雄" << HeroName << "装备" << pWeapon->weapoName << endl;
}