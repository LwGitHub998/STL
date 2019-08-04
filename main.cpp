
#include "commnd.h"
#include "Hero.h"
#include "Monsters.h"
#include "Weapon.h"

void Fighting()
{
	cout << "游戏开始" << endl;
	cout << endl;
	//打印英雄
	FileManger f;	//只需创建一个就可以
	string Herofile = string("./Hero.csv");	//文件路径
	map<string, map<string, string>> mapHeroData;	//保存信息map
	f.LoadCsvFile(Herofile, mapHeroData);	//这里还可以直接传字符串，修改函数
	//auto it = mapHeroData["1"]["HeroName"].c_str();
	//auto it2 = mapHeroData["1"]["HeroInfo"].c_str();
	//printf("1、%s  %s", it, it2);
	cout << "1、" << mapHeroData["1"]["HeroName"].c_str() << "  "<< mapHeroData["1"]["HeroInfo"].c_str() << endl;
	cout << "2、" <<mapHeroData["2"]["HeroName"].c_str() << "  " << mapHeroData["2"]["HeroInfo"].c_str() << endl;
	cout << "3、" << mapHeroData["3"]["HeroName"].c_str() << "  " << mapHeroData["2"]["HeroInfo"].c_str() << endl;
	cout << "选择英雄：";
	int select = 0;
	while (cin >> select)	//缓冲区会有一个\n
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
	string Weaponfile = string("./Weapon.csv");	//文件路径
	map<string, map<string, string>> mapWeaponData;	//保存信息map
	f.LoadCsvFile(Weaponfile, mapWeaponData);
	cout << "1、赤手空拳" << endl;
	cout << "2、" <<  mapWeaponData["1"]["WeaponName"] << endl;
	cout << "3、" << mapWeaponData["2"]["WeaponName"] << endl;
	cout << "4、" << mapWeaponData["3"]["WeaponName"] << endl;
	cout << "选择武器：";
	select = 0;
	while (cin >> select)	//缓冲区会有一个\n
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
	
	//装备武器
	hero.pWeapon = weapon;
	
	//随机出一个怪物
	int id = rand() % 5 + 1;
	Monster monster(id);
	cout << "本轮怪物为：" << monster.MonsterName << endl;
	//PK开始
	int round = 1;
	while (1)
	{
		cout << endl;
		cout << "请输入任意键开始本回合" << endl;
		getchar();
		system("cls");	//清屏
		cout << "第" << round << "回合" << endl;
		cout << endl;
		//英雄攻击怪物
		hero.Attack(&monster);
		//怪物攻击英雄
		monster.Attack(&hero);
		cout << endl;
		cout << "英雄" << hero.HeroName << "剩余血量：" << hero.HeroHp << endl;
		cout << "怪物" << monster.MonsterName << "剩余血量：" << monster.MonsterHp << endl;
		cout << endl;
		
		if (0 >= hero.HeroHp)//判断死亡
		{
			cout << "英雄" << hero.HeroName << "死亡，本轮游戏失败!" << endl;
			break;
		}
		if (0 >= monster.MonsterHp)//判断死亡
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
	//读出数据放入整体的map中后作为参数传给hero类，但是为了简化main函数，将其放入类的构造函数中
	while (1)
	{
		Fighting();
		getchar();
		system("cls");
	}
	system("pause");
	return 0;
}
//优化
/*应该是def

将人物暴击时的伤害也加入计算，
把伤害计算等函数合并再一起，只留一个是否触发效果的函数，

但是这样就需要再英雄类的伤害函数中完成整体伤害的计算

也就是把触发函数设计成一个公共函数，其他函数也类似
但是这样多态就没有意义了，因为每次只创建一个武器类，再父类中
实现这些函数，再子类中设计各自的变量，应用继承

在一个类实现函数与定义变量，使用这个类创建一个武器对象就可以使用，
因为每次只需要使用一个武器类就可以类了，这就需要在流程函数中实现，
需要用户选择字符串然后进行判断，
优化一下界面

*/