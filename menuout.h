#include <iostream>
#include <string>
#include <iomanip>
#include "color.h"
#include "sql.h"
using namespace std;

information user;			//1,1000,0
color c;

void special(int i, char ch)								//�Զ�->������ٸ��ַ�
{
	for (int j = 0; j < i; j++)
		cout << ch;
}

//�ָ���
void cut()
{
	int i;
	c.blue();
	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;
}

//����
void count()
{
	user.officalscore = user.official[0] * 2500 + user.official[1] * 500 + user.official[2] * 100;
	user.nvwushenscore = user.nvwushen[0] * 10000 + user.nvwushen[1] * 5000 + user.nvwushen[2] * 100 + user.nvwushen[3] * 50;
	user.cardscore = user.card[0] * 1000 + user.card[1] * 500 + user.card[2] * 100 + user.card[3] * 10;
	if (user.cardscore + user.officalscore + user.nvwushenscore >= 15000)
		user.point[3] = 1;
	user.allgamesj = user.bangbangsj + user.ganhuaisj + user.officalsj;
}

class menuout			//����˵������
{
public:

	//�û���ӭ
	void welcome()
	{
		cout << c.blue() << "\t��ӭ����! ��� ";
		c.green();
		cout << user.name;
		cout << c.blue() << "!" << endl;
	}


	//��������
	void name()
	{
		int i = 0;
		for (i = 0; i < 48; i++)
			cout << char(32);
		c.white();
		cout << "��������봽𽱳�ϵͳ" << endl;

	}

	//��������
	void menu()
	{
		int i, j;
		cut();
		for (i = 0; i < 9; i++)
			cout << endl;
		c.white();
		for (j = 0; j < 55; j++)
			cout << char(32);
		cout << "1.����ϵͳ" << endl << endl << endl;
		for (j = 0; j < 55; j++)
			cout << char(32);
		cout << "2.����Ա��¼" << endl << endl << endl;
		for (j = 0; j < 55; j++)
			cout << char(32);
		cout << "3.�˳�ϵͳ" << endl;

		for (i = 0; i < 9; i++)
			cout << endl;
		cut();
	}
	//�˵�������Ǯ����ʯ���
	void headout()
	{
		int i = 0;
		c.blue();																					//��һ��ֱ��
		for (i = 0; i < 120; i++)
			cout << "-";
		cout << endl;
		count();
		//�����Ǯ����ʯ
		c.indigo();
		cout.setf(ios::right, ios::adjustfield);
		cout.fill(' ');
		cout << "      �}֧������" << setw(7) << user.outrmb() << " Ԫ";
		cout << "\t\t\t��ˮ���� " << setw(7) << user.outsj() << " ��";
		cout << "\t\t\t���ɾ͵�����";
		for (i = 0; i < 4; i++)
			if (user.point[i])
				cout << c.blue() << "\b��";
			else
				cout << c.blue() << "\b��";
		cout << " " << 25 * user.point[0] + 25 * user.point[1] + 25 * user.point[2] + 25 * user.point[3] << "%";
		cout << endl;
		//�ڶ���ֱ��
		c.blue();
		for (i = 0; i < 120; i++)
			cout << "-";
		cout << endl;
	}
	//�˵��м�ѡ�����
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
		//box�ϰ벿��
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
		//box���ֲ���
		for (k = 0; k < 3; k++)
		{
			for (i = 0; i < 6; i++)
				cout << char(32);
			cout << "|";
			for (j = 0; j < 12; j++)
				cout << char(32);
			c.yellow();
			if (k == 0)
				cout << "��  ֵ";
			else if (k == 1)
				cout << "��  ��";
			else if (k == 2)
				cout << "��  ��";
			c.red();
			for (j = 0; j < 12; j++)
				cout << char(32);
			cout << "|";
		}
		cout << endl;
		//box�°벿��
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
		//boxѡ��
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
		//���һ��
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
	//��ֵ����
	void deposit()
	{
		int i;
		cout << endl;
		cout << c.red() << "\t����ڼ��״γ�ֵ������";
		cout << c.pink() << " 2����ˮ�� ";
		cout << c.red() << "�Żݣ�" << endl;
		cout << endl;
		for (i = 0; i < 60; i++)
		{
			c.blue();
			cout << "��";
		}
		cout << endl << endl;
		//����ײ�
		for (i = 0; i < 7; i++)
		{
			cout << c.white() << "\t�ײ� " << i + 1 << ": ʹ�� ";
			cout.width(4);
			cout << user.first[0][i] << " Ԫ��ֵ  ";
			cout.width(4);
			cout << user.diamond[i];
			if (user.first[1][i])
			{
				cout << c.pink() << "+ ";
				cout.width(4);
				cout << user.diamond[i];
			}
			cout << c.white() << "ö��ˮ��" << endl << endl;
		}
		cout << endl << c.red() << "(��ע�⣬ͨ���κ���ʽ��ֵ��ˮ���޷�����������ң������Գ�ֵ����";
		cout << endl << endl << endl;
		cut();
	}
	//ȷ�ϳ�ֵ
	void confirm(int i)
	{
		cout << c.yellow() << "����ѡ���� �ײ�" << i << " ʹ��";
		cout.width(3);
		cout << c.white() << user.first[0][i - 1];
		cout << c.yellow() << "Ԫ��ֵ";
		cout.width(4);
		cout << user.diamond[i - 1];
		if (user.first[1][i - 1])
		{
			cout << c.pink() << "+ ";
			cout.width(4);
			cout << user.diamond[i - 1];
		}
		cout << c.yellow() << "ö��ˮ��,";
		cout << c.yellow() << "��";
		cout << c.red() << " Y ";
		cout << c.yellow() << "����ȷ��!(�� E �����ϼ��˵�)";
	}

