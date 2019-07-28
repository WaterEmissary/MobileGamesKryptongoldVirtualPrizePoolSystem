#include <iostream>
using namespace std;

class information		//持有物品
	{
		public:
			int firstsignin;			//判断是否首次登录
			char name[20];				//用户名
			int first[2][7];			//首充记录
			int diamond[7];				//邦邦充值规则
			int card[4];				//邦邦库存卡片
			int ten[4];					//邦邦十连记录
			int bangbangsj;				//邦邦消耗水晶
			int p;						//方舟概率
			int official[3];			//方舟干员
			int officalsj;				//方舟消耗水晶
			int cardscore;				//邦邦卡片评分
			int officalscore;			//方舟总评
			int nvwushenscore;			//肝坏3总评
			int nvwushen[4];			//崩崩崩女武神
			int ganhuaisj;				//崩崩崩消耗水晶
			int allgamesj;				//所有游戏消耗水晶
			float point[4];				//总评
			float ppoint;				//全部总评
			information()				//int,float,int
				:firstsignin(1)
				,rmb(2000)
				,sj(0)
			{	
				int i, j;
				cardscore = 0;
				name[0] = 0;
				this->p = 0;			//初始高资深中率
				this->bangbangsj = 0;	//邦邦消耗水晶
				this->officalsj = 0;	//方舟消耗水晶
				this->ganhuaisj = 0;	//崩崩崩消耗水晶
				this->first[0][0] = 648;		//邦邦充值金额
				this->first[0][1] = 328;
				this->first[0][2] = 198;
				this->first[0][3] = 98;
				this->first[0][4] = 64;
				this->first[0][5] = 30;
				this->first[0][6] = 6;
				for (i = 0; i < 7; i++)
					this->first[1][i] = 1;		//首充记录
				//充值规则
				this->diamond[0] = 130;
				this->diamond[1] = 66;
				this->diamond[2] = 40;
				this->diamond[3] = 20;
				this->diamond[4] = 10;
				this->diamond[5] = 6;
				this->diamond[6] = 1;

				//库存卡片
				for (j = 0; j < 4; j++)
					this->card[j] = 0;

				//拥有干员
				for (j = 0; j < 3; j++)
					this->official[j] = 0;

				//拥有女武神
				for (j = 0; j < 4; j++)
					this->nvwushen[j] = 0;

				//成就初值
				for (j = 0; j < 4; j++)
					this->point[j] = 0;	}
			float outrmb()
			{
				return this->rmb;
			}
			void usermb(int i)
			{
				this->rmb -= i;
			}
			void cgrmb()
			{
				cin >> this->rmb;
				if (this->rmb >= 50000) this->rmb = 50000;
				cin.clear();
				cin.ignore(1024, '\n');//防止输入非数字字符
				
			}
			void getsj(int i)
			{
				this->sj += i;
			}
			int outsj()
			{
				return this->sj;
			}
			void cgsj()
			{
				cin >> this->sj;
				if (this->sj >= 5000000) this->sj = 5000000;
				cin.clear();
				cin.ignore(1024, '\n');//防止输入非数字字符
			}
			void re()//数据初始化
			{
				int i,j;
				this->firstsignin = 1;
				this->rmb = 2000;
				this->sj = 0;
				this->name[0] = 0;
				for (i = 0; i < 7; i++)
					this->first[1][i] = 1;
				for (j = 0; j < 4; j++)
					this->card[j] = 0;
				for (j = 0; j < 3; j++)
					this->official[j] = 0;
				for (j = 0; j < 4; j++)
					this->nvwushen[j] = 0;
				for (j = 0; j < 4; j++)
					this->point[j] = 0;
				this->p = 0;			
				this->bangbangsj = 0;	
				this->officalsj = 0;	
				this->ganhuaisj = 0;
			}

			
	private:
	
		float rmb;					//钱
		int sj;						//水晶
		
	
	};