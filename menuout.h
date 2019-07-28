#include <iostream>
#include <string>
#include <iomanip>
#include "color.h"
#include "sql.h"
using namespace std;

information user;			//1,1000,0
color c;

void special(int i, char ch)								//自定->输出多少个字符
{
	for (int j = 0; j < i; j++)
		cout << ch;
}

//分隔线
void cut()
{
	int i;
	c.blue();
	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;
}

//计算
void count()
{
	user.officalscore = user.official[0] * 2500 + user.official[1] * 500 + user.official[2] * 100;
	user.nvwushenscore = user.nvwushen[0] * 10000 + user.nvwushen[1] * 5000 + user.nvwushen[2] * 100 + user.nvwushen[3] * 50;
	user.cardscore = user.card[0] * 1000 + user.card[1] * 500 + user.card[2] * 100 + user.card[3] * 10;
	if (user.cardscore + user.officalscore + user.nvwushenscore >= 15000)
		user.point[3] = 1;
	user.allgamesj = user.bangbangsj + user.ganhuaisj + user.officalsj;
}

class menuout			//定义菜单输出类
{
public:

	//用户欢迎
	void welcome()
	{
		cout << c.blue() << "\t欢迎回来! 玩家 ";
		c.green();
		cout << user.name;
		cout << c.blue() << "!" << endl;
	}


	//顶部名称
	void name()
	{
		int i = 0;
		for (i = 0; i < 48; i++)
			cout << char(32);
		c.white();
		cout << "手游虚拟氪金奖池系统" << endl;

	}