	//ѡ����Ϸ�������
	void choice()
	{
		cout << c.blue() << "\t\t\t\t\t\t  SBEAM �� Ϸ ��" << endl << endl << "\t��  ��~";
		cout << c.green() << user.name;
		cout << c.blue() << " ,��Ŀǰӵ��������Ϸ��" << endl << endl << endl;
		cout << c.yellow() << "\b\t1. ����ֶ�" << endl << endl;
		cout << "\t2. ���귽��" << endl << endl;
		cout << "\t3. �λ�3" << endl << endl;
		special(10, '\n');
		cut();


	}

	//���齱�������
	void bangbangdraw()
	{
		int i, j;

		cout.setf(ios::left, ios::adjustfield);
		cout.fill(' ');

		//˵������
		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.red();
		cout << setw(59) << "        ������ֶ� �����л�ȡ��Ƭ��������";
		cout << c.blue() << "|";
		cout << c.red() << "\t\t������ֶ� ��������ʮ�γ�ȡ" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.pink();
		cout << setw(59) << "        ����� ���ǿ�Ƭ        ��ȡ����   4%";
		cout << c.blue() << "|";
		cout << c.white() << "\t\t��������ʮ�γ�ȡ���񽱸����뵥����ͬ" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.yellow();
		cout << setw(59) << "        ����   ���ǿ�Ƭ        ��ȡ����   16%";
		cout << c.blue() << "|";
		cout << c.white() << "\t\t��һ��ʮ����ȡ�У����ٻ��һ��" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.green();
		cout << setw(59) << "        ���     ���ǿ�Ƭ        ��ȡ����   32%";
		cout << c.blue() << "|";
		cout << c.yellow() << "\t\t����\t ���ǿ�Ƭ ";
		cout << c.white() << "�� ";
		cout << c.pink() << "�����\t���ǿ�Ƭ" << endl;

		for (i = 0; i < 59; i++) cout << " ";
		cout << c.blue() << "|" << endl;

		c.white();
		cout << setw(59) << "        ��       һ�ǿ�Ƭ        ��ȡ����   48%";
		cout << c.blue() << "|";
		cout << endl;

		//�հײ���
		for (j = 0; j < 5; j++)
		{
			for (i = 0; i < 59; i++) cout << " ";
			cout << c.blue() << "|" << endl;

		}


		//���򲿷�
			//����
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

		//�м����
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

		//�м�����
		special(14, ' ');
		cout << c.red() << "|";
		special(10, ' ');
		cout << "�� һ ��";
		special(9, ' ');
		cout << c.red() << "|";
		special(14, ' ');

		cout << c.blue() << "|";

		special(14, ' ');
		cout << c.red() << "|";
		special(9, ' ');
		cout << "�� ʮ ��";
		special(10, ' ');
		cout << c.red() << "|";
		cout << endl;

		special(14, ' ');
		cout << c.red() << "|";
		special(7, ' ');
		cout << "(���� 5 ˮ��)";
		special(7, ' ');
		cout << c.red() << "|";
		special(14, ' ');

		cout << c.blue() << "|";

		special(14, ' ');
		cout << c.red() << "|";
		special(7, ' ');
		cout << "(���� 50 ˮ��)";
		special(6, ' ');
		cout << c.red() << "|";
		cout << endl;


		//�м���ĸ
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

		//�׶�
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

		//�հײ���
		for (j = 0; j < 2; j++)
		{
			for (i = 0; i < 59; i++) cout << " ";
			cout << c.blue() << "|" << endl;

		}

		cut();
	}

