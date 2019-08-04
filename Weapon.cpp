#include "Weapon.h"

//只需实现一个类，其他的类都是类似的，

/////////////////////////////////////////////////////////
//小刀类
//初始化
Knife::Knife()
{
	//Weapon信息
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");	//文件路径
	map<string, map<string, string>> mapWeaponData;	//保存信息map
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	//获取id，方便后面的修改
	string id = mapWeaponData["1"]["WeaponId"];	//取出“1”, 有点像废话

	//string weapoName;	//武器名称
	//int baseDanage;	//基础攻击
	//int critPuls;	//暴击系数
	//int critRate;	//暴击率
	//int suckPuls;	//吸血系数
	//int suckRate;	//吸血率
	//int frozenRate;	//冰冻率

	//派生类中可以直接访问父类成员,而且map说通过key值直接查找value的，所以在表格中信息名称顺序无所谓
	weapoName = mapWeaponData[id]["WeaponName"];	//武器名称
	//需要把string类型的字符串转化为int，调用atoi函数
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//基础攻击
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//暴击系数
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//暴击率
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//吸血系数
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//吸血率
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//冰冻率

}
//再游戏流程函数中接受基础伤害和各种效果true或flase，然后再游戏流程中完成计算
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
		//触发暴击 返回基础伤害*暴击系数
		return baseDamage * critPuls;
	}
	return 0;	//表示未触发暴击
}
//获得吸血 返回值大于0触发吸血
int Knife::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		//触发吸血 返回基础伤害*吸血系数
		return baseDamage * suckPuls;
	}
	return 0;	//表示未触发暴击
}
///获得冰冻 返回值大于0则触发冰冻
int Knife::getFrozen()
{
	if (isTrigger(suckRate))	//触发冰冻
	{
		//触发冰冻 返回1
		return 1;
	}
	return 0;	//表示未触发冰冻
}
//触发函数
//冰冻效果 返回true代表冰冻
//暴击效果 返回true代表暴击
int Knife::isTrigger(int rete)	//rete 冰冻概率
{
	int num = rand() % 100 + 1; //1~100生成一个随机数
	if (num < rete)
	{
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////

//大砍刀类
//初始化
BroadSword::BroadSword()
{
	//Weapon信息
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");	//文件路径
	map<string, map<string, string>> mapWeaponData;	//保存信息map
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	//获取id，方便后面的修改
	string id = mapWeaponData["2"]["WeaponId"];	//取出“1”, 有点像废话

	//string weapoName;	//武器名称
	//int baseDanage;	//基础攻击
	//int critPuls;	//暴击系数
	//int critRate;	//暴击率
	//int suckPuls;	//吸血系数
	//int suckRate;	//吸血率
	//int frozenRate;	//冰冻率

	//派生类中可以直接访问父类成员,而且map说通过key值直接查找value的，所以在表格中信息名称顺序无所谓
	weapoName = mapWeaponData[id]["WeaponName"];	//武器名称
	//需要把string类型的字符串转化为int，调用atoi函数
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//基础攻击
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//暴击系数
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//暴击率
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//吸血系数
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//吸血率
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//冰冻率

}
//再游戏流程函数中接受基础伤害和各种效果true或flase，然后再游戏流程中完成计算
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
		//触发暴击 返回基础伤害*暴击系数
		return baseDamage * critPuls;
	}
	return 0;	//表示未触发暴击
}
//获得吸血 返回值大于0触发吸血
int BroadSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		//触发吸血 返回基础伤害*吸血系数
		return baseDamage * suckPuls;
	}
	return 0;	//表示未触发暴击
}
///获得冰冻 返回值大于0则触发冰冻
int BroadSword::getFrozen()
{
	if (isTrigger(suckRate))	//触发冰冻
	{
		//触发冰冻 返回1
		return 1;
	}
	return 0;	//表示未触发冰冻
}
//触发函数
//冰冻效果 返回true代表冰冻
//暴击效果 返回true代表暴击
int BroadSword::isTrigger(int rete)	//rete 冰冻概率
{
	int num = rand() % 100 + 1; //1~100生成一个随机数
	if (num < rete)
	{
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////

//屠龙刀类
//初始化
DragonSword::DragonSword()
{
	//Weapon信息
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");	//文件路径
	map<string, map<string, string>> mapWeaponData;	//保存信息map
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	//获取id，方便后面的修改
	string id = mapWeaponData["3"]["WeaponId"];	//取出“1”, 有点像废话

	//string weapoName;	//武器名称
	//int baseDanage;	//基础攻击
	//int critPuls;	//暴击系数
	//int critRate;	//暴击率
	//int suckPuls;	//吸血系数
	//int suckRate;	//吸血率
	//int frozenRate;	//冰冻率

	//派生类中可以直接访问父类成员,而且map说通过key值直接查找value的，所以在表格中信息名称顺序无所谓
	weapoName = mapWeaponData[id]["WeaponName"];	//武器名称
	//需要把string类型的字符串转化为int，调用atoi函数
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//基础攻击
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//暴击系数
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//暴击率
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//吸血系数
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//吸血率
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//冰冻率

}
//再游戏流程函数中接受基础伤害和各种效果true或flase，然后再游戏流程中完成计算
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
		//触发暴击 返回基础伤害*暴击系数
		return baseDamage * critPuls;
	}
	return 0;	//表示未触发暴击
}
//获得吸血 返回值大于0触发吸血
int DragonSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		//触发吸血 返回基础伤害*吸血系数
		return baseDamage * suckPuls;
	}
	return 0;	//表示未触发暴击
}
///获得冰冻 返回值大于0则触发冰冻
int DragonSword::getFrozen()
{
	if (isTrigger(suckRate))	//触发冰冻
	{
		//触发冰冻 返回1
		return 1;
	}
	return 0;	//表示未触发冰冻
}
//触发函数
//冰冻效果 返回true代表冰冻
//暴击效果 返回true代表暴击
int DragonSword::isTrigger(int rete)	//rete 冰冻概率
{
	int num = rand() % 100 + 1; //1~100生成一个随机数
	if (num < rete)
	{
		return true;
	}
	return false;
}