	//引导界面
	void menu()
	{
		int i, j;
		cut();
		for (i = 0; i < 9; i++)
			cout << endl;
		c.white();
		for (j = 0; j < 55; j++)
			cout << char(32);
		cout << "1.进入系统" << endl << endl << endl;
		for (j = 0; j < 55; j++)
			cout << char(32);
		cout << "2.管理员登录" << endl << endl << endl;
		for (j = 0; j < 55; j++)
			cout << char(32);
		cout << "3.退出系统" << endl;

		for (i = 0; i < 9; i++)
			cout << endl;
		cut();
	}
	//菜单顶部金钱和钻石输出
	void headout()
	{
		int i = 0;
		c.blue();																					//第一行直线
		for (i = 0; i < 120; i++)
			cout << "-";
		cout << endl;
		count();
		//输出金钱和钻石
		c.indigo();
		cout.setf(ios::right, ios::adjustfield);
		cout.fill(' ');
		cout << "      ▆支付宝余额：" << setw(7) << user.outrmb() << " 元";
		cout << "\t\t\t★水晶： " << setw(7) << user.outsj() << " 个";
		cout << "\t\t\t◆成就点数：";
		for (i = 0; i < 4; i++)
			if (user.point[i])
				cout << c.blue() << "\b■";
			else
				cout << c.blue() << "\b□";
		cout << " " << 25 * user.point[0] + 25 * user.point[1] + 25 * user.point[2] + 25 * user.point[3] << "%";
		cout << endl;
		//第二行直线
		c.blue();
		for (i = 0; i < 120; i++)
			cout << "-";
		cout << endl;
	}
	//菜单中间选项输出
	void box()
	{
		int i, j, k;																					//box-top
		cout << "\n";
		c.red();
		for (k = 0; k < 3; k++)
		{
			for (i = 0; i < 6; i++)
				cout << char(32);
			for (j = 0; j < 32; j++)
				cout << "-";
		}
		cout << endl;
		//box上半部分
		for (k = 0; k < 9; k++)
		{
			for (j = 0; j < 3; j++)
			{
				for (i = 0; i < 6; i++)
					cout << char(32);
				cout << "|";
				for (i = 0; i < 30; i++)
					cout << char(32);
				cout << "|";

			}
			cout << endl;
		}
		//box带字部分
		for (k = 0; k < 3; k++)
		{
			for (i = 0; i < 6; i++)
				cout << char(32);
			cout << "|";
			for (j = 0; j < 12; j++)
				cout << char(32);
			c.yellow();
			if (k == 0)
				cout << "充  值";
			else if (k == 1)
				cout << "抽  奖";
			else if (k == 2)
				cout << "档  案";
			c.red();
			for (j = 0; j < 12; j++)
				cout << char(32);
			cout << "|";
		}
		cout << endl;
		//box下半部分
		for (k = 0; k < 9; k++)
		{
			for (j = 0; j < 3; j++)
			{
				for (i = 0; i < 6; i++)
					cout << char(32);
				cout << "|";
				for (i = 0; i < 30; i++)
					cout << char(32);
				cout << "|";

			}
			cout << endl;
		}
		//box选项
		for (k = 0; k < 3; k++)
		{
			for (i = 0; i < 6; i++)
				cout << char(32);
			cout << "|";
			for (j = 0; j < 12; j++)
				cout << char(32);
			if (k == 0)
				cout << "   A  ";
			else if (k == 1)
				cout << "   B  ";
			else if (k == 2)
				cout << "   C  ";
			for (j = 0; j < 12; j++)
				cout << char(32);
			cout << "|";
		}
		cout << endl;
		//最后一行
		for (k = 0; k < 3; k++)
		{
			for (i = 0; i < 6; i++)
				cout << char(32);
			for (j = 0; j < 32; j++)
				cout << "-";
		}
		cout << "\n\n";
		c.blue();
		for (i = 0; i < 120; i++)
			cout << "-";
		cout << endl;
	}
	//充值界面
	void deposit()
	{
		int i;
		cout << endl;
		cout << c.red() << "\t■活动期间首次充值可享受";
		cout << c.pink() << " 2倍★水晶 ";
		cout << c.red() << "优惠！" << endl;
		cout << endl;
		for (i = 0; i < 60; i++)
		{
			c.blue();
			cout << "■";
		}
		cout << endl << endl;
		//输出套餐
		for (i = 0; i < 7; i++)
		{
			cout << c.white() << "\t套餐 " << i + 1 << ": 使用 ";
			cout.width(4);
			cout << user.first[0][i] << " 元充值  ";
			cout.width(4);
			cout << user.diamond[i];
			if (user.first[1][i])
			{
				cout << c.pink() << "+ ";
				cout.width(4);
				cout << user.diamond[i];
			}
			cout << c.white() << "枚★水晶" << endl << endl;
		}
		cout << endl << c.red() << "(请注意，通过任何形式充值的水晶无法返还成人民币，请理性充值！）";
		cout << endl << endl << endl;
		cut();
	}
	//确认充值
	void confirm(int i)
	{
		cout << c.yellow() << "○您选择了 套餐" << i << " 使用";
		cout.width(3);
		cout << c.white() << user.first[0][i - 1];
		cout << c.yellow() << "元充值";
		cout.width(4);
		cout << user.diamond[i - 1];
		if (user.first[1][i - 1])
		{
			cout << c.pink() << "+ ";
			cout.width(4);
			cout << user.diamond[i - 1];
		}
		cout << c.yellow() << "枚★水晶,";
		cout << c.yellow() << "按";
		cout << c.red() << " Y ";
		cout << c.yellow() << "进行确认!(按 E 返回上级菜单)";
	}

	//选择游戏界面输出
	void choice()
	{
		cout << c.blue() << "\t\t\t\t\t\t  SBEAM 游 戏 库" << endl << endl << "\t■  嗨~";
		cout << c.green() << user.name;
		cout << c.blue() << " ,您目前拥有以下游戏！" << endl << endl << endl;
		cout << c.yellow() << "\b\t1. 邦邦乐队" << endl << endl;
		cout << "\t2. 明年方舟" << endl << endl;
		cout << "\t3. 肝坏3" << endl << endl;
		special(10, '\n');
		cut();


	}

