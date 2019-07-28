#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

class function
{
public:
	//ÓÃ»§×¢²á
	void userregister()
	{
		int i;
		char ch;
		while (1) {
			i = 0;
			while ((ch = getchar()) != '\n')
				user.name[i++] = ch;
			user.name[i] = 0;
			//·ÀÖ¹ÓÃ»§Ö±½ÓÊä»Ø³µ
			if (user.name[0] == 0)
			{
				special(68, '\b');
				continue;
			}
			break;
		}

	}
	//È·ÈÏ¹ºÂòÊ×³ä
	int surebuy(int i)
	{
		if (user.outrmb() >= user.first[0][i - 1])//ÅÐ¶Ï´æ¿îÊÇ·ñ´óÓÚ³äÖµÌ×²Í
		{
			user.usermb(user.first[0][i - 1]);
			user.getsj(user.diamond[i - 1]);
			if (user.first[1][i - 1])//ÅÐ¶ÏÊÇ·ñÊ×³ä
			{
				user.getsj(user.diamond[i - 1]);
				user.first[1][i - 1] = 0;
			}
			return 1;

		}
		else return 0;
	}

	//ÅÐ¶ÏÊÇ·ñÄÜ³é
	int ifcandraw(int i)
	{
		if (user.outsj() >= i)
			return 1;
		else
			return 0;
	}

	//°î°îµ¥³é
	int bangbangdrawone()
	{
		int r;
		srand(int(time(0)));
		user.getsj(-5);					//×êÊ¯-5
		user.bangbangsj += 5;
		r = rand() % 99 + 1;
		if (r >= 1 && r <= 4)						//ËÄÐÇ¿¨Æ¬
		{
			user.card[0]++;
			return 0;
		}
		else if (r >= 5 && r <= 20)				//ÈýÐÇ¿¨Æ¬
		{
			user.card[1]++;
			return 1;
		}
		else if (r >= 21 && r <= 52)				//¶þÐÇ¿¨Æ¬
		{
			user.card[2]++;
			return 2;
		}
		else if (r >= 53 && r <= 100)				//Ò»ÐÇ¿¨Æ¬
		{
			user.card[3]++;
			return 3;
		}


	}

	//°î°îÊ®Á¬
	void bangbangdrawten()
	{
		int r, i, j;
		srand(int(time(0)));
		user.getsj(-50);
		user.bangbangsj += 50;

		//³õÊ¼»¯Ê®Á¬
		for (j = 0; j < 4; j++)
			user.ten[j] = 0;

		for (i = 0; i < 9; i++)
		{

			r = rand() % 99 + 1;

			if (r >= 1 && r <= 4)						//ËÄÐÇ¿¨Æ¬
			{
				user.card[0]++;
				user.ten[0]++;
				user.point[0] = 1;
			}
			else if (r >= 5 && r <= 20)				//ÈýÐÇ¿¨Æ¬
			{
				user.card[1]++;
				user.ten[1]++;
			}
			else if (r >= 21 && r <= 52)				//¶þÐÇ¿¨Æ¬
			{
				user.card[2]++;
				user.ten[2]++;
			}
			else if (r >= 53 && r <= 100)				//Ò»ÐÇ¿¨Æ¬
			{
				user.card[3]++;
				user.ten[3]++;
			}

		}
		//±£µ×
		if (user.ten[3] == 0 && user.ten[2] == 0)
		{
			r = rand() % 19 + 1;
			if (r >= 1 && r <= 4)						//ËÄÐÇ¿¨Æ¬
			{
				user.card[0]++;
				user.ten[0]++;
			}
			else if (r >= 5 && r <= 20)				//ÈýÐÇ¿¨Æ¬
			{
				user.card[1]++;
				user.ten[1]++;
			}
		}
		else
		{
			r = rand() % 99 + 1;

			if (r >= 1 && r <= 4)						//ËÄÐÇ¿¨Æ¬
			{
				user.card[0]++;
				user.ten[0]++;
			}
			else if (r >= 5 && r <= 20)				//ÈýÐÇ¿¨Æ¬
			{
				user.card[1]++;
				user.ten[1]++;
			}
			else if (r >= 21 && r <= 52)				//¶þÐÇ¿¨Æ¬
			{
				user.card[2]++;
				user.ten[2]++;
			}
			else if (r >= 53 && r <= 100)				//Ò»ÐÇ¿¨Æ¬
			{
				user.card[3]++;
				user.ten[3]++;
			}
		}

	}



	//·½ÖÛ
	int fangzhoudrawone()
	{
		int r;
		srand(int(time(0)));
		user.getsj(-10);		//×êÊ¯-10
		user.officalsj += 10;
		r = rand() % 99 + 1;
		if (r >= 1 && r <= 2 + user.p)						//¸ß×ÊÉî¸ÉÔ±
		{
			user.official[0]++;
			user.p = 0;
			return 0;
		}
		else if (r >= 3 + user.p && r <= 11 + user.p * 5 / 6)	/*ºóÃæµÄ+p*5/6=(p-(p*1/6)) */ // ×ÊÉî¸ÉÔ±
		{
			user.official[1]++;
			user.p += 2;
			return 1;
		}
		else if (r >= 12 + user.p * 5 / 6 && r <= 100)			//ÆÕÍ¨¸ÉÔ±
		{
			user.official[2]++;
			user.p += 2;
			return 2;
		}

	}

	//±À»µ3µ¥³é

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

			if (r >= 1 && r <= 4 + p)					//sss¿¨Æ¬
			{
				user.nvwushen[0]++;
				return 0;
			}
			else if (r >= 5 + p && r <= 20 + 5 * p)				//ss¿¨Æ¬
			{
				user.nvwushen[1]++;
				return 1;
			}
			else if (r >= 21 + 5 * p && r <= 52 + 13 * p)				//s¿¨Æ¬
			{
				user.nvwushen[2]++;
				return 2;
			}
			else if (r >= 53 + 13 * p && r <= 100)				//a¿¨Æ¬
			{
				user.nvwushen[3]++;
				return 3;
			}

		}
		else if (cost <= 95)
		{
			if (r >= 1 && r <= 4 + p)					//sss¿¨Æ¬
			{
				user.nvwushen[0]++;
				return 0;
			}
			else if (r >= 5 + p && r <= 20 + 5 * p)				//ss¿¨Æ¬
			{
				user.nvwushen[1]++;
				return 1;
			}
			else if (r >= 21 + 5 * p && r <= 100)				//s¿¨Æ¬
			{
				user.nvwushen[2]++;
				return 2;
			}
		}
		else if (cost <= 500)
		{
			if (r >= 1 && r <= 4 + p)					//sss¿¨Æ¬
			{
				user.nvwushen[0]++;
				return 0;
			}
			else if (r >= 5 + p && r <= 100)				//ss¿¨Æ¬
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
