#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

class function
{
public:
	//�û�ע��
	void userregister()
	{
		int i;
		char ch;
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
			}
			break;
		}

	}
	//ȷ�Ϲ����׳�
	int surebuy(int i)
	{
		if (user.outrmb() >= user.first[0][i - 1])//�жϴ���Ƿ���ڳ�ֵ�ײ�
		{
			user.usermb(user.first[0][i - 1]);
			user.getsj(user.diamond[i - 1]);
			if (user.first[1][i - 1])//�ж��Ƿ��׳�
			{
				user.getsj(user.diamond[i - 1]);
				user.first[1][i - 1] = 0;
			}
			return 1;

		}
		else return 0;
	}

	//�ж��Ƿ��ܳ�
	int ifcandraw(int i)
	{
		if (user.outsj() >= i)
			return 1;
		else
			return 0;
	}

	//����
	int bangbangdrawone()
	{
		int r;
		srand(int(time(0)));
		user.getsj(-5);					//��ʯ-5
		user.bangbangsj += 5;
		r = rand() % 99 + 1;
		if (r >= 1 && r <= 4)						//���ǿ�Ƭ
		{
			user.card[0]++;
			return 0;
		}
		else if (r >= 5 && r <= 20)				//���ǿ�Ƭ
		{
			user.card[1]++;
			return 1;
		}
		else if (r >= 21 && r <= 52)				//���ǿ�Ƭ
		{
			user.card[2]++;
			return 2;
		}
		else if (r >= 53 && r <= 100)				//һ�ǿ�Ƭ
		{
			user.card[3]++;
			return 3;
		}


	}

	//���ʮ��
	void bangbangdrawten()
	{
		int r, i, j;
		srand(int(time(0)));
		user.getsj(-50);
		user.bangbangsj += 50;

		//��ʼ��ʮ��
		for (j = 0; j < 4; j++)
			user.ten[j] = 0;

		for (i = 0; i < 9; i++)
		{

			r = rand() % 99 + 1;

			if (r >= 1 && r <= 4)						//���ǿ�Ƭ
			{
				user.card[0]++;
				user.ten[0]++;
				user.point[0] = 1;
			}
			else if (r >= 5 && r <= 20)				//���ǿ�Ƭ
			{
				user.card[1]++;
				user.ten[1]++;
			}
			else if (r >= 21 && r <= 52)				//���ǿ�Ƭ
			{
				user.card[2]++;
				user.ten[2]++;
			}
			else if (r >= 53 && r <= 100)				//һ�ǿ�Ƭ
			{
				user.card[3]++;
				user.ten[3]++;
			}

		}
		//����
		if (user.ten[3] == 0 && user.ten[2] == 0)
		{
			r = rand() % 19 + 1;
			if (r >= 1 && r <= 4)						//���ǿ�Ƭ
			{
				user.card[0]++;
				user.ten[0]++;
			}
			else if (r >= 5 && r <= 20)				//���ǿ�Ƭ
			{
				user.card[1]++;
				user.ten[1]++;
			}
		}
		else
		{
			r = rand() % 99 + 1;

			if (r >= 1 && r <= 4)						//���ǿ�Ƭ
			{
				user.card[0]++;
				user.ten[0]++;
			}
			else if (r >= 5 && r <= 20)				//���ǿ�Ƭ
			{
				user.card[1]++;
				user.ten[1]++;
			}
			else if (r >= 21 && r <= 52)				//���ǿ�Ƭ
			{
				user.card[2]++;
				user.ten[2]++;
			}
			else if (r >= 53 && r <= 100)				//һ�ǿ�Ƭ
			{
				user.card[3]++;
				user.ten[3]++;
			}
		}

	}



	//����
	int fangzhoudrawone()
	{
		int r;
		srand(int(time(0)));
		user.getsj(-10);		//��ʯ-10
		user.officalsj += 10;
		r = rand() % 99 + 1;
		if (r >= 1 && r <= 2 + user.p)						//�������Ա
		{
			user.official[0]++;
			user.p = 0;
			return 0;
		}
		else if (r >= 3 + user.p && r <= 11 + user.p * 5 / 6)	/*�����+p*5/6=(p-(p*1/6)) */ // �����Ա
		{
			user.official[1]++;
			user.p += 2;
			return 1;
		}
		else if (r >= 12 + user.p * 5 / 6 && r <= 100)			//��ͨ��Ա
		{
			user.official[2]++;
			user.p += 2;
			return 2;
		}

	}

	//����3����

	int ganghuai3drawone(int cost)
	{
		int r, p;
		srand(int(time(0)));

		p = (cost - 20) / 5;
		user.getsj(-cost);
		user.ganhuaisj += cost;
		r = rand() % 99 + 1;
		if (cost <= 35)
		{

			if (r >= 1 && r <= 4 + p)					//sss��Ƭ
			{
				user.nvwushen[0]++;
				return 0;
			}
			else if (r >= 5 + p && r <= 20 + 5 * p)				//ss��Ƭ
			{
				user.nvwushen[1]++;
				return 1;
			}
			else if (r >= 21 + 5 * p && r <= 52 + 13 * p)				//s��Ƭ
			{
				user.nvwushen[2]++;
				return 2;
			}
			else if (r >= 53 + 13 * p && r <= 100)				//a��Ƭ
			{
				user.nvwushen[3]++;
				return 3;
			}

		}
		else if (cost <= 95)
		{
			if (r >= 1 && r <= 4 + p)					//sss��Ƭ
			{
				user.nvwushen[0]++;
				return 0;
			}
			else if (r >= 5 + p && r <= 20 + 5 * p)				//ss��Ƭ
			{
				user.nvwushen[1]++;
				return 1;
			}
			else if (r >= 21 + 5 * p && r <= 100)				//s��Ƭ
			{
				user.nvwushen[2]++;
				return 2;
			}
		}
		else if (cost <= 500)
		{
			if (r >= 1 && r <= 4 + p)					//sss��Ƭ
			{
				user.nvwushen[0]++;
				return 0;
			}
			else if (r >= 5 + p && r <= 100)				//ss��Ƭ
			{
				user.nvwushen[1]++;
				return 1;
			}

		}
		else if (cost >= 500)
		{
			user.nvwushen[0]++;
			return 0;
		}


	}




};
