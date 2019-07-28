#include <iostream>
#include<cstdlib>
#include<conio.h>
#include<stdlib.h>
#include "menuout.h"
#include "function.h"
#include"admin.h"
using namespace std;

menuout mo;//声明菜单输出类
function f;//声明功能类
aadmin a;//声明管理类



int main()
{
	int _menuget;
	void _yd();
	int _menu();
	void _deposit();
	void _draw();
	void _item();
	void _choice();
	system("mode con cols=120 lines=35");    //调整窗口大小
	cout << setiosflags(ios::fixed) << setprecision(2);//保留2位小数

	while (1)
	{
		_yd();
		while (1)
		{
			_menuget = _menu();
			switch (_menuget)
			{
			case 1:break;			//退出
			case 2:	_deposit(); continue; 				//充值
			case 3:	_choice(); continue;					//抽奖
			case 4:; _item(); continue;				//仓库
			}break;
		}continue;
	}


	system("pause");

	return 0;
}

//进入引导界面
void _yd()
{
	char yd_ch;//接受字符
	//注册界面
	do
	{


		system("cls");
		mo.name();//标题
		mo.menu();//引导菜单
		c.yellow();
		cout << "○请按下数字键\"1\"或者\"2\"或者\"3\"进行选择!";
		yd_ch = _getch();
		if (yd_ch == int('1'))
		{	//第一次登录注册
			if (user.firstsignin)
			{
				char namech;
				do {
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << c.blue() << "\t\t\t\t\t您是第一次登录，请输入用户名注册：" << endl;
					cout << "\t\t\t\t\t\t  (按回车键确认)" << endl<<endl;
					cout << "\t\t\t\t\t\t    "; c.white();
					f.userregister();
					cout << endl << endl << c.blue() << "\t\t\t    您确认使用 ";
					c.white();
					cout << user.name;
					cout << c.blue() << " 作为用户名吗？(按 \"Y\" 确认或按 \"N\" 重新输入)";
					namech = _getch();
					if (namech == 'Y' || namech == 'y')
					{
						user.firstsignin = 0;
						break;
					}
					else if (namech == 'N' || namech == 'n')
					{
						user.name[0] = 0; continue;
					}
				} while (1);
			}
		}
		//管理员界面
		else if (yd_ch == int('2'))
		{
			a.admin();
			continue;
		}
		//退出程序
		else if (yd_ch == int('3'))
			exit(1);
		else
		{
			system("cls");
			mo.name();//标题
			mo.menu();//引导菜单
			c.yellow();
			cout << "○您输入了";
			cout << c.red() << yd_ch;
			cout << c.yellow() << ",请重新输入\"1\"或者\"2\"或者\"3\"!";
		}
	} while (yd_ch != int('1'));
};

//进入主菜单界面
int _menu()
{
	char ch;
	int i = 0;
	system("cls");
	mo.name();//标题
	mo.headout();//水晶数量
	mo.welcome();//用户欢迎
	mo.box();//选项
	cout << c.yellow() << "○请输入对应的字母进行选择！（按\"E\"返回上级菜单）";
	do
	{
		ch = _getch();
		if (ch == 'a' || ch == 'A')							//充值
		{
			i = 2;
		}
		else if (ch == 'b' || ch == 'B')					//抽奖
		{
			i = 3;
		}
		else if (ch == 'c' || ch == 'C')					//仓库
		{
			i = 4;
		}
		else if (ch == 'e' || ch == 'E')					//返回
		{
			i = 1;
		}
		else
		{
			system("cls");
			mo.name();//标题
			mo.headout();//水晶数量
			mo.welcome();
			mo.box();//选项
			cout << c.yellow() << "○您输入了";
			cout << c.red() << ch;
			cout << c.yellow() << ",请重新输入\"A\"或者\"B\"或者\"C\"!（按\"E\"返回上级菜单）";
		}
	} while (i == 0);
	return i;
}

