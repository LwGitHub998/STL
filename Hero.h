#pragma once
#include "commnd.h"
#include "Monsters.h"
#include "Weapon.h"

//������ǰ����
class Monster; //������
//Ӣ����
class Hero
{
public:
	Hero(int heroId);
	void Attack(Monster* monster);	//�����
	void EquipWeapon(Weapon* weapon);	//������
public:
	//HeroId, HeroName, HeapHp, HeroAtk, HeroDef, HeroInfo
	int HeroHp;	//����ֵ
	int HeroAtk;	//������
	int HeroDef;	//������
	string HeroName;	//����
	string HeroInfo;	//�ص�
	Weapon* pWeapon;	//������ָ��
};