	//邦邦抽奖界面输出
	void bangbangdraw()
	{
		int i, j;

		cout.setf(ios::left, ios::adjustfield);
		cout.fill(' ');

		//说明部分
		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.red();
		cout << setw(59) << "        ■邦邦乐队 奖池中获取卡片概率如下";
		cout << c.blue() << "|";
		cout << c.red() << "\t\t■邦邦乐队 连续进行十次抽取" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.pink();
		cout << setw(59) << "        ★★★★ 四星卡片        获取概率   4%";
		cout << c.blue() << "|";
		cout << c.white() << "\t\t连续进行十次抽取，获奖概率与单抽相同" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.yellow();
		cout << setw(59) << "        ★★★   三星卡片        获取概率   16%";
		cout << c.blue() << "|";
		cout << c.white() << "\t\t在一次十连抽取中，至少获得一张" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.green();
		cout << setw(59) << "        ★★     二星卡片        获取概率   32%";
		cout << c.blue() << "|";
		cout << c.yellow() << "\t\t★★★\t 三星卡片 ";
		cout << c.white() << "或 ";
		cout << c.pink() << "★★★★\t四星卡片" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.white();
		cout << setw(59) << "        ★       一星卡片        获取概率   48%";
		cout << c.blue() << "|";
		cout << endl;

		//空白部分
		for (j = 0; j < 5; j++)
		{
			for (i = 0; i < 59; i++) cout << " ";
			cout << c.blue() << "|" << endl;

		}


		//方框部分
			//顶端
		for (i = 0; i < 15; i++) cout << " ";
		for (i = 0; i < 30; i++)
		{
			c.red();
			cout << "-";
		}
		for (i = 0; i < 14; i++) cout << " ";
		cout << c.blue() << "|";

		for (i = 0; i < 15; i++) cout << " ";
		for (i = 0; i < 30; i++)
		{
			c.red();
			cout << "-";
		}
		cout << endl;

		//中间空行
		special(14, ' ');
		cout << c.red() << "|";
		special(27, ' ');
		cout << c.red() << "|";
		special(14, ' ');

		cout << c.blue() << "|";

		special(14, ' ');
		cout << c.red() << "|";
		special(27, ' ');
		cout << c.red() << "|";
		cout << endl;

		//中间文字
		special(14, ' ');
		cout << c.red() << "|";
		special(10, ' ');
		cout << "抽 一 次";
		special(9, ' ');
		cout << c.red() << "|";
		special(14, ' ');

		cout << c.blue() << "|";

		special(14, ' ');
		cout << c.red() << "|";
		special(9, ' ');
		cout << "抽 十 次";
		special(10, ' ');
		cout << c.red() << "|";
		cout << endl;

		special(14, ' ');
		cout << c.red() << "|";
		special(7, ' ');
		cout << "(消耗 5 水晶)";
		special(7, ' ');
		cout << c.red() << "|";
		special(14, ' ');

		cout << c.blue() << "|";

		special(14, ' ');
		cout << c.red() << "|";
		special(7, ' ');
		cout << "(消耗 50 水晶)";
		special(6, ' ');
		cout << c.red() << "|";
		cout << endl;


		//中间字母
		special(14, ' ');
		cout << c.red() << "|";
		special(13, ' ');
		cout << "A";
		special(13, ' ');
		cout << c.red() << "|";
		special(14, ' ');

		cout << c.blue() << "|";

		special(14, ' ');
		cout << c.red() << "|";
		special(13, ' ');
		cout << "B";
		special(13, ' ');
		cout << c.red() << "|";
		cout << endl;

		//底端
		for (i = 0; i < 15; i++) cout << " ";
		for (i = 0; i < 30; i++)
		{
			c.red();
			cout << "-";
		}
		for (i = 0; i < 14; i++) cout << " ";
		cout << c.blue() << "|";

		for (i = 0; i < 15; i++) cout << " ";
		for (i = 0; i < 30; i++)
		{
			c.red();
			cout << "-";
		}
		cout << endl;

		//空白部分
		for (j = 0; j < 2; j++)
		{
			for (i = 0; i < 59; i++) cout << " ";
			cout << c.blue() << "|" << endl;

		}

		cut();
	}