//进入充值界面
void _deposit()
{
	int i = 0;
	char ch, confirmch;
	system("cls");
	mo.name();//名字
	mo.headout();//水晶数量
	mo.deposit();//充值界面
	cout << c.yellow() << "○请输入对应套餐前的数字进行充值！(按\"E\"返回上级菜单）";
	do
	{
		ch = _getch();
		if (ch >= int('1') && ch <= int('7'))
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.deposit();//充值界面
			mo.confirm(int(ch - '0'));//确认充值
			confirmch = _getch();
			if (confirmch == 'y' || confirmch == 'Y')
				if (f.surebuy(int(ch - '0')))
				{
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.deposit();//充值界面
					cout << c.yellow() << "○充值成功！(按 数字键 继续充值或按\"E\"离开本页面）";
				}
				else
				{
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.deposit();//充值界面
					cout << c.yellow() << "○充值失败!请确认帐户内余额是否足够！(按 数字键 继续充值或按\"E\"离开本页面）";
				}

		}
		else if (ch == 'e' || ch == 'E')
			i = 1;
		else
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.deposit();//充值界面
			cout << c.yellow() << "○您输入了";
			cout << c.red() << ch;
			cout << c.yellow() << ",请重新输入\"1\"到\"7\"的数字!（按\"E\"返回上级菜单）";
		}

	} while (i == 0);
}
//进入游戏选择界面
void _choice()
{
	void _bangbangdraw();
	void _fangzhoudraw();
	void _ganhuai3draw();
	char ch;
	system("cls");
	mo.name();//名字
	mo.headout();//水晶数量
	mo.choice();//游戏选择
	cout << c.yellow() << "○请输入对应的数字选择你的游戏！(按\"E\"返回上级菜单）";
	do {
		ch = _getch();
		if (ch == '1')			//进入邦邦
		{
			_bangbangdraw();
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.choice();//游戏选择
			cout << c.yellow() << "○请输入对应的数字选择你的游戏！(按\"E\"返回上级菜单）";
			continue;
		}
		else if (ch == '2')		//进入方舟
		{
			_fangzhoudraw();
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.choice();//游戏选择
			cout << c.yellow() << "○请输入对应的数字选择你的游戏！(按\"E\"返回上级菜单）";
			continue;
		}
		else if (ch == '3')		//	进入肝坏3
		{
			_ganhuai3draw();
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.choice();//游戏选择
			cout << c.yellow() << "○请输入对应的数字选择你的游戏！(按\"E\"返回上级菜单）";
			continue;
		}
		else if (ch == 'e' || ch == 'E')
			break;
		else
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.choice();//游戏选择
			cout << c.yellow() << "○您输入了";
			cout << c.red() << ch;
			cout << c.yellow() << ",请重新输入\"1\"到\"3\"的数字!（按\"E\"返回上级菜单）";
		}


	} while (1);


}
//进入邦邦抽奖界面
void _bangbangdraw()
{
	char ch, drawch;
	int i = 0;
	system("cls");
	mo.name();//名字
	mo.headout();//水晶数量
	mo.bangbangdraw();//抽奖界面
	cout << c.yellow() << "○请输入\"A\"或\"B\"抽取卡片！(按\"E\"返回上级菜单）";
	do {
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.bangbangdraw();//抽奖界面
			cout << c.yellow() << "○确认进行";
			cout << c.red() << " 一次 ";
			cout << c.yellow() << "抽取？ 按";
			cout << c.red() << " Y ";
			cout << c.yellow() << "确认！(按\"E\"返回上级菜单）";
			drawch = _getch();
			if (drawch == 'Y' || drawch == 'y')						//确认抽奖   一次
			{
				if (f.ifcandraw(5))
				{
					int cardget;
					cardget = f.bangbangdrawone();
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.bangbangdraw();//抽奖界面
					//中奖输出
					cout << c.yellow() << "○您刚刚获得了 ";
					if (cardget == 0)
					{
						cout << c.pink() << "★★★★\t四星卡片";
						user.point[0] = 1;
					}
					else if (cardget == 1)
						cout << c.yellow() << "★★★  \t三星卡片";
					else if (cardget == 2)
						cout << c.green() << "★★    \t二星卡片";
					else if (cardget == 3)
						cout << c.white() << "★      \t一星卡片";
					cout << c.yellow() << "* 1!" << endl << endl << "(按 \"A\" 或 \"B\" 继续抽奖或者按 \"E\" 返回上级菜单)";

				}
				else
				{
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.bangbangdraw();//抽奖界面
					cout << c.yellow() << "○抽卡失败!请确水晶是否足够！(按 \"A\" 或 \"B\" 继续充值或按\"E\"离开本页面）";

				}
			}
			else if (drawch == 'e' || drawch == 'E')break;

		}
		else if (ch == 'b' || ch == 'B')
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.bangbangdraw();//抽奖界面
			cout << c.yellow() << "○确认进行";
			cout << c.red() << " 十次 ";
			cout << c.yellow() << "抽取？ 按";
			cout << c.red() << " Y ";
			cout << c.yellow() << "确认！(按\"E\"返回上级菜单）";
			drawch = _getch();

			if (drawch == 'Y' || drawch == 'y')//确认抽奖   十次
			{
				if (f.ifcandraw(50))
				{
					f.bangbangdrawten();
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.bangbangdraw();//抽奖界面
					//中奖输出
					cout << c.yellow() << "○您刚刚获得了\t";
					cout << c.pink() << "\b★★★★\t四星卡片";
					cout << c.yellow() << "\t* " << user.ten[0] << endl;

					cout << c.yellow() << "\t\t★★★  \t三星卡片";
					cout << c.yellow() << "\t* " << user.ten[1] << endl;

					cout << c.green() << "\t\t★★    \t二星卡片";
					cout << c.yellow() << "\t* " << user.ten[2] << endl;

					cout << c.white() << "\t\t★      \t一星卡片";
					cout << c.yellow() << "\t* " << user.ten[3] << endl;

					cout << c.yellow() << endl << "(按 \"A\" 或 \"B\" 继续抽奖或者按 \"E\" 返回上级菜单)";
				}
				else
				{
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.bangbangdraw();//抽奖界面
					cout << c.yellow() << "○抽卡失败!请确水晶是否足够！(按 \"A\" 或 \"B\" 继续抽奖或按\"E\"离开本页面）";

				}
			}
			else if (drawch == 'e' || drawch == 'E')break;

		}
		else if (ch == 'e' || ch == 'E')
			i = 1;
		else
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.bangbangdraw();//抽奖界面
			cout << c.yellow() << "○您输入了";
			cout << c.red() << ch;
			cout << c.yellow() << ",请重新输入\"A\"或\"B\"抽取卡片！(按\"E\"返回上级菜单）";
		}

	} while (i == 0);

}

