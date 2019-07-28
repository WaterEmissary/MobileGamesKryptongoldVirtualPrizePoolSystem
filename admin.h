#include<iostream>
#include<cstring>
using namespace std;

//输出
void adminout()
{
	int i;

	for (i = 0; i < 48; i++)
		cout << char(32);
	cout << c.blue() << "  管理员后台界面" << endl;
	c.blue();
	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;
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
	c.blue();
	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;

	cout << c.blue() << "\t■功能：" << endl << endl;
	cout << "\t\t1.修改支付宝余额" << endl << endl;
	cout << "\t\t2.修改水晶数量" << endl << endl;
	cout << "\t\t3.修改邦邦乐队四星卡片数量" << endl << endl;
	cout << "\t\t4.修改明年方舟高资深干员数量" << endl << endl;
	cout << "\t\t5.修改肝坏3SSS级女武神数量" << endl << endl;
	cout << "\t\t6.修改用户名称" << endl << endl;
	cout << "\t\t7.用户信息初始化" << endl << endl;

	special(8, '\n');

	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;
}
class aadmin {
public:
	void admin()
	{
		int i = 0, key = 0;
		char id[6], ch;
		if (user.firstsignin)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << c.red() << "\t\t\t\t\t当前无用户，请注册后再进入管理界面！";
			_getch();
		}
		else {
			do {
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << c.blue() << "\t\t\t\t\t\t请输入管理员口令：" << endl << endl;
				cout << "\t\t\t\t\t\t    ";
				for (i = 0; i < 5; i++)
				{
					id[i] = _getch();
					cout << "*";
				}
				id[5] = 0;
				if (strcmp(id, "admin") == 0)
				{
					int key = 0;
					char ch;
					system("cls");

					//输出金钱和钻石
					adminout();
					cout << c.yellow() << "○请输入数字键选择功能!(按 \"E\" 返回上级菜单)";
					do {
						system("cls");
						//输出金钱和钻石
						adminout();
						cout << c.yellow() << "○请输入数字键选择功能!(按 \"E\" 返回上级菜单)";
						ch = _getch();
						//修改余额
						if (ch == '1')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "○请输入需要修改的余额数(最大值50000元)： ";
							user.cgrmb();
							continue;
						}
						//修改水晶
						else if (ch == '2')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "○请输入需要修改的水晶数(最大值5000000个)： ";
							user.cgsj();
							continue;
						}
						//修改四星卡片
						else if (ch == '3')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "○请输入需要修改的卡片数： ";
							cin >> user.card[0];
							if (user.card[0] >= 1)
								user.point[0] = 1;
							cin.clear();
							cin.ignore(1024, '\n');//防止输入非数字字符
							continue;
						}
						//修改干员
						else if (ch == '4')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "○请输入需要修改的干员数： ";
							cin >> user.official[0];
							if (user.official[0] >= 1)
								user.point[1] = 1;
							cin.clear();
							cin.ignore(1024, '\n');//防止输入非数字字符
							continue;
						}
						//修改女武神
						else if (ch == '5')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "○请输入需要修改的女武神数： ";
							cin >> user.nvwushen[0];
							if (user.nvwushen[0] >= 1)
								user.point[2] = 1;
							cin.clear();
							cin.ignore(1024, '\n');//防止输入非数字字符
							continue;
						}
						//修改用户名
						else if (ch == '6')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "○请输入需要修改的名称： ";
							int i;
							char ch;
							c.white();
							while (1) {
								i = 0;
								while ((ch = getchar()) != '\n')
									user.name[i++] = ch;
								user.name[i] = 0;
								//防止用户直接输回车
								if (user.name[0] == 0)
								{
									special(68, '\b');
									continue;
								}break;
							}
							continue;

						}
						else if (ch == '7')
						{	
							char ch;
							system("cls");
							adminout();
							cout << c.red() << "○警告，这样会失去所有用户信息且无法复原！按\"Y\"确认或者按\"E\"返回上级菜单 "<<endl;
							ch = _getch();
							if (ch == 'y' || ch == 'Y')
							{
								user.re();
								cin.clear();
								cin.ignore(1024, '\n');//防止输入非数字字符
								break;
							}
							else if (ch == 'e' || ch == 'E')
								break;
						}
						else if (ch == 'e' || ch == 'E')
							break;
						else
						{
							system("cls");

							//输出金钱和钻石
							adminout();
							cout << c.yellow() << "○您输入了";
							cout << c.red() << ch;
							cout << c.yellow() << ",请重新输入数字键选择功能!（按\"E\"返回上级菜单）";
						}



					} while (key == 0);
					break;

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << c.red() << "\t\t\t\t\t\t口令错误！请重新输入！" << endl << endl;
					cout << endl << c.yellow() << "\t\t\t\t\t按 任意键 重新输入或按 \"E\" 返回上级菜单";
					ch = _getch();

					if (ch == 'e' || ch == 'E')
						break;
				}
			} while (key == 0);
		}


	}
};