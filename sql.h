#include <iostream>
using namespace std;

class information		//������Ʒ
	{
		public:
			int firstsignin;			//�ж��Ƿ��״ε�¼
			char name[20];				//�û���
			int first[2][7];			//�׳��¼
			int diamond[7];				//����ֵ����
			int card[4];				//����濨Ƭ
			int ten[4];					//���ʮ����¼
			int bangbangsj;				//�������ˮ��
			int p;						//���۸���
			int official[3];			//���۸�Ա
			int officalsj;				//��������ˮ��
			int cardscore;				//��Ƭ����
			int officalscore;			//��������
			int nvwushenscore;			//�λ�3����
			int nvwushen[4];			//������Ů����
			int ganhuaisj;				//����������ˮ��
			int allgamesj;				//������Ϸ����ˮ��
			float point[4];				//����
			float ppoint;				//ȫ������
			information()				//int,float,int
				:firstsignin(1)
				,rmb(2000)
				,sj(0)
			{	
				int i, j;
				cardscore = 0;
				name[0] = 0;
				this->p = 0;			//��ʼ����������
				this->bangbangsj = 0;	//�������ˮ��
				this->officalsj = 0;	//��������ˮ��
				this->ganhuaisj = 0;	//����������ˮ��
				this->first[0][0] = 648;		//����ֵ���
				this->first[0][1] = 328;
				this->first[0][2] = 198;
				this->first[0][3] = 98;
				this->first[0][4] = 64;
				this->first[0][5] = 30;
				this->first[0][6] = 6;
				for (i = 0; i < 7; i++)
					this->first[1][i] = 1;		//�׳��¼
				//��ֵ����
				this->diamond[0] = 130;
				this->diamond[1] = 66;
				this->diamond[2] = 40;
				this->diamond[3] = 20;
				this->diamond[4] = 10;
				this->diamond[5] = 6;
				this->diamond[6] = 1;

				//��濨Ƭ
				for (j = 0; j < 4; j++)
					this->card[j] = 0;

				//ӵ�и�Ա
				for (j = 0; j < 3; j++)
					this->official[j] = 0;

				//ӵ��Ů����
				for (j = 0; j < 4; j++)
					this->nvwushen[j] = 0;

				//�ɾͳ�ֵ
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
				cin.ignore(1024, '\n');//��ֹ����������ַ�
				
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
				cin.ignore(1024, '\n');//��ֹ����������ַ�
			}
			void re()//���ݳ�ʼ��
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
	
		float rmb;					//Ǯ
		int sj;						//ˮ��
		
	
	};