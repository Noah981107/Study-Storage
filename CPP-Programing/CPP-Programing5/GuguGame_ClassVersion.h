#include <cstdio>
#include <cstdlib> 
#include <ctime>	
#include <math.h>  

class Gugugame {
	int Numgames = 0;                                                    //���� ���Ӽ� ��ü Numgames ����, �ʱⰪ 0
	int Numwins = 0;													 //���� ���� ���Ӽ� Numwins ����, �ʱⰪ 0
	double Score = 0;													 //ȯ��� ���� Score ����, �ʱⰪ 0
																		 
	bool Gugudan()														 //1. ������ ���� ����
	{
		int a = rand() % 8 + 2;											 //���� �� a�� ������ �̿��Ͽ� ���� (2~9����)
		int b = rand() % 8 + 2;											 //���� �� b�� ������ �̿��Ͽ� ���� (2~9����)
		int result;														 //���� result ����

		Numgames++;														 //���� ���Ӽ� ����
		printf("[����%d��]: %2d x %2d = ", Numgames, a, b);
		scanf_s("%d", &result);
		if (result == a * b)											 //����� ������ Ǭ ���� ������ ���� �������� 1����
			Numwins++;
		return (result == a * b);										 //������ ���� ��ȯ
	}

	bool Gugudan2()                                                      //2. ���ڸ� �� ���� ���� ����
	{
		int a = ((rand() % 8 + 1) * 10) + (rand() % 8 + 1);				 //���� �� a�� ������ �̿��Ͽ� ���� (11~99����)
		int b = ((rand() % 8 + 1) * 10) + (rand() % 8 + 1);				 //���� �� b�� ������ �̿��Ͽ� ���� (11~99����)
		int result;														 //���� result ����

		Numgames++;														 //���� ���Ӽ� ����
		printf("[����%d��]: %2d x %2d = ", Numgames, a, b);
		scanf_s("%d", &result);
		if (result == a * b)											 //����� ������ Ǭ ���� ������ ���� �������� 1����
			Numwins++;
		return (result == a * b);										 //������ ���� ��ȯ
	}
public:
	int menu;                                                            //�޴��� �Է°��� ���� ��ȭ�ϱ� ������ public���� ���
	double tElapsed = 0;                                                 //�ɸ��ð� ���� ��ȭ�ϴ� ���̱� ������ public���� ���

	bool plusgame()                                                      //3. �Է¹��� �ڸ����� ���� ���� ���� ����
	{
		int answer1 = 0, answer2 = 0, result;							 //������ ���� ������ �ʱⰪ answer1,answer2 �� ����� result ����
		for (int i = 0; i < menu; i++)									 //�������Ͽ��� ���� menu ��ŭ �ڸ����� �� �����
		{
			answer1 += (rand() % 8 + 1) * pow(10, i);					 //pow()�Լ��� �̿��Ͽ� ���ؾ��� ���ڸ� �Է¹��� �ڸ��� ��ŭ �����
			answer2 += (rand() % 8 + 1) * pow(10, i);					 //pow()�Լ��� �̿��Ͽ� ���ؾ��� ���ڸ� �Է¹��� �ڸ��� ��ŭ �����
		}
		Numgames++;														 //���� ���Ӽ� ����
		printf("[����%d��]: %2d + %2d = ", Numgames, answer1, answer2);
		scanf_s("%d", &result);
		if (result == answer1 + answer2)								 //����� ������ Ǭ ���� ������ ���� �������� 1����
			Numwins++;
		return (result == answer1 + answer2);							 //������ ���� ��ȯ
	}

	double speedcheck()                                                  //���� �ҿ�ð��� Ȯ���ϴ� �Լ�
	{
		clock_t t0 = clock();											 //���� ó�� �ð� üũ
		switch (menu)                                                    //�������Ͽ��� ���� menu�� ���� ���ӽ��� �� ���� 
		{
		case 1:															 //1. ������ ���� 
			for (int i = 0; i < 10; i++)								 //������ �� 10�����̱� ������ 10�� �ݺ�
			{
				if (Gugudan() == false)									 //������ ���� Ʋ���� Ʋ�Ƚ��ϴ� ���
					printf("\tƲ�Ƚ��ϴ�.\n");
			}
			break;
		case 2:															 //2. ���ڸ��� ���� ���� 
			for (int i = 0; i < 10; i++)								 //������ �� 10�����̱� ������ 10�� �ݺ�
			{
				if (Gugudan2() == false)								 //������ ���� Ʋ���� Ʋ�Ƚ��ϴ� ���
					printf("\tƲ�Ƚ��ϴ�.\n");
			}
			break;
		default:														 //3. �Է¹��� �ڸ����� ���� ���� ���� ����
			for (int i = 0; i < 10; i++)								 //������ �� 10�����̱� ������ 10�� �ݺ�
			{
				if (plusgame() == false)								 //������ ���� Ʋ���� Ʋ�Ƚ��ϴ� ���
					printf("\tƲ�Ƚ��ϴ�.\n");
			}
			break;
		}
		clock_t t1 = clock();
		tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
		Score = (Numgames < Numwins) ? 0.0 : 100 * (5.0 * Numgames - tElapsed) / (5.0 * Numgames);
		return Score;
	}
	void play()
	{
		srand((unsigned)time(NULL));                                                                   //������ ��� ��ȭ�ϵ��� ��
		printf("[�޴�]\n");
		printf("1. ������\n2.�� �ڸ� �� ����\n3-9. 3-9�ڸ� �� ���� ����\n\n");
		printf("�ϰ���������� �����ϼ��� : ");
		scanf_s("%d", &menu);

		switch (menu)                                                                                  //����ڰ� ������ �޴��� ���� �����ϴ� ������ �ٸ�
		{
		case 1:																						   //������ ����
		{
			printf("[���ǵ� ������ ����]\n\n");
			printf("����� ������ �Ƿ��� �׽�Ʈ�ϼ���, ��ȸ�� 10���Դϴ�.\n\n");
			getchar();
			double score = speedcheck();															   //������ ���� ����
			printf("\n���� = %4.1f�� (�� %4.1f��)\n", score, tElapsed);								  //���� ���
			break;
		}
		case 2:																						  //���ڸ� �� ���� ����
		{
			printf("[���ǵ� ���ڸ��� ���� ����]\n\n");
			printf("����� ���ڸ��� ���� �Ƿ��� �׽�Ʈ�ϼ���, ��ȸ�� 10���Դϴ�.\n\n");
			getchar();
			double score = speedcheck();															   //���ڸ� �� ���� ���� ����
			printf("\n���� = %4.1f�� (�� %4.1f��)\n", score, tElapsed);								  //���� ���
			break;
		}
		default:																					   //n�ڸ��� ���� ����
		{
			printf("[���ǵ� %d�ڸ��� ����]\n\n", menu);
			printf("����� ���� �Ƿ��� �׽�Ʈ�ϼ���, ��ȸ�� 10���Դϴ�.\n\n");
			getchar();
			double score = speedcheck();															   //n�ڸ��� ���� ���� ����
			printf("\n���� = %4.1f�� (�� %4.1f��)\n", score, tElapsed);								  //���� ���
			break;
		}
		}
	}
};