//������ ���� V2 ���� ����
#include "NHS_�ǽ�03_2.h"

int menu;                                                                                      //������ �޴��� �Է¹��� �������� menu ����

void main()
{
	srand((unsigned)time(NULL));                                                               //������ ��� ��ȭ�ϵ��� ��
	printf("[�޴�]\n");
	printf("1. ������\n2.�� �ڸ� �� ����\n3-9. 3-9�ڸ� �� ���� ����\n\n");
	printf("�ϰ���������� �����ϼ��� : ");
	scanf_s("%d", &menu);

	switch (menu)                                                                              //����ڰ� ������ �޴��� ���� �����ϴ� ������ �ٸ�
	{
		case 1:                                                                                //������ ����
		{
			printf("[���ǵ� ������ ����]\n\n");
			printf("����� ������ �Ƿ��� �׽�Ʈ�ϼ���, ��ȸ�� 10���Դϴ�.\n\n");
			getchar();
			double score = speedcheck();                                                       //������ ���� ����
			printf("\n���� = %4.1f�� (�� %4.1f��)\n", score, tElapsed);                        //���� ���
			break;                       
		}
		case 2:                                                                                //���ڸ� �� ���� ����
		{
			printf("[���ǵ� ���ڸ��� ���� ����]\n\n");
			printf("����� ���ڸ��� ���� �Ƿ��� �׽�Ʈ�ϼ���, ��ȸ�� 10���Դϴ�.\n\n");
			getchar();
			double score = speedcheck();													   //���ڸ� �� ���� ���� ����
			printf("\n���� = %4.1f�� (�� %4.1f��)\n", score, tElapsed);						   //���� ���
			break;
		}
		default:                                                                               //n�ڸ��� ���� ����
		{
			printf("[���ǵ� %d�ڸ��� ����]\n\n", menu);
			printf("����� ���� �Ƿ��� �׽�Ʈ�ϼ���, ��ȸ�� 10���Դϴ�.\n\n");
			getchar();
			double score = speedcheck();													   //n�ڸ��� ���� ���� ����
			printf("\n���� = %4.1f�� (�� %4.1f��)\n", score, tElapsed);						   //���� ���
			break;
		}
	}
}