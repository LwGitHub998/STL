#include "Weapon.h"

/////////////////////////////////////////////////////////
//小刀类
Knife::Knife()
{
	//Weapon信息
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");
	map<string, map<string, string>> mapWeaponData;
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	string id = mapWeaponData["1"]["WeaponId"];
	weapoName = mapWeaponData[id]["WeaponName"];	//武器名称
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//基础攻击
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//暴击系数
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//暴击率
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//吸血系数
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//吸血率
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//冰冻率

}
//获得武器基础伤害
int Knife::getBaseDamage()
{
	return baseDamage;
}
//暴击效果  返回值大于0触发暴击
int Knife::getCrit()
{
	if (isTrigger(critRate))
	{
		return baseDamage * critPuls;
	}
	return 0;
}
//获得吸血 返回值大于0触发吸血
int Knife::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		return baseDamage * suckPuls;
	}
	return 0;
}
///获得冰冻 返回值大于0则触发冰冻
int Knife::getFrozen()
{
	if (isTrigger(suckRate))
	{
		return 1;
	}
	return 0;
}
//触发函数
int Knife::isTrigger(int rete)
{
	int num = rand() % 100 + 1; 
	if (num < rete)
	{
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////

//大砍刀类
BroadSword::BroadSword()
{
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");
	map<string, map<string, string>> mapWeaponData;
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	string id = mapWeaponData["2"]["WeaponId"];
	weapoName = mapWeaponData[id]["WeaponName"];	//武器名称
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//基础攻击
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//暴击系数
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//暴击率
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//吸血系数
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//吸血率
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//冰冻率

}
//获得基础伤害
int BroadSword::getBaseDamage()
{
	return baseDamage;
}
//暴击效果  返回值大于0触发暴击
int BroadSword::getCrit()
{
	if (isTrigger(critRate))
	{
		return baseDamage * critPuls;
	}
	return 0;
}
//获得吸血 返回值大于0触发吸血
int BroadSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		return baseDamage * suckPuls;
	}
	return 0;	
}
///获得冰冻 返回值大于0则触发冰冻
int BroadSword::getFrozen()
{
	if (isTrigger(suckRate))
	{
		return 1;
	}
	return 0;
}
//触发函数
int BroadSword::isTrigger(int rete)
{
	int num = rand() % 100 + 1; 
	if (num < rete)
	{
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////

//屠龙刀类

DragonSword::DragonSword()
{
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");
	map<string, map<string, string>> mapWeaponData;	
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	string id = mapWeaponData["3"]["WeaponId"];	
	weapoName = mapWeaponData[id]["WeaponName"];	//武器名称
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//基础攻击
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//暴击系数
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//暴击率
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//吸血系数
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//吸血率
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//冰冻率

}

//获得基础伤害
int DragonSword::getBaseDamage()
{
	return baseDamage;
}
//暴击效果  返回值大于0触发暴击
int DragonSword::getCrit()
{
	if (isTrigger(critRate))
	{
		return baseDamage * critPuls;
	}
	return 0;	
}
//获得吸血 返回值大于0触发吸血
int DragonSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		return baseDamage * suckPuls;
	}
	return 0;	
}
///获得冰冻 返回值大于0则触发冰冻
int DragonSword::getFrozen()
{
	if (isTrigger(suckRate))
	{
		return 1;
	}
	return 0;	
}
//触发函数
int DragonSword::isTrigger(int rete)
{
	int num = rand() % 100 + 1;
	if (num < rete)
	{
		return true;
	}
	return false;
}