	//方舟抽奖界面输出
	void fangzhoudraw()
	{
		cout << c.red() << endl << "\t■ 明年方舟 寻访的规则如下：" << endl << endl;
		cout << c.white() << "\t※在 明年方舟 干员寻访中，全部可能寻访到的干员※" << endl << endl;
		cout << c.pink() << "\t\t高资深干员";
		cout << c.white() << "（2 % ）";

		//高资深概率顶部
		c.red(), special(5, '\t'), special(38, '-'), special(1, '\n');

		c.white(), special(16, ' '), special(15, '-');
		//一行竖线
		c.red(), special(6, '\t'), cout << "|", special(36, ' '), cout << "|", special(1, '\n');

		cout << c.green() << "\t\t资深干员  ";
		cout << c.white() << "（8 % ）";

		cout.setf(ios::left, ios::adjustfield);
		cout.fill(' ');

		cout << c.red() << "\t\t\t\t\t| 当前获得 ";
		cout << c.pink() << "高资深干员";
		cout << c.red() << "的概率为";
		cout << c.pink() << setw(4) << 2 + user.p;
		cout << c.red() << "\b\b% |" << endl;

		c.white(), special(16, ' '), special(15, '-');
		//二行竖线
		c.red(), special(6, '\t'), cout << "|", special(36, ' '), cout << "|", special(1, '\n');

		cout << c.white() << "\t\t普通干员  ";
		cout << c.white() << "（50 % ）";

		//高概底部
		c.red(), special(5, '\t'), special(38, '-'), special(1, '\n');

		c.white(), special(16, ' '), special(15, '-'), special(1, '\n');
		cout << endl << "\t在所有【标准寻访】中，如果单次寻访没有获得 ";
		cout << c.pink() << "高资深干员 ";
		cout << c.white() << "\n\n\t则下一次寻访获得 ";
		cout << c.pink() << "高资深干员 ";
		cout << c.white() << "的概率将从原本的 ";
		cout << c.pink() << "2%";
		cout << c.white() << "提升到 ";
		cout << c.pink() << "4%";
		cout << c.white() << "\n\n\t如果该次还没有寻访到 ";
		cout << c.pink() << "高资深干员 ";
		cout << c.white() << "\n\n\t则下一次寻访获得 ";
		cout << c.pink() << "高资深干员 ";
		cout << c.white() << "的概率由 ";
		cout << c.pink() << "4%";
		cout << c.white() << "提升到 ";
		cout << c.pink() << "6%";
		cout << c.white() << "\n\n\t以此类推，每次提高 2% 的概率，直至达到100%时必定获得 ";
		cout << c.pink() << "高资深干员 ";
		special(3, '\n');
		cut();
	}


	//肝坏3抽奖界面输出
	void ganguai3draw()
	{
		cout << endl;
		cout << c.red() << "\t\t\t\t\t\t※肝坏3女武神招募界面※" << endl << endl;
		cout << c.red() << "\t■在本界面中您可以通过消耗水晶招募女武神对抗肝坏的世界！" << endl << endl;
		cout << c.green() << "\t  " << user.name;
		cout << c.white() << ",当你投入水晶时可以获得以下";
		cout << c.yellow() << "女武神：" << endl << endl;
		c.yellow(), cout << "\t\t\t\t\t    <", special(25, '-'), cout << ">" << endl;
		cout << c.pink() << "\t\t\t\t\t    ▲SSS级女武神"; cout << c.white() << " (极小概率)" << endl << endl;
		cout << c.yellow() << "\t\t\t\t     △SS级女武神"; cout << c.white() << "\t\t\t\b\b\b\b (略小概率)" << endl << endl;
		cout << c.green() << "\t\t\t      ▼S级女武神"; cout << c.white() << "\t\t\t\t\t\b\b\b\b (略大概率)" << endl << endl;
		cout << c.white() << "\t\t      ▽A级女武神"; cout << c.white() << "\t\t\t\t\t\t\t\b\b\b\b (极大概率)" << endl;
		c.yellow(), cout << "\t\t    <", special(75, '-'), cout << ">" << endl << endl;
		cout << c.white() << "\t\t\t\t\b\b\b系统会根据你投入的";
		cout << c.blue() << "水晶数量";
		cout << c.white() << "来判断将会招募到什么等级的";
		cout << c.yellow() << "女武神" << endl << endl;
		cout << c.white() << "\t\t\t\t\t一次至少投入";
		cout << c.green() << "20";
		cout << c.white() << "个水晶，上限不封顶！" << endl << endl << endl << endl;
		cut();


	}


