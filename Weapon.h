#pragma once
#include "commnd.h"
////////////////////////////////////
//武器类
class Weapon
{
public:
	//全部都是纯虚函数，这个类作为基类使用
	//获得基础伤害
	virtual int getBaseDamage() = 0;
	//暴击效果  返回值大于0触发暴击
	virtual int getCrit() = 0;
	//获得吸血 返回值大于0触发吸血
	virtual int getSuckBlood() = 0;
	///获得冰冻 返回值大于0则触发冰冻
	virtual int getFrozen() = 0;
	//触发函数
	//冰冻效果 返回true代表冰冻
	//暴击效果 返回true代表暴击
	virtual int isTrigger(int rete) = 0;

public:
	string weapoName;	//武器名称
	int baseDamage;	//基础攻击
	int critPuls;	//暴击系数	//表示造成暴击时武器额外造成多少伤害，默认英雄没有造成暴击伤害
	int critRate;	//暴击率
	int suckPuls;	//吸血系数
	int suckRate;	//吸血率
	int frozenRate;	//冰冻率
};
/////////////////////////////////////////////
//小刀类
class Knife :public Weapon
{
public:
	//实现对虚函数的重写，构成多态

	//初始化小刀属性
	Knife();
	//获得基础伤害
	virtual int getBaseDamage();
	//暴击效果  返回值大于0触发暴击
	virtual int getCrit();
	//获得吸血 返回值大于0触发吸血
	virtual int getSuckBlood();
	///获得冰冻 返回值大于0则触发冰冻
	virtual int getFrozen();
	//触发函数
	//冰冻效果 返回true代表冰冻
	//暴击效果 返回true代表暴击
	virtual int isTrigger(int rete);
};
////////////////////////////////////
//大砍刀类
class BroadSword :public Weapon
{
public:
	//实现对虚函数的重写，构成多态

	//初始化小刀属性
	BroadSword();
	//获得基础伤害
	virtual int getBaseDamage();
	//暴击效果  返回值大于0触发暴击
	virtual int getCrit();
	//获得吸血 返回值大于0触发吸血
	virtual int getSuckBlood();
	///获得冰冻 返回值大于0则触发冰冻
	virtual int getFrozen();
	//触发函数
	//冰冻效果 返回true代表冰冻
	//暴击效果 返回true代表暴击
	virtual int isTrigger(int rete);
};
/////////////////////////////////
//屠龙刀类
class DragonSword :public Weapon
{
public:
	//实现对虚函数的重写，构成多态

	//初始化小刀属性
	DragonSword();
	//获得基础伤害
	virtual int getBaseDamage();
	//暴击效果  返回值大于0触发暴击
	virtual int getCrit();
	//获得吸血 返回值大于0触发吸血
	virtual int getSuckBlood();
	///获得冰冻 返回值大于0则触发冰冻
	virtual int getFrozen();
	//触发函数
	//冰冻效果 返回true代表冰冻
	//暴击效果 返回true代表暴击
	virtual int isTrigger(int rete);
};