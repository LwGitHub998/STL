#pragma once
#include "commnd.h"
////////////////////////////////////
//������
class Weapon
{
public:
	//ȫ�����Ǵ��麯�����������Ϊ����ʹ��
	//��û����˺�
	virtual int getBaseDamage() = 0;
	//����Ч��  ����ֵ����0��������
	virtual int getCrit() = 0;
	//�����Ѫ ����ֵ����0������Ѫ
	virtual int getSuckBlood() = 0;
	///��ñ��� ����ֵ����0�򴥷�����
	virtual int getFrozen() = 0;
	//��������
	//����Ч�� ����true�������
	//����Ч�� ����true������
	virtual int isTrigger(int rete) = 0;

public:
	string weapoName;	//��������
	int baseDamage;	//��������
	int critPuls;	//����ϵ��	//��ʾ��ɱ���ʱ����������ɶ����˺���Ĭ��Ӣ��û����ɱ����˺�
	int critRate;	//������
	int suckPuls;	//��Ѫϵ��
	int suckRate;	//��Ѫ��
	int frozenRate;	//������
};
/////////////////////////////////////////////
//С����
class Knife :public Weapon
{
public:
	//ʵ�ֶ��麯������д�����ɶ�̬

	//��ʼ��С������
	Knife();
	//��û����˺�
	virtual int getBaseDamage();
	//����Ч��  ����ֵ����0��������
	virtual int getCrit();
	//�����Ѫ ����ֵ����0������Ѫ
	virtual int getSuckBlood();
	///��ñ��� ����ֵ����0�򴥷�����
	virtual int getFrozen();
	//��������
	//����Ч�� ����true�������
	//����Ч�� ����true������
	virtual int isTrigger(int rete);
};
////////////////////////////////////
//�󿳵���
class BroadSword :public Weapon
{
public:
	//ʵ�ֶ��麯������д�����ɶ�̬

	//��ʼ��С������
	BroadSword();
	//��û����˺�
	virtual int getBaseDamage();
	//����Ч��  ����ֵ����0��������
	virtual int getCrit();
	//�����Ѫ ����ֵ����0������Ѫ
	virtual int getSuckBlood();
	///��ñ��� ����ֵ����0�򴥷�����
	virtual int getFrozen();
	//��������
	//����Ч�� ����true�������
	//����Ч�� ����true������
	virtual int isTrigger(int rete);
};
/////////////////////////////////
//��������
class DragonSword :public Weapon
{
public:
	//ʵ�ֶ��麯������д�����ɶ�̬

	//��ʼ��С������
	DragonSword();
	//��û����˺�
	virtual int getBaseDamage();
	//����Ч��  ����ֵ����0��������
	virtual int getCrit();
	//�����Ѫ ����ֵ����0������Ѫ
	virtual int getSuckBlood();
	///��ñ��� ����ֵ����0�򴥷�����
	virtual int getFrozen();
	//��������
	//����Ч�� ����true�������
	//����Ч�� ����true������
	virtual int isTrigger(int rete);
};