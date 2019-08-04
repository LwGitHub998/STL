#include "Hero.h"


//Ӣ����
Hero::Hero(int heroId)
{
	//Hero��Ϣ
	FileManger fh;	//ֻ�贴��һ���Ϳ���
	string Herofile = string("./Hero.csv");	//�ļ�·��
	map<string, map<string, string>> mapHeroData;	//������Ϣmap
	fh.LoadCsvFile(Herofile, mapHeroData);

	//idתstring
	string tmpId = std::to_string(heroId);
	//HeroId, HeroName, HeapHp, HeroAtk, HeroDef, HeroInfo
	//��ȡid�����������޸�
	string id = mapHeroData[tmpId]["HeroId"];
	//int HeroHp;	//����ֵ
	//int HeroAtk;	//������
	//int HeroDef;	//������
	//string HeroName;	//����
	//string HeroInfo;	//�ص�
	//Weapon* pWeapon;	//������ָ��
	HeroName = mapHeroData[id]["HeroName"];
	HeroInfo = mapHeroData[id]["HeroInfo"];
	HeroDef = atoi(mapHeroData[id]["HeroDef"].c_str());
	HeroAtk = atoi(mapHeroData[id]["HeroAtk"].c_str());
	HeroHp = atoi(mapHeroData[id]["HeroHp"].c_str());
	pWeapon = nullptr;
}
void Hero::Attack(Monster* monster)
{
	int crit = 0;	//����
	int suck = 0;	//��Ѫ
	int frozen = 0;		//����
	int damage = 0;	//�Թ�������˺�

	if (nullptr == pWeapon)
	{
		//û����������û�ж�����˺��ӳ�
		damage = HeroAtk;
		//������ʵ�˺�
		//cout << "Ӣ��" << HeroName << "�Թ���" << monster->MonsterName << "�����" << damage << "���˺�" << endl;
	}
	else
	{
		//�����˺�+���������˺�
		damage = HeroAtk + pWeapon->getBaseDamage();
		//�Ƿ񱩻� �����˺�*����ϵ��  ���������Ӣ�۹���*��������ϵ��
		crit = pWeapon->getCrit();
		//��Ѫ
		suck = pWeapon->getSuckBlood();
		//����
		frozen = pWeapon->getFrozen();
	}
	if (crit)	//��ɱ���
	{
		damage += crit;
		cout << "Ӣ��" << HeroName << "ʹ������" << pWeapon->weapoName << "��������Ч��,����" << monster->MonsterName << "�ܵ������˺�" << endl;
	}
	if (suck)
	{
		cout << "Ӣ��" << HeroName << "ʹ������" << pWeapon->weapoName << "������ѪЧ����Ӣ��������" << suck << "������ֵ" << endl;
	}
	if (frozen)
	{
		cout << "Ӣ��" << HeroName << "ʹ������" << pWeapon->weapoName << "��������Ч��������" << monster->MonsterName << "ֹͣ����һ�غ�" << endl;
		//�������
		monster->isFrizen = true;
	}


	//���¹��Ӣ����Ϣ
	//����Թ�����˺�
	int trueDamage = ((damage - monster->MonsterDef) > 0) ? damage - monster->MonsterDef : 1;
	//Ӣ����Ѫ
	HeroHp += suck;
	//���¹���Ѫ��
	monster->MonsterHp -= trueDamage;
	cout << "Ӣ��" << HeroName << "�Թ���" << monster->MonsterName << "�����" << trueDamage << "���˺�" << endl;
}
void Hero::EquipWeapon(Weapon* weapon)
{
	if (nullptr == weapon)	//�û�ûװ������
	{
		return;
	}
	pWeapon = weapon;	//Ӣ��װ������
	cout << "Ӣ��" << HeroName << "װ��" << pWeapon->weapoName << endl;
}