	//信息界面输出
	void itemout()
	{
		cout << endl;
		cout << c.red() << "\t\t■个人档案";
		cout << c.blue() << "\t\t\t\t\t|\t";
		cout << c.red() << "■个人数据" << endl;
		cout << c.blue() << "\t\t\t\t\t\t\t\t|" << endl;

		cout.setf(ios::left, ios::adjustfield);
		cout.fill(' ');
		cout << c.blue() << "\t\t用户名: ";
		cout << c.green() << "  " << setw(20) << user.name;

		cout << c.blue() << "\t\t|\t";
		cout << c.white() << "邦邦乐队 " << endl;

		c.white(), cout << "\t\t    "; special(16, '-'), cout << c.blue() << "\t\t\t\t|" << endl;
		cout << c.blue() << "\t\t\t\t\t\t\t\t|";
		cout << c.blue() << "\t 获得评分：";
		//计算总评

		cout << c.pink() << (float)user.cardscore << endl;

		cout << c.blue() << "\t\t用户分组：";
		if (user.allgamesj <= 200)
			cout << c.white() << "普通会员";
		else if (user.allgamesj <= 600)
			cout << c.green() << "高级会员";
		else
			cout << c.pink() << "白金会员";
		cout << c.blue() << "\t\t\t\t|\t";
		cout << c.blue() << "累计消耗水晶：";
		cout << c.white() << user.bangbangsj << endl;

		c.white(), cout << "\t\t    "; special(16, '-'), cout << c.blue() << "\t\t\t\t|" << endl;
		cout << c.blue() << "\t\t\t\t\t\t\t\t|";
		cout << c.white() << "\t 明年方舟" << endl;



		cout.setf(ios::right, ios::adjustfield);
		cout.fill(' ');
		cout << c.blue() << "\t\t所有游戏消耗水晶:";
		cout << c.white() << setw(6) << user.allgamesj;
		cout << c.blue() << "个\t\t\t|" << endl;
		c.white(), cout << "\t\t    "; special(16, '-');
		cout << c.blue() << "\t\t\t\t|";
		cout << c.blue() << "\t 获得评分：";

		cout << c.pink() << (float)user.officalscore << endl;

		cout << c.blue() << "\t\t达成成就：";
		cout << "\t\t\t\t\t|";
		cout << "\t 累计消耗水晶:";
		cout << c.white() << user.officalsj << endl;


		cout.setf(ios::right, ios::adjustfield);

		if (user.point[0])
			cout << c.blue() << "\t\t    ■";
		else
			cout << c.blue() << "\t\t    □";

		cout << c.white() << "  邦邦乐队";
		cout << c.pink() << setw(11) << "四星卡片";

		if (user.point[0])
			cout << c.green() << " 已获得√";
		else cout << c.red() << " 未获得×";
		cout << c.blue() << "\t|";
		cout << endl << "\t\t\t\t\t\t\t\t|" << endl;

		if (user.point[1])
			cout << c.blue() << "\t\t    ■";
		else
			cout << c.blue() << "\t\t    □";
		cout << c.white() << "  明年方舟";
		cout << c.pink() << setw(11) << "高资深干员";
		if (user.point[1])
			cout << c.green() << " 已获得√";
		else cout << c.red() << " 未获得×";
		cout << c.blue() << "\t|";
		cout << c.white() << "\t 肝坏3";
		cout << endl << c.blue() << "\t\t\t\t\t\t\t\t|" << endl;

		if (user.point[2])
			cout << c.blue() << "\t\t    ■";
		else
			cout << c.blue() << "\t\t    □";
		cout << c.white() << "  肝坏3";
		cout << c.pink() << setw(11) << "   SSS级女武神";
		if (user.point[2])
			cout << c.green() << " 已获得√";
		else cout << c.red() << " 未获得×";
		cout << c.blue() << "\t|";
		cout << c.blue() << "\t 获得评分：";

		cout << c.pink() << (float)user.nvwushenscore;
		cout << endl << c.blue() << "\t\t\t\t\t\t\t\t|";
		cout << c.blue() << "\t 累计消耗水晶:";
		cout << c.white() << user.ganhuaisj << endl;

		if (user.point[3])
			cout << c.blue() << "\t\t    ■";
		else
			cout << c.blue() << "\t\t    □";
		cout << c.white() << "  总评达到";
		cout << c.pink() << setw(8) << "15000";
		cout << c.white() << "分";
		if (user.point[3])
			cout << c.green() << " 已获得√";
		else cout << c.red() << " 未获得×";
		cout << c.blue() << "\t|";
		cout << endl << "\t\t\t\t\t\t\t\t|" << endl;
		cut();

	}

};