//进入方舟抽奖界面
void _fangzhoudraw()
{
	char ch, drawch;
	int i = 0;
	system("cls");
	mo.name();//名字
	mo.headout();//水晶数量
	mo.fangzhoudraw();//抽奖界面
	cout << c.yellow() << "○请输入\"A\"寻访干员！(按\"E\"返回上级菜单）";
	do {
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.fangzhoudraw();//抽奖界面
			cout << c.yellow() << "○确认进行";
			cout << c.red() << " 一次 ";
			cout << c.yellow() << "寻访？ 按";
			cout << c.red() << " Y ";
			cout << c.yellow() << "确认！(按\"E\"返回上级菜单）";
			drawch = _getch();
			//确认寻访
			if (drawch == 'Y' || drawch == 'y')
			{
				if (f.ifcandraw(10))
				{
					int officelget;
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.fangzhoudraw();//抽奖界面
					officelget = f.fangzhoudrawone();
					cout << c.yellow() << "○您刚刚获得了\t";
					if (officelget == 0)
					{
						cout << c.pink() << "高资深干员";
						user.point[1] = 1;
					}
					else if (officelget == 1)
						cout << c.green() << "资深干员  ";
					else if (officelget == 2)
						cout << c.white() << "普通干员  ";
					cout << c.yellow() << " !" << endl << endl << "(按 \"A\" 继续抽奖或者按 \"E\" 返回上级菜单)";


				}
				else
				{
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.fangzhoudraw();//抽奖界面
					cout << c.yellow() << "○抽卡失败!请确水晶是否足够！(按 \"E\"离开本页面）";

				}

			}
		}
		else if (ch == 'e' || ch == 'E')
			break;
		else
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.fangzhoudraw();//抽奖界面
			cout << c.yellow() << "○您输入了";
			cout << c.red() << ch;
			cout << c.yellow() << ",请重新输入\"A\"或\"B\"抽取卡片！(按\"E\"返回上级菜单）";
		}




	} while (1);

}

