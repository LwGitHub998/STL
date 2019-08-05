
#include "common.h"
#include "Hero.h"
#include "Monsters.h"
#include "Weapon.h"

void Fighting()
{
	cout << "游戏开始" << endl;
	cout << endl;
	FileManger f;	
	string Herofile = string("./Hero.csv");
	map<string, map<string, string>> mapHeroData;	
	f.LoadCsvFile(Herofile, mapHeroData);	
	//auto it = mapHeroData["1"]["HeroName"].c_str();
	//auto it2 = mapHeroData["1"]["HeroInfo"].c_str();
	//printf("1、%s  %s", it, it2);
	cout << "1、" << mapHeroData["1"]["HeroName"].c_str() << "  "<< mapHeroData["1"]["HeroInfo"].c_str() << endl;
	cout << "2、" <<mapHeroData["2"]["HeroName"].c_str() << "  " << mapHeroData["2"]["HeroInfo"].c_str() << endl;
	cout << "3、" << mapHeroData["3"]["HeroName"].c_str() << "  " << mapHeroData["2"]["HeroInfo"].c_str() << endl;
	cout << "选择英雄：";
	int select = 0;
	while (cin >> select)
	{
		getchar();
		if (select >= 1 && select <= 3)
		{
			break;
		}
		cout << "选择错误,请重新输入：";
	}
	Hero hero(select);
	cout << "您选择的英雄是" << hero.HeroName << endl;
	cout << endl;
	string Weaponfile = string("./Weapon.csv");
	map<string, map<string, string>> mapWeaponData;
	f.LoadCsvFile(Weaponfile, mapWeaponData);
	cout << "1、赤手空拳" << endl;
	cout << "2、" <<  mapWeaponData["1"]["WeaponName"] << endl;
	cout << "3、" << mapWeaponData["2"]["WeaponName"] << endl;
	cout << "4、" << mapWeaponData["3"]["WeaponName"] << endl;
	cout << "选择武器：";
	select = 0;
	while (cin >> select)
	{
		getchar();
		if (select >= 1 && select <= 4)
		{
			break;
		}
		cout << "选择错误,请重新输入：";
	}
	cout << endl;
	Weapon* weapon = nullptr;
	switch (select)
	{
	case 1:
		cout << "您选择了赤手空拳" << endl;
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
		cout << "英雄" << hero.HeroName << "装备了" << weapon->weapoName << "，";
		cout << "增加了基础伤害" << weapon->baseDamage << "点，";
		cout << "暴击率：" << weapon->critRate << "%，";
		cout << "吸血率：" << weapon->suckRate << "%，";
		cout << "冰冻率：" << weapon->frozenRate << "%";
		cout << endl;
	}
	hero.pWeapon = weapon;
	int id = rand() % 5 + 1;
	Monster monster(id);
	cout << "本轮怪物为：" << monster.MonsterName << endl;
	int round = 1;
	while (1)
	{
		cout << endl;
		cout << "请输入任意键开始本回合" << endl;
		getchar();
		system("cls");	//清屏
		cout << "第" << round << "回合" << endl;
		cout << endl;
		hero.Attack(&monster);
		monster.Attack(&hero);
		cout << endl;
		cout << "英雄" << hero.HeroName << "剩余血量：" << hero.HeroHp << endl;
		cout << "怪物" << monster.MonsterName << "剩余血量：" << monster.MonsterHp << endl;
		cout << endl;
		
		if (0 >= hero.HeroHp)
		{
			cout << "英雄" << hero.HeroName << "死亡，本轮游戏失败!" << endl;
			break;
		}
		if (0 >= monster.MonsterHp)
		{
			cout << "怪物" << monster.MonsterName << "死亡，本轮游戏胜利!" << endl;
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
	while (1)
	{
		Fighting();
		getchar();
		system("cls");
	}
	system("pause");
	return 0;
}
