#include "Monsters.h"


//������
Monster::Monster(int monsterId) //ָ�������
{
	//Monsters��Ϣ
	FileManger fm;
	string Monstersfile = string("./Monsters.csv");	//�ļ�·��
	map<string, map<string, string>> mapMonstersData;	//������Ϣmap
	fm.LoadCsvFile(Monstersfile, mapMonstersData);
	string tmpId = std::to_string(monsterId);
	//��ȡid�����������޸�
	//MonsterId,MonsterName,MonsterHp,MonsterAtk,MonsterDef
	string id = mapMonstersData[tmpId]["MonsterId"];
	MonsterName = mapMonstersData[id]["MonsterName"];;
	MonsterHp = atoi(mapMonstersData[id]["MonsterHp"].c_str());//Ѫ��
	MonsterAtk = atoi(mapMonstersData[id]["MonsterAtk"].c_str());	//������
	MonsterDef = atoi(mapMonstersData[id]["MonsterDef"].c_str());	//������
	isFrizen = false;	//Ĭ��û�б����� 
}
void Monster::Attack(Hero* hero)	//��Ӣ��
{
	//�жϹ����Ƿ񱾱�����������ﱻ��������ֹͣ����һ�غ�
	if (isFrizen)
	{
		//����
		//˭���ȹ���˵����
		cout << "����" << MonsterName << "��������ֹͣ����һ�غ�" << endl;
		isFrizen = false;
		return;
		
	}
	//�����Ӣ�۵��˺� 
	//�����˺�-Ӣ�۷�����
	int damage = ((MonsterAtk - hero->HeroDef) > 0) ? (MonsterAtk - hero->HeroDef) : 1;
	//Ӣ�۵�����ֵ
	hero->HeroHp -= damage;
	cout << "����" << MonsterName << "��Ӣ��" << hero->HeroName << "�����" << damage << "���˺�" << endl;
}