//肝坏3抽奖界面
void _ganhuai3draw()
{
	int cost;
	char ch, outch;
	outch = 0;
	system("cls");
	mo.name();//名字
	mo.headout();//水晶数量
	mo.ganguai3draw();//抽奖界面
	cout << c.yellow() << "○请输入\"A\"招募女武神！(按\"E\"返回上级菜单）";
	do {
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.ganguai3draw();//抽奖界面
			cout << c.yellow() << "○请输入您决定使用多少水晶招募女武神：";
			do {
				system("cls");
				mo.name();//名字
				mo.headout();//水晶数量
				mo.ganguai3draw();//抽奖界面
				cout << c.yellow() << "○请输入您决定使用多少水晶招募女武神：";
				cin >> cost;
				if (cost < 20)
				{
					cin.clear();
					cin.ignore(1024, '\n');//防止输入非数字字符
					system("cls");
					mo.name();//名字
					mo.headout();//水晶数量
					mo.ganguai3draw();//抽奖界面
					cout << c.yellow() << "○您输入的水晶数量不正确！(按\"E\"返回上级菜单）";
					outch = _getch();
					if (outch == 'e' || outch == 'E')
						break;
				}
			} while (cost < 20);
			if (outch == 'e' || outch == 'E')
			{
				system("cls");
				mo.name();//名字
				mo.headout();//水晶数量
				mo.ganguai3draw();//抽奖界面
				cout << c.yellow() << "○按任意键返回上级菜单！";
				continue;
			}
			if (f.ifcandraw(cost))
			{
				int ganhuai;
				system("cls");
				mo.name();//名字
				mo.headout();//水晶数量
				mo.ganguai3draw();//抽奖界面
				ganhuai = f.ganghuai3drawone(cost);
				cout << c.yellow() << "○您刚刚获得了\t";
				if (ganhuai == 0)
				{
					cout << c.pink() << " SSS级女武神";
					user.point[2] = 1;
				}
				else if (ganhuai == 1)
					cout << c.yellow() << " SS级女武神";
				else if (ganhuai == 2)
					cout << c.green() << " S级女武神";
				else if (ganhuai == 3)
					cout << c.white() << " A级女武神";
				cout << c.yellow() << " !" << endl << endl << "(按 \"A\" 继续抽奖或者按 \"E\" 返回上级菜单)";
			}
			else
			{
				system("cls");
				mo.name();//名字
				mo.headout();//水晶数量
				mo.ganguai3draw();//抽奖界面
				cout << c.yellow() << "○抽卡失败!请确水晶是否足够！(按 \"E\"离开本页面）";
			}


		}
		else if (ch == 'e' || ch == 'E')
			break;
		else
		{
			system("cls");
			mo.name();//名字
			mo.headout();//水晶数量
			mo.ganguai3draw();//抽奖界面
			cout << c.yellow() << "○您输入了";
			cout << c.red() << ch;
			cout << c.yellow() << ",请重新输入\"A\"招募女武神！(按\"E\"返回上级菜单）";
		}

	} while (1);

}

//进入仓库
void _item()
{
	system("cls");
	mo.name();//名字
	mo.headout();//水晶数量
	mo.itemout();//仓库输出
	cout << c.yellow() << "○（按任意键返回上级菜单）";
	_getch();



}