//���þ� �귿 ���� ���� ���� ���� ����
#include "NHS_�ǽ�03_1.h"

extern int nguns;                                                                //�������Ͽ��� �����Ͽ��� nguns������ �ܺ�����

void playgame(int nplayers, int nbullets)										 //���� ������ �����ϴ� �Լ� playgame
{
	srand((unsigned)time(NULL));												 //������ ��� ��ȭ�ϵ��� ��

	int start = rand() % nplayers;												 //�����ϴ� ����� �������� ����
	int count = 0;																 //�ѿ� �´� ����� ���� �������� ���� count���� �ʱⰪ�� 0
	printf("������ �����ϰڽ��ϴ�. %d��° ���� �����մϴ�.\n\n", start + 1);

	for (int i = 0; i < nguns; i++)												 //��� ���������� ���� ���� ������ ���� �ݺ���
	{
		int death = rand() % nguns;												 //�������� �Ѿ��� ������ źâ ����
		printf("[%d��° ���]\tź���� �����߽��ϴ�.\n", start+1);
		printf("\t\t���͸� ������ �ݹߵ˴ϴ�!\n");
		getchar();
		if (death < nbullets)                                                    //�ѿ� ���� ����� ǥ������ ���ǹ�
		{
			printf("\t\t%d��° ����� �ѿ� �¾ҽ��ϴ�.\n\n", start + 1);
			count++;															 //�ѿ� ���� ����� ���ڸ� ����������
		}
		else
			printf("\t\t��ҽ��ϴ�.\n\n");
		
		if (nbullets == count)													 //�ѿ� ���� ����� ���� �Ѿ��� ������ ��ġ�ϸ� �ݺ����� �������´�.
			break;

		start = (start + 1) % nplayers;											 //���� ������ ���� ������� �ѱ��.
	}
	printf("\n\t\t������ �����մϴ�\n");
}