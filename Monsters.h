#pragma once
#include "commnd.h"
#include "Hero.h"

class Hero;
//������
class Monster
{
public:
	Monster(int monsterId); //ָ�������
	void Attack(Hero* hero);	//��Ӣ��
public:
	//MonsterId,MonsterName,MonsterHp,MonsterAtk,MonsterDef
	string MonsterName;	//��������
	int MonsterHp;//����ֵ
	int MonsterAtk;	//������
	int MonsterDef;	//������
	bool isFrizen;	//�����Ƿ����
};