#include <iostream>
#include<cstdlib>
#include<conio.h>
#include<stdlib.h>
#include "menuout.h"
#include "function.h"
#include"admin.h"
using namespace std;

menuout mo;//�����˵������
function f;//����������
aadmin a;//����������



int main()
{
	int _menuget;
	void _yd();
	int _menu();
	void _deposit();
	void _draw();
	void _item();
	void _choice();
	system("mode con cols=120 lines=35");    //�������ڴ�С
	cout << setiosflags(ios::fixed) << setprecision(2);//����2λС��

	while (1)
	{
		_yd();
		while (1)
		{
			_menuget = _menu();
			switch (_menuget)
			{
			case 1:break;			//�˳�
			case 2:	_deposit(); continue; 				//��ֵ
			case 3:	_choice(); continue;					//�齱
			case 4:; _item(); continue;				//�ֿ�
			}break;
		}continue;
	}


	system("pause");

	return 0;
}

//������������
void _yd()
{
	char yd_ch;//�����ַ�
	//ע�����
	do
	{


		system("cls");
		mo.name();//����
		mo.menu();//�����˵�
		c.yellow();
		cout << "���밴�����ּ�\"1\"����\"2\"����\"3\"����ѡ��!";
		yd_ch = _getch();
		if (yd_ch == int('1'))
		{	//��һ�ε�¼ע��
			if (user.firstsignin)
			{
				char namech;
				do {
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << c.blue() << "\t\t\t\t\t���ǵ�һ�ε�¼���������û���ע�᣺" << endl;
					cout << "\t\t\t\t\t\t  (���س���ȷ��)" << endl<<endl;
					cout << "\t\t\t\t\t\t    "; c.white();
					f.userregister();
					cout << endl << endl << c.blue() << "\t\t\t    ��ȷ��ʹ�� ";
					c.white();
					cout << user.name;
					cout << c.blue() << " ��Ϊ�û�����(�� \"Y\" ȷ�ϻ� \"N\" ��������)";
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
		//����Ա����
		else if (yd_ch == int('2'))
		{
			a.admin();
			continue;
		}
		//�˳�����
		else if (yd_ch == int('3'))
			exit(1);
		else
		{
			system("cls");
			mo.name();//����
			mo.menu();//�����˵�
			c.yellow();
			cout << "����������";
			cout << c.red() << yd_ch;
			cout << c.yellow() << ",����������\"1\"����\"2\"����\"3\"!";
		}
	} while (yd_ch != int('1'));
};

//�������˵�����
int _menu()
{
	char ch;
	int i = 0;
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.welcome();//�û���ӭ
	mo.box();//ѡ��
	cout << c.yellow() << "���������Ӧ����ĸ����ѡ�񣡣���\"E\"�����ϼ��˵���";
	do
	{
		ch = _getch();
		if (ch == 'a' || ch == 'A')							//��ֵ
		{
			i = 2;
		}
		else if (ch == 'b' || ch == 'B')					//�齱
		{
			i = 3;
		}
		else if (ch == 'c' || ch == 'C')					//�ֿ�
		{
			i = 4;
		}
		else if (ch == 'e' || ch == 'E')					//����
		{
			i = 1;
		}
		else
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.welcome();
			mo.box();//ѡ��
			cout << c.yellow() << "����������";
			cout << c.red() << ch;
			cout << c.yellow() << ",����������\"A\"����\"B\"����\"C\"!����\"E\"�����ϼ��˵���";
		}
	} while (i == 0);
	return i;
}

//�����ֵ����
void _deposit()
{
	int i = 0;
	char ch, confirmch;
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.deposit();//��ֵ����
	cout << c.yellow() << "���������Ӧ�ײ�ǰ�����ֽ��г�ֵ��(��\"E\"�����ϼ��˵���";
	do
	{
		ch = _getch();
		if (ch >= int('1') && ch <= int('7'))
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.deposit();//��ֵ����
			mo.confirm(int(ch - '0'));//ȷ�ϳ�ֵ
			confirmch = _getch();
			if (confirmch == 'y' || confirmch == 'Y')
				if (f.surebuy(int(ch - '0')))
				{
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.deposit();//��ֵ����
					cout << c.yellow() << "���ֵ�ɹ���(�� ���ּ� ������ֵ��\"E\"�뿪��ҳ�棩";
				}
				else
				{
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.deposit();//��ֵ����
					cout << c.yellow() << "���ֵʧ��!��ȷ���ʻ�������Ƿ��㹻��(�� ���ּ� ������ֵ��\"E\"�뿪��ҳ�棩";
				}

		}
		else if (ch == 'e' || ch == 'E')
			i = 1;
		else
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.deposit();//��ֵ����
			cout << c.yellow() << "����������";
			cout << c.red() << ch;
			cout << c.yellow() << ",����������\"1\"��\"7\"������!����\"E\"�����ϼ��˵���";
		}

	} while (i == 0);
}
//������Ϸѡ�����
void _choice()
{
	void _bangbangdraw();
	void _fangzhoudraw();
	void _ganhuai3draw();
	char ch;
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.choice();//��Ϸѡ��
	cout << c.yellow() << "���������Ӧ������ѡ�������Ϸ��(��\"E\"�����ϼ��˵���";
	do {
		ch = _getch();
		if (ch == '1')			//������
		{
			_bangbangdraw();
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.choice();//��Ϸѡ��
			cout << c.yellow() << "���������Ӧ������ѡ�������Ϸ��(��\"E\"�����ϼ��˵���";
			continue;
		}
		else if (ch == '2')		//���뷽��
		{
			_fangzhoudraw();
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.choice();//��Ϸѡ��
			cout << c.yellow() << "���������Ӧ������ѡ�������Ϸ��(��\"E\"�����ϼ��˵���";
			continue;
		}
		else if (ch == '3')		//	����λ�3
		{
			_ganhuai3draw();
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.choice();//��Ϸѡ��
			cout << c.yellow() << "���������Ӧ������ѡ�������Ϸ��(��\"E\"�����ϼ��˵���";
			continue;
		}
		else if (ch == 'e' || ch == 'E')
			break;
		else
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.choice();//��Ϸѡ��
			cout << c.yellow() << "����������";
			cout << c.red() << ch;
			cout << c.yellow() << ",����������\"1\"��\"3\"������!����\"E\"�����ϼ��˵���";
		}


	} while (1);


}
//������齱����
void _bangbangdraw()
{
	char ch, drawch;
	int i = 0;
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.bangbangdraw();//�齱����
	cout << c.yellow() << "��������\"A\"��\"B\"��ȡ��Ƭ��(��\"E\"�����ϼ��˵���";
	do {
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.bangbangdraw();//�齱����
			cout << c.yellow() << "��ȷ�Ͻ���";
			cout << c.red() << " һ�� ";
			cout << c.yellow() << "��ȡ�� ��";
			cout << c.red() << " Y ";
			cout << c.yellow() << "ȷ�ϣ�(��\"E\"�����ϼ��˵���";
			drawch = _getch();
			if (drawch == 'Y' || drawch == 'y')						//ȷ�ϳ齱   һ��
			{
				if (f.ifcandraw(5))
				{
					int cardget;
					cardget = f.bangbangdrawone();
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.bangbangdraw();//�齱����
					//�н����
					cout << c.yellow() << "�����ոջ���� ";
					if (cardget == 0)
					{
						cout << c.pink() << "�����\t���ǿ�Ƭ";
						user.point[0] = 1;
					}
					else if (cardget == 1)
						cout << c.yellow() << "����  \t���ǿ�Ƭ";
					else if (cardget == 2)
						cout << c.green() << "���    \t���ǿ�Ƭ";
					else if (cardget == 3)
						cout << c.white() << "��      \tһ�ǿ�Ƭ";
					cout << c.yellow() << "* 1!" << endl << endl << "(�� \"A\" �� \"B\" �����齱���߰� \"E\" �����ϼ��˵�)";

				}
				else
				{
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.bangbangdraw();//�齱����
					cout << c.yellow() << "��鿨ʧ��!��ȷˮ���Ƿ��㹻��(�� \"A\" �� \"B\" ������ֵ��\"E\"�뿪��ҳ�棩";

				}
			}
			else if (drawch == 'e' || drawch == 'E')break;

		}
		else if (ch == 'b' || ch == 'B')
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.bangbangdraw();//�齱����
			cout << c.yellow() << "��ȷ�Ͻ���";
			cout << c.red() << " ʮ�� ";
			cout << c.yellow() << "��ȡ�� ��";
			cout << c.red() << " Y ";
			cout << c.yellow() << "ȷ�ϣ�(��\"E\"�����ϼ��˵���";
			drawch = _getch();

			if (drawch == 'Y' || drawch == 'y')//ȷ�ϳ齱   ʮ��
			{
				if (f.ifcandraw(50))
				{
					f.bangbangdrawten();
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.bangbangdraw();//�齱����
					//�н����
					cout << c.yellow() << "�����ոջ����\t";
					cout << c.pink() << "\b�����\t���ǿ�Ƭ";
					cout << c.yellow() << "\t* " << user.ten[0] << endl;

					cout << c.yellow() << "\t\t����  \t���ǿ�Ƭ";
					cout << c.yellow() << "\t* " << user.ten[1] << endl;

					cout << c.green() << "\t\t���    \t���ǿ�Ƭ";
					cout << c.yellow() << "\t* " << user.ten[2] << endl;

					cout << c.white() << "\t\t��      \tһ�ǿ�Ƭ";
					cout << c.yellow() << "\t* " << user.ten[3] << endl;

					cout << c.yellow() << endl << "(�� \"A\" �� \"B\" �����齱���߰� \"E\" �����ϼ��˵�)";
				}
				else
				{
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.bangbangdraw();//�齱����
					cout << c.yellow() << "��鿨ʧ��!��ȷˮ���Ƿ��㹻��(�� \"A\" �� \"B\" �����齱��\"E\"�뿪��ҳ�棩";

				}
			}
			else if (drawch == 'e' || drawch == 'E')break;

		}
		else if (ch == 'e' || ch == 'E')
			i = 1;
		else
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.bangbangdraw();//�齱����
			cout << c.yellow() << "����������";
			cout << c.red() << ch;
			cout << c.yellow() << ",����������\"A\"��\"B\"��ȡ��Ƭ��(��\"E\"�����ϼ��˵���";
		}

	} while (i == 0);

}