	//���۳齱�������
	void fangzhoudraw()
	{
		cout << c.red() << endl << "\t�� ���귽�� Ѱ�õĹ������£�" << endl << endl;
		cout << c.white() << "\t���� ���귽�� ��ԱѰ���У�ȫ������Ѱ�õ��ĸ�Ա��" << endl << endl;
		cout << c.pink() << "\t\t�������Ա";
		cout << c.white() << "��2 % ��";

		//��������ʶ���
		c.red(), special(5, '\t'), special(38, '-'), special(1, '\n');

		c.white(), special(16, ' '), special(15, '-');
		//һ������
		c.red(), special(6, '\t'), cout << "|", special(36, ' '), cout << "|", special(1, '\n');

		cout << c.green() << "\t\t�����Ա  ";
		cout << c.white() << "��8 % ��";

		cout.setf(ios::left, ios::adjustfield);
		cout.fill(' ');

		cout << c.red() << "\t\t\t\t\t| ��ǰ��� ";
		cout << c.pink() << "�������Ա";
		cout << c.red() << "�ĸ���Ϊ";
		cout << c.pink() << setw(4) << 2 + user.p;
		cout << c.red() << "\b\b% |" << endl;

		c.white(), special(16, ' '), special(15, '-');
		//��������
		c.red(), special(6, '\t'), cout << "|", special(36, ' '), cout << "|", special(1, '\n');

		cout << c.white() << "\t\t��ͨ��Ա  ";
		cout << c.white() << "��50 % ��";

		//�߸ŵײ�
		c.red(), special(5, '\t'), special(38, '-'), special(1, '\n');

		c.white(), special(16, ' '), special(15, '-'), special(1, '\n');
		cout << endl << "\t�����С���׼Ѱ�á��У��������Ѱ��û�л�� ";
		cout << c.pink() << "�������Ա ";
		cout << c.white() << "\n\n\t����һ��Ѱ�û�� ";
		cout << c.pink() << "�������Ա ";
		cout << c.white() << "�ĸ��ʽ���ԭ���� ";
		cout << c.pink() << "2%";
		cout << c.white() << "������ ";
		cout << c.pink() << "4%";
		cout << c.white() << "\n\n\t����ôλ�û��Ѱ�õ� ";
		cout << c.pink() << "�������Ա ";
		cout << c.white() << "\n\n\t����һ��Ѱ�û�� ";
		cout << c.pink() << "�������Ա ";
		cout << c.white() << "�ĸ����� ";
		cout << c.pink() << "4%";
		cout << c.white() << "������ ";
		cout << c.pink() << "6%";
		cout << c.white() << "\n\n\t�Դ����ƣ�ÿ����� 2% �ĸ��ʣ�ֱ���ﵽ100%ʱ�ض���� ";
		cout << c.pink() << "�������Ա ";
		special(3, '\n');
		cut();
	}


	//�λ�3�齱�������
	void ganguai3draw()
	{
		cout << endl;
		cout << c.red() << "\t\t\t\t\t\t���λ�3Ů������ļ�����" << endl << endl;
		cout << c.red() << "\t���ڱ�������������ͨ������ˮ����ļŮ����Կ��λ������磡" << endl << endl;
		cout << c.green() << "\t  " << user.name;
		cout << c.white() << ",����Ͷ��ˮ��ʱ���Ի������";
		cout << c.yellow() << "Ů����" << endl << endl;
		c.yellow(), cout << "\t\t\t\t\t    <", special(25, '-'), cout << ">" << endl;
		cout << c.pink() << "\t\t\t\t\t    ��SSS��Ů����"; cout << c.white() << " (��С����)" << endl << endl;
		cout << c.yellow() << "\t\t\t\t     ��SS��Ů����"; cout << c.white() << "\t\t\t\b\b\b\b (��С����)" << endl << endl;
		cout << c.green() << "\t\t\t      ��S��Ů����"; cout << c.white() << "\t\t\t\t\t\b\b\b\b (�Դ����)" << endl << endl;
		cout << c.white() << "\t\t      ��A��Ů����"; cout << c.white() << "\t\t\t\t\t\t\t\b\b\b\b (�������)" << endl;
		c.yellow(), cout << "\t\t    <", special(75, '-'), cout << ">" << endl << endl;
		cout << c.white() << "\t\t\t\t\b\b\bϵͳ�������Ͷ���";
		cout << c.blue() << "ˮ������";
		cout << c.white() << "���жϽ�����ļ��ʲô�ȼ���";
		cout << c.yellow() << "Ů����" << endl << endl;
		cout << c.white() << "\t\t\t\t\tһ������Ͷ��";
		cout << c.green() << "20";
		cout << c.white() << "��ˮ�������޲��ⶥ��" << endl << endl << endl << endl;
		cut();


	}


