#include<iostream>
#include<cstring>
using namespace std;

//���
void adminout()
{
	int i;

	for (i = 0; i < 48; i++)
		cout << char(32);
	cout << c.blue() << "  ����Ա��̨����" << endl;
	c.blue();
	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;
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
	c.blue();
	for (i = 0; i < 120; i++)
		cout << "-";
	cout << endl;

	cout << c.blue() << "\t�����ܣ�" << endl << endl;
	cout << "\t\t1.�޸�֧�������" << endl << endl;
	cout << "\t\t2.�޸�ˮ������" << endl << endl;
	cout << "\t\t3.�޸İ���ֶ����ǿ�Ƭ����" << endl << endl;
	cout << "\t\t4.�޸����귽�۸������Ա����" << endl << endl;
	cout << "\t\t5.�޸ĸλ�3SSS��Ů��������" << endl << endl;
	cout << "\t\t6.�޸��û�����" << endl << endl;
	cout << "\t\t7.�û���Ϣ��ʼ��" << endl << endl;

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
			cout << c.red() << "\t\t\t\t\t��ǰ���û�����ע����ٽ��������棡";
			_getch();
		}
		else {
			do {
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << c.blue() << "\t\t\t\t\t\t���������Ա���" << endl << endl;
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

					//�����Ǯ����ʯ
					adminout();
					cout << c.yellow() << "�����������ּ�ѡ����!(�� \"E\" �����ϼ��˵�)";
					do {
						system("cls");
						//�����Ǯ����ʯ
						adminout();
						cout << c.yellow() << "�����������ּ�ѡ����!(�� \"E\" �����ϼ��˵�)";
						ch = _getch();
						//�޸����
						if (ch == '1')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "����������Ҫ�޸ĵ������(���ֵ50000Ԫ)�� ";
							user.cgrmb();
							continue;
						}
						//�޸�ˮ��
						else if (ch == '2')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "����������Ҫ�޸ĵ�ˮ����(���ֵ5000000��)�� ";
							user.cgsj();
							continue;
						}
						//�޸����ǿ�Ƭ
						else if (ch == '3')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "����������Ҫ�޸ĵĿ�Ƭ���� ";
							cin >> user.card[0];
							if (user.card[0] >= 1)
								user.point[0] = 1;
							cin.clear();
							cin.ignore(1024, '\n');//��ֹ����������ַ�
							continue;
						}
						//�޸ĸ�Ա
						else if (ch == '4')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "����������Ҫ�޸ĵĸ�Ա���� ";
							cin >> user.official[0];
							if (user.official[0] >= 1)
								user.point[1] = 1;
							cin.clear();
							cin.ignore(1024, '\n');//��ֹ����������ַ�
							continue;
						}
						//�޸�Ů����
						else if (ch == '5')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "����������Ҫ�޸ĵ�Ů�������� ";
							cin >> user.nvwushen[0];
							if (user.nvwushen[0] >= 1)
								user.point[2] = 1;
							cin.clear();
							cin.ignore(1024, '\n');//��ֹ����������ַ�
							continue;
						}
						//�޸��û���
						else if (ch == '6')
						{
							system("cls");
							adminout();
							cout << c.yellow() << "����������Ҫ�޸ĵ����ƣ� ";
							int i;
							char ch;
							c.white();
							while (1) {
								i = 0;
								while ((ch = getchar()) != '\n')
									user.name[i++] = ch;
								user.name[i] = 0;
								//��ֹ�û�ֱ����س�
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
							cout << c.red() << "�𾯸棬������ʧȥ�����û���Ϣ���޷���ԭ����\"Y\"ȷ�ϻ��߰�\"E\"�����ϼ��˵� "<<endl;
							ch = _getch();
							if (ch == 'y' || ch == 'Y')
							{
								user.re();
								cin.clear();
								cin.ignore(1024, '\n');//��ֹ����������ַ�
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

							//�����Ǯ����ʯ
							adminout();
							cout << c.yellow() << "����������";
							cout << c.red() << ch;
							cout << c.yellow() << ",�������������ּ�ѡ����!����\"E\"�����ϼ��˵���";
						}



					} while (key == 0);
					break;

				}
				else
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << c.red() << "\t\t\t\t\t\t����������������룡" << endl << endl;
					cout << endl << c.yellow() << "\t\t\t\t\t�� ����� ��������� \"E\" �����ϼ��˵�";
					ch = _getch();

					if (ch == 'e' || ch == 'E')
						break;
				}
			} while (key == 0);
		}


	}
};