//���뷽�۳齱����
void _fangzhoudraw()
{
	char ch, drawch;
	int i = 0;
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.fangzhoudraw();//�齱����
	cout << c.yellow() << "��������\"A\"Ѱ�ø�Ա��(��\"E\"�����ϼ��˵���";
	do {
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.fangzhoudraw();//�齱����
			cout << c.yellow() << "��ȷ�Ͻ���";
			cout << c.red() << " һ�� ";
			cout << c.yellow() << "Ѱ�ã� ��";
			cout << c.red() << " Y ";
			cout << c.yellow() << "ȷ�ϣ�(��\"E\"�����ϼ��˵���";
			drawch = _getch();
			//ȷ��Ѱ��
			if (drawch == 'Y' || drawch == 'y')
			{
				if (f.ifcandraw(10))
				{
					int officelget;
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.fangzhoudraw();//�齱����
					officelget = f.fangzhoudrawone();
					cout << c.yellow() << "�����ոջ����\t";
					if (officelget == 0)
					{
						cout << c.pink() << "�������Ա";
						user.point[1] = 1;
					}
					else if (officelget == 1)
						cout << c.green() << "�����Ա  ";
					else if (officelget == 2)
						cout << c.white() << "��ͨ��Ա  ";
					cout << c.yellow() << " !" << endl << endl << "(�� \"A\" �����齱���߰� \"E\" �����ϼ��˵�)";


				}
				else
				{
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.fangzhoudraw();//�齱����
					cout << c.yellow() << "��鿨ʧ��!��ȷˮ���Ƿ��㹻��(�� \"E\"�뿪��ҳ�棩";

				}

			}
		}
		else if (ch == 'e' || ch == 'E')
			break;
		else
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.fangzhoudraw();//�齱����
			cout << c.yellow() << "����������";
			cout << c.red() << ch;
			cout << c.yellow() << ",����������\"A\"��\"B\"��ȡ��Ƭ��(��\"E\"�����ϼ��˵���";
		}




	} while (1);

}