	//��Ϣ�������
	void itemout()
	{
		cout << endl;
		cout << c.red() << "\t\t�����˵���";
		cout << c.blue() << "\t\t\t\t\t|\t";
		cout << c.red() << "����������" << endl;
		cout << c.blue() << "\t\t\t\t\t\t\t\t|" << endl;

		cout.setf(ios::left, ios::adjustfield);
		cout.fill(' ');
		cout << c.blue() << "\t\t�û���: ";
		cout << c.green() << "  " << setw(20) << user.name;

		cout << c.blue() << "\t\t|\t";
		cout << c.white() << "����ֶ� " << endl;

		c.white(), cout << "\t\t    "; special(16, '-'), cout << c.blue() << "\t\t\t\t|" << endl;
		cout << c.blue() << "\t\t\t\t\t\t\t\t|";
		cout << c.blue() << "\t ������֣�";
		//��������

		cout << c.pink() << (float)user.cardscore << endl;

		cout << c.blue() << "\t\t�û����飺";
		if (user.allgamesj <= 200)
			cout << c.white() << "��ͨ��Ա";
		else if (user.allgamesj <= 600)
			cout << c.green() << "�߼���Ա";
		else
			cout << c.pink() << "�׽��Ա";
		cout << c.blue() << "\t\t\t\t|\t";
		cout << c.blue() << "�ۼ�����ˮ����";
		cout << c.white() << user.bangbangsj << endl;

		c.white(), cout << "\t\t    "; special(16, '-'), cout << c.blue() << "\t\t\t\t|" << endl;
		cout << c.blue() << "\t\t\t\t\t\t\t\t|";
		cout << c.white() << "\t ���귽��" << endl;



		cout.setf(ios::right, ios::adjustfield);
		cout.fill(' ');
		cout << c.blue() << "\t\t������Ϸ����ˮ��:";
		cout << c.white() << setw(6) << user.allgamesj;
		cout << c.blue() << "��\t\t\t|" << endl;
		c.white(), cout << "\t\t    "; special(16, '-');
		cout << c.blue() << "\t\t\t\t|";
		cout << c.blue() << "\t ������֣�";

		cout << c.pink() << (float)user.officalscore << endl;

		cout << c.blue() << "\t\t��ɳɾͣ�";
		cout << "\t\t\t\t\t|";
		cout << "\t �ۼ�����ˮ��:";
		cout << c.white() << user.officalsj << endl;


		cout.setf(ios::right, ios::adjustfield);

		if (user.point[0])
			cout << c.blue() << "\t\t    ��";
		else
			cout << c.blue() << "\t\t    ��";

		cout << c.white() << "  ����ֶ�";
		cout << c.pink() << setw(11) << "���ǿ�Ƭ";

		if (user.point[0])
			cout << c.green() << " �ѻ�á�";
		else cout << c.red() << " δ��á�";
		cout << c.blue() << "\t|";
		cout << endl << "\t\t\t\t\t\t\t\t|" << endl;

		if (user.point[1])
			cout << c.blue() << "\t\t    ��";
		else
			cout << c.blue() << "\t\t    ��";
		cout << c.white() << "  ���귽��";
		cout << c.pink() << setw(11) << "�������Ա";
		if (user.point[1])
			cout << c.green() << " �ѻ�á�";
		else cout << c.red() << " δ��á�";
		cout << c.blue() << "\t|";
		cout << c.white() << "\t �λ�3";
		cout << endl << c.blue() << "\t\t\t\t\t\t\t\t|" << endl;

		if (user.point[2])
			cout << c.blue() << "\t\t    ��";
		else
			cout << c.blue() << "\t\t    ��";
		cout << c.white() << "  �λ�3";
		cout << c.pink() << setw(11) << "   SSS��Ů����";
		if (user.point[2])
			cout << c.green() << " �ѻ�á�";
		else cout << c.red() << " δ��á�";
		cout << c.blue() << "\t|";
		cout << c.blue() << "\t ������֣�";

		cout << c.pink() << (float)user.nvwushenscore;
		cout << endl << c.blue() << "\t\t\t\t\t\t\t\t|";
		cout << c.blue() << "\t �ۼ�����ˮ��:";
		cout << c.white() << user.ganhuaisj << endl;

		if (user.point[3])
			cout << c.blue() << "\t\t    ��";
		else
			cout << c.blue() << "\t\t    ��";
		cout << c.white() << "  �����ﵽ";
		cout << c.pink() << setw(8) << "15000";
		cout << c.white() << "��";
		if (user.point[3])
			cout << c.green() << " �ѻ�á�";
		else cout << c.red() << " δ��á�";
		cout << c.blue() << "\t|";
		cout << endl << "\t\t\t\t\t\t\t\t|" << endl;
		cut();

	}

};