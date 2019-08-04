#include "Weapon.h"

//ֻ��ʵ��һ���࣬�������඼�����Ƶģ�

/////////////////////////////////////////////////////////
//С����
//��ʼ��
Knife::Knife()
{
	//Weapon��Ϣ
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");	//�ļ�·��
	map<string, map<string, string>> mapWeaponData;	//������Ϣmap
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	//��ȡid�����������޸�
	string id = mapWeaponData["1"]["WeaponId"];	//ȡ����1��, �е���ϻ�

	//string weapoName;	//��������
	//int baseDanage;	//��������
	//int critPuls;	//����ϵ��
	//int critRate;	//������
	//int suckPuls;	//��Ѫϵ��
	//int suckRate;	//��Ѫ��
	//int frozenRate;	//������

	//�������п���ֱ�ӷ��ʸ����Ա,����map˵ͨ��keyֱֵ�Ӳ���value�ģ������ڱ������Ϣ����˳������ν
	weapoName = mapWeaponData[id]["WeaponName"];	//��������
	//��Ҫ��string���͵��ַ���ת��Ϊint������atoi����
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//��������
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//����ϵ��
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//������
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//��Ѫϵ��
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//��Ѫ��
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//������

}
//����Ϸ���̺����н��ܻ����˺��͸���Ч��true��flase��Ȼ������Ϸ��������ɼ���
//������������˺�
int Knife::getBaseDamage()
{
	return baseDamage;
}
//����Ч��  ����ֵ����0��������
int Knife::getCrit()
{
	if (isTrigger(critRate))
	{
		//�������� ���ػ����˺�*����ϵ��
		return baseDamage * critPuls;
	}
	return 0;	//��ʾδ��������
}
//�����Ѫ ����ֵ����0������Ѫ
int Knife::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		//������Ѫ ���ػ����˺�*��Ѫϵ��
		return baseDamage * suckPuls;
	}
	return 0;	//��ʾδ��������
}
///��ñ��� ����ֵ����0�򴥷�����
int Knife::getFrozen()
{
	if (isTrigger(suckRate))	//��������
	{
		//�������� ����1
		return 1;
	}
	return 0;	//��ʾδ��������
}
//��������
//����Ч�� ����true�������
//����Ч�� ����true������
int Knife::isTrigger(int rete)	//rete ��������
{
	int num = rand() % 100 + 1; //1~100����һ�������
	if (num < rete)
	{
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////

//�󿳵���
//��ʼ��
BroadSword::BroadSword()
{
	//Weapon��Ϣ
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");	//�ļ�·��
	map<string, map<string, string>> mapWeaponData;	//������Ϣmap
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	//��ȡid�����������޸�
	string id = mapWeaponData["2"]["WeaponId"];	//ȡ����1��, �е���ϻ�

	//string weapoName;	//��������
	//int baseDanage;	//��������
	//int critPuls;	//����ϵ��
	//int critRate;	//������
	//int suckPuls;	//��Ѫϵ��
	//int suckRate;	//��Ѫ��
	//int frozenRate;	//������

	//�������п���ֱ�ӷ��ʸ����Ա,����map˵ͨ��keyֱֵ�Ӳ���value�ģ������ڱ������Ϣ����˳������ν
	weapoName = mapWeaponData[id]["WeaponName"];	//��������
	//��Ҫ��string���͵��ַ���ת��Ϊint������atoi����
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//��������
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//����ϵ��
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//������
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//��Ѫϵ��
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//��Ѫ��
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//������

}
//����Ϸ���̺����н��ܻ����˺��͸���Ч��true��flase��Ȼ������Ϸ��������ɼ���
//��û����˺�
int BroadSword::getBaseDamage()
{
	return baseDamage;
}
//����Ч��  ����ֵ����0��������
int BroadSword::getCrit()
{
	if (isTrigger(critRate))
	{
		//�������� ���ػ����˺�*����ϵ��
		return baseDamage * critPuls;
	}
	return 0;	//��ʾδ��������
}
//�����Ѫ ����ֵ����0������Ѫ
int BroadSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		//������Ѫ ���ػ����˺�*��Ѫϵ��
		return baseDamage * suckPuls;
	}
	return 0;	//��ʾδ��������
}
///��ñ��� ����ֵ����0�򴥷�����
int BroadSword::getFrozen()
{
	if (isTrigger(suckRate))	//��������
	{
		//�������� ����1
		return 1;
	}
	return 0;	//��ʾδ��������
}
//��������
//����Ч�� ����true�������
//����Ч�� ����true������
int BroadSword::isTrigger(int rete)	//rete ��������
{
	int num = rand() % 100 + 1; //1~100����һ�������
	if (num < rete)
	{
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////

//��������
//��ʼ��
DragonSword::DragonSword()
{
	//Weapon��Ϣ
	FileManger fw;
	string Weaponfile = string("./Weapon.csv");	//�ļ�·��
	map<string, map<string, string>> mapWeaponData;	//������Ϣmap
	fw.LoadCsvFile(Weaponfile, mapWeaponData);
	//��ȡid�����������޸�
	string id = mapWeaponData["3"]["WeaponId"];	//ȡ����1��, �е���ϻ�

	//string weapoName;	//��������
	//int baseDanage;	//��������
	//int critPuls;	//����ϵ��
	//int critRate;	//������
	//int suckPuls;	//��Ѫϵ��
	//int suckRate;	//��Ѫ��
	//int frozenRate;	//������

	//�������п���ֱ�ӷ��ʸ����Ա,����map˵ͨ��keyֱֵ�Ӳ���value�ģ������ڱ������Ϣ����˳������ν
	weapoName = mapWeaponData[id]["WeaponName"];	//��������
	//��Ҫ��string���͵��ַ���ת��Ϊint������atoi����
	baseDamage = atoi(mapWeaponData[id]["WeaponAtk"].c_str());	//��������
	critPuls = atoi(mapWeaponData[id]["WeaponCritPlus"].c_str());	//����ϵ��
	critRate = atoi(mapWeaponData[id]["WeaponCritRate"].c_str());	//������
	suckPuls = atoi(mapWeaponData[id]["WeaponSuckPlus"].c_str());	//��Ѫϵ��
	suckRate = atoi(mapWeaponData[id]["WeaponSuckRate"].c_str());	//��Ѫ��
	frozenRate = atoi(mapWeaponData[id]["WeaponFrozenRate"].c_str());	//������

}
//����Ϸ���̺����н��ܻ����˺��͸���Ч��true��flase��Ȼ������Ϸ��������ɼ���
//��û����˺�
int DragonSword::getBaseDamage()
{
	return baseDamage;
}
//����Ч��  ����ֵ����0��������
int DragonSword::getCrit()
{
	if (isTrigger(critRate))
	{
		//�������� ���ػ����˺�*����ϵ��
		return baseDamage * critPuls;
	}
	return 0;	//��ʾδ��������
}
//�����Ѫ ����ֵ����0������Ѫ
int DragonSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		//������Ѫ ���ػ����˺�*��Ѫϵ��
		return baseDamage * suckPuls;
	}
	return 0;	//��ʾδ��������
}
///��ñ��� ����ֵ����0�򴥷�����
int DragonSword::getFrozen()
{
	if (isTrigger(suckRate))	//��������
	{
		//�������� ����1
		return 1;
	}
	return 0;	//��ʾδ��������
}
//��������
//����Ч�� ����true�������
//����Ч�� ����true������
int DragonSword::isTrigger(int rete)	//rete ��������
{
	int num = rand() % 100 + 1; //1~100����һ�������
	if (num < rete)
	{
		return true;
	}
	return false;
}