//�λ�3�齱����
void _ganhuai3draw()
{
	int cost;
	char ch, outch;
	outch = 0;
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.ganguai3draw();//�齱����
	cout << c.yellow() << "��������\"A\"��ļŮ����(��\"E\"�����ϼ��˵���";
	do {
		ch = _getch();
		if (ch == 'a' || ch == 'A')
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.ganguai3draw();//�齱����
			cout << c.yellow() << "��������������ʹ�ö���ˮ����ļŮ����";
			do {
				system("cls");
				mo.name();//����
				mo.headout();//ˮ������
				mo.ganguai3draw();//�齱����
				cout << c.yellow() << "��������������ʹ�ö���ˮ����ļŮ����";
				cin >> cost;
				if (cost < 20)
				{
					cin.clear();
					cin.ignore(1024, '\n');//��ֹ����������ַ�
					system("cls");
					mo.name();//����
					mo.headout();//ˮ������
					mo.ganguai3draw();//�齱����
					cout << c.yellow() << "���������ˮ����������ȷ��(��\"E\"�����ϼ��˵���";
					outch = _getch();
					if (outch == 'e' || outch == 'E')
						break;
				}
			} while (cost < 20);
			if (outch == 'e' || outch == 'E')
			{
				system("cls");
				mo.name();//����
				mo.headout();//ˮ������
				mo.ganguai3draw();//�齱����
				cout << c.yellow() << "������������ϼ��˵���";
				continue;
			}
			if (f.ifcandraw(cost))
			{
				int ganhuai;
				system("cls");
				mo.name();//����
				mo.headout();//ˮ������
				mo.ganguai3draw();//�齱����
				ganhuai = f.ganghuai3drawone(cost);
				cout << c.yellow() << "�����ոջ����\t";
				if (ganhuai == 0)
				{
					cout << c.pink() << " SSS��Ů����";
					user.point[2] = 1;
				}
				else if (ganhuai == 1)
					cout << c.yellow() << " SS��Ů����";
				else if (ganhuai == 2)
					cout << c.green() << " S��Ů����";
				else if (ganhuai == 3)
					cout << c.white() << " A��Ů����";
				cout << c.yellow() << " !" << endl << endl << "(�� \"A\" �����齱���߰� \"E\" �����ϼ��˵�)";
			}
			else
			{
				system("cls");
				mo.name();//����
				mo.headout();//ˮ������
				mo.ganguai3draw();//�齱����
				cout << c.yellow() << "��鿨ʧ��!��ȷˮ���Ƿ��㹻��(�� \"E\"�뿪��ҳ�棩";
			}


		}
		else if (ch == 'e' || ch == 'E')
			break;
		else
		{
			system("cls");
			mo.name();//����
			mo.headout();//ˮ������
			mo.ganguai3draw();//�齱����
			cout << c.yellow() << "����������";
			cout << c.red() << ch;
			cout << c.yellow() << ",����������\"A\"��ļŮ����(��\"E\"�����ϼ��˵���";
		}

	} while (1);

}

//����ֿ�
void _item()
{
	system("cls");
	mo.name();//����
	mo.headout();//ˮ������
	mo.itemout();//�ֿ����
	cout << c.yellow() << "�𣨰�����������ϼ��˵���";
	_getch();



}