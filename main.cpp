
#include "commnd.h"
#include "Hero.h"
#include "Monsters.h"
#include "Weapon.h"

void Fighting()
{
	cout << "��Ϸ��ʼ" << endl;
	cout << endl;
	//��ӡӢ��
	FileManger f;	//ֻ�贴��һ���Ϳ���
	string Herofile = string("./Hero.csv");	//�ļ�·��
	map<string, map<string, string>> mapHeroData;	//������Ϣmap
	f.LoadCsvFile(Herofile, mapHeroData);	//���ﻹ����ֱ�Ӵ��ַ������޸ĺ���
	//auto it = mapHeroData["1"]["HeroName"].c_str();
	//auto it2 = mapHeroData["1"]["HeroInfo"].c_str();
	//printf("1��%s  %s", it, it2);
	cout << "1��" << mapHeroData["1"]["HeroName"].c_str() << "  "<< mapHeroData["1"]["HeroInfo"].c_str() << endl;
	cout << "2��" <<mapHeroData["2"]["HeroName"].c_str() << "  " << mapHeroData["2"]["HeroInfo"].c_str() << endl;
	cout << "3��" << mapHeroData["3"]["HeroName"].c_str() << "  " << mapHeroData["2"]["HeroInfo"].c_str() << endl;
	cout << "ѡ��Ӣ�ۣ�";
	int select = 0;
	while (cin >> select)	//����������һ��\n
	{
		getchar();
		if (select >= 1 && select <= 3)
		{
			break;
		}
		cout << "ѡ�����,���������룺";
	}
	Hero hero(select);
	cout << "��ѡ���Ӣ����" << hero.HeroName << endl;
	cout << endl;
	string Weaponfile = string("./Weapon.csv");	//�ļ�·��
	map<string, map<string, string>> mapWeaponData;	//������Ϣmap
	f.LoadCsvFile(Weaponfile, mapWeaponData);
	cout << "1�����ֿ�ȭ" << endl;
	cout << "2��" <<  mapWeaponData["1"]["WeaponName"] << endl;
	cout << "3��" << mapWeaponData["2"]["WeaponName"] << endl;
	cout << "4��" << mapWeaponData["3"]["WeaponName"] << endl;
	cout << "ѡ��������";
	select = 0;
	while (cin >> select)	//����������һ��\n
	{
		getchar();
		if (select >= 1 && select <= 4)
		{
			break;
		}
		cout << "ѡ�����,���������룺";
	}
	cout << endl;
	Weapon* weapon = nullptr;
	switch (select)
	{
	case 1:
		cout << "��ѡ���˳��ֿ�ȭ" << endl;
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new BroadSword;
		break;
	case 4:
		weapon = new DragonSword;
		break;
	}
	if (select != 1)
	{
		cout << "Ӣ��" << hero.HeroName << "װ����" << weapon->weapoName << "��";
		cout << "�����˻����˺�" << weapon->baseDamage << "�㣬";
		cout << "�����ʣ�" << weapon->critRate << "%��";
		cout << "��Ѫ�ʣ�" << weapon->suckRate << "%��";
		cout << "�����ʣ�" << weapon->frozenRate << "%";
		cout << endl;
	}
	
	//װ������
	hero.pWeapon = weapon;
	
	//�����һ������
	int id = rand() % 5 + 1;
	Monster monster(id);
	cout << "���ֹ���Ϊ��" << monster.MonsterName << endl;
	//PK��ʼ
	int round = 1;
	while (1)
	{
		cout << endl;
		cout << "�������������ʼ���غ�" << endl;
		getchar();
		system("cls");	//����
		cout << "��" << round << "�غ�" << endl;
		cout << endl;
		//Ӣ�۹�������
		hero.Attack(&monster);
		//���﹥��Ӣ��
		monster.Attack(&hero);
		cout << endl;
		cout << "Ӣ��" << hero.HeroName << "ʣ��Ѫ����" << hero.HeroHp << endl;
		cout << "����" << monster.MonsterName << "ʣ��Ѫ����" << monster.MonsterHp << endl;
		cout << endl;
		
		if (0 >= hero.HeroHp)//�ж�����
		{
			cout << "Ӣ��" << hero.HeroName << "������������Ϸʧ��!" << endl;
			break;
		}
		if (0 >= monster.MonsterHp)//�ж�����
		{
			cout << "����" << monster.MonsterName << "������������Ϸʤ��!" << endl;
			break;
		}
		round++;
	}
	if (weapon != nullptr)
	{
		delete weapon;
	}
 }
int main()
{
	srand((unsigned)time(NULL));
	//�������ݷ��������map�к���Ϊ��������hero�࣬����Ϊ�˼�main���������������Ĺ��캯����
	while (1)
	{
		Fighting();
		getchar();
		system("cls");
	}
	system("pause");
	return 0;
}
//�Ż�
/*Ӧ����def

�����ﱩ��ʱ���˺�Ҳ������㣬
���˺�����Ⱥ����ϲ���һ��ֻ��һ���Ƿ񴥷�Ч���ĺ�����

������������Ҫ��Ӣ������˺���������������˺��ļ���

Ҳ���ǰѴ���������Ƴ�һ��������������������Ҳ����
����������̬��û�������ˣ���Ϊÿ��ֻ����һ�������࣬�ٸ�����
ʵ����Щ����������������Ƹ��Եı�����Ӧ�ü̳�

��һ����ʵ�ֺ����붨�������ʹ������ഴ��һ����������Ϳ���ʹ�ã�
��Ϊÿ��ֻ��Ҫʹ��һ��������Ϳ������ˣ������Ҫ�����̺�����ʵ�֣�
��Ҫ�û�ѡ���ַ���Ȼ������жϣ�
�Ż�һ�½���

*/