//������ ���� V2 ���� ����
#include "NHS_�ǽ�03_2.h"

static int Numgames = 0;                                            //���� ���Ӽ� Numgames ����, �ʱⰪ 0
static int Numwins = 0;                                             //���� ���� ���Ӽ� Numwins ����, �ʱⰪ 0 
static double Score = 0;                                            //ȯ��� ���� Score ����, �ʱⰪ 0
double tElapsed = 0;                                                //���� �ҿ� �ð� tElapsed ����, �ʱⰪ 0
extern int menu;                                                    //���� ���Ͽ��� �Է¹��� menu�� �ܺ�����

static bool Gugudan()                                               //1. ������ ���� ����
{
	int a = rand() % 8 + 2;                                         //���� �� a�� ������ �̿��Ͽ� ���� (2~9����)
	int b = rand() % 8 + 2;                                         //���� �� b�� ������ �̿��Ͽ� ���� (2~9����)
	int result;                                                     //���� result ����

	Numgames++;                                                     //���� ���Ӽ� ����
	printf("[����%d��]: %2d x %2d = ", Numgames, a, b);                
	scanf_s("%d", &result);
	if (result == a * b)                                            //����� ������ Ǭ ���� ������ ���� �������� 1����
		Numwins++;                   
	return (result == a * b);                                       //������ ���� ��ȯ
} 

static bool Gugudan2()                                              //2. ���ڸ� �� ���� ���� ����
{
	int a = ((rand() % 8 + 1) * 10) + (rand() % 8 + 1);				//���� �� a�� ������ �̿��Ͽ� ���� (11~99����)
	int b = ((rand() % 8 + 1) * 10) + (rand() % 8 + 1);				//���� �� b�� ������ �̿��Ͽ� ���� (11~99����)
	int result;														//���� result ����

	Numgames++;														//���� ���Ӽ� ����
	printf("[����%d��]: %2d x %2d = ", Numgames, a, b);
	scanf_s("%d", &result);
	if (result == a * b)											//����� ������ Ǭ ���� ������ ���� �������� 1����
		Numwins++;
	return (result == a * b);										//������ ���� ��ȯ
}

static bool plusgame()                                              //3. �Է¹��� �ڸ����� ���� ���� ���� ����
{
	int answer1 = 0, answer2 = 0, result;						    //������ ���� ������ �ʱⰪ answer1,answer2 �� ����� result ����
	for (int i = 0; i < menu; i++)								    //�������Ͽ��� ���� menu ��ŭ �ڸ����� �� �����
	{																
		answer1 += (rand() % 8 + 1) * pow(10, i);                   //pow()�Լ��� �̿��Ͽ� ���ؾ��� ���ڸ� �Է¹��� �ڸ��� ��ŭ �����
		answer2 += (rand() % 8 + 1) * pow(10, i);					//pow()�Լ��� �̿��Ͽ� ���ؾ��� ���ڸ� �Է¹��� �ڸ��� ��ŭ �����  
	}
	Numgames++;                                                     //���� ���Ӽ� ����
	printf("[����%d��]: %2d + %2d = ", Numgames, answer1, answer2);
	scanf_s("%d", &result);
	if (result == answer1 + answer2)								//����� ������ Ǭ ���� ������ ���� �������� 1����
		Numwins++;
	return (result == answer1 + answer2);							//������ ���� ��ȯ
}

double speedcheck()                                                 //���� �ҿ�ð��� Ȯ���ϴ� �Լ�
{
	clock_t t0 = clock();                                           //���� ó�� �ð� üũ
		switch(menu)                                                //�������Ͽ��� ���� menu�� ���� ���ӽ��� �� ����
		{
			case 1:                                                 //1. ������ ���� 
				for (int i = 0; i < 10; i++)                        //������ �� 10�����̱� ������ 10�� �ݺ�
				{
					if (Gugudan() == false)                         //������ ���� Ʋ���� Ʋ�Ƚ��ϴ� ���
						printf("\tƲ�Ƚ��ϴ�.\n");
				}
				break;
			case 2:                                                 //2. ���ڸ��� ���� ���� 
				for (int i = 0; i < 10; i++)						//������ �� 10�����̱� ������ 10�� �ݺ�
				{
					if (Gugudan2() == false)						//������ ���� Ʋ���� Ʋ�Ƚ��ϴ� ���
						printf("\tƲ�Ƚ��ϴ�.\n");
				}
				break;
			default:                                                //3. �Է¹��� �ڸ����� ���� ���� ���� ����
				for (int i = 0; i < 10; i++)						//������ �� 10�����̱� ������ 10�� �ݺ�
				{
					if (plusgame() == false)						//������ ���� Ʋ���� Ʋ�Ƚ��ϴ� ���
						printf("\tƲ�Ƚ��ϴ�.\n");
				}
				break;
		}
	clock_t t1 = clock();                                                                       //���� �������� �ð� üũ
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;                                              //��ü �ҿ� �ð� 
	Score = (Numgames< Numwins) ? 0.0 : 100 * (5.0 * Numgames - tElapsed) / (5.0 * Numgames);   // ���� ȯ��
	return Score;                                                                               //������ ��ȯ�Ѵ�
}